#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> getKeyMatrix(string key)
{
     for(int i=0;i<key.length();i++)
          if(key[i]=='J')
               key[i] = 'I';
     vector<vector<char>> K(5);
     bool visited[26];
     memset(visited,false,sizeof(visited));
     visited[9] = true;
     int k = 0;
     char ch = 'A';
     for(int i=0;i<5;i++)
     {
          vector<char> v(5);
          for(int j=0;j<5;j++)
          {
               if(k<key.length())
               {
                    if(!visited[key[k]-'A'])
                    {
                         v[j] = key[k];
                         visited[key[k]-'A'] = true;
                         k++;
                    }
                    else
                         k++,j--;
               }
               else
               {
                    if(!visited[ch-'A'])
                    {
                         v[j] = ch;
                         ch++;
                    }
                    else
                    {
                         ch++;
                         j--;
                    }
               }
          }
          K[i] = v;
     }
     return K;
}

pair<int,int> getPosition(char ch,vector<vector<char>> km)
{
     for(int i=0;i<5;i++)
          for(int j=0;j<5;j++)
               if(km[i][j] == ch)
                    return pair<int,int> (i,j);
}

void encrypt(string message, string key)
{
     //Getting the key Matrix
     vector<vector<char>> keyMatrix = getKeyMatrix(key);
     //Dividing the message into pairs
     vector<string> pairs;
     for(int i=0;i<message.length();i+=2)
     {
          if(i+1 < message.length())
          {
               if(message[i]==message[i+1])
               {
                    string s = "";
                    s += message[i];
                    s += 'X';
                    pairs.push_back(s);
                    i-=1;
               }
               else
               {
                    string s = "";
                    s+=message[i];
                    s+=message[i+1];
                    pairs.push_back(s);
               }

          }
          else
          {
               string s = "";
               s += message[i];
               s += 'X';
               pairs.push_back(s);

          }
     }
     //Encrypting the message using Playfair cipher
     string ciphertext = "";
     for(auto s:pairs)
     {
          pair<int,int> first = getPosition(s[0],keyMatrix);
          pair<int,int> second = getPosition(s[1],keyMatrix);
          //Same row
          if(first.first == second.first)
          {
               int i1 = first.first;
               int i2 = second.first;
               int j1 = (first.second + 1) % 5;
               int j2 = (second.second + 1) % 5;
               ciphertext += keyMatrix[i1][j1];
               ciphertext += keyMatrix[i2][j2];
          } //Else if same column
          else if(first.second == second.second)
          {
               int i1 = (first.first + 1) % 5;
               int i2 = (second.first + 1) % 5;
               int j1 = first.second;
               int j2 = second.second;
               ciphertext += keyMatrix[i1][j1];
               ciphertext += keyMatrix[i2][j2];
          } //Else different row and column
          else
          {
               int i1 = first.first;
               int j1 = second.second;
               int i2 = second.first;
               int j2 = first.second;
               ciphertext += keyMatrix[i1][j1];
               ciphertext += keyMatrix[i2][j2];
          }
     }
     cout<<"Encrypted Message is: "<<ciphertext<<endl;
}

void decrypt(string message, string key)
{
     //Getting the key matrix
     vector<vector<char>> keyMatrix = getKeyMatrix(key);
     //Dividing the message into pairs
     vector<string> pairs;
     for(int i=0;i<message.length();i+=2)
     {
          string s = "";
          s += message[i];
          s += message[i+1];
          pairs.push_back(s);
     }
     //Decrypting the message using Playfair cipher
     string decipher = "";
     for(auto s:pairs)
     {
          pair<int,int> first = getPosition(s[0],keyMatrix);
          pair<int,int> second = getPosition(s[1],keyMatrix);
          //Same row
          if(first.first == second.first)
          {
               int i1 = first.first;
               int i2 = second.first;
               int j1 = (first.second - 1) % 5;
               if(j1 < 0)
                    j1+=5;
               int j2 = (second.second - 1) % 5;
               if(j2 < 0)
                    j2+=5;
               decipher += keyMatrix[i1][j1];
               decipher += keyMatrix[i2][j2];
          } //Else if same column
          else if(first.second == second.second)
          {
               int i1 = (first.first - 1) % 5;
               if(i1 < 0)
                    i1+=5;
               int i2 = (second.first - 1) % 5;
               if(i2 < 0)
                    i2+=5;
               int j1 = first.second;
               int j2 = second.second;
               decipher += keyMatrix[i1][j1];
               decipher += keyMatrix[i2][j2];
          } //Else different row and column
          else
          {
               int i1 = first.first;
               int j1 = second.second;
               int i2 = second.first;
               int j2 = first.second;
               decipher += keyMatrix[i1][j1];
               decipher += keyMatrix[i2][j2];
          }
     }
     cout<<"Decrypted Message is: "<<decipher<<endl;
     cout<<"*Note: \n1. Wherever there is 'I', there is a possibility of existence of 'J' at that position as well..."<<endl;
     cout<<"2. 'X' can be ignored or not based on your intuition..."<<endl;
}

int main()
{
     string key,message;
     cout<<"Implementation of Playfair cipher!!"<<endl;
     int choice;
     do
     {
          cout<<"\n1 - Encryption\n2 - Decryption"<<endl;
          cout<<"Choice (Press 0 to quit): ";
          cin>>choice;
          switch(choice)
          {
               case 0:   break;
               case 1:   cout<<"Enter the key: ";
                         cin>>key;
                         cout<<"Enter the message to encrypt: ";
                         cin>>message;
                         encrypt(message,key);
                         break;
               case 2:   cout<<"Enter the message to decrypt: ";
                         cin>>message;
                         cout<<"Enter the key: ";
                         cin>>key;
                         decrypt(message,key);
                         break;
               default:  cout<<"No option available for this choice..."<<endl;
          }
     }while(choice != 0);
     return 0;
}

