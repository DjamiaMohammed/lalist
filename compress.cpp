//#include "zipfile.h"
// begin zipfile.h

#define ACTION_NONE 0
#define ACTION_CREATE 1
#define ACTION_EXTRACT 2
#define ACTION_UPDATE 3
#define ACTION_LIST 4

#define TRUE 1
#define FALSE 0

/* Amount of bytes to read at a time.  You can change this to optimize for
   your system */
#define RDSZ 4096

/* Change these to match your system:
   ub1 == unsigned 1 byte word
   ub2 == unsigned 2 byte word
   ub4 == unsigned 4 byte word
*/

typedef unsigned char ub1;

typedef unsigned short ub2;

typedef unsigned int ub4;


struct zipentry {
  ub2 mod_time;
  ub2 mod_date;
  ub4 crc;
  ub4 csize;
  ub4 usize;
  ub4 offset;
  ub1 compressed;
  char *filename;

  struct zipentry *next_entry;
};

typedef struct zipentry zipentry;

/* $Id: zipfile.h,v 1.1 2000/12/09 03:08:23 apbianco Exp $

   $Log: zipfile.h,v $
   Revision 1.1  2000/12/09 03:08:23  apbianco
   2000-12-08  Alexandre Petit-Bianco  <apbianco@cygnus.com>

           * fastjar: Imported.

   Revision 1.1.1.1  1999/12/06 03:09:11  toast
   initial checkin..



   Revision 1.6  1999/05/10 08:33:08  burnsbr
   added UNPACK_UB4 and UNPACK_UB2

   Revision 1.5  1999/04/26 02:36:34  burnsbr
   added LOC_EXTRA macro

   Revision 1.4  1999/04/23 12:01:19  burnsbr
   added more defines


*/

/*
  zipfile.h - defines for indexing zipfile headers
  Copyright (C) 1999  Bryan Burns

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#define LOC_EXTRA   6  /* extra bytes */
#define LOC_COMP    8  /* compression method */
#define LOC_MODTIME 10 /* last modification time */
#define LOC_MODDATE 12 /* last modification date */
#define LOC_CRC     14 /* CRC */
#define LOC_CSIZE   18 /* compressed size */
#define LOC_USIZE   22 /* uncompressed size */
#define LOC_FNLEN   26 /* filename length */
#define LOC_EFLEN   28 /* extra-field length */

#define CEN_COMP    10 /* compression method */
#define CEN_MODTIME 12
#define CEN_MODDATE 14
#define CEN_CRC     16
#define CEN_CSIZE   20
#define CEN_USIZE   24
#define CEN_FNLEN   28
#define CEN_EFLEN   30
#define CEN_COMLEN  32
#define CEN_OFFSET  42


/* macros */
#define PACK_UB4(d, o, v) d[o] = (ub1)((v) & 0x000000ff); \
                          d[o + 1] = (ub1)(((v) & 0x0000ff00) >> 8); \
                          d[o + 2] = (ub1)(((v) & 0x00ff0000) >> 16); \
                          d[o + 3] = (ub1)(((v) & 0xff000000) >> 24)

#define PACK_UB2(d, o, v) d[o] = (ub1)((v) & 0x00ff); \
                          d[o + 1] = (ub1)(((v) & 0xff00) >> 8)

#define UNPACK_UB4(s, o) (ub4)s[o] + (((ub4)s[o + 1]) << 8) +\
                         (((ub4)s[o + 2]) << 16) + (((ub4)s[o + 3]) << 24)

#define UNPACK_UB2(s, o)  (ub2)s[o] + (((ub2)s[o + 1]) << 8)

// end zipfile.h

#include <zlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "compress.h"


#ifndef O_BINARY
#define O_BINARY 0
#endif

void add_entry(struct zipentry *);
void init_headers(void);

int add_file_to_jar(int, int, const char*, struct stat*);
int add_to_jar(int, const char*, const char*);
int create_central_header(int);


/* global variables */
ub1 file_header[30];
ub1 data_descriptor[16];
int do_compress;
int seekable;
int verbose;
char *jarfile;
/* If non zero, then don't recurse in directory. Instead, add the
   directory entry and relie on an explicit list of files to populate
   the archive. This option isn't supported by the original jar tool. */
int use_explicit_list_only;
/* If non zero, then read the entry names from stdin. This option
   isn't supported by the original jar tool. */
int read_names_from_stdin;
zipentry *ziplist; /* linked list of entries */
zipentry *ziptail; /* tail of the linked list */
int number_of_entries; /* number of entries in the linked list */


