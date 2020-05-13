#ifndef APPDB_H_INCLUDED
#define APPDB_H_INCLUDED
#include <string>
#include <vector>
struct listp
{
    int ID ;
	std::string firstname;
	std::string lastname;
	std::string sonof;
	std::string HINC;
	std::string PINC;
	std::string Address;
	int BT=0;
	std::string phone;
	std::string work;
	std::string nationlity;
	std::string HRF;
	int TE=1;
};

struct listpe
{
    int NB;
    std::string name;
    std::string HINC;
    int TE;
};

struct data_t
{
    unsigned int day;
    unsigned int months;
    unsigned int year;
};

class appdb
{

public:
    appdb(const char* c);
    int init(const char* file,const char* file1);
    int finsh();
    ~appdb();
    short open_list_file(const char* file);
    short open_backup_file(const char* file);
    /////////////////////   start for main.db    ////////////
    int add(listp& lp);
    int edit(int ID, listp& lp);
    void upgrad(int ID);
    void Delete(int ID);
    int getID_by_name(std::string name);
    int getID_by_name_data_son(std::string name,std::string data,std::string son );
    int getID_by_phone(std::string phone);
    listp get_lp(int ID);
    int len();
    void getIOS(std::string& name,std::string& NRC,std::string& Examcenter,std::string& state);
    void setIOS(std::string name,std::string NRC,std::string Examcenter,std::string state);
    std::vector<listp> get_lps();
    /////////////////////   end for main.db      ////////////

    /////////////////////   start for backup.db    ////////////
    void addtolist(listpe lp);
    int createtable(data_t data);
    int endtable(const char *dir,const char* filename);
    listpe get_lpe(int ID,int& _Nexam1,int& _Nexam2,int& _Nexam3);
    std::vector<listpe> getle_byname(std::string tname);
    std::vector<std::string> getmb();
    std::string getmbNRC(std::string name);
    std::string getmbdate(std::string name);

    /////////////////////   end for backup.db      ////////////
private:

    /////////////////////   start for main.db    ////////////
    void getIOS();
    std::string _IOS_name;
    std::string _IOS_NRC;
    std::string _Examcenter;
    std::string _state;
    /////////////////////   end for main.db      ////////////

    /////////////////////   start for backup.db    ////////////
    std::string _t_name;
    int Nexam1;
    int Nexam2;
    int Nexam3;
    data_t _data;
    /////////////////////   end for backup.db      ////////////


};

#endif // APPDB_H_INCLUDED
