#include <iostream>
#include <stdlib.h>
using namespace std;

class heap{
  public:
  int *arr=NULL;
  int tam;
  
  heap(){
    arr=new int[1];
    tam=0;
  }

  void bottomup(int *inn,int n){
    this->arr=inn;
    int i;
    int k;
    int v;
    bool h;
    for(i=n/2;i>=1;i--){
      k=i;
      v=arr[k];
      h=false;
      while(!h&&2*k<=n){
        int j=2*k;
        if(j<n){
          if(arr[j]<arr[j+1]) j=j+1;
        }
        if(v>=inn[j]){
          h=true;
        }
        else{
          arr[k]=arr[j];
          k=j;
        }
      }
      arr[k]=v;
    }
  }

  void insert(int k){
    tam++;
    realloc(arr,1+tam);
    arr[tam]=k;
    //cout<<arr[tam]<<" "<<tam<<endl;
    int l=tam;
    int f=l/2;
    while(f>=1&&arr[f]<arr[l]){
      //cout<<"dale "<<k<<endl;
      swap(arr[l],arr[f]);
      l=f;
      f=l/2;
    }
  }

  void remove(){
    swap(arr[1],arr[tam]);
    realloc(arr,1+tam);
    tam--;
    int j=1;
    int f=2;
    bool h=true;

    while(h){
      if(f<tam){
        if(arr[f]<arr[f+1]) f=f+1;
      }
      if(arr[j]<arr[f]){
        swap(arr[j],arr[f]);
        j=f;
        f=2*j;
      }
      else h=false;
    }


  }

  void clear(){
    tam=0;
    delete[] arr;
    arr=new int[1];
  }

};



int main() {
  int a[]={0,1,7,3,9,4,5,10};
  heap h;
  /*h.bottomup(a, 7);
  cout<<"dale"<<endl;
  for(int i=1;i<8;i++){
    cout<<a[i]<<endl;
  }*/
  h.insert(10);
  for(int i=1;i<h.tam+1;i++){
    cout<<h.arr[i]<<" ";
  }
  cout<<endl;
  h.insert(3);
  for(int i=1;i<h.tam+1;i++){
    cout<<h.arr[i]<<" ";
  }
  cout<<endl;
  h.insert(8);
  h.insert(4);
  for(int i=1;i<h.tam+1;i++){
    cout<<h.arr[i]<<" ";
  }
  cout<<endl;
  h.insert(11);
  for(int i=1;i<h.tam+1;i++){
    cout<<h.arr[i]<<" ";
  }
  cout<<endl;
  h.remove();
  for(int i=1;i<h.tam+1;i++){
    cout<<h.arr[i]<<" ";
  }
  cout<<endl;

}
