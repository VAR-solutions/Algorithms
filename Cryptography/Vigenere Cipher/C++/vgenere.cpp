#include<bits/stdc++.h>

using namespace std;

string enc(string text,string key){
  string finkey;
  int t;
    if(text.length()>key.length()){
      t=(text.length()/key.length())+1;

    for(int i=0;i<t;i++){
      finkey+=key;
    }
  }
    else{
      finkey=key;
    }

    for(int i=0;i<text.length();i++){
      //cout<<((int(text[i])-97+int(key[i])-97)%26)+97;
      text[i]=char(((int(text[i])-97+int(finkey[i])-97)%26)+97);
    }
    return text;
    //finalkey created
}

string dec(string text,string key){
  string finkey;
  int t;
    if(text.length()>key.length()){
      t=(text.length()/key.length())+1;

    for(int i=0;i<t;i++){
      finkey+=key;
    }
  }
    else{
      finkey=key;
    }

    for(int i=0;i<text.length();i++){
      //cout<<((int(text[i])-97+int(key[i])-97)%26)+97;
      //cout<<int(finkey[0])<<"\n\n\n";
      int temp=(int(text[i])-65-int(finkey[i])+97)%26;
      //cout<<temp<<"\n\n";
      if(temp<0){
        temp=26-temp;
      }
      //cout<<temp<<"\n";
      text[i]=char(temp+97);
    }
    return text;
}

int main(){
  string key;
  string text;
  int ch;
  while(true){
    cout<<"Enter if you want to 1)encrypt or 2)decrypt 3)exit:\n";
    cin>>ch;
    if(ch==1){
      cout<<"enter the text to be encrypted:\n";
      cin>>text;
      cout<<"enter the key\n";
      cin>>key;
      cout<<enc(text,key)<<"\n";
    }
    else if(ch==2){
      cout<<"enter the text to be decrypted:\n";
      cin>>text;
      //transform(text.begin(), text.end(), text.begin(), ::tolower);
      cout<<"enter the key:\n";
      cin>>key;
      cout<<dec(text,key)<<"\n";
    }
    else{
      break;
    }
  }
  return 0;
}
