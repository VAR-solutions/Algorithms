#include <bits/stdc++.h>
using namespace std;


struct Heap{
    int *vet, max_size, curr_size;
};

Heap *create_heap(int tam){
  Heap *h = new Heap();
  h->vet = (int *) malloc((tam+1)*sizeof(int));
  h->max_size = tam+1;
  h->curr_size = 1;
  return h;
}

void clear(Heap *h){
  free(h->vet);
  free(h);
}

void heapify(Heap *h, int k){
  int v = h->vet[k];
  bool heap = false;
  while(!heap && 2*k<=h->curr_size-1){
    int j = 2*k;
    if(j<h->curr_size-1){
      if(h->vet[j]<h->vet[j+1]) j++;
    } if (v>= h->vet[j]) heap = true;
    else{
      h->vet[k] = h->vet[j];
      k = j;
    }
  }
  h->vet[k] = v;
}

void bottom_up(Heap *h){
  for(int i=(h->curr_size-1)/2; i>=1; i--){
    heapify(h, i);
  }
}

void remove_heap(Heap *h){
  if(h->curr_size <= 1) return;
  swap(h->vet[1], h->vet[h->curr_size-1]);
  h->curr_size--;
  heapify(h, 1);
}

void heapify2(Heap *h, int k){
	int v = h->vet[k];
	int heap = 0;
	while(!heap && k/2 >= 1){
		int j = k/2;
		if (h->vet[j] >= h->vet[k]){
			heap = 1;
		}
		else {
			swap(h->vet[j], h->vet[k]);
			k = j;
		}
	}
}

void insert(Heap *h, int k){
    h->vet[h->curr_size] = k;
    heapify2(h, h->curr_size);
    h->curr_size++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Heap *h = create_heap(n);
    for(int i=1, a; i<=n; i++){
        cin >> a;
        h->vet[i] = a;
        h->curr_size++;
    }
    bottom_up(h);
    cout << "BOTTOM-UP:" << endl;
    while(h->curr_size>1){
        cout << "TOPO = " << h->vet[1] << endl;
        remove_heap(h);
    }
    cout << endl << endl;
    int tam;
    cin >> tam;
    clear(h);
    Heap *c = create_heap(tam);
    for(int i=1, a; i<=tam; i++){
        cin >> a;
        insert(c, a);
    }
    cout << "TOP-DOWN:" << endl;
    while(c->curr_size>1){
        cout << "TOPO = " << c->vet[1] << endl;
        remove_heap(c);
    }
    clear(c);
    return 0;
}
