/*
File : kmposit3.cpp
/* Deskripsi 	: program sederhana untuk input data matriks secara diagonal */
/* Dibuat oleh 	: Chandra Abdul Fattah / 141511038 */
/* Tanggal 		: 17-11-2014 */

#include<stdio.h>
int a[4][4],i,j;
main(){
	i=1;
	j=1;
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			if(i==j){
				a[i][j]=i;
			}
			else{
				a[i][j]=0;
			}
			printf("%d ",a[i][j]);
		}
		printf("\n \n");
	}
}
