#include <iostream>
#include  <windows.h>
using namespace std;
void calender ();
bool leapYear(int year);
int main ()
{
	
	while (true)
	{
	system("CLS");
	int choice;
	int year;
	cout<<"Select one of the following.\n";
	cout<<"1. Leap Year Calculator.\n";
	cout<<"2. Calender.\n";
	cout<<"0. Exit.\n";
	cin>>choice;
	switch(choice)
	{
	case 1:               // Leap Year Calculator.
		cout<<"Enter a year from 2000 to 2400.\n";
		cin >>year;
		if (leapYear(year))
		{
			cout<<year<<" is a Leap Year.\n";
			system("pause");
		}
		else 
		{
			cout<<year<<" is not a Leap Year.\n";
			system("pause");
		}
		break;
	case 2:                // Calander from 2000 to 2400
		calender();
		system("pause");
		break;
	case 0:
		return 0;
		break;
	default:
		cin.clear();
		cin.ignore();
		cout<<"Please enter a valid number.\n";
		system("pause");
		break;
	}


	
	}
	
}


void calender()
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	int count=5;
	for (int i=2000;i<2002;i++)
	{
		
		for (int j=1;j<=12;j++)
		{
			if (leapYear(i))
			{
				SetConsoleTextAttribute(color, 10 );
			}
			else 
			{
				SetConsoleTextAttribute(color, 7 );
			}
			int arr[6][7];
			
			int week = 0;
			cout<<"--------------------------------------\n";
			cout<<"Year "<< i<<"  Month "<<j <<endl;
			cout<<"Mo  Tu  We  Th  Fr  Sa  Su \n";
			int days;
			if (j==1||j==3||j==5||j==7||j==8||j==10||j==12)
			{
				days = 31;
			}
			else if (j==2)
			{
				if (leapYear(i))
				{
					days= 29;
				}
				else 
				{
					days = 28;
				}
			}
			else 
			{
				days = 30;
			}
			for (int x=0;x<count;x++)
			{
				cout<<"    ";
			}
			for (int k = 1;k<=days;k++)
			{
				
				arr[week][count]=k;
				if (k<10)
				{
					cout<<" ";
				}
				cout<<arr[week][count] <<"  ";
				count++;
				if (count==7)
				{
					count=0;
					week++;
					cout<<endl;
				}
				
			}
			cout<<endl;
		}
	}
}
bool leapYear(int year)
{
	if (year % 4 ==0)
	{
		if (year%100==0&&year%400!=0)
		{
		return false;
		}
		else 
			return true;
	}
	else 
		return false;
}