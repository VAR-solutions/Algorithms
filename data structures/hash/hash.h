#include<iostream>
using namespace std;

class Hash
  {
     private:
             int size,count,Tcount,uns,suc;
             string key,type;
             float lf;                                   
             struct node** head;                         //pointer to hash table
     public:
            struct node** initialise(int size,string type);
            int insert(string key,int Tcount,int count,struct node** head);
	    int find(string key);
	    void deletekey(string key);
            float load_factor(int count);
            struct node** rehash(int size,struct node** head);
            void disp_stats(int count);
  };