unsigned long unix2dostime (time_t *time)
{
  struct tm *ltime = localtime (time);
  int year = ltime->tm_year - 80;
  if (year < 0)
    year = 0;

  return (year << 25
	  | (ltime->tm_mon + 1) << 21
	  | ltime->tm_mday << 16
	  | ltime->tm_hour << 11
	  | ltime->tm_min << 5
	  | ltime->tm_sec >> 1);
}


static z_stream zs;

void init_compression(){

  memset(&zs, 0, sizeof(z_stream));

  zs.zalloc = Z_NULL;
  zs.zfree = Z_NULL;
  zs.opaque = Z_NULL;

  if(deflateInit2(&zs, Z_DEFAULT_COMPRESSION, Z_DEFLATED, -MAX_WBITS,
                  5, Z_DEFAULT_STRATEGY) != Z_OK){

    fprintf(stderr, "Error initializing deflation!\n");
    exit(1);
  }
}

int compress_file(int in_fd, int out_fd, struct zipentry *ze){
  Bytef in_buff[RDSZ];
  Bytef out_buff[RDSZ];
  unsigned int rdamt, wramt;
  unsigned long tr = 0;
  int rtval;

  rdamt = 0;

  zs.avail_in = 0;
  zs.next_in = in_buff;

  zs.next_out = out_buff;
  zs.avail_out = (uInt)RDSZ;

  ze->crc = crc32(0L, Z_NULL, 0);

  for(; ;){
      if(zs.avail_in == 0 && zs.avail_out > 0){
      if((rtval = read(in_fd, in_buff, RDSZ)) == 0)
        break;

      if(rtval == -1){
        perror("read");
        exit(1);
      }

      rdamt = rtval;

      ze->crc = crc32(ze->crc, in_buff, rdamt);

      tr += rdamt;

      zs.next_in = in_buff;
      zs.avail_in = rdamt;
    }

    if(deflate(&zs, 0) != Z_OK){
      fprintf(stderr, "Error deflating! %s:%d\n", __FILE__, __LINE__);
      exit(1);
    }

    if(zs.avail_out == 0){

      if(write(out_fd, out_buff, RDSZ) != RDSZ){
        perror("write");
        exit(1);
      }

      zs.next_out = out_buff;
      zs.avail_out = (uInt)RDSZ;
    }

  }

  if(zs.avail_out < RDSZ){

    wramt = RDSZ - zs.avail_out;

    if(write(out_fd, out_buff, wramt) != (int)wramt){
      perror("write");
      exit(1);
    }
    zs.next_out = out_buff;
    zs.avail_out = (uInt)RDSZ;
  }

  while(deflate(&zs, Z_FINISH) == Z_OK){
    wramt = RDSZ - zs.avail_out;

    if(write(out_fd, out_buff, wramt) != (int)wramt){
      perror("write");
      exit(1);
    }

    zs.next_out = out_buff;
    zs.avail_out = (uInt)RDSZ;
  }

  if(zs.avail_out != RDSZ){
    wramt = RDSZ - zs.avail_out;

    if(write(out_fd, out_buff, wramt) != (int)wramt){
      perror("write");
      exit(1);
    }
  }

  ze->usize = (ub4)zs.total_in;
  ze->csize = (ub4)zs.total_out;

  if(deflateReset(&zs) != Z_OK){
    fprintf(stderr, "Error resetting deflation\n");
    exit(1);
  }

  return 0;
}

void end_compression(){
  int rtval;

  if((rtval = deflateEnd(&zs)) != Z_OK && rtval != Z_DATA_ERROR){
    fprintf(stderr, "Error calling deflateEnd\n");
    fprintf(stderr, "error: (%d) %s\n", rtval, zs.msg);
    exit(1);
  }
}

void init_headers(){
  file_header[0] = 0x50;
  file_header[1] = 0x4b;
  file_header[2] = 0x03;
  file_header[3] = 0x04;
  file_header[4] = 10;
  for (int i = 5; i < 30; ++i) file_header[i] = 0;
  PACK_UB4(data_descriptor, 0, 0x08074b50);
}

void add_entry(struct zipentry *ze){

  if(ziplist == NULL){
    ziplist = ze;
    ziptail = ziplist;
  } else {
    ziplist->next_entry = ze;
    ziplist = ze;
  }

  number_of_entries++;
}


