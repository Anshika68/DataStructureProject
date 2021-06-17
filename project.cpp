#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<unordered_map>
#include<string>
#include<vector>
    //#include"result.h";
    using namespace std;
    class Student
    {
     public:
    char name[40];
    int enrollment_no;
    float cgpa;
    int semester;
    //string branch;
    char branch[15];
    long phone_number;
    char email_id[50];
     
     public:
      void getData();
      void showData();
      int getenrollment_no()
      {return enrollment_no;}
     char*  getbranch(){
      return branch;
      }
     
    }s;

 void mainmenu();
void stud_login();
int adminlogin();

   
   
    void Student::getData()
    {
      cout<<"<---Enter the students details-->"<<endl;
    cout<<"Enter enrollment nummber of student--->"<<endl;
    cin>>enrollment_no;


    cout<<"Enter the name of student---->"<<endl;
    cin.ignore();cin.getline(name,40);

    cout<<"Enter current semester------>"<<endl;
    cin>>semester;

    cout<<"Enter branch of student------->"<<endl;
    cin.ignore();
    cin>>branch;

    cout<<"Enter phone number of student------->"<<endl;
    cin>>phone_number;

    cout<<"Enter email id of student------->"<<endl;
    cin.ignore(); cin.getline(email_id,50);

   

    }
    void addData()
    {
    ofstream fout;
     fout.open("Studen.dat",ios::binary|ios::out|ios::app);
     s.getData();
     fout.write((char*)&s,sizeof(s));
     fout.close();
     cout<<"\n\nData Successfully Saved to File....\n";
    }

    void Student::showData()
    {
     cout<<"\n\n.......Student Details......\n";
     cout<<"Enrollment No.     : "<<enrollment_no<<endl;
     cout<<"Name         : "<<name<<endl;
     cout<<"Semester         : "<<semester<<endl;
     cout<<"Branch         : "<<branch<<endl;
     cout<<"Phone Number         : "<<phone_number<<endl;
     cout<<"Email         : "<<email_id<<endl;
     
     cout<<endl;
    }
    void displayData()
    {
     ifstream fin;
     fin.open("Studen.dat",ios::in|ios::binary);
     while(fin.read((char*)&s,sizeof(s)))
     {
      s.showData();
     }
     fin.close();
     cout<<"\n\nData Reading from File Successfully Done....\n";
    }
       
    void searchData()
    {
     int n, flag=0;
     ifstream fin;
     fin.open("Studen.dat",ios::in|ios::binary);
     cout<<"Enter Admission Number you want to search : ";
     cin>>n;
     
     while(fin.read((char*)&s,sizeof(s)))
     {
      if(n==s.getenrollment_no())
      {
       cout<<"The Details of Admission No. "<<n<<" shown herewith:\n";
       s.showData();
       flag++;
      }
     }
     fin.close();
     if(flag==0)
      cout<<"The Admission No. "<<n<<" not found....\n\n";
     cout<<"\n\nData Reading from File Successfully Done....\n";
    }

    void deleteData()
    {
     int n, flag=0;
     ifstream fin;
     ofstream fout,tout;

     fin.open("Studen.dat",ios::in|ios::binary);
     fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
     tout.open("TrashStud.dat",ios::out|ios::app|ios::binary);

     cout<<"Enter Admission Number you want to move to Trash : ";
     cin>>n;
     
     while(fin.read((char*)&s,sizeof(s)))
     {
      if(n==s.getenrollment_no())
      {
       cout<<"The Following Admission No. "<<n<<" has been moved to Trash:\n";
       s.showData();
       tout.write((char*)&s,sizeof(s));
       flag++;
      }
      else
      {
       fout.write((char*)&s,sizeof(s));
      }
     }
     fout.close();
     tout.close();
     fin.close();
     if(flag==0)
      cout<<"The Admission No. "<<n<<" not found....\n\n";
     remove("Studen.dat");
     rename("tempStud.dat","Studen.dat");
    }
   
    void getTrash()
    {
     ifstream fin;
     fin.open("TrashStud.dat",ios::in|ios::binary);
     while(fin.read((char*)&s,sizeof(s)))
     {
      s.showData();
     }
     fin.close();
     cout<<"\n\nData Reading from Trash File Successfully Done....\n"<<endl;
    }

    void modifyData()
    {
     int n, flag=0, pos;
     fstream fio;

     fio.open("Studen.dat",ios::in|ios::out|ios::binary);
     
     cout<<"Enter enrollment Number you want to Modify : ";
     cin>>n;
     
     while(fio.read((char*)&s,sizeof(s)))
     {
      pos=fio.tellg();
      if(n==s.enrollment_no)
      {
       cout<<"The Following enrollment No. "<<n<<" will be modified with new data:\n"<<endl;
       s.showData();
       cout<<"Now Enter the New Details...."<<endl;
       s.getData();
       fio.seekg(pos-sizeof(s));
       fio.write((char*)&s,sizeof(s));
       flag++;
      }
     }
     fio.close();
     
     if(flag==0)
      cout<<"The enrollment No. "<<n<<" not found...."<<endl;
    }

   
   int credit(string s){
unordered_map<string,int> credit;
       //1st year                 //2nd year
      credit["BAS-103"]=4; credit["BCS-201"]=4;
      credit["BAS-105"]=4; credit["BCS-203"]=4;
      credit["BAS-101"]=4; credit["BIT-201"]=4;
      credit["BMA-110"]=4; credit["BIT-203"]=4;
      credit["BEC-110"]=4; credit["GEC-201"]=4;
      credit["BMA-120"]=2; credit["BCS-253 "]=4;
      credit["BMA-130"]=2; credit["BAS-201"]=4;
      credit["BAS-102 "]=4; credit["BAS-203"]=4;
      credit["BAS-104"]=4; credit["BEC-209"]=4;
      credit["BAS-106"]=4; credit["BMA-211"]=4;
      credit["BCS-110"]=4;     credit["HMC-110"]=4;
    unordered_map<string,int>::iterator c;
for(c=credit.begin();c!=credit.end();c++){
if(c->first==s){
return c->second;
}
}

     
}
int getgrades(string s){
unordered_map<string,int> grades;
grades["A+"]=10;
grades["A"]=9;
grades["B+"]=8;
grades["B"]=7;
grades["C+"]=6;
grades["C"]=5;
grades["D"]=4;
unordered_map<string,int>::iterator g;
for(g=grades.begin();g!=grades.end();g++){
if(g->first==s){
return g->second;
}
}

}
void displaycoursesbysem(){
int n;
cout<<"Enter semester no : ";
cin>>n;
if(n==1){
cout<<"1. BAS-101  Applied Mathematics-I             3-1-0 4 BAS"<<endl;
cout<<"2. BAS-103  Applied Physics-I                 2-1-2 4 BAS"<<endl;
cout<<"3. BAS-105  Applied Chemistry                 2-1-2 4 BAS"<<endl;
cout<<"4. BMA-110/  Engineering Mechanics/            3-0-2 4 OEC"<<endl;
   cout<<"   BEC-110   Basic Electrical Engineering"<<endl;
     cout<<"5. BMA-120/  WorkshopPractice                  0-1-2 2 OEC"<<endl;
        cout<<"   BMA-130   /Engineering Graphics"<<endl;
        cout<<"6. HMC-110/  Humanities and Social Science/   3-1-0/ 4 HMC/ "<<endl;
        cout<<"   BCS-110   Programming in C Language        3-0-2   OEC   "<<endl;}
   
    else if(n==2){
    cout<<"1. BAS- 102  Applied Mathematics-II 3-1-0 4 BAS"<<endl;
    cout<<"2. BAS- 104  Applied Physics-II 2-1-2 4 BAS"<<endl;
    cout<<"3. BAS- 106  Environmental Science 2-1-2 4 BAS"<<endl;
    cout<<"4. BEC- 110/ Basic Electrical Engineering/ 3-0-2 4 OEC"<<endl;
    cout<<"             BMA-110 Engineering Mechanics"<<endl;
    cout<<"6. HMC- 110/  Humanities and Social Science/   3-1-0/ 4 HMC/ "<<endl;
        cout<<"   BCS- 110   Programming in C Language        3-0-2   OEC   "<<endl;
   
}
}
void result(){



vector<string> sub;
vector<string>grades;
cout<<"enter no of sub: ";
int n;
cin>>n;
for(int i=0;i<n;i++){
cout<<"enter the paper code and grades of"<<i<<"subject"<<endl;
cout<<"paper code: ";
string s;
cin>>s;
sub.push_back(s);
   cout<<"grades: ";
       string k;
       cin>>k;
   grades.push_back(k) ;
}
int total_marks=0;
int total_credit;
float cgpa;
for(int i=0;i<n;i++){

total_marks=credit(sub[i])*getgrades(grades[i])+total_marks;
total_credit=total_credit+credit(sub[i]);
}
cgpa=total_marks/total_credit;
cout<<"cgpa - "<<cgpa<<endl;


}

   
void stud_view()
{
        system("cls");
        char var;
        do {
        cout<<"Indira Gandhi Delhi Technical University for Women \n "<<endl;
        cout<<"Student View Page \n "<<endl;
        cout<<"Enter 1 to display your profile info \n "<<endl;
        cout<<"Enter 2 Student courses \n "<<endl;
        cout<<"Press 0 to sign out \n"<<endl;
        int ch;
        x:
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1: searchData();  break;
        case 2: displaycoursesbysem();  break;
        case 0: mainmenu(); break;
        default: cout<<"Invalid choice Try again \n ";
        goto x;
        }
        cout<<"Enter y to continue or n for not -  ";
        cin>>var;
        }while(var=='y');
}

