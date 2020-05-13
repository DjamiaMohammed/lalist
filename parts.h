#ifndef PARTS_H_INCLUDED
#define PARTS_H_INCLUDED
#include "libxml/encoding.h"

class parts
{
public:
    const char* appname;
    const char* dir;
    int init(const char *dir,const char* creator);
    int makedocx(const char* docxname);
private:
    int finish();
    int DocPropsApp(const char *uri);
    int DocPropsCore(const char *uri,const char* creator);
    int ContentTypes(const char *uri);
    int Rels(const char *uri);
    int RelsDocument(const char *uri);
    int Styles(const char *uri);
    int Settings(const char *uri);
    int WebSettings(const char *uri);
    int FontTable(const char *uri);
    int Theme(const char *uri);


};

#endif // PARTS_H_INCLUDED
