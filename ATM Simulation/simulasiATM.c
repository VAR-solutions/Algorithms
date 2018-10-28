#include <stdio.h>
#include<string.h>
int cek=0,saldo=5000000,pengeluaran=0;
main(){
	int y;
	system("color 1e");
	if(cek==0){
	printf("==================================================================\n");
	printf("============== Selamat datang Di Bank bank bank ==================\n");
	printf("==================================================================\n");
	login();
	system("cls");
	printf("loading...");
	sleep(1);
	system("cls");
	}
	printf("==================================================================\n");
	printf("============== Selamat datang Di Bank bank bank ==================\n");
	printf("==================================================================\n");
	printf("1> PENARIKAN\t\t\t\t\tINFO SALDO\t<4\n");
	printf("2> TRANSFER\t\t\t\t\tUBAH PIN\t<5\n");
	printf("3> BELI PULSA\t\t\t\t\tKELUAR\t\t<6\n");
	scanf("%d",&y);
	switch(y){
		case 1 : penarikan();break;
		case 2 : transfer();break;
		case 3 : pulsa();break;
		case 4 : saldo1();break;
		case 5 : pin();break;
		case 6 : keluar();break;
	}
	return 0;
}
login(){
	char pass[10];
	printf("Masukkan kartu Anda\n");
	system("pause");
	do{
		printf("Masukkan pin Anda\n");
		scanf("%s",&pass);
		if(strcmp(pass,"123456")==0){
			cek=1;
		}else{
			printf("Pin yang anda masukkan salah, Silahkan masukkan kembali\n");
		}
	}while(cek==0);
}
saldo1() {
	system("color 1e");
	/* Deklarasi */
	/* Algoritma */
		saldo=saldo-pengeluaran;
		printf("Saldo Anda: Rp%d\n", saldo);
		system("pause");
	printf("loading... mengarahkan kembali ke menu utama");
		sleep(2);
		system("cls");
		main();
}
pulsa() {
	system("color 1e");
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
    pengeluaran=pengeluaran+pulsa;
    system("pause");
    printf("loading... mengarahkan kembali ke menu utama");
		sleep(2);
		system("cls");
		main();
}
pin(){
	char pass[10],tmp[10];
	system("cls");
	printf("Masukkan pin baru anda\n");
	scanf("%s",&pass);
	printf("Konfirmasi pin baru\n");
	scanf("%s",&tmp);
	if(strcmp(pass,tmp)==0){
		printf("Pin telah diperbarui\n");
		printf("loading... mengarahkan kembali ke menu utama");
		sleep(1);
		system("cls");
		main();
	}else{
		printf("Pin tidak sesuai, Pin tidak berhasil diperbarui\n");
		sleep(2);
		printf("loading...");
		sleep(1);
		system("cls");
		pin();
	}
}
transfer() {
	system("color 1e");
	/* Deklarasi */
	char rek[50];
	long int Ya=2,transfer;
	
	
	/* Algoritma */
	while(Ya==2) {
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
	printf("Masukkan no. rekening: "); scanf("%s", &rek);
	printf("Masukkan nominal uang yang akan Anda transfer: "); scanf("%d", &transfer);
	printf("\n");
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
	if(transfer<=saldo)	{
		printf("Apakah anda yakin akan mentransfer uang dengan:\n", transfer, rek);
		printf("Nominal\t\t: %d\n", transfer);
		printf("No. rekening\t: %s\n", rek);
		printf("Nama\t\t: Dira\n");
		printf("1. Ya 2. Batal\n");
		scanf("%d", &Ya);
	} else {
		printf("Saldo Anda tidak mencukupi\n");
	}
	}
	printf("\n");
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n\n");
	printf("Transaksi berhasil\n\n");
	printf("\อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
	pengeluaran=pengeluaran+transfer;
	system("pause");
	printf("loading... mengarahkan kembali ke menu utama");
		sleep(2);
		system("cls");
		main();
}

keluar(){
	int x;
	printf("Yakin Keluar? \n1>ya \t 2>tidak\n");
	scanf("%d",&x);
	if(x==1){
		system("cls");
		printf("Terimakasih atas kunjungan Anda\n");
		printf("Silahkan ambil kembali kartu Anda\n");
	}else{
		printf("loading... mengarahkan kembali ke menu utama");
		sleep(1);
		system("cls");
		main();
	}
}
penarikan(){
	long int nom1,nom2,nom3,bil,total,jumlahUang;
	int seratusRibu=0, limaPuluh=0, duaPuluh=0;
	printf("Masukkan jumlah uang yang akan ditarik:\n");
	scanf("%d", &jumlahUang);
	
	if (jumlahUang <= 5000000){
		if(jumlahUang<saldo){
		seratusRibu = jumlahUang/100000;
		limaPuluh = (jumlahUang - (seratusRibu*100000)) / 50000;
		duaPuluh = (jumlahUang-(seratusRibu*100000)-(limaPuluh*50000))/20000;
		
		if ((jumlahUang-(seratusRibu*100000)-(limaPuluh*50000)-(duaPuluh*20000)) != 0){
			limaPuluh = 0;
			duaPuluh = (jumlahUang-(seratusRibu*100000)) / 20000;
		}
		
		if ((jumlahUang-(seratusRibu*100000)-(limaPuluh*50000)-(duaPuluh*20000)) != 0){
			seratusRibu-=1;
			limaPuluh +=1;
			duaPuluh = (jumlahUang-(seratusRibu*100000)-(limaPuluh*50000))/20000;
		}
		
		if ((((jumlahUang-(seratusRibu*100000)-(duaPuluh*20000)) == 0) || ((jumlahUang-(limaPuluh*50000)-(duaPuluh*20000)) == 0) || ((jumlahUang-(seratusRibu*100000)-(limaPuluh*50000)-(duaPuluh*20000)) == 0)) && (seratusRibu>=0)){
				if (duaPuluh > 0){
					printf("%d lembar uang Rp. 20,000,-\n", duaPuluh);
				}
				if (limaPuluh > 0){
					printf("%d lembar uang Rp. 50,000,-\n", limaPuluh);
				}
				if (seratusRibu > 0){
					printf("%d lembar uang Rp. 100,000,-\n", seratusRibu);
				}
		} else {
			printf("Nominal tidak valid\n");
		}
	}else{
		printf("Saldo tidak mencukupi\n");
	}
	} else {
		printf("Nominal maksimal Rp. 5,000,000,-\n");
	}
	printf("Terbilang : ");
	total=jumlahUang;
	if(total>=1000000){
		bil=total / 1000000;
		total=total % 1000000;
			switch(bil){
				case 1 : printf("se");break;
				case 2 : printf("dua "); break;
				case 3 : printf("tiga "); break;
				case 4 : printf("empat "); break;
				case 5 : printf("lima "); break;
				case 6 : printf("enam "); break;
				case 7 : printf("tujuh "); break;
				case 8 : printf("delapan "); break;
				case 9 : printf("sembilan "); break;
			}
		printf("juta ");	
	}
	if(total>=100000){
		bil=total / 100000;
		total=total % 100000;
			switch(bil){
				case 1 : printf("se");break;
				case 2 : printf("dua "); break;
				case 3 : printf("tiga "); break;
				case 4 : printf("empat "); break;
				case 5 : printf("lima "); break;
				case 6 : printf("enam "); break;
				case 7 : printf("tujuh "); break;
				case 8 : printf("delapan "); break;
				case 9 : printf("sembilan "); break;
			}
		printf("ratus ");
	}
		if(total>=1000){
		bil=total;
			if (bil>10000 && bil<20000){
					bil=bil/1000 %10;
					switch(bil){
						case 1 : printf("se");break;
						case 2 : printf("dua "); break;
						case 3 : printf("tiga "); break;
						case 4 : printf("empat "); break;
						case 5 : printf("lima "); break;
						case 6 : printf("enam "); break;
						case 7 : printf("tujuh "); break;
						case 8 : printf("delapan "); break;
						case 9 : printf("sembilan "); break;
					}
					printf("belas ");	
			}else {
				if(bil>=20000 || bil==10000){
					bil=total/10000;
					total=total%10000;
					switch(bil){
						case 1 : printf("se");break;
						case 2 : printf("dua "); break;
						case 3 : printf("tiga "); break;
						case 4 : printf("empat "); break;
						case 5 : printf("lima "); break;
						case 6 : printf("enam "); break;
						case 7 : printf("tujuh "); break;
						case 8 : printf("delapan "); break;
						case 9 : printf("sembilan "); break;
					}
					printf("puluh ");
				}
					bil=total/1000;
					switch(bil){
						case 1 : printf("satu ");break;
						case 2 : printf("dua "); break;
						case 3 : printf("tiga "); break;
						case 4 : printf("empat "); break;
						case 5 : printf("lima "); break;
						case 6 : printf("enam "); break;
						case 7 : printf("tujuh "); break;
						case 8 : printf("delapan "); break;
						case 9 : printf("sembilan "); break;
				}	
				}
					printf("ribu ");
				total=total % 1000;
		}
		bil=total;
		if(total>=100){
		bil=total / 100;
		total=total % 100;
			switch(bil){
				case 1 : printf("se");break;
				case 2 : printf("dua "); break;
				case 3 : printf("tiga "); break;
				case 4 : printf("empat "); break;
				case 5 : printf("lima "); break;
				case 6 : printf("enam "); break;
				case 7 : printf("tujuh "); break;
				case 8 : printf("delapan "); break;
				case 9 : printf("sembilan "); break;
			}
		printf("ratus ");
		}
		bil=total;
			if (bil>10 && bil<20){
					bil=bil %10;
					switch(bil){
						case 1 : printf("se");break;
						case 2 : printf("dua "); break;
						case 3 : printf("tiga "); break;
						case 4 : printf("empat "); break;
						case 5 : printf("lima "); break;
						case 6 : printf("enam "); break;
						case 7 : printf("tujuh "); break;
						case 8 : printf("delapan "); break;
						case 9 : printf("sembilan "); break;
					}
					printf("belas ");	
			}else {
				if(bil>=20){
					bil=total/10;
					total=total%10;
					switch(bil){
						case 1 : printf("se");break;
						case 2 : printf("dua "); break;
						case 3 : printf("tiga "); break;
						case 4 : printf("empat "); break;
						case 5 : printf("lima "); break;
						case 6 : printf("enam "); break;
						case 7 : printf("tujuh "); break;
						case 8 : printf("delapan "); break;
						case 9 : printf("sembilan "); break;
					}
					printf("puluh ");
				}
					bil=total;
					switch(bil){
						case 1 : printf("satu ");break;
						case 2 : printf("dua "); break;
						case 3 : printf("tiga "); break;
						case 4 : printf("empat "); break;
						case 5 : printf("lima "); break;
						case 6 : printf("enam "); break;
						case 7 : printf("tujuh "); break;
						case 8 : printf("delapan "); break;
						case 9 : printf("sembilan "); break;
				}	
				}
	printf("rupiah\n");
	pengeluaran=pengeluaran+jumlahUang;
	system("pause");
	printf("loading... mengarahkan kembali ke menu utama");
		sleep(2);
		system("cls");
		main();
}
