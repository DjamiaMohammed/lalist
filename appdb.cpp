#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "sqlite_modern_cpp.h"
//#define APPDB_M_INCLUDED
#include "document.h"
#include "appdb.h"
//#include <wx/utils.h>
using namespace std;
using namespace sqlite;

database* dbm = 0;
database* dbb = 0;
data_t* dt;
int finished;
void messageserror(const char* error)
{
    cout<<error<<endl;
}

int findtable(sqlite3* apSQLite, const char* apTableName)
{
	sqlite3_stmt*   mpStmt;
	sqlite3_prepare_v2(apSQLite, "SELECT count(*) FROM sqlite_master WHERE type='table' AND name=?", 64, &mpStmt, NULL);
	sqlite3_column_count(mpStmt);
	sqlite3_bind_text(mpStmt, 1, apTableName, -1, SQLITE_TRANSIENT);
	sqlite3_step(mpStmt);
	int rc = (1 == sqlite3_column_int(mpStmt, 0));
	sqlite3_finalize(mpStmt);
	return rc;
}
//*
 appdb::appdb(const char* c)
 {
    init("main.db","backup.db");
 }
//*/
int appdb::finsh()
{

    dbm->close();
    dbb->close();
    delete dbb;
    delete dbm;
    return 0;
}

appdb::~appdb()
{
    this->Nexam1 = this->Nexam2= this->Nexam3=0;
    this->_data.day = this->_data.months = this->_data.year= 0;
    this->_IOS_name.clear();
    this->_IOS_NRC.clear();
    this->_Examcenter.clear();
    this->_state.clear();
    this->_t_name.clear();
}
int appdb::init(const char* file,const char* file1)
{
    open_list_file(file);
    open_backup_file(file1);
    return 0;
}

short appdb::open_list_file(const char* file)
{
    finished = 0;
    dbm = new database(file);
    if(!findtable(dbm->connection().get(),"IOS")){
        *dbm << "CREATE TABLE IOS (name	TEXT NOT NULL, "
            "NRC	TEXT NOT NULL, Examcenter	TEXT NOT NULL, state	TEXT NOT NULL, "
            "NLP	INTEGER, NE	  INTEGER, Ncode	  INTEGER, NP 	INTEGER, Ndrive	 INTEGER);";
            *dbm<<"insert into IOS ( name , NRC , Examcenter ,state )"
        "values (?, ?, ?, ?) ;"<<""<<""<<""<<"";
    }

    if(!findtable(dbm->connection().get(),"listp"))
        *dbm << "CREATE TABLE listp (ID	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
	"firstname	TEXT NOT NULL,lastname	TEXT NOT NULL,sonof	TEXT NOT NULL,HINC	TEXT NOT NULL,"
	"PINC	TEXT NOT NULL,Address	TEXT NOT NULL, BT	INTEGER NOT NULL DEFAULT 0, phone	TEXT NOT NULL,"
	 " work  	TEXT NOT NULL, nationlity	TEXT NOT NULL, HRF	 TEXT NOT NULL, TE	INTEGER NOT NULL DEFAULT 1);";

	 this->getIOS();
}
short appdb::open_backup_file(const char* file)
{
    finished = 0;
    dbb = new database(file);
    if(!findtable(dbb->connection().get(),"main"))
        *dbb << "CREATE TABLE main (ID	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
            "name	TEXT NOT NULL, NRC	 TEXT NOT NULL, data	 INTEGER NOT NULL,"
            "Ncode	TEXT, NP 	TEXT, Ndrive	 TEXT, sum	 TEXT);";
    this->getIOS();



}

    /////////////////////   start for main.db    ////////////
int appdb::add(listp& lp)
{
    int id;
    *dbm<<"insert into listp ( firstname, lastname, sonof, HINC, PINC, Address, BT, phone, work, nationlity, HRF, TE)"
        "values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);"
        <<lp.firstname<<lp.lastname<<lp.sonof<<lp.HINC<<lp.PINC<<lp.Address<<lp.BT<<lp.phone<<lp.work<<lp.nationlity<<lp.HRF<<lp.TE;
    *dbm<<"SELECT ID FROM listp WHERE firstname = ? AND lastname = ? AND sonof = ? AND HINC = ? AND PINC = ? AND Address = ? AND BT = ? "
    " AND phone = ? AND work = ? AND nationlity = ? AND HRF = ? AND TE = ?;"<<lp.firstname<<lp.lastname<<lp.sonof<<lp.HINC<<lp.PINC
    <<lp.Address<<lp.BT<<lp.phone<<lp.work<<lp.nationlity<<lp.HRF<<lp.TE>>[&](int ID){
       id = ID;
    };
    return id;
}
int appdb::edit(int ID, listp& lp)
{
    if(lp.BT > 7) {messageserror("BT ERROR");return 1;}
    if(lp.TE > 3) {messageserror("TE error");return 2;}
    *dbm<<"UPDATE listp set firstname = ? , lastname = ? , sonof = ? , HINC = ? , PINC = ? , Address = ? , BT = ? , "
    " phone = ? , work = ? , nationlity = ? , HRF = ? , TE = ? where ID  = ?;"
    <<lp.firstname<<lp.lastname<<lp.sonof<<lp.HINC<<lp.PINC<<lp.Address<<lp.BT<<lp.phone<<lp.work<<lp.nationlity<<lp.HRF<<lp.TE<<ID;
    return 0;
}

