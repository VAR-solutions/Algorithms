//Pembelian Pulsa

#include <stdio.h>

void main () {
	system("color 1f");
	/* Deklarasi */
	long int pulsa=0, nominal=0;
	int Ya=2;
	char nomor[20];
	
	/* Algoritma */
	printf("\t�����������������������������������������������������������ͻ\n");
    printf("\t����������������������������������������������������������ͻ�\n");
    printf("\t��            Pilihan Nominal Pulsa                        ��\n");
    printf("\t�� 1. 5,000                               4. 50,000        ��\n");
    printf("\t�� 2. 10,000                              5. 100,000       ��\n");
    printf("\t�� 3. 20,000                              6. 200,000       ��\n");
    printf("\t����������������������������������������������������������ͼ�\n");
    printf("\t�����������������������������������������������������������ͼ\n\n");
    while((Ya==2)  && (nominal!=6)) {
		printf("Masukkan nomor Anda: "); scanf("%s", &nomor);
    	printf("Pilih nominal pulsa: "); scanf("%d", &nominal);
		printf("\�����������������������������������������������������������������\n");
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
		printf("\�����������������������������������������������������������������\n\n");
	}
    printf("Pengisian pulsa %d ke nomor %s berhasil\n\n", pulsa, nomor);
    printf("\�����������������������������������������������������������������\n");
}
