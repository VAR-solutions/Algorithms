#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;

struct data
{
	string Name;
	string Author;
	string Year; 
	string Price; 
	string Number;
	string Code;
	
	};
	data limit[10];
	int size,input,c,id;
	
void inputdata()
{
	cout<<"\nInput amount data : "; cin>>input;
	id = 0;
	for (c=0; c<input; c++){
		id=id+1;
		cout<<"\nData -"<<id<<endl;
		cout<<""; 
		getline(cin, limit[size].Number);
		cout<<"Code Book \t\t : "; 
		getline(cin, limit[size].Code);
		cout<<"Name Book \t\t : ";
		getline(cin, limit[size].Name);
		cout<<"Publication Year Book\t : ";
		getline(cin, limit[size].Year);
		cout<<"Name Author \t\t : "; 
		getline(cin, limit[size].Author);
		cout<<"Price Book \t\t : ";
		getline(cin, limit[size].Price);
		size++;
	}
	
}

void viewdata()
{
	int i,j;
	cout<<"\n=============================Data=============================\n\n";
	cout<<"==============================================================================\n";
	j=0;
	for(i=0; i<size; i++){
		j=j+1;
		
		
		cout<<"Number\t\t\t : "<<j<<limit[i].Number<<"\n";
		cout<<"Code Book\t\t : "<<limit[i].Code<<"\n";
		cout<<"Name Book\t\t : "<<limit[i].Name<<"\n"; 
		cout<<"Year Book\t\t : "<<limit[i].Year<<"\n";
		cout<<"Author\t\t : "<<limit[i].Author<<"\n";
		cout<<"Price\t\t\t : "<<limit[i].Price<<"\n";
		cout<<endl;
	}
	
	getch();
	
}

void deletedata()
{
	int x,y;
	cout<<"Delete data -"; cin>>x;
	y=x-1;
	size--;
	for(int i=y; i<size; i++)
	{
		limit[i] = limit[i+1];
	}
	
	cout<<"\n\n\n\n\n\n\n\n\n+++++++++++++++++++++++++++++++++Data -"<<x<<" Deleted+++++++++++++++++++++++++";
	getch();
	
}

void editdata()
{
	int k,l;
	cout<<"Input Data edit : "; cin>>k;
	l=k-1;
	
	
	cout<<""; 
	getline(cin, limit[l].Number);
	cout<<"Code Book\t: ";
	getline(cin, limit[l].Code);
	cout<<"Name Book\t: ";
	getline(cin, limit[l].Name);
	cout<<"Publication Year\t: ";
	getline(cin, limit[l].Year);
	cout<<"Name Author\t: ";
	getline(cin, limit[l].Author);
	cout<<"Price\t\t: ";
	getline(cin, limit[l].Price);
	
	viewdata();
}

int main()
{
	int choice;
	char w;
	
	start:
		cout<<"\n==================== MENU CHOICE ========================";
		cout<<"\n1. Input Data";
		cout<<"\n2. View Data";
		cout<<"\n3. Edit Data";
		cout<<"\n4. Delete Data";
		cout<<"\n5. Exit";
		
		cout<<"\n\nInput Choice : "; cin>>choice;
		if(choice==1)
		{
			 inputdata(); goto start;
		}
		if(choice==2)
		{
			 viewdata(); goto start;
		}
		if(choice==3)
		{
			 editdata(); goto start;
		}
		if(choice==4)
		{
			 deletedata(); goto start;
		}
			if(choice==5)
		{
			
			cout<<"\n\n\n\n\n\n\n\n\n ARE YOU SURE EXIT FROM PROGRAM??\n\n";
			cout<<"          [Y]      [N]      \n"<<endl;
			cout<<" "; cin>>w;
			if(w=='y'||w=='Y')
			{
				
				cout<<"\n\n\n\n\n*******************PROGRAM FINISH**********************";
			}
			if(w=='n'||w=='N')
			{
				goto start;
			}
		}
			else
		{
			
			cout<<"CHOICE 1 - 5";
			getch();  goto start;
		}
}
