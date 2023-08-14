#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<ctime>
#include<string>
using namespace std;
class person{
	
	string pass="";
	char ch;
	public:
	void show(){
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tSCHOOL BILLING SYSTEM \n\n";
    cout<<"\t\t\t\t\t------------------------------";
    cout<<"\n\t\t\t\t\t\t     LOGIN \n";	
    cout<<"\t\t\t\t\t------------------------------\n\n";	
	   // current date/time based on current system
	   time_t  now= time(0);
	   
	   // convert now to string form
	   string dt = ctime(&now);
	
	cout << "\t\t\t\tTHE LOGIN DATE & TIME IS :" << dt << endl;
    cout << "\t\t\t\t\tENTER PASSWORD: ";
	cin>>pass;
    if(pass == "1234"){
      cout << "\n\n\n\t\t\t\t\tACCESS GRANTED.... :))))) \n";
      system("PAUSE");
      system("cls");
   }
   else{
      cout << "\n\n\t\t\t\t\tAccess Aborted... :(((((( \n\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
    	exit(0);
   		}
   }
   virtual void add_record() =0;
   virtual void display() =0;
   virtual void edit() =0;
   virtual void search() =0;
   virtual void deleterecord() =0;
};
#endif