int add_to_jar(int fd, const char *new_dir, const char *file){
  struct stat statbuf;
  DIR *dir;
  struct dirent *de;
  zipentry *ze;
  int stat_return;
  char *old_dir = NULL;

  while (*file=='.' && *(file+1)=='/')
    file+=2;

  if(new_dir != NULL){
    old_dir = getcwd(NULL, 0);

    if(chdir(new_dir) == -1){
      perror(new_dir);
      return 1;
    }
  }

  if(!strcmp(file, jarfile)){
    if(verbose)
      printf("skipping: %s\n", file);
    return 0;
  }

  stat_return = stat(file, &statbuf);

  if(stat_return == -1){
    perror(file);
    return 1;
  } else if(S_ISDIR(statbuf.st_mode)){
    char *fullname;
    char *t_ptr;
    int nlen;
    unsigned long mod_time;

    dir = opendir(file);

    if(dir == NULL){
      perror("opendir");
      return 1;
    }

    nlen = strlen(file) + 256;
    fullname = (char*)malloc(nlen * sizeof(char));
    memset(fullname, 0, (nlen * sizeof(char)));

    if(fullname == NULL){
      fprintf(stderr, "Filename is NULL!\n");
      return 1;
    }

    strcpy(fullname, file);
    nlen = strlen(file);

    if(fullname[nlen - 1] != '/'){
      fullname[nlen] = '/';
      t_ptr = (fullname + nlen + 1);
    } else
      t_ptr = (fullname + nlen);


    memset((file_header + 12), '\0', 16);

    nlen = (t_ptr - fullname);

    mod_time = unix2dostime(&statbuf.st_mtime);

    PACK_UB2(file_header, LOC_EXTRA, 0);
    PACK_UB2(file_header, LOC_COMP, 0);
    PACK_UB2(file_header, LOC_FNLEN, nlen);
    PACK_UB4(file_header, LOC_MODTIME, mod_time);

    if(verbose)
      printf("adding: %s (in=%d) (out=%d) (stored 0%%)\n", fullname, 0, 0);

    ze = (zipentry*)malloc(sizeof(zipentry));
    if(ze == NULL){
      perror("malloc");
      exit(1);
    }

    memset(ze, 0, sizeof(zipentry));
    ze->filename = (char*)malloc((nlen + 1) * sizeof(char) + 1);
    strcpy(ze->filename, fullname);
    ze->filename[nlen] = '\0';

    ze->offset = lseek(fd, 0, SEEK_CUR);
    ze->mod_time = (ub2)(mod_time & 0x0000ffff);
    ze->mod_date = (ub2)((mod_time & 0xffff0000) >> 16);
    ze->compressed = FALSE;

    add_entry(ze);

    write(fd, file_header, 30);
    write(fd, fullname, nlen);

    while(!use_explicit_list_only && (de = readdir(dir)) != NULL){
      if(de->d_name[0] == '.')
        continue;
      if(!strcmp(de->d_name, jarfile)){
        if(verbose)
          printf("skipping: %s\n", de->d_name);
        continue;
      }

      strcpy(t_ptr, de->d_name);

      if(add_to_jar(fd, NULL, fullname)){
        fprintf(stderr, "Error adding file to jar!\n");
        return 1;
      }
    }

    free(fullname);
    closedir(dir);

  } else if(S_ISREG(statbuf.st_mode)){
    int add_fd;

    add_fd = open(file, O_RDONLY | O_BINARY);
    if(add_fd < 0){
      fprintf(stderr, "Error opening %s.\n", file);
      return 0;
    }

    if(add_file_to_jar(fd, add_fd, file, &statbuf)){
      fprintf(stderr, "Error adding file to jar!\n");
      return 1;
    }

  } else {
    fprintf(stderr, "Illegal file specified: %s\n", file);
  }

  if(old_dir != NULL){
    if(chdir(old_dir))
      perror(old_dir);

    free(old_dir);
  }

  return 0;
}

