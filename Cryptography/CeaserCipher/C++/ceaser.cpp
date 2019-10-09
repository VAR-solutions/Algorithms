//program to decrypt ceaser cipher
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
 string s;
 cin>>s;
 //the most common letter in the english alphabet is e
 map<char,int> fre;
 for(int i=0;i<s.length();i++){
   //cout<<"hah";
   fre[s[i]]+=1;
 }
//finding the key
auto x= max_element(fre.begin(),fre.end(),fre.value_comp());
//cout<<"hah";
int key;
key=abs(int('e')-int(x->first));
string fin;
for(int i=0;i<s.length();i++){
  //cout<<"gfg";
  fin[i]=char((int(s[i])-key)%26);
}
for(int i=0;i<fin.length();i++){
  cout<<fin[i];
}
return 0;
}
