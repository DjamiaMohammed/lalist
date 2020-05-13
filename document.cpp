#include "document.h"
#include "xmlheader.h"
//#include <stdio.h>
#include <cstdio>
#include <string.h>
#define wr this->writer
using namespace std;

struct data_t
//*
{
    unsigned int day;
    unsigned int months;
    unsigned int year;
};
//*/

int writerPr(xmlTextWriterPtr writer,pragraph_t *pg)
{
    W_S_E(writer, "w:rPr");
    if(pg->b==true){W_SE_E(writer, "w:b");W_SE_E(writer, "w:bCs");}
    W_SWE_EAE(writer, "w:sz", "w:val", "32");
    W_SWE_EAE(writer,"w:szCs", "w:val", "32");
    if(pg->single == true){W_SWE_EAE(writer, "w:u", "w:val", "single");}
    if(pg->rtl==true){W_SE_E(writer, "w:rtl");}
    W_SWE_EAE(writer, "w:lang", "w:bidi", "ar-DZ");
    W_E_E(writer);// w:rPr
    return 0;
}

 document::document(const char *dir,const char* creator)
{
    this->appname = "word";
    this->init(dir,creator);
    this->writer = xmlNewTextWriterFilename("word/document.xml", 0);
    W_S_D(wr, "yes");
    W_S_E(wr,"w:document");
    W_W_A(wr, "xmlns:ve", "http://schemas.openxmlformats.org/markup-compatibility/2006");
    W_W_A(wr, "xmlns:o", "urn:schemas-microsoft-com:office:office");
    W_W_A(wr, "xmlns:r", "http://schemas.openxmlformats.org/officeDocument/2006/relationships");
    W_W_A(wr, "xmlns:m", "http://schemas.openxmlformats.org/officeDocument/2006/math");
    W_W_A(wr, "xmlns:v", "urn:schemas-microsoft-com:vml");
    W_W_A(wr, "xmlns:wp", "http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing");
    W_W_A(wr, "xmlns:w10", "urn:schemas-microsoft-com:office:word");
    W_W_A(wr, "xmlns:w", "http://schemas.openxmlformats.org/wordprocessingml/2006/main");
    W_W_A(wr, "xmlns:wne", "http://schemas.microsoft.com/office/word/2006/wordml");
    W_S_E(wr, "w:body");


}
int document::finish()
{
    W_S_E(wr, "w:sectPr");
    ////
    W_S_E(wr, "w:pgSz");
    W_W_A(wr, "w:w", "11906");
    W_W_A(wr, "w:h", "16838");
    W_E_E(wr);
    ////
    W_S_E(wr, "w:pgMar");
    W_W_A(wr, "w:top", "720");
    W_W_A(wr, "w:right", "720");
    W_W_A(wr, "w:bottom", "720");
    W_W_A(wr, "w:left", "720");
    W_W_A(wr, "w:header", "708");
    W_W_A(wr, "w:footer", "708");
    W_W_A(wr, "w:gutter", "0");
    W_E_E(wr);
    //////
    W_SWE_EAE(wr, "w:cols", "w:space", "708");
    W_SWE_EAE(wr, "w:docGrid", "w:linePitch", "360");
    /////
    W_E_E(wr); // w:sectPr
    W_E_E(wr); //  w:body
    W_E_E(wr); //  w:document
    W_E_D(wr);
    CLEAN(wr);
    return 0;
}

int document::begin(const char *Months, const char *matrucule, const char *ExamCenter, const char *state, data_t *d)
{
    this->Nexam1 = 0;this->Nexam2 = 0;this->Nexam3 = 0;
    this->data(d);
    this->addpragraph();
    this->addpragraph("الـجـمـهـوريــة الـجـزائـريــة الـديـمـقـراطـيــة الـشـعـبـيــة",1,0,1,1);
    this->addpragraph();
    this->addpragraph(state, 1,1);
    this->addpragraph("مـديـريــة الـــنــقـــــــل", 1,1);
    this->addpragraph("رقم:............ / م ن 0/");
    this->addpragraph("مـركـز الامـتـحـــــان:", ExamCenter);
    this->addpragraph("مدرسة تعليم السياقـة : ", Months);
    this->addpragraph("إسم ولقب الممتحــــن: ...............................    ", "إمتحان يــوم", this->Data);
    this->addpragraph("رقـم تسجيل السيــارة:",matrucule);
    this->addpragraph();
    this->addpragraph("\" قــائمــة الــمترشحيـــن لرخصـة السياقــة\"",1,1,1,1);
    this->addpragraph();
    this->addtable();
    //
    return 0;
}

