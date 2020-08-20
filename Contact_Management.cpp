//C++ program for contact management begginner level
#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

//Functions list
void addContact();				//to add a new contact
void searchContact();			//to search among saved contacts
void help();					//to get help
void do_exit();					//to exit 
bool check_digit(string);		//to check the length of phone number
bool check_number(string);		//to check whether number consist of numbers only or not

string fname,lname,number;

int main()
{
	system("cls");									//To clear screen
	system("color 0A");								//To change color of foreground and background
	//system("color %");							//To get the color codes un-comment this line
	int choice;
	cout<<"\n\n\n\t\t\tCONTACT MANAGEMENT: ";
	cout<<"\n\n\tEnter the Available choices below: ";
	cout<<"\n\t1.Adding a New Contact Details";
	cout<<"\n\t2.Searching a contact";
	cout<<"\n\t3.Help";
	cout<<"\n\t4.Exit\n\t>>> ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			addContact();
			break;
		case 2:
			searchContact();
			break;
		case 3:
			help();
			break;
		case 4:
			do_exit();
			break;
		default:
			cout<<"\n\tEnter a valid choice\n";
			cout<<"\tEnter any key to continue: ";
			getch();
			main();
	}
	return 0;
}

void addContact()										//Fucntion to add new contact
{
	ofstream phone("Number.txt", ios::app);				//Open in append mode
	system("cls");
	int test;
	
	cout<<"\n\tEnter First Name: ";
	cin>>fname;
	cout<<"\n\tEnter Last Name: ";
	cin>>lname;
	cout<<"\n\tEnter Contact Number: ";
	cin>>number;
	if(check_digit(number)==true)				//checking if the phone number has 10 digits or not
	{
		if(check_number(number)==true)			//checking whether the phone number consist of numbers only
		{
			if(phone.is_open())
			{
				int test;
				phone<<fname<<" "<<lname<<" "<<number<<endl;
				cout<<"\n\tContacts saved succesfully";
				cout<<"\n\t1. Continue\n\t2. Exit\n\t";
				cin>>test;
				switch(test)
				{
					case 1:
						main();
						break;
					case 2:
						do_exit();
						break;
					default:
						cout<<"\n\tEnter a valid option";
				}
			}
			else
			cout<<"\n\tError Opening file";
		}
		else
		{
			cout<<"\n\tPhone number must be a number";
			cout<<"\n\t1. Try again\n\t2. Exit\n\t";
			cin>>test;
			switch(test)
			{
				case 1:
					cout<<"\n\tEnter any key to continue ";
					getch();
					main();
					break;
				case 2:
					do_exit();
					break;
				default:
					cout<<"\n\tEnter correctly";
			}
		}
	}
	else
	{
		cout<<"\n\tPhone number must be of 10 digits";
		cout<<"\n\t1. Try again\n\t2. Exit\n\t";
		cin>>test;
		switch(test)
		{
			case 1:
				cout<<"\n\tEnter any key to continue ";
				getch();
				main();
				break;
			case 2:
				do_exit();
				break;
			default:
				cout<<"\n\tEnter correctly";
		}
		
	}
	phone.close();
		
}

bool check_digit(string Name)				//boolean function to check the length of phone number
{
	if(Name.length()==10)
	return true;
	else
	return false;
}

bool check_number(string name)			//boolean function to check the whether phone consist of numbers or not
{
	bool check= true;
	for(int i=0;i<name.length();i++)
	{
		if((name[i])>=48 && int(name[i])<=57)
		{
			continue;
		}
		else
		{
			check=false;
			break;
		}
	}
	if(check==true)
		return true;
	else
		return false;
}

void searchContact()				//to search the saved contacts
{
	bool found = false;
	ifstream phone1;
	phone1.open("Number.txt");
	string key;
	cout<<"\n\tEnter the string to be found: ";
	cin>>key;
	while(phone1>>fname>>lname>>number)
	{
		if(key==fname || key==lname || key==number)
		{
			system("cls");
			cout<<"\n\tContact Details: ";
			cout<<"\n\t"<<fname<<" "<<lname<<":";
			cout<<"\n\t"<<number;
			found = true;
			break;
		}
	}
	if(found == false)
	cout<<"\n\tNo contacts found";
}

void help()					//HELP function
{
	system("cls");
	cout<<"\n\tThis is a beginner level contact Management Program using C++\n";
	cout<<"\n\tPress any key to continue: ";
	getch();
	main();
}

void do_exit()				//To exit
{
	system("cls");
	cout<<"Press any key to exit";
	exit(1);
}
