#include<iostream>
#include<string>
#include<conio.h>

#include "teacher.h"
#include "student.h"
#include "person.h"
using namespace std;
int main(){
	
	student stuObject; 
	person *testObject1 = &stuObject;
	stuObject.show();
	Teacher teacherObj;
	person *testObject = &teacherObj;
	char choice;
	while(1){
	system("cls");
	cout<<endl;
	cout<<"\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
    cout<<"\n\n\t\t\t\t\t  SCHOOL BILLING SYSTEM \n\n";
    cout<<"\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
    cout<<"\n\n\t\t\t\t\t\t:MAIN SCREEN:\n\n";
    cout<<"\t\t\t\t\t1. Students Information"<<endl;
    cout<<"\t\t\t\t\t2. Teacher Information"<<endl;
    cout<<"\t\t\t\t\t3. Exit Program"<<endl;
    cout<<"\n\n\t\t\t\tEnter your choice: ";
    cin>>choice;
    system("cls");
    switch(choice){
	
    case '1' :
	{
		while(1){
		cout<<"\n\n";
		cout<<"\t\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n\n";
		cout<<"\t\t\t\t\t1. ADD NEW ENTRY TO RECORD \n";
		cout<<"\t\t\t\t\t2. DISPLAY ALL RECORD\n";
		cout<<"\t\t\t\t\t3. SEARCH RECORD BY FIRSR NAME\n";
		cout<<"\t\t\t\t\t4. EDIT RECORD\n";
		cout<<"\t\t\t\t\t5. DELETE RECORD\n";
		cout<<"\t\t\t\t\t6. GOTO MAIN PAGE\n";
		cout<<"\n\n\t\t\t\t ENTER YOUR CHOICE: ";
		cin>>choice;
		switch(choice){
			case '1':
				{
					testObject1->add_record(); 
					
				}
				continue;
				
				case '2':
					{
						testObject1->display(); 
					}
					continue;
				case '3':
					{
						testObject1->search(); 
					}
					continue;
				case '4':
					{
						testObject1->edit();
					}
					continue;
				case '5':
					{
					testObject1->deleterecord();
					}
					continue;
				case '6':
					{
						break;
					}
				   }
    		break;
				}
		continue;
			}
	case '2':
	{
		while(1){
				system("cls");
				cout<<"\t\t\t TEACHER'S INFORMATION AND BIO DATA SECTION\n\n\n";
				cout<<"\t\t\t\t\t1. ADD NEW ENTRY TO RECORD \n";
				cout<<"\t\t\t\t\t2. DISPLAY ALL RECORD\n";
				cout<<"\t\t\t\t\t3. SEARCH RECORD BY ID\n";
				cout<<"\t\t\t\t\t4. EDIT RECORD\n";
				cout<<"\t\t\t\t\t5. DELETE RECORD\n";
				cout<<"\t\t\t\t\t6. GOTO MAIN PAGE\n";
				cout<<"\n\n\t\t\t\t ENTER YOUR CHOICE: ";
				cin>>choice;
				switch(choice){
					case '1':
						{
						testObject->add_record();	
						}
						continue;
					case '2':
						{
							testObject->display();
							cout<<"\nPRESS ANY KEY TO CONTINUE...";
							getch();
						}
						continue;
					case '3':
						{
							testObject->search();
							system("PAUSE");
							cout<<"\nPRESS ANY KEY TO CONTINUE...";
						}
						continue;
					case '4':
						{
						testObject->edit();
						}
							continue;
					case '5':
						{
							testObject->deleterecord();
						}
							continue;
					case '6':
						{
							break;
						}
				}
				
				break;
			}
			continue;
	}
	case '3':
		{
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tDESIGNED BY MAJU STUDENTS OF SOFTWARE ENGINEERING DEPARTMENT..................... :)";
			break;
		}	
		}	//	first switch ends here
		break;
	}
		//first while ends here
}	//main ends here