int document::data(data_t *d)
{
    char d_Months[45];
    switch(d->months)
    {
    case 1:
        sprintf(d_Months, "جــــــــانـــفــي");
        break;
    case 2:
        sprintf(d_Months, "فـــيــفـــــــري");
        break;
    case 3:
        sprintf(d_Months, "مــــــارس");
        break;
    case 4:
        sprintf(d_Months, "أفــــــــــريــــــل");
        break;
    case 5:
        sprintf(d_Months, "مــــــــــاي");
        break;
    case 6:
        sprintf(d_Months, "جـــــــوان");
        break;
    case 7:
        sprintf(d_Months, "جـــويـــلــيــة");
        break;
    case 8:
        sprintf(d_Months, "اوت");
        break;
    case 9:
        sprintf(d_Months, "ســـبـــتــمــبــر");
        break;
    case 10:
        sprintf(d_Months, "اكــــتـــوبـــر");
        break;
    case 11:
        sprintf(d_Months, "نــــوفــمــبــر");
        break;
    case 12:
        sprintf(d_Months, "ديـــســـمـــبــر");
        break;
    default:
        sprintf(d_Months, " ");
        break;
    }
   // d->Months = d_Months;
    if(d->day <10)
    {
        sprintf(this->Data, " 0%u %s %u", d->day, d_Months, d->year);
    }
    else
    {
        sprintf(this->Data, " %u %s %u", d->day, d_Months, d->year);
    }

    return 0;
}

int document::addpragraph(const char *text)
{
    pragraph_t pg;
    pg.b = 0;
    pg.con = 0;
    pg.single = 0;
    pg.rtl = 0;
    pg.table = 0;
    this->addpragraph(text,& pg);
    return 0;
}

int document::addpragraph(const char *text,bool b)
{
  pragraph_t pg;
    pg.b = b;
    pg.con = 0;
    pg.single = 0;
    pg.rtl = 0;
    pg.table = 0;
    this->addpragraph(text,& pg);
    return 0;
}

int document::addpragraph(const char* text,bool b,bool single)
{
    pragraph_t pg;
    pg.b = b;
    pg.con = 0;
    pg.single = single;
    pg.rtl = 0;
    pg.table = 0;
    this->addpragraph(text,& pg);
    return 0;
}

int document::addpragraph(const char *text,bool b,bool single,bool stl,bool con,bool table)
{
    pragraph_t pg;
    pg.b = b;
    pg.con = con;
    pg.single = single;
    pg.rtl = stl;
    pg.table = table;
    this->addpragraph(text,& pg);
    return 0;
}


int document::addpragraph(const char *text,bool b,bool single,bool stl, bool con)
{
    pragraph_t pg;
    pg.b = b;
    pg.con = con;
    pg.single = single;
    pg.rtl = stl;
    pg.table = 0;
    this->addpragraph(text,& pg);
    return 0;
}

int document::addpragraph(const char *text,pragraph_t *pg)
{
    W_S_E(this->writer, "w:p");
    W_S_E(wr, "w:pPr");
    if(pg->con==1){W_SWE_EAE(wr, "w:jc", "w:val", "center");}
    writerPr(this->writer,pg);
    W_E_E(wr); // w:pPr
    W_S_E(wr, "w:r");
    writerPr(this->writer,pg);
    W_W_E(wr, "w:t", text);
    W_E_E(wr); // w:r
    W_E_E(wr); // w:p
    return 0;
}

int document::addpragraph()
{
    pragraph_t pg;
    pg.b = 0;
    pg.con = 0;
    pg.rtl = 0;
    pg.single = 0;
    pg.table = 0;
    W_S_E(wr, "w:p");
    W_S_E(wr, "w:pPr");
    W_SWE_EAE(wr, "w:jc", "w:val", "center");
    writerPr(this->writer,&pg);
    W_E_E(wr); // w:pPr
    W_E_E(wr); // w:p
    return 0;
}

int document::addpragraph(const char *text1, const char *text2)
{
    pragraph_t pg;
    pg.b = 0;
    pg.con = 0;
    pg.rtl = 0;
    pg.single = 0;
    pg.table = 0;
    W_S_E(this->writer, "w:p");
    W_S_E(wr, "w:pPr");
    pg.b = 1;
    writerPr(this->writer,& pg);
    W_E_E(wr); // w:pPr
    // 1
    pg.b = 0;
    pg.rtl = 1;
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_W_E(wr, "w:t", text1);
    W_E_E(wr); // w:r
    // 2
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_S_E(wr, "w:t");
    W_W_A(wr, "xml:space", "preserve");
    W_W_R(wr, " ");
    W_E_E(wr);
    W_E_E(wr); // w:r
    // 3
    pg.b = 1;
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_W_E(wr, "w:t", text2);
    W_E_E(wr); // w:r
    W_E_E(wr); // w:p
    return 0;
}