void appdb::upgrad(int ID)
{
    int TE = 0;
    *dbm<<"SELECT TE FROM listp WHERE ID = ? ;"<<ID>>[&](int TEL){ TE = TEL;};
    TE++;
    if (TE > 3) TE = 3;
    *dbm<<"UPDATE listp set TE = ? where ID = ? ;"<<TE<<ID;
}

void appdb::Delete(int ID)
{
    *dbm<<"DELETE from listp WHERE ID = ? ; "<<ID;
}

listp appdb::get_lp(int ID)
{
    listp s;
    *dbm<<"SELECT * from listp where ID = ?"<<ID>>[&](int ID,string firstname,string lastname,string sonof,string HINC,string PINC,
                                                      string Address,int BT,string phone,string work,string nationlity,string HRF,int TE){
    s.ID = ID;s.firstname = firstname;s.lastname = lastname;s.sonof = sonof;s.HINC = HINC;
    s.PINC = PINC;s.Address = Address;s.BT = BT;s.phone = phone;s.work = work;s.nationlity = nationlity;s.HRF = HRF; s.TE = TE;
    };
    return s;
}

int appdb::getID_by_name(std::string name)
{
    int id;
    *dbm<<"SELECT ID FROM listp WHERE firstname = ? OR lastname = ? ;"<<name<<name>>[&](int ID){
        id = ID;
    };
    return id;
}
int appdb::getID_by_name_data_son(std::string name,std::string data,std::string son)
{
    int id;
    *dbm<<"SELECT ID FROM listp WHERE firstname = ? OR lastname = ? OR sonof = ? OR HINC = ? OR PINC = ? ;"
    <<name<<name<<son<<data<<data>>[&](int ID){
        id = ID;
    };
    return id;
}
int appdb::getID_by_phone(std::string phone)
{
    int id;
    *dbm<<"SELECT ID FROM listp WHERE phone = ? ;"<<phone>>[&](int ID){
        id = ID;
    };
    return id;
}

void appdb::getIOS()
{
    *dbm<<"SELECT name, NRC , Examcenter ,state FROM IOS ;">>[&](string name1,string NRC1,string Examcenter1,string state1){
    this->_IOS_name = name1; this->_IOS_NRC = NRC1; this->_Examcenter = Examcenter1;this->_state = state1;
    };
}

void appdb::getIOS(std::string& name,std::string& NRC,std::string& Examcenter,std::string& state)
{
    *dbm<<"SELECT name, NRC , Examcenter ,state FROM IOS ;">>[&](string name1,string NRC1,string Examcenter1,string state1){
    name = name1; NRC = NRC1; Examcenter = Examcenter1;state = state1;
    };
    this->_IOS_name = name;
    this->_IOS_NRC = NRC;
    this->_Examcenter = Examcenter;
    this->_state = state;
}

void appdb::setIOS(std::string name,std::string NRC,std::string Examcenter,std::string state)
{
    *dbm<<"UPDATE IOS set name = ? , NRC = ? , Examcenter = ? ,state = ? "<<name<<NRC<<Examcenter<<state;
    this->_IOS_name = name;
    this->_IOS_NRC = NRC;
    this->_Examcenter = Examcenter;
    this->_state = state;
}

vector<listp> appdb::get_lps()
{
    vector<listp> vlistp;
    vlistp.clear();
    *dbm<<"SELECT * FROM listp">>[&](int ID,string firstname,string lastname,string sonof,string HINC,string PINC,
                                                      string Address,int BT,string phone,string work,string nationlity,string HRF,int TE)
                                {
                                listp s;
    s.ID = ID;s.firstname = firstname;s.lastname = lastname;s.sonof = sonof;s.HINC = HINC;
    s.PINC = PINC;s.Address = Address;s.BT = BT;s.phone = phone;s.work = work;s.nationlity = nationlity;s.HRF = HRF; s.TE = TE;
                                vlistp.push_back(s);
                                };
    return vlistp;

}

int appdb::len()
{
    string lt;
    *dbm<<"SELECT COUNT(*) FROM listp ;">>[&](string l){lt = l;};
    return atoi(lt.c_str());

}
    /////////////////////   end for main.db      ////////////

    /////////////////////   start for backup.db    ////////////