int adminView()
{
    char var;
    int ch;
do {
system("cls");
x:
  cout<<"...............STUDENT MANAGEMENT SYSTEM..............\n";
  cout<<"======================================================\n";
  cout<<"0. Exit and go to main page\n";
  cout<<"1. Write Data to File\n";
  cout<<"2. Read Data From File\n";
  cout<<"3. Search Data From File\n";
  cout<<"4. Delete Data From File\n";
  cout<<"5. Get Deleted Records from Trash file\n";
  cout<<"6. Modify Data in File\n";
  cout<<"7. Courses"<<endl;
  cout<<"8. Result"<<endl;
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls");

  switch(ch)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
   case 4: deleteData(); break;
   case 5: getTrash(); break;
   case 6: modifyData(); break;
   case 7: displaycoursesbysem(); break;
   case 8: result(); break;
   case 0: mainmenu();  break;
   default: cout<<"\n Invalid choice. Enter again ";
   goto x;
   
}
cout<<"Enter y to continue or n for not: ";
cin>>var;
}while(var=='y');

}


//login student
   string stud_password="password";
void stud_login()
    {
        system("cls");
        string password;
        int rollno;
        cout<<"Enter enrollment no.: ";
        cin>>rollno;
        cout<<"Enter Password: ";
        cin>>password;
        if(stud_password == password&&rollno>0 )
        {
            stud_view();
        }
        else
        {
            cout<<"Invalid password \n ";
            cout<<"Enter 1 to try log in again \n";
            cout<<"Enter 2 to return to previous page to select different login option \n ";
            int ch;
            x:
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch)
                {
                    case 1: stud_login();  break;
                    case 2: mainmenu();  break;
                    default: cout<<"Invalid Choice Try again \n ";
                    goto x;
                }
        }
    }

