#include "parts.h"
#include "xmlheader.h"
#include <fstream>
#include <io.h>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "compress.h"
using namespace std;



int parts::DocPropsCore(const char* uri,const char* creator)
{
    xmlTextWriterPtr writer;
    writer = xmlNewTextWriterFilename(uri,0);
    time_t result = time(nullptr);
    tm tm = *localtime(&result);
    stringstream s;
    s << std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
    //s.str().c_str();
    W_S_D(writer,"yes");
    W_S_E(writer, "cp:coreProperties");
    W_W_A(writer, "xmlns:cp", "http://schemas.openxmlformats.org/package/2006/metadata/core-properties");
    W_W_A(writer, "xmlns:dc", "http://purl.org/dc/elements/1.1/");
    W_W_A(writer, "xmlns:dcterms", "http://purl.org/dc/terms/");
    W_W_A(writer, "xmlns:dcmitype", "http://purl.org/dc/dcmitype/");
    W_W_A(writer, "xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
    W_W_E(writer, "dc:creator", creator);
    W_W_E(writer, "cp:lastModifiedBy", creator);
    // dcterms:created
    W_S_E(writer, "dcterms:created");
    W_W_A(writer, "xsi:type", "dcterms:W3CDTF");
    W_W_R(writer, s.str().c_str());
    W_E_E(writer);
    // dcterms:modified
    W_S_E(writer, "dcterms:modified");
    W_W_A(writer, "xsi:type", "dcterms:W3CDTF");
    W_W_R(writer, s.str().c_str());
    W_E_E(writer);
    W_E_E(writer); // cp:coreProperties
    W_E_D(writer);
    CLEAN(writer);
    return 0;
}

int parts::DocPropsApp(const char* uri)
{
    xmlTextWriterPtr writer;
    writer = xmlNewTextWriterFilename(uri, 0);
    W_S_D(writer, "yes");
    W_S_E(writer, "Properties");
    W_W_A(writer, "xmlns", "http://schemas.openxmlformats.org/officeDocument/2006/extended-properties");
    W_W_A(writer, "xmlns:vt", "http://schemas.openxmlformats.org/officeDocument/2006/docPropsVTypes");
    W_W_E(writer, "Application", this->appname);
    W_E_E(writer); // Properties
    W_E_D(writer);
    CLEAN(writer);
    return 0;
}

int parts::ContentTypes(const char* uri)
{
    #include "Content_Types.h"
    ofstream fout;
    fout.open(uri, ios::binary);
    fout.write(( char*)& rawData,sizeof(rawData));
    fout.close();
    return 0;
}

int parts::Rels(const char* uri)
{
      #include "Rels.h"
      ofstream fout;
      fout.open(uri, ios::binary);
      fout.write((char*)& rawData,sizeof(rawData));
      fout.close();
      return 0;
}

int parts::RelsDocument(const char* uri)
{
    #include "RelsDocument.h"
    ofstream fout;
    fout.open(uri, ios::binary);
    fout.write((char*)& rawData,sizeof(rawData));
    fout.close();
    return 0;
}

int parts::Styles(const char* uri)
{
    #include "Styles.h"
    ofstream fout;
    fout.open(uri, ios::binary);
    fout.write((char*)& rawData, sizeof(rawData));
    fout.close();
    return 0;
}

int parts::Settings(const char* uri)
{
    #include "Settings.h"
    ofstream fout;
    fout.open(uri, ios::binary);
    fout.write((char*)& rawData,sizeof(rawData));
    fout.close();
    return 0;
}

int parts::WebSettings(const char* uri)
{
    #include "WebSettings.h"
    ofstream fout;
    fout.open(uri, ios::binary);
    fout.write((char*)& rawData,sizeof(rawData));
    fout.close();
    return 0;
}

int parts::FontTable(const char* uri)
{
    #include "FontTable.h"
    ofstream fout;
    fout.open(uri, ios::binary);
    fout.write((char*)& rawData,sizeof(rawData));
    fout.close();
    return 0;
}

int parts::Theme(const char* uri)
{
    #include "Theme.h"
    ofstream fout;
    fout.open(uri, ios::binary);
    fout.write((char*)& rawData,sizeof(rawData));
    fout.close();
    return 0;
}

int parts::init(const char* dir,const char* creator)
{

    this->dir = getcwd(0,1024);
    mkdir(dir);
    chdir(dir);
    //this->dir = dir;
    mkdir("_rels");
    mkdir("docProps");
    mkdir("word");
    mkdir("word/_rels");
    mkdir("word/theme");
    this->ContentTypes("[Content_Types].xml");
    this->DocPropsApp("docProps/app.xml");
    this->DocPropsCore("docProps/core.xml",creator);
    this->FontTable("word/fontTable.xml");
    this->Rels("_rels/.rels");
    this->RelsDocument("word/_rels/document.xml.rels");
    this->Settings("word/settings.xml");
    this->Styles("word/styles.xml");
    this->Theme("word/theme/theme1.xml");
    this->WebSettings("word/webSettings.xml");
    return 0;
}

int parts::finish()
{


    remove("[Content_Types].xml");
    remove("docProps/app.xml");
    remove("docProps/core.xml");
    remove("word/fontTable.xml");
    remove("_rels/.rels");
    remove("word/_rels/document.xml.rels");
    remove("word/settings.xml");
    remove("word/styles.xml");
    remove("word/theme/theme1.xml");
    remove("word/webSettings.xml");
    remove("word/document.xml");
    rmdir("word/theme");
    rmdir("word/_rels");
    rmdir("word");
    rmdir("docProps");
    rmdir("_rels");
    chdir(this->dir);
    memset(&this->appname,0,sizeof(this->appname));
    memset(&this->dir,0,sizeof(this->dir));


    return 0;
}

int parts::makedocx(const char* docxname)
{
    remove(docxname);
    DOCXInit(docxname);
    const char* Filenames[] = {"_rels\\.rels",  "docProps\\app.xml",
    "docProps\\core.xml", "word\\_rels\\document.xml.rels","word\\theme\\theme1.xml",
    "word\\document.xml","word\\fontTable.xml", "word\\settings.xml",
    "word\\styles.xml","word\\webSettings.xml","[Content_Types].xml",};

	unsigned int nCount = sizeof( Filenames )/sizeof( char* );

	//////////////////////////////

	for ( unsigned int i = 0; i < nCount; i++ )
	{
	   // file.write(Filenames[i]);
        DOCXadd((char*)Filenames[i]);
	}
	//////////////////////////////
    DOCXQuit();
    this->finish();
    return 0;
}



























