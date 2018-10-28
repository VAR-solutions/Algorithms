#include<stdio.h>
#include"boolean.h"
int b,k,m,n,l;
int kesamaan;
boolean sama;
main(){
	//inisialisasi matriks
	m=3; //sebagai baris
	n=3; //sebagai kolom
	sama = true;
	int y[3][3] = {
				   {1,0,0},
				   {0,2,0},
				   {0,0,1}
			  };
	printf("\n \n");
	for(b=0;b<m;b++){
		for(k=0;k<n;k++){
			printf(" %d ",y[b][k]);
		}
		printf("\n \n");
	}
	printf("------------------------- \n");
	printf("Hasil pengecekan : \n");
	//cek baris = kolom?
	if(m==n){
		printf("- Baris dan kolom pada matriks sama \n");
		for(b=0;b<m;b++){
			for(k=0;k<n;k++){
			if(b==k){
				sama = sama && y[b][k]!=0;	
			}
			 else{
				sama = sama && y[b][k]==0;
			}		
		   }
		}
		if(sama){
			printf("- matriks ini diagonal");
		}
		else{
			printf("- bukan diagonal");
		}
		printf("\n");
		}
		
		//matriks simetri
		for(b=0;b<m;b++){
			for(k=0;k<n;k++){
				if(b!=k){
					if(y[b][k]==y[k][b]){
					kesamaan = kesamaan+1;
					}
				}
			}
		}
		kesamaan = kesamaan/2;
		if(kesamaan==m){
			printf("- matriks ini simetris");
		}	
		else{
		printf("Baris dan kolom pada matriks di atas tidak sama");
	}
}
