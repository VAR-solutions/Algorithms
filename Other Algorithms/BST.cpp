#include <iostream>

using namespace std;

class node{

  public:

  int val;
  int element;
  node* left;
  node* right;

  node(int val,node*left,node*right){
    this->val=val;
    this->left=left;
    this->right=right;
  }

};


class bst{

  public:

  node* root;
  int num;

  bst(){
    num=0;
    root=NULL;
  }

  node* insertr(node* no,int k){
    if(no==NULL) {
      no=new node(k,NULL,NULL);
      return no;
    }
    if(k<no->val){
      no->left=insertr(no->left,k);
      return no;
    }
    else{
      no->right=insertr(no->right,k);
      return no;
    }

  }

  void insert(int k){
    if(this->root==NULL) {
      this->root=new node(k,NULL,NULL);
      num++;
      exit(0);
    }
    if(k<this->root->val){
      this->root->left=insertr(root->left,k);
      num++;
      exit(0);
    }
    else{
      this->root->right=insertr(root->right,k);
      num++;
      exit(0);
    }
    exit(-1);
  }

  bool findr(node*no,int k){
    if(no==NULL) return false;
    if(k==this->root->val) return true;
    if(k<no->val){
        return findr(no->left,k);
      }
      else{
        return findr(no->right,k);
      }

  }

  bool find(int k){
    if(num>0){
      if(k==this->root->val) return true;

      if(k<this->root->val){
        return findr(this->root->left,k);
      }
      else{
        return findr(this->root->right,k);
      }
    }
    return false;
  }
  

};

int main() {
  string str;
  cin>>str;
  int*nha=NULL;
  nha[55]=3;
}
