/*
File : matrik1.cpp
Deskripsi : Program sederhana untuk membuat matriks bentuk segitiga */
/* Dibuat oleh 	: Chandra Abdul Fattah / 141511038 */
/* Tanggal 		: 17-11-2014 */

#include<stdio.h>
int a[4][3];
int i,j;
main(){
	for(i=1;i<=3;i++){
		for(j=1;j<=5-i;j++){
			a[i][j]=i;
			printf("%d ",a[i][j]);
		}
		printf("\n \n");
	}
}
