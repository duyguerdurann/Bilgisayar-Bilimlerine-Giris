#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

main(){
	int m; //Deðiþkenler Tanýmlandý
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
	for (int i=0;i<n;i++){  // matris içine 1 ve 0 atamalarý yapýldý.
		for (int j=0;j<m;j++){
		/*	scanf("%d",&oneandzero);
			matrix[i][j] = oneandzero;*/
		matrix[i][j] = rand() % 2;
		}
	}  
	int sLines[n][2]; // 2 sütunlu matris. Ýlkk sütununda hattýn yoðunluk deðeri, ikinci sütununda hattýn numarasý tutulacak.
	
	for (a=0;a<n;a++){ // bu döngüde hattýn yoðunluðu - 1 deðerlerinin toplamý - hesaplandý
		for (b=0;b<m;b++){
			printf("%d ",matrix[a][b]);
			counter = counter + matrix[a][b]; // "counter" deðiþkeni hattaki 1 lerin toplam deðerini hesaplayýp diziye atmak amacýyla satýrýn tamamýnýn toplamýna eþitlendi.
		}
		printf("\n");
		sLines [a][2] = counter; // Hesaplanan deðer oluþturulan dizinin ilk sütununa atandý
		counter = 0; // Diðer hatlarýn hesabý için sayaç sýfýrlandý.
		sLines [a][1] = a+1; // dizinini ikinci sütununa hattýn numarasý kaydedildi.
	}
	
		printf("\n");
	// Aþaðýdaki kýsým toplam deðerleri yazdýrýyo. Çýktýda sýralanmýþ hali istiyo. yazdýrmak gereksiz.
	/*printf("\n");
	for(a1=0;a1<n;a1++){
	printf("%d %d - ",sLines[a1][0], sLines[a1][1]); 
	}*/
	
	int temp;
	for (q=0;q<n;q++){ //bu döngü de bubble sort ile hatlar yoðunluðuna göre büyükten küçüðe sýralandý.
		for (w=0;w<n;w++){
			if(sLines[q][2] > sLines [w][2]){
				temp = sLines[q][2]; //sýralama iþlemi bubble
				sLines[q][2] = sLines[w][2];
				sLines[w][2] = temp;
				
				temp = sLines[q][1]; // Sýralama iþlemi hattýn sýra numarasýný deðiþtirmemek için hem 2. sütuna da yapýldý. 
				sLines[q][1] = sLines[w][1];
				sLines[w][1] = temp;
				
			}
		}
	}
	
	for(a1=0;a1<n;a1++){ // Sýralanmýþ þekilde hatlar ve yoðunluklarý - A ÞIKKI -
	printf("Bus Line %d : %d Stops.",sLines[a1][1], sLines[a1][2]);
	printf("\n");
	}
	
	
	// Sütundaki 1 deðerlerinin toplamý;
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
	
	// sütun toplam matrisinin sýralanmasý
	int temp2;
	
	for (q1=0;q1<m;q1++){
		for (w1=0;w1<m;w1++){
			if(sColumns[q1][1] > sColumns [w1][1]){
				temp2 = sColumns[q1][1]; //sýralama iþlemi bubble
				sColumns[q1][1] = sColumns[w1][1];
				sColumns[w1][1] = temp2;
				
				temp2 = sColumns[q1][0]; //Sýralama iþlemi hattýn sýra numarasýný deðiþtirmemek için hem 2. sütuna da yapýldý.  bubble
				sColumns[q1][0] = sColumns[w1][0];
				sColumns[w1][0] = temp2;
			}
		}
	}
	
	printf("\n");
	printf("\n");
	
	 for(a1=0;a1<m;a1++){ // SIRALANMIÞ SÜTUNlar yazdýrmak istersen
	printf("Line %d : %d Stops.",sColumns[a1][0], sColumns[a1][1]);
	printf("\n");
	}
	printf("\n");
	printf("\n");
	// Most busy stop
	counter = 1; // sýralanmýþ sütun toplam deðerlerden ayný olan en yüksek deðerleri/deðeri buluyor
	for (z=0;z<m-1;z++){
		if(sColumns[0][1] == sColumns[z+1][1]){
			counter++;
		}
	}
	
	printf("The most busy stop: "); // en yüksek deðerlerden/deðerden oluþan sütun yoðunluklarýný, ayný olan dütun deðeri sayýsý kadar döngüde iþleyip ekrana yazdýrýyoruz.
	for (int y=0;y<counter;y++){ // artan bir sýralama ile dizi sýralandýðýndan 0 dan baþlatýp arttýrarak iþlem yapýnca en yüksek deðerlere ulaþýyoruz.
		printf("Stop %d,  ",sColumns[y][0]);
	}
	
	// Less busy stop
	
	int counter2 = 1; // sýralanmýþ sütun toplam deðerlerden ayný olan en düþük deðerleri/deðeri buluyor
	int kk = m-1;
	for (int sz=kk;sz>0;sz--){
		if(sColumns[kk][1] == sColumns[(sz-1)][1]){
			counter2++;
		}
	} 
	
	printf("\n");
	printf("\n");
	
	printf("The less busy stop: "); // en düþük deðerlerden/deðerden oluþan sütun yoðunluklarýný, ayný olan dütun deðeri sayýsý kadar döngüde iþleyip ekrana yazdýrýyoruz. 
	for (int y1=(m-1);y1>((m-1)-counter2);y1--){ // azalan bir sýralama ile diziyi sýraladýðýmýzdan tersten çalýþtýrýnca en düþük deðerleri elde etmiþ oluyoruz.
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

//Her bir hattý, bir diðeri ile karþýlaþtýrýp ortak durak sayýsýný ayrý bir matrise yazan döngü */

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

//Ortak durak sayýsýný içeren matristeki en yüksek deðerin bulunup o deðerin ait olduðu hatlarý tespit eden döngü
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
//En yoðun duraðýn hangisi olduðunun yazdýrýlmasý iþlemi
printf("The most busy bus stop : Stop %d ", sLines[0][0]+1);
while (sLines[k][1]==sLines[k+1][1]){
printf("and Stop %d",sLines[k+1][0]+1);
k++;
}
k=1;
printf("\n");
//En seyrek duraðýn hangi durak olduðunun yazdýrýlmasý iþlemi
printf("The least busy bus stop : Stop %d ", sLines[m-1][0]+1);
while (sLines[m-k][1]==sLines[m-k-1][1]){
printf("and Stop %d",sLines[m-k-1][0]+1);
k--;
}
printf("\n");
printf("\n");
//En benzer hatlarýn hangisi olduðunun yazdýrýlmasý iþlemi
printf("The most identical bus lines : Bus Line %d and Bus Line%d",tmp[0][0]+1,tmp[0][1]+1);
return 0;

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
