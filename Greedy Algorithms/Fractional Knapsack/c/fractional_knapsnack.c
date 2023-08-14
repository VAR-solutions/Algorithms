#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int ll;
typedef unsigned long long int llu;
typedef long double ld;

ll* newArr(llu n){
	return (llu*)malloc(n*sizeof(llu));
}

void fillArr(ll* arr, llu n, char* msg){
	printf("%s\n", msg);
	for(llu i=0; i<n; i++)
		scanf("%lld", (arr+ i));
}

void fetchSize(llu* size, char* msg){
	printf("%s ", msg);
	llu n; scanf("%lld", size);
}

void fill(ll* w, ll* v, llu n){
	printf("Drop the values in foll. format,\n  <val> <wt>\n");
	for(llu i=0; i<n; i++){
		printf("%llu. ", (i+1));
		scanf("%lld %lld", (v+i), (w+i));
	}
}

void swap(ll* a, ll* b){
	ll temp = *a;
	*a = *b;
	*b = temp;
}

void swap_d(ld* a, ld* b){
	ld temp = *a;
	*a = *b;
	*b = temp;
}

ll fix_pivot(ll* w, ld* v, ll l, ll r){
	ll pivot = v[r], ind = l-1;
	for(ll i=l; i<r; i++){
		if(v[i]>=pivot){
			ind++;
			swap_d(v+i, v+ind);
			swap(w+i, w+ind);
		}
	}
	swap_d(v+(++ind), v+r);
	swap(w+ind, w+r);
	return ind;
}

void quicksort(ll* w, ld* v, ll l, ll r){
	if(l<r){
		ll pi = fix_pivot(w, v, l, r);
		quicksort(w, v, l, pi-1);
		quicksort(w, v, pi, r);
	}
}

void jam_knapsnack(ll* w, ll* v, ll n, ll size){
	ld* effval = (ld*)malloc(n*sizeof(ld)); ll item =0; ld loot =0;
	for(ll i =0; i<n; i++)
		effval[i] = (ld)v[i]/w[i];
	
	quicksort(w, effval, 0, n-1);

	while(size>0 && item < n){
		if(w[item] <= size){
			size -= w[item];
			loot += w[item]*effval[item];
		}
		else{
			loot += size*effval[item];
			size = 0;
		}
		item++;
	}

	for(int i =0; i<20; i++)
		printf("~");
	// fix(&loot);
	printf("\nknapsnack volume left-> %lld\nTotal loot-> %.4Lf\n", size, loot);
}

int main(void){
	llu n, size; 
	fetchSize(&n, "Number of food items? ");
	fetchSize(&size, "Size of knapsnack? ");

	ll* weight = newArr(n);
	ll* value  = newArr(n);
	fill(weight, value, n);

	jam_knapsnack(weight, value, (ll)n, (ll)size);
	free(weight); free(value);

	return 0;
}