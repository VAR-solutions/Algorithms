#include<bits/stdc++.h>
using namespace std;
struct trie {
  struct trie *children[26];
  bool isend;
  trie () {
    memset(children,NULL,sizeof(children));
    isend = false;
  }
};

struct trie* root;
void insert( string s1){
  struct trie *curr = root;
  for(char ch : s1){
    int currindex = ch - 'a';
    if(curr->children[currindex] == NULL){
      curr->children[currindex] = new trie;
    }
    curr = curr->children[currindex];
  }
  curr->isend = true;
}

bool search(string s1){
  struct trie *curr = root;
  for(char ch : s1){
    int currindex = ch - 'a';
    if(curr->children[currindex]==NULL)
      return false;
    curr = curr->children[currindex];
  }
  return curr->isend;
}

int main() {
  root = new trie;
  insert("alex");
  insert("eric");
  insert("daniel");
  insert("zee");
  insert("zoi");
  insert("jonathon");
  insert("darek");
  insert("amly");
  string result = search("zoi") ? "Found" : "Not Found";
  std::cout << result << '\n';
  return 0;
}
