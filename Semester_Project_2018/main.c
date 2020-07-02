#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

static int matris[4][4];
int skor = 0;
int i = 0, j = 0;
int a = 0;
int k = 0;
int bos = 0;
int m, tmp;
char tus;

int random_sayi() {  //diziden random sayi uretir.
	int dizi[4] = { 2,2,2,4 };
	k = rand() % 4;
	k = dizi[k];
	return k;
}

void EkranaYazdir() {
	//Ekrana yazdýrma 
	printf(" \n ______ ______ ______ ______ \n");
	for (i = 0; i < 4; i++) {
		printf("|      |      |      |      |\n");
		printf("|");
		for (j = 0; j < 4; j++) {
			if (matris[i][j] == 0) {
				printf("%4c  |", ' ');
			}
			else {
				printf(" %4d |", matris[i][j]);
			}
		}
		printf("\n");
		printf("|______|______|______|______|\n");
	}
	//printf(" Skorunuz:%d\n",skor);
}

void OyunuBitirme(){   //OYUNU BITIRME FONKSIYONU
	
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
		   if( matris[i][j] != 0) {
				system("CLS");
				printf("  Skorunuz:%d\n",skor);
			}
		}
	}
}

void Boskutucuk() {  //BOS KUTUCUK FONKSIYONU BOS MATRÝS YERLERÝNÝ TESPÝT EDER.
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			if (matris[i][j] == 0) {
				bos = bos + 1;
			} 	
		}
	}
}

void OyunuBaslat() { //OYUNU BASLATMA FONKSIYONU  2 RANDOM SAYI SAYIYLA OYUNU BASLATIR.
	int n = 0;
	srand(time(NULL));
	for (n = 0; n < 2; n++) {
		a = random_sayi();
		i = rand() % 4;
		j = rand() % 4;
		while (matris[i][j] != 0) {
			i = rand() % 4;
			j = rand() % 4;
		}
		matris[i][j] = a;
	}
}

void RandomSayiAtama() { //RANDOM SAYI ATMA FONKSIYONU

	srand(time(NULL));
	a = random_sayi();
	i = rand() % 4;
	j = rand() % 4;
	while (matris[i][j] != 0) {
		i = rand() % 4;
		j = rand() % 4;
	}
	matris[i][j] = a;
}

