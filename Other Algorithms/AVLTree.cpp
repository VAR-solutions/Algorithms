#include <iostream>
 
using namespace std;

class node{

  public:

  int val;
  int height;
  node* left;
  node* right;

  node(int val,node*left,node*right){
    this->val=val;
    this->left=left;
    this->right=right;
  }

};


class avl{

  public:

  node* root;
  int num;
  bool ins;
  //int *arr;
  int arr[300000];
  int aux;

  avl(){
    num=0;
    root=NULL;
    //arr=NULL;
    ins=false;
  }

  int getbalance(node*rt){
    int hleft;
    int hright;
    if(rt->left==NULL) hleft=-1;
    else hleft=rt->left->height;
    if(rt->right==NULL) hright=-1;
    else hright=rt->right->height;
    int balance=hleft-hright;
    //cout<<"height left right"<<hleft<<" "<<hright<<endl;
    return balance;
  }

  void getheight(node*rt){
    int hleft;
    int hright;
    if(rt->left==NULL) hleft=-1;
    else hleft=rt->left->height;
    if(rt->right==NULL) hright=-1;
    else hright=rt->right->height;
    rt->height=1+max(hright,hleft);
  }

  node* rotright(node* rt){
    node* l=rt->left;
    node* lr=l->right;
    l->right=rt;
    rt->left=lr;
    getheight(rt);
    getheight(l);
    return l;
  }

  node*rotleft(node*rt){
    node* r=rt->right;
    node* rl=r->left;
    r->left=rt;
    rt->right=rl;
    getheight(rt);
    getheight(r);
    return r;
  }

  node* insertr(node* no,int k){
    if(no==NULL) {
      no=new node(k,NULL,NULL);
      return no;
    }
    else if(k<no->val){
      no->left=insertr(no->left,k);
    }
    else{
      no->right=insertr(no->right,k);
    }
    getheight(no);
    int balance=getbalance(no);

    if(balance>1&&k<no->left->val){
      return rotright(no);
    }
    else if(balance<-1&&k>=no->right->val){
      return rotleft(no);
    }
    else if(balance>1&&k>=no->left->val){
      no->left=rotleft(no->left);
      return rotright(no);
    }
    else if(balance<-1&&k<no->right->val){
      no->right=rotright(no->right);
      return rotleft(no);
    }
    //cout<<"nao balanceou"<<endl;
    return no;
  }

  void insert(int k){
    //cout<<"dale"<<endl;
    ins=false;
    //cout<<"dakl"<<endl;
    if(this->root==NULL) {
      //cout<<"dale"<<endl;
      this->root=new node(k,NULL,NULL);
      num++;
    }
    else if(k<this->root->val){
      this->root->left=insertr(root->left,k);
      num++;
    }
    else{
      this->root->right=insertr(root->right,k);
      num++;
    }
    getheight(root);
    int balance=getbalance(root);
    //cout<<"balance "<<balance<<endl;
    if(balance>1&&k<root->left->val){
      root= rotright(root);
    }
    else if(balance<-1&&k>=root->right->val){
      root= rotleft(root);
    }
    else if(balance>1&&k>=root->left->val){
      root->left=rotleft(root->left);
      root= rotright(root);
    }
    else if(balance<-1&&k<root->right->val){
      root->right=rotright(root->right);
      root= rotleft(root);
    }
  }

  void getprer(node* rt){
    if(rt!=NULL){
      getprer(rt->left);
      arr[aux]=rt->val;
      aux++;
      getprer(rt->right);
    }
  }

  void getpre(){
    if(!ins){
      aux=0;
      ins=true;
      //delete arr;
      //arr=new int[num];
      getprer(root->left);
      arr[aux]=root->val;
      aux++;
      getprer(root->right);
    }
  }

  int Bisearch(int k){
    //cout<<"nha"<<endl;
    
    /*int i;
    cout<<"root "<<root->val<<endl;
    for(i=0;i<num;i++){
      cout<<arr[i]<<endl;
    }*/
    int r=num;
    int l=0;
    int m;
    while(l<=r){
      m=(l+r)/2;
      if(k==arr[m]){
        //cout<<1+m<<endl;
        printf("%d\n",m+1);
        return m;
      }
      else if(k>arr[m]){
        l=m+1;
      }
      else r=m-1;
    }
    //cout<<"Data tidak ada"<<endl;
    printf("Data tidak ada\n");
    return -1;
  }

};

int main() {
  avl t;
  int qr;
  int req;
  int val;
  for(cin>>qr;qr>0;qr--){
    //cin>>req;
    scanf("%d",&req);
    //cin>>val;
    scanf("%d",&val);
    if(req==1){
      t.insert(val);
    }
    else if(req==2){
      t.getpre();
      t.Bisearch(val);
    }
  }
}
