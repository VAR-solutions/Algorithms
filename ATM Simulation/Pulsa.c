//Pembelian Pulsa

#include <stdio.h>

void main () {
	system("color 1f");
	/* Deklarasi */
	long int pulsa=0, nominal=0;
	int Ya=2;
	char nomor[20];
	
	/* Algoritma */
	printf("\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
    printf("\tบษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออปบ\n");
    printf("\tบบ            Pilihan Nominal Pulsa                        บบ\n");
    printf("\tบบ 1. 5,000                               4. 50,000        บบ\n");
    printf("\tบบ 2. 10,000                              5. 100,000       บบ\n");
    printf("\tบบ 3. 20,000                              6. 200,000       บบ\n");
    printf("\tบศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผบ\n");
    printf("\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n");
    while((Ya==2)  && (nominal!=6)) {
		printf("Masukkan nomor Anda: "); scanf("%s", &nomor);
    	printf("Pilih nominal pulsa: "); scanf("%d", &nominal);
		printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
		switch (nominal) {
    		case 1 : pulsa=5000; Ya=1; break;
    		case 2 : pulsa=10000; Ya=1; break;
    		case 3 : pulsa=20000; Ya=1; break;
    		case 4 : pulsa=50000; Ya=1; break;
    		case 5 : pulsa=100000; Ya=1; break;
    		case 6 : pulsa=200000; Ya=1; break;
    		default : printf("Pilihan nominal tidak tersedia\n"); break;
    	}
    	if(Ya!=2) {
    		printf("Apakah Anda yakin akan mengisi pulsa %d ke nomor %s\n", pulsa, nomor);
    		printf("1. Ya 2. Batal\n");
    		scanf("%d", &Ya);
    	}
		printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
	}
    printf("Pengisian pulsa %d ke nomor %s berhasil\n\n", pulsa, nomor);
    printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
}
