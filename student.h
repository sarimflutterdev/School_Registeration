#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"

#include<iostream>
#include<fstream>
#include<string>

class student :public person {
	string firs_name,last_name;
	int roll_no,stu_class,temp;
	float fees;
	int total_number_record=0;
	public:
		void add_record(){

			fstream f;
			f.open("add_record.txt",ios_base::app);
			char option='y'; 
			while(option=='y'|option=='Y'){ 
			cout<<"WOULD YOU LIKE TO ENTER MORE DATA (Y/N):";
			cin>>option;
			if(option=='n'|option=='N'){
			f.close(); 
			continue; 
			}
			cout<<"ENTER STUDENT FIRST NAME:";cin>>firs_name;
			cout<<"ENTER STUDENT LAST NAME:";cin>>last_name;
			cout<<"ENTER STUDENT ROLL NO:";cin>>roll_no;
			cout<<"ENTER STUDENT CLASS :";cin>>stu_class;
			if(stu_class==1){
			fees=6000;
			cout<<"FEES OF CLASS 1 : 6000. " ;
	}
			if(stu_class==2){
			fees=6000;
			cout<<"FEES OF CLASS 2 : 6000. " ;
	}
	
			if(stu_class==3){
			fees=6000;
			cout<<"FEES OF CLASS 3 :6000. ";
	}
			if(stu_class==4){
			fees=6000;
			cout<<"FEES OF CLASS 4 :6000. ";
	}
			if(stu_class==5){
			fees=70000;
			cout<<"FEES OF CLASS 5 :70000. ";
	}
			if(stu_class==6){		
			fees=7000;
			cout<<"FEES OF CLASS 6 :70000. ";
	}
			if(stu_class==7){
			fees=7000;
			cout<<"FEES OF CLASS 7 :70000. " ;
	}
			if(stu_class==8){
			fees=9000;
			cout<<"FEES OF CLASS 8 :9000. " ;
	}
			if(stu_class==9){
			fees=9000;
			cout<<"FEES OF CLASS 9 :9000. " ;
	}
			if(stu_class==10){
			fees=9000;
			cout<<"FEES OF CLASS 10 :9000. " ;
	}
		cout<<"\nENTER TO PAY FEE AMOUNT: ";
	total_number_record++;
	int amount;
	cin>>amount;
	if(amount>=fees){
	int a=amount-fees;
	cout<<"YOUR RETURN AMOUNT IS : "<<a;
	cout<<"\nTHANKYOU YOUR FEES IS  PAID!!"<<endl;
	}
	else if(amount<=fees){
		int b=fees-amount;
		cout<<"\nDUE AMOUNT IS  "<<b;
		cout<<"\nFEE DEFAULTER.";
	}
			 
			f<<endl<<firs_name<<" "<<last_name<<" "<<roll_no<<" "<<stu_class<<" "<<total_number_record;
			cout<<"\n YOUR DATA IS ENTERED TO RECORD....."<<endl;
			
		}
	}
	
