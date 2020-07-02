    #include <stdio.h>
	#include <stdlib.h>
	
	int main() {
		int m,n;                // Matris satir ve sutun sayisini kullanicidan aldik.
		printf("Matris satir: ");
		scanf("%d",&m);
		printf("Matris sutun: ");
		scanf("%d",&n);
		
		int matrix[m][n];            // integer olarak bir dizi tanimladik. 
		
		for(int i=0;i<m;i++){  // olusturdugumuz diziyi kullanicidan girilmesini sagladik.
			for(int j=0;j<n;j++){
				scanf("%d",&matrix[i][j]); 
			}
		}
		int *p = (int *)&matrix;   // dizimizin adresini pointer olarak gösterdik.
		
		int *comp = (int *)malloc(sizeof(int));  // compress yapicagimiz diziyi pointer olarak tanimlayip mallocla bellekle yer ayirdik.
		int z = 1, temp = p[0], *temp1, counter = 1, a = 0 , x = 0; // istedigimiz zaman bu yeri genisletip daraltabiliriz veya serbest birakabiliriz.
		int donus_sayisi = 1;      // bunu yapmamizin sebebi girilen matris compress edildiginde ne kadar boyutu olucagi belli olmadigi için kolaylik .
		                            // integer degiskenlerimizi tanimladik pointer dizimizin ilk girdisini tmp ile atadik. 
		                            
	  // ******************************** COMPRESS ISLEMI
	  
		while(z<m*n){  //  döngü satir ve sutun sayisinin carpiminindan kücük olana kadar dönecektir.
			while(p[z] == temp){  // burda iç içe while yaparak tmp ile bir sonraki dizi girdisini karsilastiriyoruz. 
				temp = p[z];  // ayni ise counter ve z artirip bir sonraki karsilastirmayi yapiyoruz.
				counter++;
				z++;
			}
			
			temp1 = (int*) realloc(comp, 2*donus_sayisi*sizeof(int)); // her seferinde gecici bir pointer kullanarak compr olan malloc'un boyutunu; 
			comp = temp1; // realloc yaparak dönüs sayisinin 2 kati integer olarak büyütüyoruz. dizinin boyutu bellekte veri isledikce büyümüs olacak.
			donus_sayisi++; // karisiklik olmasin diye degisken isimlerini farkli kullandim.
			
			comp[x] = counter; //diziye ilk counteri daha sonra temp'teki degeri atayarak 2 ser 2 ser diziyi arttirim yapariz.
			comp[x+1] = temp;
			x+=2;
			
			temp = p[z];  // karsilastirmak icin pointerdaki bir sonraki girdiyi tempye atariz. 
			counter = 0; // ve counteri 0 layarak islemin döngü halinde devam etmesini saglariz.
		}
		
		for(int q=0;q<x;q++){
			printf("%d ",comp[q]); // olusan comp dizisini yazdiririz.
			}
		printf("\n");
		
		// **************************************  COMPRESS RATIO ISLEMI 
		float cratio = (float)1-((float)x/(m*n)); // float olarak compress ratio'ni hesaplariz.ve yazdiririz.
		printf("%f \n",cratio);
	
		
		// **************************************  DECOMPRESS ISLEMI 
		
		int *yeniDizi;  // Pointer olarak dizi tanimlariz.
		yeniDizi = (int*) malloc(m*n*sizeof(int)); // diziyi mallocla satir ve sutun carpimi olacak kadar bellekte yer ayirtiriz.
		
		int eleman_sayisi = 0, *temp2, sayi, count, j;
		for(int i=0; i<x; i+=2){   // iç içe for yaparak compress acma islemini yapariz.
			count = comp[i];
			sayi = comp[i + 1];
		
			for(j = 0; j < count; j++){
				yeniDizi[j+eleman_sayisi] = sayi;
			}
			
			eleman_sayisi += count;
		}
		
		for(int i = 0; i < m; i++){ // decompress olan dizimizi yazdiririz.
			for(int j=0; j<n; j++){
				printf("%d ",yeniDizi[i*n+j]);
			}
			printf("\n");
		}
		
		return 0;
	}
	

