#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include "hash.h"

using namespace std;

struct node
  {
     string name;
     int frequency;
  };

struct node** hash::initialise(int siz,string typ)             //function to initialise hashtable 
  {
     size=siz;
     type=typ;
     head=new node*[size];
     
     uns=0;
     suc=0;
     
     for(int i=0;i<size;i++)
        head[i]=NULL;
     return head;
  }

int Hashfunc(string key)                                       //hash function to distribute keys
 {
   int s=0,x;
   for(int i=0;key[i]!='\0';i++)
     {
       x=(int)key[i];
       s=s+x;
     }
   return s;
 }


struct node* createnode(string key,int Tcount)                  //functin to create a new node 
  {
     struct node* temp=new node();
     temp->name=key;
     temp->frequency=Tcount;

   return temp;
  }


int hash::insert(string key,int Tcount,int count,struct node** head)        //function to insert a node 
  {
      
      loadfactor=(float)count/size;
      
    if(loadfactor<0.75)
    {
      struct node* temp;
      int index=Hashfunc(key);
      temp=createnode(key,Tcount);
      int a=index%size;
      if(head[a]==NULL){
         head[a]=temp;
         count++;
         suc++;
         return count;}
      else
       {
          if(head[a]->name==key){
    
             head[a]->frequency=head[a]->frequency+Tcount;
             return count;}
          else{
          int i=1;
          int b=a;
          while(head[b]!=NULL&&i<size)
           {
    
              if(type=="LP")
                b=(a+i)%size;
	      else 
                b=(a+(i*i))%size;

              i++;
              uns++;
           }
           if(head[b]==NULL){
            
             head[b]=temp;
             count++;
         return count;}
           else{
              head=rehash(size,head);
              count=insert(key,Tcount,count,head);
              return count;}
       }
     }
    }
    else
      {
         head=rehash(size,head);
         count=insert(key,Tcount,count,head);
         return count;
      }
	
   }

struct node** hash::rehash(int siz,struct node** head)                      //function to rehash the table
  {
      int i=0;
      size=2*siz;
      struct node** headnew;
      headnew=initialise(size,type);
      int count=1;
      while(i<siz)
       {
          if(head[i]!=NULL)
           {
             count=insert(head[i]->name,head[i]->frequency,count,headnew);
           }
          i++;
       }
       head =headnew;
     return head;
  }
          

int hash::find(string key)                                        //function to find given key and return its frequency
  {
     int a=Hashfunc(key);
     a=a%size;
       if(head[a]!=NULL)
        {
          if(head[a]->name==key)
                 return head[a]->frequency;
          int i=1,b;
          while(i<size)
           {
              b=(a+i)%size;
              if(head[b]->name==key)
                 return head[b]->frequency;
              else{
                 i++;
             
                  }
           }
        }
     return 0;
  }  
  
void hash::deletekey(string key)                                      //function to delete a given key
  {
      int a=Hashfunc(key);
       a=a%size;
       int i=0,b;
        if(head[a]!=NULL)
        {
          while(i<size)
           {
              b=(a+i)%size;
              if(head[b]->name==key)
               {
                  head[b]->name="deleted";
                  head[b]->frequency=0;
                  cout<<head[b]->name<<" "<<head[b]->frequency<<endl;
                  return;
               }
              else 
                 i++;
           }
         }
     cout<<"This key doesn't exist to delete"<<endl;
     return;
  }

float hash::load_factor(int count)                             //function to compute load factor 
  {
    return (float)count/size;
  }

void hash::disp_stats(int count)	                      //to display stat ie no success and unsuccefull collisins
  {
    cout<<"Unsuccesful-"<<uns<<endl;
    cout<<"Successful-"<<suc<<endl;
    cout<<load_factor(count)<<endl;
  }