		void display(){
			fstream f;
			f.open("add_record.txt",ios_base::in);
			cout<<"\nDISPLAYING OUTPUT FROM FILE.."<<endl;
			cout<<"\nNAME\t\t\t ROLL NO\t\t\t CLASS"<<endl;
			while(f.eof()==0){
			f>>firs_name>>last_name>>roll_no>>stu_class>>total_number_record;
			cout<<firs_name<<last_name<<"\t\t"<<roll_no<<"\t\t\t\t"<<stu_class<<endl;

		}
		cout<<"TOTAL NUMBER OF RECORD : "<<total_number_record;
	}
	
//	void search(){
//		int notfound=0;									BY ROLL NO 
//		int rollno;
//		ifstream f;
//		f.open("add_record.txt");
//		cout<<"ENTER ROLL NUMBER OF STUDENT TO FIND RECORD: ";cin>>rollno;
//		if(f.is_open())
//		while(f.eof()==0){
//		f>>firs_name>>last_name>>roll_no>>stu_class;
//		 if (rollno==roll_no) {
//		 		notfound=1;
//                cout << "\n STUDENT FIRST NAME:\t" <<firs_name;
//                cout << "\n STUDENT LAST NAME:\t"  <<last_name;
//                cout << "\n STUDENT ROLL NO :\t"   <<roll_no;
//                cout << "\n STUDENT CLASS  :\t"    <<stu_class;
//            }
//       		 if(notfound == 0){
//			cout<<"\n\t\t\tNo Record Found"<<endl;
//			}
//		}
//	}
	void search(){//BY FIRST NAME
		int notfound=0;									
		string f_name;
		ifstream f;
		f.open("add_record.txt");
		cout<<"ENTER FIRST NAME OF STUDENT TO FIND RECORD: ";cin>>f_name;
		if(f.is_open())
		while(f.eof()==0){
		f>>firs_name>>last_name>>roll_no>>stu_class>>total_number_record;
		 if (f_name==firs_name) {
                cout << "\n STUDENT FIRST NAME:\t" <<firs_name;
                cout << "\n STUDENT LAST NAME:\t"  <<last_name;
                cout << "\n STUDENT ROLL NO :\t"   <<roll_no;
                cout << "\n STUDENT CLASS  :\t"    <<stu_class;
            }
		}
		
		 if(notfound == 0){
			cout<<"\n\t\t\tNo Record Found"<<endl;
			}
	}
	void edit(){
		fstream file,b;
		int temp_edit;
		cout<<"ENTER ROLL NO OF STUDENT WHICH YOU WANT TO EDIT : ";
		cin>>temp_edit;
		file.open("add_record.txt",ios_base::in);
		b.open("new_record.txt",ios_base::app);
		while(file.eof()==0){
			file>>firs_name>>last_name>>roll_no>>stu_class>>total_number_record;
			if(roll_no!=temp_edit){
				b<<endl<<firs_name<<" "<<last_name<<" "<<roll_no<<" "<<stu_class<<" "<<total_number_record;
			}//if ends here
			else{
				cout<<"ENTER NEW ROLL NO :";cin>>roll_no;
				cout<<"ENTER FIRST NAME :";cin>>firs_name;
				cout<<"ENTER LAST NAME :";cin>>last_name;
				cout<<"ENTER STUDENT CLASS :";cin>>stu_class;
				b<<endl<<firs_name<<" "<<last_name<<" "<<roll_no<<" "<<stu_class<<" "<<total_number_record;
			} 
		}//while ends here
		b.close();
		file.close();
		
		if(remove("add_record.txt")!=0){
			cout<<"\n\tFILE DOES NOT REMOVE";
		}
		else{
			cout<<"NO RECORD FOUND OF THIS ROLL NO ";
		}
		
		if(rename("new_record.txt","add_record.txt")!=0){
			cout<<"\n\tFILE DOEST NOT RENAME";
	}
}
	void deleterecord(){
		int del_stu_rec;
		cout<<"ENTER ROLL NO OF STUDENT WHICH YOU WANT TO DELETE :";
		cin>>del_stu_rec;
		ifstream a;
		a.open("add_record.txt");
		ofstream b;
		b.open("new_record.txt");
		
		while(a.eof()==0){
			if(roll_no!=del_stu_rec){
				b<<endl<<firs_name<<" "<<last_name<<" "<<roll_no<<" "<<stu_class<<" "<<total_number_record<<endl;
				
			}//if ends here
			else{
				cout<<"\nRECORD DELETED";
			}
			a>>firs_name;
			a>>last_name;
			a>>roll_no;
			a>>stu_class;
		}//while ends here
		b.close();
		a.close();
		
		if(remove("add_record.txt")!=0){
			cout<<"\n\tFILE DOES NOT REMOVE";
		}
		else{
			cout<<"\n\tOKAY.. FILE REMOVED";
		}
		
		if(rename("new_record.txt","add_record.txt")!=0){
			cout<<"\n\tFILE DOEST NOT RENAME";
		}
		else{
			cout<<"\n\tOKAY FILE RENAMED";
		}
	}//delete record function ends here
};
#endif
