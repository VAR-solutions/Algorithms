//cek saldo

#include <stdio.h>

void main () {
	system("color 1f");
	/* Deklarasi */
	long int uang=5000000, pengeluaran=0;
	
	/* Algoritma */
	if(pengeluaran==0) {
		printf("Saldo Anda: Rp%d\n", uang);
	} else {
		uang=uang-pengeluaran;
		printf("Saldo : Rp%d\n", uang);
	}
}
