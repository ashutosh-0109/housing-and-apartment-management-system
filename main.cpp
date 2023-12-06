#include <iostream>
#include <windows.h>
#include <mysql.h>
#include<sstream>

using namespace std;
MYSQL *conn;
int qstate;
  MYSQL_ROW row;
  int main();
  MYSQL_RES* res;


void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
class room
{
    string pass;
    string f_n,m_n,l_n,mail,contect,aadhar,id_no,per_add;
    public:
            void display();
         //   void update_list();
            void login();
            void tenant_login();
};
void room::display()
{
  MYSQL* conn;

  int qstate=0;
  int i=15;
    conn= mysql_init(0);
        conn = mysql_real_connect(conn,"192.168.43.193","admin","admin","housing_management",0,NULL,0);
        string fid,tof,sts;
        float rnt;
    cout<<"                         ROOM AND THEIR DETAILS"<<endl;
    cout<<"                     ------------------------------"<<endl;

    gotoxy(3,10);cout<<"# detail of room and their available status :";
    gotoxy(5,13);cout<<"| flat_id"<<endl;
    gotoxy(15,13);cout<<"| type of flat"<<endl;
    gotoxy(28,13);cout<<"| rent"<<endl;
    gotoxy(35,13);cout<<"| status  |"<<endl;
    qstate=mysql_query(conn,"select * from room_detail");
    if(!qstate)
    {
        res = mysql_store_result(conn);
        while(row = mysql_fetch_row(res))
        {
            gotoxy(5,i);cout<<row[0];gotoxy(15,i);cout<<row[1];gotoxy(28,i);cout<<row[2];gotoxy(35,i);cout<<row[3];
            i=i+2;
        }
        i=i+1;gotoxy(5,i);
        cout<<"please press 0)";
        i=i+1;gotoxy(5,i);
        cout<<"Enter choice :";
        gotoxy(20,i);
        int j;
        cin>>j;
        if(j==0)
            return;
            else
            {

            }
    }




};
void room::tenant_login()
{
    int flag;
    MYSQL* conn;
    conn= mysql_init(0);
    int qstate;
        conn = mysql_real_connect(conn,"192.168.43.193","admin","admin","housing_management",0,NULL,0);
        if(conn)
        {
            cout<<"database connected"<<endl;

        }
        else
        {
            cout<<"not connected"<<endl;
        }


    int n;


    loop:
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                             TENANT PAGE"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    gotoxy(5,6);cout<<"select any one option"<<endl;
    gotoxy(5,7);cout<<"1. already have an account"<<endl;
    gotoxy(5,8);cout<<"2. new user"<<endl;
    gotoxy(5,9);cout<<"-----"<<endl;
    gotoxy(5,11);cout<<"-----"<<endl;
    gotoxy(5,10);cin>>n;

    system("cls");
        switch(n)
            {
                case 1:
                     {   login:
                        system("cls");

                        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"                                 TENANT PAGE"<<endl;
                        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

                        gotoxy(5,6);cout<<"enter your login id (contact number) :"<<endl;
                        gotoxy(45,6);cin>>contect;
int x;
                        gotoxy(5,8);cout<<"please enter your password"<<endl;
                        gotoxy(45,8);cin>>pass;
                        stringstream ss1;
                        ss1<<"select password from tenant_details where contact_number = '"<<contect<<"'";
                         string query=ss1.str();
                        const char * q=query.c_str();
                        qstate=mysql_query(conn,q);

                         if(!qstate)
                            {
                                    res = mysql_store_result(conn);
                                    while(row = mysql_fetch_row(res))
                                    {
                                        if(pass==row[0])
                                        {
                                            cout<<"Access granted"<<endl;
                                            flag=1;
                                            system("cls");




                                        }
                                        else
                                        {
                                            cout<<"Wrong Password"<<endl;
                                            system("pause");
                                            system("cls");
                                            main();

                                        }
                                    }
                                }
                                if(flag==1)
                                {               xyz:
                                    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                    cout<<"                                                        TENANT PAGE"<<endl;
                                    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                                stringstream ss2;
                                                ss2<<"select first_name,flat_no,flat_type from tenant_details where contact_number='"<<contect<<"'";
                                                string query=ss2.str();
                                                const char * q=query.c_str();
                                                qstate=mysql_query(conn,q);

                                                 if(!qstate)
                                                    {
                                                            res = mysql_store_result(conn);
                                                            while(row = mysql_fetch_row(res))
                                                            {
                                                                cout<<"                                      WELCOME"<<endl;
                                                                cout<<"                                --------------------"<<endl<<endl<<endl<<endl;
                                                                gotoxy(5,10);cout<<"NAME                 :- "<<row[0]<<endl;
                                                                gotoxy(5,11);cout<<"flat_no              :- "<<row[1]<<endl;
                                                                gotoxy(5,12);cout<<"flat type            :- "<<row[2]<<endl;

                                                                gotoxy(2,16);cout<<"select any one option.....";
                                                                gotoxy(5,17);cout<<"1. view your payment status...."<<endl;
                                                                gotoxy(5,18);cout<<"2. return...."<<endl;
                                                                cin>>x;
                                                            }

                                                    }
                                                    stringstream ss3;
                                                    if(x==1)
                                                    {
                        gotoxy(1,20);cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------";
                                                        gotoxy(5,22);cout<<"your payment status is :- "<<endl;
                                                         ss3<<"select * from rent_fair where flat_type=(select flat_type from tenant_details where contact_number ='"<<contect<<"')";
                                                string query=ss3.str();
                                                const char * q=query.c_str();
                                                qstate=mysql_query(conn,q);
                                    string ec,wb,sp,mp,rent;
                                    float  ec1,wb1,sp1,mp1,rent1,total;
                                    stringstream s,s1,s2,s3,s4;
                                                 if(!qstate)
                                                    {
                                                            res = mysql_store_result(conn);
                                                            while(row = mysql_fetch_row(res))
                                                            {
                                                                gotoxy(10,24);cout<<"you have         :-"<<row[0]<<endl;
                                                                gotoxy(10,25);cout<<"_____________________________";
                                                                gotoxy(10,26);cout<<"|   electricity bill  |  "<<row[1]<<" |";ec=row[1];
                                                                gotoxy(10,27);cout<<"|   water bill        |  "<<row[2]<<" |";wb=row[2];
                                                                gotoxy(10,28);cout<<"|   security pay      |  "<<row[3]<<" |";sp=row[3];
                                                                gotoxy(10,29);cout<<"|   maintenance pay   |  "<<row[4]<<" |";mp=row[4];
                                                                gotoxy(10,30);cout<<"|   rent              |  "<<row[5]<<"|";rent=row[5];
                                                                gotoxy(10,31);cout<<"|---------------------|------|";
                                                                s<<ec;
                                                                s>>ec1;
                                                                s1<<wb;
                                                                s1>>wb1;
                                                                s2<<sp;
                                                                s2>>sp1;
                                                                s3<<mp;
                                                                s3>>mp1;
                                                                s4<<rent;
                                                                s4>>rent1;

                                                                total=ec1+wb1+sp1+mp1+rent1;
                                                                gotoxy(10,32);cout<<"|        Total        |  "<<total<<"|";
                                                                gotoxy(10,33);cout<<"|_____________________|______|";
                                                                cout<<endl<<"press any key to go back....";
                                                                int key;
                                                                cin>>key;
                                                                system("cls");
                                                                goto xyz;

                                                            }


                                                    }
                                                }
                                                else
                                                    {
                                                        system("cls");
                                                        main();
                                                    }



               break;
                     }}
                case 2:
                    {

                        cout<<"----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"                                                new user/registration "<<endl;
                        cout<<"----------------------------------------------------------------------------------------------------------------------------------------"<<endl;

                        gotoxy(5,5);cout<<"please enter the following details :"<<endl;
                        gotoxy(5,7);cout<<"first_name        : "<<endl;
                        gotoxy(5,8);cout<<"last_name         : "<<endl;
                        gotoxy(5,9);cout<<"contact_number    : "<<endl;
                        gotoxy(5,10);cout<<"email_id          : "<<endl;
                        gotoxy(5,11);cout<<"document verification type (aadhar/PAN card only) : "<<endl;
                        gotoxy(5,12);cout<<"ID number         : "<<endl;
                        gotoxy(5,13);cout<<"permanent address : ";
                        gotoxy(25,7);cin>>f_n;
                        gotoxy(25,8);cin>>l_n;
                        gotoxy(25,9);cin>>contect;
                        gotoxy(25,10);cin>>mail;
                        gotoxy(57,11);cin>>aadhar;
                        gotoxy(25,12);cin>>id_no;
                        gotoxy(25,13);cin>>per_add;
                        gotoxy(5,16);cout<<"your contact number is your login id :-   "<<contect<<endl;
                        gotoxy(5,17);cout<<"set password :- ";
                        gotoxy(25,17);cin>>pass;

                        stringstream ss;
                        ss<< "INSERT INTO tenant_details(first_name,last_name,contact_number,e_mail_id,document_type,id_number,address,password) VALUES('"<<f_n<<"','"<<l_n<<"','"<<contect<<"','"<<mail<<"','"<<aadhar<<"','"<<id_no<<"','"<<per_add<<"','"<<pass<<"')";
                        string query=ss.str();
                        const char * q=query.c_str();
                        qstate=mysql_query(conn,q);
                        if(qstate==0)
                            cout<<endl<<"Data inserted";
                        else
                            cout<<endl<<"Data not inserted";



                        cout<<endl<<endl<<"now you can login";

                        goto login;


                    }
                        break;

                default :
                    system ("cls");
                    cout<<"invalid input"<<endl;
                    goto loop;
            }
}