int document::addpragraph(const char *text1,const char *text2,const char *text3)
{
    pragraph_t pg;
    pg.b = 0;
    pg.con = 0;
    pg.rtl = 0;
    pg.single = 0;
    pg.table = 0;
    W_S_E(this->writer, "w:p");
    W_S_E(wr, "w:pPr");
    pg.b = 1;
    writerPr(this->writer,& pg);
    W_E_E(wr); // w:pPr
    // 1
    pg.b = 0;
    pg.rtl = 1;
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_W_E(wr, "w:t", text1);
    W_E_E(wr); // w:r
    // 2
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_S_E(wr, "w:t");
    W_W_A(wr, "xml:space", "preserve");
    W_W_R(wr, "    ");
    W_E_E(wr);
    W_E_E(wr); // w:r
    // 3
    pg.b = 0;
    pg.single = 1;
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_W_E(wr, "w:t", text2);
    W_E_E(wr); // w:r
    // 4
    pg.single = 0;
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_S_E(wr, "w:t");
    W_W_A(wr, "xml:space", "preserve");
    W_W_R(wr, " :  ");
    W_E_E(wr);
    W_E_E(wr); // w:r
    // 5
    pg.single = 0;
    pg.b = 1;
    W_S_E(wr, "w:r");
    writerPr(this->writer,&pg);
    W_W_E(wr, "w:t", text3);
    W_E_E(wr); // w:r
    W_E_E(wr); // w:p
    return 0;
}

#define tblGrid(x) W_SWE_EAE(wr, "w:gridCol", "w:w",x)
int document::addtable()
{
    W_S_E(wr, "w:tbl");
    // w:tblPr
    W_S_E(wr, "w:tblPr");
    W_SWE_EAE(wr, "w:tblStyle", "w:val", "Grilledutableau");
    W_SE_E(wr, "w:bidiVisual");
    W_S_E(wr, "w:tblW");
    W_W_A(wr, "w:w", "0");
    W_W_A(wr, "w:type", "auto");
    W_E_E(wr); // w:tblW
    W_SWE_EAE(wr, "w:tblLayout", "w:type", "fixed");
    W_SWE_EAE(wr, "w:tblLook", "w:val", "04A0");
    W_E_E(wr); // w:tblPr
    W_S_E(wr, "w:tblGrid");
    tblGrid("832");
    tblGrid("3472");
    tblGrid("1760");
    tblGrid("1100");
    tblGrid("1980");
    tblGrid("1538");
    W_E_E(wr);// w:tblGrid
    W_S_E(wr, "w:tr");
    this->writertc("832", "الـرقـم",1,0);
    this->writertc("3472", "الــلــقــب و الأســـم",0,0);
    this->writertc("1760", "تاريخ الازدياد",1,0);
    this->writertc("1100", "الـصنـف",1,0);
    this->writertc("1980", "طبيعـة الامتحـان",1,0);
    this->writertc("1538", "الـنـتـيـجــة",0,0);
    W_E_E(wr); //w:tr

    return 0;
}

int document::end()
{
    W_E_E(wr);// w:tbl
    this->addpragraph();
    this->addtableN();
    this->finish();
    return 0;
}

int document::addtableN()
{
    char exam1[3];// = "";
    char exam2[3];// = "";
    char exam3[3]; //= "";
    char examsun[3];// = "";
    //// sun
    sprintf(exam1, "%u", this->Nexam1);
    sprintf(exam2, "%u", this->Nexam2);
    sprintf(exam3, "%u", this->Nexam3);
    sprintf(examsun, "%u", this->Nexam1 + this->Nexam2 + this->Nexam3);
    // start table
    W_S_E(wr, "w:tbl");
    // w:tblPr
    W_S_E(wr, "w:tblPr");
    W_SWE_EAE(wr, "w:tblStyle", "w:val", "Grilledutableau");
    W_SE_E(wr, "w:bidiVisual");
    W_S_E(wr, "w:tblW");
    W_W_A(wr, "w:w", "0");
    W_W_A(wr, "w:type", "auto");
    W_E_E(wr); // w:tblW
    W_SWE_EAE(wr, "w:jc", "w:val", "center");
    W_S_E(wr, "w:tblInd");
    W_W_A(wr, "w:w", "784");
    W_W_A(wr, "w:type", "dxa");
    W_E_E(wr); // w:tblInd
    W_SWE_EAE(wr, "w:tblLook", "w:val", "04A0");
    W_E_E(wr); // w:tblPr
    W_S_E(wr, "w:tblGrid");
    tblGrid("1760");
    tblGrid("1760");
    tblGrid("2200");
    tblGrid("2640");
    W_E_E(wr); // w:tblGrid
    // table row
    this->writertrN();
    this->writertrN("القانـــــون", exam1);
    this->writertrN("المناورات", exam2);
    this->writertrN("القيـــــــادة", exam3);
    this->writertrN("المجـــموع", examsun);
    // end of table
    W_E_E(wr);// w:tbl
    return 0;
}