void OyunuOyna() {  //OYUNU OYNAMA FONKSIYONU KLAVYEDEN GIRILEN TUÞLARLA OYUNU OYNATIR.
	char tus1 = _getch();
	while ((tus1 != 'e') && (tus1 != 'E')) {
		if ((tus1 == 'w') || (tus1 == 'W')) {
			system("CLS");
			printf("\n\nw'ye bastiniz\n");
			//yukari siralama
			for (i = 0; i<4; i++) {
				for (j = 1; j<4; j++) {
					if (matris[j][i] != 0) {
						for (m = 0; m<j; m++) {
							if (matris[m][i] == 0) {
								tmp = matris[j][i];
								matris[j][i] = matris[m][i];
								matris[m][i] = tmp;
							}
						}
					}
				}
			}
			//yukari toplama
			for (i = 0; i<4; i++) {
				for (j = 0; j<3; j++) {
					if (matris[j][i] == matris[j + 1][i]) {
						matris[j][i] = matris[j][i] * 2;
						skor = skor + matris[j][i];
						for (m = j + 1; m<3; m++) {
							matris[m][i] = matris[m + 1][i];
						}
						matris[3][i] = 0;
					}
				}
			}
			//Bos kutucuk kontrolu
			Boskutucuk();
			OyunuBitirme();
			//random sayi atama
			if (bos != 0) {
				RandomSayiAtama();
			}
		
			EkranaYazdir();
		}
		else if ((tus1 == 's') || (tus1 == 'S')) {
			system("CLS");
			printf("\n\ns'ye bastiniz\n");
			//asagi siralama
			for (i = 0; i<4; i++) {
				for (j = 2; j >= 0; j--) {
					if (matris[j][i] != 0) {
						for (m = 3; m>j; m--) {
							if (matris[m][i] == 0) {
								tmp = matris[j][i];
								matris[j][i] = matris[m][i];
								matris[m][i] = tmp;
							}
						}
					}
				}
			}
			//asagi toplama
			for (i = 0; i<4; i++) {
				for (j = 3; j>0; j--) {
					if (matris[j][i] == matris[j - 1][i]) {
						matris[j][i] = matris[j][i] * 2;
						skor = skor + matris[j][i];
						for (m = j - 1; m>0; m--) {
							matris[m][i] = matris[m - 1][i];
						}
						matris[0][i] = 0;
					}
				}
			}
			//Boskutucuk kontrolü
			Boskutucuk();
			OyunuBitirme();
			//Random sayi atama
			if (bos != 0) {
				RandomSayiAtama();
			}
			EkranaYazdir();
		}
		else if ((tus1 == 'a') || (tus1 == 'A')) {
			system("CLS");
			printf("\n\na'ya bastiniz\n");
			//sola siralama
			for (i = 0; i<4; i++) {
				for (j = 1; j<4; j++) {
					if (matris[i][j] != 0) {
						for (m = 0; m<j; m++) {
							if (matris[i][k] == 0) {
								tmp = matris[i][j];
								matris[i][j] = matris[i][m];
								matris[i][m] = tmp;
							}
						}
					}
				}
			}
			//sol toplama
			for (i = 0; i<4; i++) {
				for (j = 0; j<4; j++) {
					if (matris[i][j] == matris[i][j + 1]) {
						matris[i][j] = matris[i][j] * 2;
						skor = skor + matris[j][i];
						for (m = j + 1; m<3; m++) {
							matris[i][m] = matris[i][m + 1];
						}
						matris[i][3] = 0;
					}
				}
			}
			// boskutucuk kontrolü
			Boskutucuk();
			OyunuBitirme();
			//Random sayi atama
			if (bos != 0) {
				RandomSayiAtama();
			}
			EkranaYazdir();
		}
		else if ((tus1 == 'd') || (tus1 == 'D')) {
			system("CLS");
			printf("\n\nd'ye bastiniz\n\n");
			//saga sýralama
			for (i = 0; i<4; i++) {
				for (j = 2; j >= 0; j--) {
					if (matris[i][j] != 0) {
						for (m = 3; m>j; m--) {
							if (matris[i][m] == 0) {
								tmp = matris[i][j];
								matris[i][j] = matris[i][m];
								matris[i][m] = tmp;
							}
						}
					}
				}
			}
			//saga toplama
			for (i = 0; i<4; i++) {
				for (j = 3; j>0; j--) {
					if (matris[i][j] == matris[i][j - 1]) {
						matris[i][j] = matris[i][j] * 2;
						skor = skor + matris[j][i];
						for (m = j - 1; m>0; m--) {
							matris[i][m] = matris[i][m - 1];
						}
						matris[i][0];
					}
				}
			}
			// boskutucuk kontrolü
			Boskutucuk();
			OyunuBitirme();
			//Random sayi atama
			if (bos != 0) {
				RandomSayiAtama();
			}
			EkranaYazdir();
		}
		tus1 = _getch();
	}

}


int main() {

	system(" color 3F ");
	printf(" \n\n       ____________*TETRÝSE HOSGELDINIZ*____________\n\n");
	printf("      'a-s-d-w' veya 'A-S-D-W' tuslariyla oynayiniz.\n  %c ");
	printf("  Ayrica baslatmak icin 'x' veya 'X' tuslarini kullaniniz.\n  %c ");
	printf("  Skorunuz: %d\n", skor);
	do {
		tus = _getch();
		if ((tus == 'x') || (tus == 'X')) {
			//system("CLS");
			OyunuBaslat();
			EkranaYazdir();
			OyunuOyna();
		}
		else {
			
			printf("lutfen duzgun tusa basiniz\n");
		}
	} while ((tus != 'e') && (tus != 'E'));
	
	return 0;
}