int add_file_to_jar(int jfd, int ffd, const char *fname, struct stat *statbuf){

  unsigned short file_name_length;
  unsigned long mod_time;
 // ub1 rd_buff[RDSZ];
  off_t offset = 0;
//  int rdamt;
  struct zipentry *ze;

  mod_time = unix2dostime(&(statbuf->st_mtime));
  file_name_length = strlen(fname);

  PACK_UB2(file_header, LOC_EXTRA, 0);
  PACK_UB2(file_header, LOC_COMP, 8);

  PACK_UB4(file_header, LOC_MODTIME, mod_time);
  PACK_UB2(file_header, LOC_FNLEN, file_name_length);

    memset((file_header + LOC_CRC), '\0', 12);

  ze = (zipentry*)malloc(sizeof(zipentry));
  if(ze == NULL){
    perror("malloc");
    exit(1);
  }

  memset(ze, 0, sizeof(zipentry));
  ze->filename = (char*)malloc((file_name_length + 1) * sizeof(char));
  strcpy(ze->filename, fname);

  ze->mod_time = (ub2)(mod_time & 0x0000ffff);
  ze->mod_date = (ub2)((mod_time & 0xffff0000) >> 16);

  ze->csize = statbuf->st_size;
  ze->usize = ze->csize;
  ze->offset = lseek(jfd, 0, SEEK_CUR);
  ze->compressed = TRUE;


  add_entry(ze);


  write(jfd, file_header, 30);


  write(jfd, fname, file_name_length);


  if(verbose){
    printf("adding: %s ", fname);
    fflush(stdout);
  }
  compress_file(ffd, jfd, ze);

  close(ffd);

  PACK_UB4(data_descriptor, 4, ze->crc);
  PACK_UB4(data_descriptor, 8, ze->csize);
  PACK_UB4(data_descriptor, 12, ze->usize);

  if(seekable){
    offset = (ze->csize + strlen(ze->filename) + 16);

    if(lseek(jfd, -offset, SEEK_CUR) == (off_t)-1){
      perror("lseek");
      exit(1);
    }

    if(write(jfd, (data_descriptor + 4), 12) != 12){
      perror("write");
      return 0;
    }

    offset -= 12;

    if(lseek(jfd, offset, SEEK_CUR) == (off_t)-1){
      perror("lseek");
      exit(1);
    }
  } else if(do_compress){

    if(write(jfd, data_descriptor, 16) != 16){
      perror("write");
      return 0;
    }
  }

  if(verbose)
    printf("(in=%d) (out=%d) (%s %d%%)\n",
           (int)ze->usize, (int)ze->csize,
           "deflated",
           ((int)((1 - ze->csize/(float)ze->usize) * 100)));

  return 0;
}

int create_central_header(int fd){
  ub1 header[46];
  ub1 end_header[22];
  int start_offset;
  int dir_size;
  int total_in = 0, total_out = 22;
  zipentry *ze;

  header[0] = 'P';
  header[1] = 'K';
  header[2] = 1;
  header[3] = 2;
  header[4] = 10;
  header[5] = 0;
  header[6] = 10;
  for (int i = 7; i < 45; ++i) header[i] = 0;

  start_offset = lseek(fd, 0, SEEK_CUR);

  for(ze = ziptail; ze != NULL; ze = ze->next_entry){

    total_in += ze->usize;
    total_out += ze->csize + 76 + strlen(ze->filename) * 2;

    if(ze->compressed){
      PACK_UB2(header, CEN_COMP, 8);
    } else {
      PACK_UB2(header, CEN_COMP, 0);
    }

    PACK_UB2(header, CEN_MODTIME, ze->mod_time);
    PACK_UB2(header, CEN_MODDATE, ze->mod_date);
    PACK_UB4(header, CEN_CRC, ze->crc);
    PACK_UB4(header, CEN_CSIZE, ze->csize);
    PACK_UB4(header, CEN_USIZE, ze->usize);
    PACK_UB2(header, CEN_FNLEN, strlen(ze->filename));
    PACK_UB4(header, CEN_OFFSET, ze->offset);

    write(fd, header, 46);

    write(fd, ze->filename, strlen(ze->filename));
  }

  dir_size = lseek(fd, 0, SEEK_CUR) - start_offset;

  end_header[0] = 0x50;
  end_header[1] = 0x4b;
  end_header[2] = 0x05;
  end_header[3] = 0x06;
  end_header[4] = 0;
  end_header[5] = 0;
  end_header[6] = 0;
  end_header[7] = 0;
  PACK_UB2(end_header, 8, number_of_entries);
  PACK_UB2(end_header, 10, number_of_entries);
  PACK_UB4(end_header, 12, dir_size);
  PACK_UB4(end_header, 16, start_offset);
  end_header[20] = 0;
  end_header[21] = 0;

  write(fd, end_header, 22);

  if(verbose)
    printf("Total:\n------\n(in = %d) (out = %d) (%s %d%%)\n",
           total_in,
           total_out,
           "deflated",
           (int)((1 - (total_out / (float)total_in)) * 100)
           );

  return 0;
}

int jarfd;

int DOCXInit(const char* docxname)
{
    jarfd=-1;
    init_headers();
    init_compression();
    jarfile=(char*)docxname;
    if(jarfile){
      jarfd = open(jarfile, O_CREAT | O_BINARY | O_WRONLY | O_TRUNC,
		   S_IRUSR | S_IWUSR);

      if(jarfd < 0){
        fprintf(stderr, "Error opening %s for writing!\n", jarfile);
        perror(jarfile);
        exit(1);
      }
      seekable = TRUE;
    }
    return 0;
}

int DOCXadd(char* fname)
{
    return add_to_jar(jarfd,0,fname);

}

void DOCXQuit(void)
{
    end_compression();
    create_central_header(jarfd);
    if (close(jarfd) != 0) {
      fprintf(stderr, "Error closing jar archive!\n");
    }
}














