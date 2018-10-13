#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include "hash.h"
using namespace std;

struct node                                                             //node to store data in record
  {
     string name;
     int frequency;
  };
  
int main(int argc,char* argv[])
  {
     int c=atoi(argv[1]);
     int size=atoi(argv[2]);                                 //taking input through command line
     string type=argv[3];
     
     hash h;
     
     struct node** head=h.initialise(size,type);               //pointer to hash table
     
     int year,Mcount,Tcount,Fcount;
     string key;
     int count=0;
     ifstream f;                                                                 
     f.open("input1.txt");                                      //taking input from file
   while(f>>year)
    {
      f>>Tcount;
      f>>Mcount;
      f>>Fcount;
      f>>key;
      if(key.length()>=5)
      count=h.insert(key,Tcount,count,head);                                        
    } 
                                                                              
    cout<<"Enter option\n";
    int option;
    cin>>option;
    float lf;
    
    switch(option)
     {
        
        case 2:cout<<"Enter key\n";
               cin>>key;
   	       cout<<h.find(key)<<endl;
		break;

	case 3:cout<<"Enter key"<<endl;
	       cin>>key;
	       if(key.length()>=5)
	       {
	       count=h.insert(key,Tcount,count,head);
	       cout<<h.find(key)<<endl;
               cout<<"ok inserted"<<endl;
               }
		break;

	case 4:cout<<"Enter key\n";
               cin>>key;
		h.deletekey(key);
		break;

	case 5: lf=h.load_factor(count);
	       cout<<lf<<endl;
		break;

	case 6:cin>>size;
		h.rehash(size,head);
		break;

	case 7:h.disp_stats(count);
		break;

     }
     
 }