void appdb::addtolist(listpe lp)
{
    if(this->_t_name == "") return;
    string s = "insert into " ;
   // string name;
     int n = 0;
     s = s +this->_t_name+ " (NB , name, HINC, TE) values (?, ?, ?, ?);";
     //name = lp.firstname+"    "+lp.lastname;
     if (lp.TE == 1) {this->Nexam1++; n=this->Nexam1;}
     if (lp.TE == 2) {this->Nexam2++; n=this->Nexam2;}
     if (lp.TE == 3) {this->Nexam3++; n=this->Nexam3;}
     *dbb<<s<<to_string(n)<<lp.name<<lp.HINC<<lp.TE;
    s.clear();
}

listpe appdb::get_lpe(int ID,int& _Nexam1,int& _Nexam2,int& _Nexam3)
{

    listpe s;
    *dbm<<"SELECT firstname,lastname,HINC,TE from listp where ID = ?"<<ID>>[&](string firstname,string lastname,string HINC,int TE){
    s.name = firstname+"    "+lastname;
    s.HINC = HINC; s.TE = TE;
    };
    if (s.TE == 1) {_Nexam1++; s.NB=_Nexam1;}
    if (s.TE == 2) {_Nexam2++; s.NB=_Nexam2;}
    if (s.TE == 3) {_Nexam3++; s.NB=_Nexam3;}

    return s;
}

int appdb::createtable(data_t data)
{
    string s ;//= "CREATE TABLE ";
    string s1 = "list_";
    string Data = to_string(data.year)+"-";
    if (data.months > 12) data.months = 12;
    else if (data.months<1) data.months = 1;
    else if (data.months<9) Data = Data+"0";
    Data= Data+to_string(data.months)+"-"+to_string(data.day);
    this->_data = data;
    int id;
    *dbb<<"insert into main (name, NRC, data) values (?, ?, ?);"<<"list_"+Data<<this->_IOS_NRC<<Data;
    *dbb<<"select ID from main where name = ? AND NRC = ? AND data = ? ;"<<"list_"+Data<<this->_IOS_NRC<<Data>>[&](int ID){
       id =ID;
    };
    s1 = s1 + to_string(id);
    s = "CREATE TABLE " +s1+ " (NB  	INTEGER NOT NULL, name	TEXT NOT NULL, HINC	    TEXT NOT NULL, TE	INTEGER NOT NULL);";
    if(!findtable(dbb->connection().get(),s1.c_str())) *dbb<<s;
    this->_t_name = s1;
    this->Nexam1 = this->Nexam2 = this->Nexam3 = 0;
    s.clear();

    return 0;
}
int appdb::endtable(const char *dir,const char* filename)
{
    int i;
    string s = "SELECT * FROM "+this->_t_name+" WHERE TE = ?;";
   *dbb<<"UPDATE main SET Ncode = ? , NP = ? , Ndrive	= ?, sum = ? , name = ? WHERE ID = ? ;"<<this->Nexam1<<to_string(this->Nexam2)
        <<to_string(this->Nexam3)<<to_string(this->Nexam1+this->Nexam2+this->Nexam3)
        <<this->_t_name<<this->_t_name.substr(this->_t_name.find_last_of("list_")+1);

        document sd(dir,this->_IOS_name.c_str());
        sd.begin(this->_IOS_name.c_str(),this->_IOS_NRC.c_str(),this->_Examcenter.c_str(),this->_state.c_str(),&this->_data);

        for(i = 1; i<=3 ;i++) {
            *dbb<<s<<i>>[&](int NB ,string name,string HINC,int TE){
                sd.addrow(NB,name.c_str(),HINC.c_str(),TE);
            };
            sd.addrow();
        }

        sd.end();
        sd.makedocx(filename);
        s.clear();
        return 0;
}

vector<listpe> appdb::getle_byname(string tname)
{
    string s = "SELECT * FROM "+tname+" ;";
    vector<listpe> c ;
    c.clear();
    *dbb<<s>>[&](int NB,string name,string HINC,int TE){
      //  wxSleep(0.02);
        listpe l;
        l.name = name;
        l.HINC = HINC;
        l.NB = NB;
        l.TE = TE;
        c.push_back(l);
    };
    //wxSleep(0.02);
    return c;
}
vector<string> appdb::getmb()
{
    vector<string> s;
    s.clear();
    *dbb<<"SELECT name FROM main;">>[&](string name){
        s.push_back(name);
    };
    return s;
}

string appdb::getmbNRC(std::string name)
{
    string s;
    *dbb<<"SELECT NRC FROM main where name = ?;"<<name>>[&](string NRC)
    {
      s = NRC;
    };
    return s;
}

string appdb::getmbdate(std::string name)
{
    string s;
    *dbb<<"SELECT data FROM main where name = ?;"<<name>>[&](string data)
    {
      s = data;
    };
    return s;
}

    /////////////////////   end for backup.db      ////////////




















