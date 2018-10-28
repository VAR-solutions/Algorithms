/*
File : penjumlahanMatriks.cpp
Deskripsi : Program sederhana untuk mencari hasil jumlah dari setiap elemen dalam array */
/* Dibuat oleh 	: Chandra Abdul Fattah / 141511038 */
/* Tanggal 		: 17-11-2014 */

#include<stdio.h>
#include<math.h>
int i,j, elemenTidakNol;
float rataData,jumlahData,jumlahElemen;
int a[4][4]={
				{1,0,0,0},
				{0,2,0,0},
				{0,0,3,0},
				{0,0,0,4}
			};
main(){
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			jumlahData = jumlahData+a[i][j];
			if(a[i][j]!=0){
				elemenTidakNol = elemenTidakNol+1;
			}
			jumlahElemen = jumlahElemen+1;
			printf(" %d ", a[i][j]);
		}
		printf("\n \n");
	}
	rataData = jumlahData/jumlahElemen;
	printf("Jumlah elemen di array a ada = %.0f \n",jumlahElemen);
	printf("Hasil penjumlahan dari data array a adalah = %.0f \n",jumlahData);
	printf("Data yang tidak 0 dari data array a ada = %d ",elemenTidakNol);
	printf("data \n");
	printf("Rata - rata dari jumlah data dari array a adalah = %.3f \n", rataData);
}
