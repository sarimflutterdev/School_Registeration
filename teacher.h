#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Teacher :public person { 
	string teacher_fname ,teacher_lname ;
	string total_number_record;
	int ID , tea_class , salary ,teaching_experience;
	public:
		void add_record(){
			fstream f;
			f.open("Tadd_record.txt",ios_base::app);
			char option='y'; 
			while(option=='y'|option=='Y'){ 
			cout<<"WOULD YOU LIKE TO ENTER MORE DATA (Y|N):";
			cin>>option;
			if(option=='n'|option=='N'){
			f.close(); 
			continue; 
			}
			cout<<"ENTER TEACHER FIRST NAME:";cin>>teacher_fname;
			cout<<"ENTER TEACHER LAST NAME:";cin>>teacher_lname;
			cout<<"ENTER TEACHER ID:";cin>>ID;
			cout<<"ENTER TEACHING EXPERIENCE:";cin>>teaching_experience;
			cout<<"ENTER TEACHER CLASS:";cin>>tea_class;
		if(teaching_experience >=1 && teaching_experience<=3 ){
			salary=30000;
			cout<<"YOUR SALARY IS :30,000 RS"<<endl;
		}
		if(teaching_experience>=4 && teaching_experience<=7 ){
			salary=40000;
			cout<<"YOUR SALARY IS :40,000 RS"<<endl;
		}
		if(teaching_experience>=8 && teaching_experience<=10 ){
			salary=50000;
			cout<<"YOUR SALARY IS :50,000 RS"<<endl;
		}
		if(teaching_experience>=11 && teaching_experience<=14 ){
			salary=60000;
			cout<<"YOUR SALARY IS :60,000 RS"<<endl;
		}
		if(teaching_experience>=15 && teaching_experience<=19 ){
			salary=70000;
			cout<<"YOUR SALARY IS :70,000 RS"<<endl;
		}
			f<<endl<<teacher_fname<<" "<<teacher_lname<<" "<<ID<<" "<<teaching_experience<<" "<<tea_class;
			cout<<"\nENTER DATA IS ENTERED TO RECORD....."<<endl;
		}
	}
	void display(){
			fstream f;
			f.open("Tadd_record.txt",ios_base::in);
			cout<<"\nDISPLAYING OUTPUT FROM FILE.."<<endl;
			cout<<"\nNAME\t\t\t ID \t\t\t EXPERIENCE \t\t\t CLASS"<<endl;
			while(f.eof()==0){
//			total_number_record
			f>>teacher_fname>>teacher_lname>>ID>>teaching_experience>>tea_class;
			cout<<teacher_fname<<teacher_lname<<"\t\t"<<ID<<"\t\t\t\t"<<teaching_experience<<"\t\t\t"<<tea_class<<endl;
		}
	}
	
	
	void search(){
		int notfound=0;
		int temp_ID;
		ifstream f;
		f.open("Tadd_record.txt");
		cout<<"ENTER ID  OF TEACHER TO FIND RECORD: ";cin>>temp_ID;
		if(f.is_open())
		while(f.eof()==0){
		f>>teacher_fname>>teacher_lname>>ID>>teaching_experience>>tea_class;
		 if (temp_ID==ID) {
		 		notfound=1;
                	cout<<"\n TEACHER FIRST NAME:\t"<<teacher_fname;
					cout<<"\n TEACHER LAST NAME:\t"<<teacher_lname;
					cout<<"\n TEACHER ID:\t"<<ID;
					cout<<"\n TEACHING EXPERIENCE"<<teaching_experience;
					cout<<"\n TEACHER CLASS:\t"<<tea_class;
            }
       		 if(notfound == 0){
			cout<<"\n\t\t\tNo Record Found"<<endl;
			}
		}
	}
	
	void edit(){
		fstream first,sec;
		int id;
		cout<<"\nENTER ID OF TEACHER WHICH YOU WANT TO EDIT...";
		cin>>id;
		first.open("Tadd_record.txt",ios_base::in);
		sec.open("temp_record.txt",ios_base::app);
		while(first.eof()==0){
			first>>teacher_fname>>teacher_lname>>ID>>teaching_experience>>tea_class;
			if(ID!=id){
				sec<<endl<<teacher_fname<<" "<<teacher_lname<<" "<<ID<<" "<<teaching_experience<<" "<<tea_class;
			}
			else{
				cout<<"ENTER NEW ID :";cin>>ID;
				cout<<"ENTER FIRST NAME :";cin>>teacher_fname;
				cout<<"ENTER LAST NAME :";cin>>teacher_lname;
				cout<<"ENTER TEACING EXPERIENCE :";cin>>teaching_experience;
				cout<<"ENTER STUDENT CLASS :";cin>>tea_class;
				sec<<endl<<teacher_fname<<" "<<teacher_lname<<" "<<ID<<" "<<teaching_experience<<" "<<tea_class;
				}
			}
			sec.close();
			first.close();
			
		if(remove("Tadd_record.txt")!=0){
			cout<<"\n\tFILE DOES NOT REMOVE";
		}
		else{
			cout<<"\n\tOKAY.. FILE REMOVED";
		}
		
		if(rename("temp_record.txt","Tadd_record.txt")!=0){
			cout<<"\n\tFILE DOEST NOT RENAME";
		}
		else{
			cout<<"\n\tOKAY FILE RENAMED";
		}
	}
	
	void deleterecord(){
		int id;
		cout<<"ENTER ID WHICH YOU WANT TO DELETE: "<<endl;
		cin>>id;
		ifstream first;
		first.open("Tadd_record.txt");
		ofstream second;
		second.open("new_record.txt");
		while(first.eof()==0){
			if(ID!=id){
				second<<endl<<teacher_fname<<" "<<teacher_lname<<" "<<ID<<" "<<teaching_experience<<" "<<tea_class<<endl;
			}
			else{
				cout<<"\n RECORD DELETED";
			}
			first>>teacher_fname;
			first>>teacher_lname;
			first>>ID;
			first>>teaching_experience;
			first>>tea_class;
		}
		second.close();
		first.close();
		
		if(remove("Tadd_record.txt")!=0){
			cout<<"\n\tFILE DOES NOT REMOVE";
		}
		else{
			cout<<"\n\tOKAY.. FILE REMOVED";
		}
		
		if(rename("new_record.txt","Tadd_record.txt")!=0){
			cout<<"\n\tFILE DOEST NOT RENAME";
		}
		else{
			cout<<"\n\tOKAY FILE RENAMED";
		}
		
	}
};
#endif