void room::login()
{
  cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                                         OWNER'S PAGE"<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    gotoxy(10,6);cout<<"welcome.... MR. ASHUTOSH SONI";


MYSQL* conn;

  int qstate=0;
  int i=15;
    conn= mysql_init(0);
        conn = mysql_real_connect(conn,"192.168.43.193","admin","admin","housing_management",0,NULL,0);
        string fid,tof,sts;


    int pstate=0;

    gotoxy(1,10);cout<<"              YOUR TENANT DETAILS ARE :-";
    gotoxy(5,12);cout<<"|----------------|---------------|------------------|----------------------------|----------|-------------|----------|-----------|";
    gotoxy(5,13);cout<<"|   FIRST NAME   |   LAST NAME   |  CONTACT NUMBER  |      E-MAIL                | DOCUMENT | DOCUMENT ID | FLAT NO. | FLAT TYPE |";
    gotoxy(5,14);cout<<"|----------------|---------------|------------------|----------------------------|----------|-------------|----------|-----------|";
    pstate=mysql_query(conn,"select first_name,last_name,contact_number,e_mail_id,document_type,id_number,flat_no,flat_type from tenant_details");
    if(!pstate)
    {
        res = mysql_store_result(conn);
        while(row = mysql_fetch_row(res))
        {
            gotoxy(5,i);cout<<"|"<<row[0];gotoxy(22,i);cout<<"|"<<row[1];gotoxy(38,i);cout<<"|"<<row[2];gotoxy(57,i);cout<<"|"<<row[3];gotoxy(86,i);cout<<"|"<<row[4];gotoxy(97,i);cout<<"|"<<row[5];gotoxy(111,i);cout<<"|"<<row[6];gotoxy(122,i);cout<<"|"<<row[7];gotoxy(134,i);cout<<"|";
            i=i+2;
            gotoxy(5,i-1);cout<<"|";gotoxy(22,i-1);cout<<"|";gotoxy(38,i-1);cout<<"|";gotoxy(57,i-1);cout<<"|";gotoxy(86,i-1);cout<<"|";gotoxy(97,i-1);cout<<"|";gotoxy(111,i-1);cout<<"|";gotoxy(122,i-1);cout<<"|";gotoxy(134,i-1);cout<<"|";
        }
     cout<<endl<<"     |--------------------------------------------------------------------------------------------------------------------------------|";
    }
    cout<<" break";
    int j=33;

    gotoxy(1,27);cout<<"              YOUR ROOM AND THEIR DETAILS"<<endl;
    gotoxy(1,28);cout<<"           ---------------------------------"<<endl;
    gotoxy(5,30);cout<<"|---------|-------------|------|----------------|";
    gotoxy(5,31);cout<<"| flat_id | type of flat| rent | status         |";
    gotoxy(5,32);cout<<"|---------|-------------|------|----------------|";
    qstate=mysql_query(conn,"select * from room_detail");
    if(!qstate)
    {
        res = mysql_store_result(conn);
        while(row = mysql_fetch_row(res))
        {
            gotoxy(5,j);cout<<"|"<<row[0];gotoxy(15,j);cout<<"|"<<row[1];gotoxy(29,j);cout<<"|"<<row[2];gotoxy(36,j);cout<<"|"<<row[3]<<"       |";
            j=j+2;
            gotoxy(5,j-1);cout<<"|";gotoxy(15,j-1);cout<<"|";gotoxy(29,j-1);cout<<"|";gotoxy(36,j-1);cout<<"|                |";
        }

        cout<<endl<<"     |----------------------------------------------|";
    }
    int z=35;
    int zstate=0;
    zstate=mysql_query(conn,"select * from rent_fair");
    gotoxy(55,27);cout<<"          RENT FAIR/DECLARATION";
    gotoxy(55,28);cout<<"     -------------------------------";
    gotoxy(55,30);cout<<"|-------------|---------------------|------------------------|----|";
    gotoxy(55,31);cout<<"|  FLAT TYPE  |        BILLS        |         CHARGES        |RENT|";
    gotoxy(55,32);cout<<"|             | ELECTRICITY | WATER | MAINTANANCE | SECURITY |    |";
    gotoxy(55,33);cout<<"|-------------|-------------|-------|-------------|----------|----|";
    if (!zstate)
    {
        res =mysql_store_result(conn);
        while(row =mysql_fetch_row(res))
        {
            gotoxy(55,z);cout<<"|"<<row[0];gotoxy(69,z);cout<<"|"<<row[1];gotoxy(83,z);cout<<"|"<<row[2];gotoxy(91,z);cout<<"|"<<row[3];gotoxy(105,z);cout<<"|"<<row[4];gotoxy(116,z);cout<<"|"<<row[5]<<"|";
            z=z+2;
            gotoxy(55,z-1);cout<<"|";gotoxy(69,z-1);cout<<"|";gotoxy(83,z-1);cout<<"|";gotoxy(91,z-1);cout<<"|";gotoxy(105,z-1);cout<<"|";gotoxy(116,z-1);cout<<"|";
        }
    gotoxy(55,z);cout<<"|-------------|-------------|-------|-------------|----------|----|";
    gotoxy(55,34);cout<<"|-------------|-------------|-------|-------------|----------|----|";
    }

system("pause");



}

int main()
{
    int n;
    room r;


        loop1:
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                       HOUSING AND APARTMENT MANAGEMENT SYSTEM                               "<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
    loop:
    gotoxy(5,6);cout<<"1. for owner's work"<<endl;
    gotoxy(5,7);cout<<"2. view room's availability and status"<<endl;
    gotoxy(5,8);cout<<"3. for tenant login"<<endl;
    gotoxy(5,9);cout<<"please enter any one option"<<endl;
    gotoxy(5,10);cin>>n;
    system ("cls");

    switch(n)
        {
            case 2:
                        r.display();
                        system("cls");
                        goto loop1;
                        break;

            case 3:
                        r.tenant_login();
                        goto loop1;
                        break;

            case 1:
                       r.login();
                       system("cls");
                       goto loop1;
                        break;
            default:
                cout<<"invalid input....again select another option";
                goto loop;


        }

}