string admin_pass ="admin";
int adminlogin()
{
    system("cls");
    string pass;
    cout<<"Admin Login Page \n ";
    cout<<"Enter admin password: ";
    cin>>pass;
    if(pass=="admin")
    {
        adminView();
    }
    else
    {
        int ch;
        cout<<"Invalid Password Entry Blocked \n";
        cout<<"Enter 1 to retry admin login \n";
        cout<<"Enter 2 to return to previous page to select different login option \n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: adminlogin();  break;
            case 2: mainmenu(); break;
        }
    }
    return 0;
}

 void mainmenu()
 {
    system("cls");
    int ch;
    cout<<"INDIRA GANDHI DELHI TECHNICAL UNIVERSITY FOR WOMEN \n";
    cout<<"Main Menu \n";
    cout<<"Enter 1 to login as admin \n";
    cout<<"Enter 2 to login as student \n";
    cout<<"Enter 0 to exit from this page \n";
    x:
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1: adminlogin();  break;
        case 2: stud_login();  break;
        case 0: exit(0);
        default: cout<<"Invalid Choice . Try again \n";
        goto x;
    }
}

int main()
{
    system("cls");
    cout<<"...............STUDENT MANAGEMENT SYSTEM..............\n";
    cout<<"======================================================\n";
    mainmenu();
}