#undef tblGrid

int document::addrow()
{
    W_S_E(wr, "w:tr");
    this->writertc("832", " ",1,0);
    this->writertc("3472", " ",0,0);
    this->writertc("1760", " ",1,0);
    this->writertc("1100", " ",1,0);
    this->writertc("1980", " ",1,0);
    this->writertc("1538", " ",0,0);
    W_E_E(wr); //w:tr
    return 0;
}

int document::addrow(unsigned int id, const char* fullname,const char* Hincreasing, const unsigned int Nexam)
{
    char exam[50] ;
    char idS[3];
    if (id>9) sprintf(idS, "%u",id);
    else sprintf(idS, "0%u",id);

    if(Nexam == 1)
    {
       this->Nexam1++;
        sprintf(exam, "القانون المرور");
    }else if(Nexam == 2)
    {
       this->Nexam2++;
        sprintf(exam, "الـــــمـنــاورات");
    }
    else if(Nexam == 3)
    {
        this->Nexam3++;
       sprintf(exam, "الــــــقـــــيـــادة");
    }

    W_S_E(wr, "w:tr");
    this->writertc("832", idS,1,1);
    this->writertc("3472", fullname,0,1);
    this->writertc("1760", Hincreasing,1,1);
    this->writertc("1100", "ب",1,1);
    this->writertc("1980", exam,1,1);
    this->writertc("1538", " ",0,1);
    W_E_E(wr); //w:tr
    return 0;
}

int document::writertc(const char* ww,const char *text,bool con,bool b)
{
    W_S_E(wr, "w:tc");
    W_S_E(wr, "w:tcPr");
    W_S_E(wr, "w:tcW");
    W_W_A(wr, "w:w", ww);
    W_W_A(wr, "w:type", "dxa");
    W_E_E(wr); // w:tcW
    W_E_E(wr); // w:tcPr
    this->addpragraph(text, b,0,1,con,1);

    W_E_E(wr); //w:tc
    return 0;
}

int document::writertrN(const char* text,const char* number)
{
    // start w:tr
    W_S_E(wr, "w:tr");
    W_S_E(wr, "w:trPr");
    W_SWE_EAE(wr, "w:jc", "w:val", "center");
    W_E_E(wr); // w:trPr
    this->writertcN("1760", text,0,1,0);
    this->writertcN("1760",number,1,0,0);
    this->writertcN("2200", "",1,0,0);
    this->writertcN("2640", "",1,0,0);

    W_E_E(wr); // w:tr

    return 0;
}

int document::writertrN()
{
    W_S_E(wr, "w:tr");
    W_S_E(wr, "w:trPr");
    W_SWE_EAE(wr, "w:jc", "w:val", "center");
    W_E_E(wr); // w:trPr
    this->writertcN("3520", "المترشحون المدعوون",1,1,1);
    this->writertcN("2200", "الغيابـــــات",1,1,0);
    this->writertcN("2640", "المترشحون الناجحون",1,1,0);
    W_E_E(wr); // w:tr

    return 0;
}

int document::writertcN(const char* ww,const char *text,bool b,bool single,bool two)
{
    W_S_E(wr, "w:tc");
    W_S_E(wr, "w:tcPr");
    W_S_E(wr, "w:tcW");
    W_W_A(wr, "w:w", ww);
    W_W_A(wr, "w:type", "dxa");
    W_E_E(wr); // w:tcW
    if(two==1){W_SWE_EAE(wr, "w:gridSpan", "w:val", "2");}
    W_E_E(wr); // w:tcPr
    //
    this->addpragraph(text,b,single,1,1);
    W_E_E(wr); // w:tc
    return 0;
}


























