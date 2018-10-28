//Transfer

#include <stdio.h>

void main () {
	system("color 1f");
	/* Deklarasi */
	char transfer[50], rek[50];
	int Ya=2;
	
	
	/* Algoritma */
	while(Ya==2) {
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
	printf("Masukkan no. rekening: "); scanf("%s", &rek);
	printf("Masukkan nominal uang yang akan Anda transfer: "); scanf("%s", &transfer);
	printf("\n");
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
		printf("Apakah anda yakin akan mentransfer uang dengan:\n", transfer, rek);
		printf("Nominal\t\t: %s\n", transfer);
		printf("No. rekening\t: %s\n", rek);
		printf("Nama\t\t: Dira\n");
		printf("1. Ya 2. Batal\n");
		scanf("%d", &Ya);
	}
	printf("\n");
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
	printf("Transaksi berhasil\n\n");
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
}
