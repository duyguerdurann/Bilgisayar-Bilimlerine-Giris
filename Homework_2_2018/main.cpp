#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

main(){
	int m; //De�i�kenler Tan�mland�
	int n;
	int a1,a,b,q,w,z,l,q1,w1;
	int oneandzero;
	int counter = 0;
	time_t t;
	 srand((unsigned) time(&t));
	printf("Bus Lines and Stops:\n");
	scanf("%d",&n);  // Bus Lines
	scanf("%d",&m);  // Bus Stops
		printf("\n");
	int matrix[n][m];  // Lines and Stops matrix
	for (int i=0;i<n;i++){  // matris i�ine 1 ve 0 atamalar� yap�ld�.
		for (int j=0;j<m;j++){
		/*	scanf("%d",&oneandzero);
			matrix[i][j] = oneandzero;*/
		matrix[i][j] = rand() % 2;
		}
	}  
	int sLines[n][2]; // 2 s�tunlu matris. �lkk s�tununda hatt�n yo�unluk de�eri, ikinci s�tununda hatt�n numaras� tutulacak.
	
	for (a=0;a<n;a++){ // bu d�ng�de hatt�n yo�unlu�u - 1 de�erlerinin toplam� - hesapland�
		for (b=0;b<m;b++){
			printf("%d ",matrix[a][b]);
			counter = counter + matrix[a][b]; // "counter" de�i�keni hattaki 1 lerin toplam de�erini hesaplay�p diziye atmak amac�yla sat�r�n tamam�n�n toplam�na e�itlendi.
		}
		printf("\n");
		sLines [a][2] = counter; // Hesaplanan de�er olu�turulan dizinin ilk s�tununa atand�
		counter = 0; // Di�er hatlar�n hesab� i�in saya� s�f�rland�.
		sLines [a][1] = a+1; // dizinini ikinci s�tununa hatt�n numaras� kaydedildi.
	}
	
		printf("\n");
	// A�a��daki k�s�m toplam de�erleri yazd�r�yo. ��kt�da s�ralanm�� hali istiyo. yazd�rmak gereksiz.
	/*printf("\n");
	for(a1=0;a1<n;a1++){
	printf("%d %d - ",sLines[a1][0], sLines[a1][1]); 
	}*/
	
	int temp;
	for (q=0;q<n;q++){ //bu d�ng� de bubble sort ile hatlar yo�unlu�una g�re b�y�kten k����e s�raland�.
		for (w=0;w<n;w++){
			if(sLines[q][2] > sLines [w][2]){
				temp = sLines[q][2]; //s�ralama i�lemi bubble
				sLines[q][2] = sLines[w][2];
				sLines[w][2] = temp;
				
				temp = sLines[q][1]; // S�ralama i�lemi hatt�n s�ra numaras�n� de�i�tirmemek i�in hem 2. s�tuna da yap�ld�. 
				sLines[q][1] = sLines[w][1];
				sLines[w][1] = temp;
				
			}
		}
	}
	
	for(a1=0;a1<n;a1++){ // S�ralanm�� �ekilde hatlar ve yo�unluklar� - A �IKKI -
	printf("Bus Line %d : %d Stops.",sLines[a1][1], sLines[a1][2]);
	printf("\n");
	}
	
	
	// S�tundaki 1 de�erlerinin toplam�;
	int sColumns [m][2];
	
	int counter3 = 0;
	for (q=0;q<m;q++){
		for (w=0;w<n;w++){
			counter3 += matrix[w][q];
		}
	sColumns[q][1] = counter3;
	counter3=0;
	sColumns[q][0] = q+1;
	}
	
	// s�tun toplam matrisinin s�ralanmas�
	int temp2;
	
	for (q1=0;q1<m;q1++){
		for (w1=0;w1<m;w1++){
			if(sColumns[q1][1] > sColumns [w1][1]){
				temp2 = sColumns[q1][1]; //s�ralama i�lemi bubble
				sColumns[q1][1] = sColumns[w1][1];
				sColumns[w1][1] = temp2;
				
				temp2 = sColumns[q1][0]; //S�ralama i�lemi hatt�n s�ra numaras�n� de�i�tirmemek i�in hem 2. s�tuna da yap�ld�.  bubble
				sColumns[q1][0] = sColumns[w1][0];
				sColumns[w1][0] = temp2;
			}
		}
	}
	
	printf("\n");
	printf("\n");
	
	 for(a1=0;a1<m;a1++){ // SIRALANMI� S�TUNlar yazd�rmak istersen
	printf("Line %d : %d Stops.",sColumns[a1][0], sColumns[a1][1]);
	printf("\n");
	}
	printf("\n");
	printf("\n");
	// Most busy stop
	counter = 1; // s�ralanm�� s�tun toplam de�erlerden ayn� olan en y�ksek de�erleri/de�eri buluyor
	for (z=0;z<m-1;z++){
		if(sColumns[0][1] == sColumns[z+1][1]){
			counter++;
		}
	}
	
	printf("The most busy stop: "); // en y�ksek de�erlerden/de�erden olu�an s�tun yo�unluklar�n�, ayn� olan d�tun de�eri say�s� kadar d�ng�de i�leyip ekrana yazd�r�yoruz.
	for (int y=0;y<counter;y++){ // artan bir s�ralama ile dizi s�raland���ndan 0 dan ba�lat�p artt�rarak i�lem yap�nca en y�ksek de�erlere ula��yoruz.
		printf("Stop %d,  ",sColumns[y][0]);
	}
	
	// Less busy stop
	
	int counter2 = 1; // s�ralanm�� s�tun toplam de�erlerden ayn� olan en d���k de�erleri/de�eri buluyor
	int kk = m-1;
	for (int sz=kk;sz>0;sz--){
		if(sColumns[kk][1] == sColumns[(sz-1)][1]){
			counter2++;
		}
	} 
	
	printf("\n");
	printf("\n");
	
	printf("The less busy stop: "); // en d���k de�erlerden/de�erden olu�an s�tun yo�unluklar�n�, ayn� olan d�tun de�eri say�s� kadar d�ng�de i�leyip ekrana yazd�r�yoruz. 
	for (int y1=(m-1);y1>((m-1)-counter2);y1--){ // azalan bir s�ralama ile diziyi s�ralad���m�zdan tersten �al��t�r�nca en d���k de�erleri elde etmi� oluyoruz.
		printf("Stop %d,  ",sColumns[y1][0]);
	}
	
	printf("\n");
	printf("\n");
		printf("\n");
	printf("\n");
		printf("\n");
	printf("\n");
		printf("\n");
	printf("\n");	printf("\n");
	printf("\n");	printf("\n");
	printf("\n");
	
	/* ------------------- */
	int lineStops[20][50], stopLines[20][50], tmp[2][1], identically[50][50];
	
	int equal = 0;
	int max=0;

//Her bir hatt�, bir di�eri ile kar��la�t�r�p ortak durak say�s�n� ayr� bir matrise yazan d�ng� */

for(int ii=0;ii<n-1;ii++){
for(int j=ii+1;j<n;j++){
for(int k=0;k<m;k++){
if(matrix[ii][k]==1 && matrix[j][k]==1){
equal++;
}
}
identically[ii][j]=equal;
equal=0;
}
}

//Ortak durak say�s�n� i�eren matristeki en y�ksek de�erin bulunup o de�erin ait oldu�u hatlar� tespit eden d�ng�
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(identically[i][j]>max){
max=identically[i][j];
tmp[0][0]=i;
tmp[0][1]=j;
}
}
}
	
	int k=0;
printf("\n");
for(int i=0;i<n;i++){
printf("Bus Line %d : %d stops", sColumns[i][0]+1, sColumns[i][1]);
printf("\n");
}
printf("\n");
//En yo�un dura��n hangisi oldu�unun yazd�r�lmas� i�lemi
printf("The most busy bus stop : Stop %d ", sLines[0][0]+1);
while (sLines[k][1]==sLines[k+1][1]){
printf("and Stop %d",sLines[k+1][0]+1);
k++;
}
k=1;
printf("\n");
//En seyrek dura��n hangi durak oldu�unun yazd�r�lmas� i�lemi
printf("The least busy bus stop : Stop %d ", sLines[m-1][0]+1);
while (sLines[m-k][1]==sLines[m-k-1][1]){
printf("and Stop %d",sLines[m-k-1][0]+1);
k--;
}
printf("\n");
printf("\n");
//En benzer hatlar�n hangisi oldu�unun yazd�r�lmas� i�lemi
printf("The most identical bus lines : Bus Line %d and Bus Line%d",tmp[0][0]+1,tmp[0][1]+1);
return 0;

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
