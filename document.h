#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED
#include "parts.h"
#include <libxml/xmlwriter.h>

struct data_t;
/*
{
    unsigned int day;
    unsigned int months;
    unsigned int year;
};
//*/
struct pragraph_t
{
    bool b;
    bool single;
    bool rtl;
    bool con;
    bool table;
};

class document:public parts
{
public:
    document(const char *dir,const char* creator);
    int addpragraph(const char *text,pragraph_t *pg);
    int addpragraph();
    /*
    table of studint to exam
    */

    // add emty row
    int addrow();
    int addrow(unsigned int id, const char* fullname,const char* Hincreasing, const unsigned int Nexam);
    int end();
    /*
    index of the docmunt for exma list
    */
    int begin(const char *Months, const char *matrucule, const char *ExamCenter, const char *state,data_t *d);

private:
    int finish();
    // table Mlist 6
    int addtable();
    int data(data_t *d);
    int addtableN();
    /*
    gragraph and text add mouted
    */
    int addpragraph(const char *text1, const char *text2);
    int addpragraph(const char *text,bool b,bool single,bool stl,bool con);
    int addpragraph(const char *text,bool b,bool single);
    int addpragraph(const char *text,bool b);
    int addpragraph(const char *text);
    int addpragraph(const char *text,bool b,bool single,bool stl,bool con,bool table);
    int addpragraph(const char *text1,const char *text2,const char *text3);
    int writertrN(const char *text,const char *number);
    int writertrN();
    int writertc(const char* ww,const char *text,bool con,bool b);
    int writertcN(const char* ww,const char *text,bool b,bool single,bool two);
    char Data[60];
    unsigned int Nexam1,Nexam2,Nexam3;
    xmlTextWriterPtr writer;
};

#endif // DOCUMENT_H_INCLUDED
