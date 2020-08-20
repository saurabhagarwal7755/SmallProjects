//Random Number generator using C++

#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

int main()
{
	system("cls");							//Clear screen
	system("color 0A");						//To change foreground and background color
	//system("color %");					//To get the color codes uncomment this line
	srand(time(0));							//To start the process at earliest
	cout<<"\t\tEnter number of tickets: ";
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<"\n\n\n\t\tProcess started for "<<(i+1)<< " person!!!\n\t\tAnd The Number is-->> ";
		int result=(rand()%6);				//Random number upto 6
		cout<<result;
		switch(result)
		{
			case 1:
				cout<<"\n\t\tBetter luck next Time";
				break;
			case 2:
				cout<<"\n\t\tYou won 100 rs";
				break;
			case 3:
				cout<<"\n\t\tOOOOOWW Your are lucky, you got a bike";
				break;
			case 4:
				cout<<"\n\t\tBad Luck";
				break;
			case 5:
				cout<<"\n\t\tYou won a Cycle";
				break;
			default:
				cout<<"\n\t\tNo Prize";
		}
	}
	return 0;
}
