#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define R 21
#define C 18
#define B 6

char ESAS [ R ] [ C ], KENAR [ R ] [ B ];  // CERCEVE AYARLARI YAPILDI

static int e11, e12, e21, e22, e31, e32, e41, e42;   //SEKILLER TANIMLANDI
static int k11, k12, k21, k22, k31, k32, k41, k42;

char tus;  // OYUNU BASLATMAK ICIN TUS TANIMI YAPILDI
int Sekil_No, Sekil_Sonraki,  i, j, a, b, c,o, yontusu;  // OYUNU OYNANMASI ICIN GEREKLI DEGISKENLER TANIMLANDI
int Cevirme = 0, Beepmatik = 0, Bosluk = 0;
int Puan = 0, Level = 1, Temas = -1, OyunBitti = 0;

void Acilis ();   // KULLANILAN FONKSIYONLAR TANIMLANDI
void Bos_Cerceve ();
void Rastgele_Sekil ();
void Sekli_Kodla ( );
void Grafik ( );
void Sekli_Sil ( );
void Sola_Git ( );
void Saga_Git ( );
void Cevir ( );
void Asagi_Hareket ();
void Satir_Analizi ();
void Temas_Analizi ();
void Pause ();
void Oyun_Sonu ();

int main ()   // MAIN FONKSIYONUNA OYUNUN OYNANMASI ICIN GEREKLI DONGU YAPISI OLUSTURULDU. 
 { 
	system(" color 0C "); // TEMA RENK AYARI 
	setlocale(LC_ALL, "Turkish");  //TURKCELESTIRME FONKSIYONU
	Acilis ( ); //ACILIS FONKSIYONUYLA OYUN BASLAR.
	if(tus == 'e' || tus == 'E') return -1; // OYUNDA VEYA ANA EKRANDA E/e TUSUNA BASILDIGINDA PROGRAM SONLANIR.
    Bos_Cerceve ( );
    Rastgele_Sekil ();

	Temas = 0;
	
for( ;; )  //OYUN OYNANMASI 
   {
     if ( OyunBitti != 0 )
       {
          Oyun_Sonu ( );   
        }
     
     if ( OyunBitti == 0 )
       {
          if ( kbhit ( ) )
           {
               yontusu = getch ( );
   
               if( (yontusu == 'a' ) || ( yontusu == 'A'))
               {
                   if( e12 - 1 != 0 &&  e22 - 1 != 0 && e32 - 1 != 0 && e42 - 1 != 0 )
                   {
                       Sola_Git ( );
                    }
                }
   
               if( (yontusu == 'd' ) || ( yontusu == 'D') )
               {
                  if( e12 + 1 != C - 1 &&  e22 + 1 != C - 1 && e32 + 1 != C - 1 && e42 + 1 != C - 1 )
                   {
                       Saga_Git ( );
                    }
                }
   
               if( (yontusu == 'w' ) || ( yontusu == 'W') )
               {
                   Cevir ( );
                }
      
               if( (yontusu == 'p') || ( yontusu == 'P') )
               {
                   Pause ( );
                   printf("Oyun durduruldu"); // OYUNUN PAUSE YAPILMASI VE TEKRAR BASLATILMASI
                   system ( "pause>nul" );
                }
                if( ( yontusu == 'e') || (yontusu == 'E' ) )  
               {
                   return -1;  // oyun ekranindayken programi bitiriyor.
                }
            }
     
       if ( yontusu == 'a' || yontusu == 'A' || yontusu == 'd' || yontusu == 'D' || yontusu == 'w' || yontusu == 'W' || yontusu == 'p' || yontusu == 'P' || yontusu == 'E' || yontusu == 'e' )
       {
          yontusu = 0;
        }
                     
     Sekli_Kodla ( );
     Grafik ( );
     Temas_Analizi ( );
   
     if ( Temas == 0 )
       {
          Sekli_Sil ( );
          Asagi_Hareket ( );
            
          if( yontusu == 0 )
           {
              if ( Beepmatik == 0 ) // SATIR SILINDIGINDE SES CIKMASI
               {
                   Sleep ( 350 - Level * 75 );
               }
           }
       }  
     if ( Temas != 0 )
       {
          Sekli_Sil ( );
          Satir_Analizi ( );
          Satir_Analizi ( );
          Satir_Analizi ( );
          Satir_Analizi ( );

   
          Grafik ( );
          Rastgele_Sekil ( );
          Cevirme = 0;
          yontusu = 0;
          Temas = 0;
        }
    }
    }
	system( "pause" );
	return 0;
  }

void Acilis() {  // ACILIS EKRANINDA CALISTIRILAN FONKSIYON.. OYUN KURALLARI VE BILGILENDIRME MEVCUTTUR. 

	printf( "\n \n \n "); 
	system("CLS");
	printf("\n\n\n\n\n\n  ");
    printf( "                       __________________________________________________________________________\n\n\n");
    printf("                           **********    ************ ***********  *******     **    ************ \n");
	printf("                               *         *                 *       *      *          *            \n");
	printf("                               *         *                 *       *     *     **    *            \n");
	printf("                               *         ************      *       ******      **    ************ \n");
	printf("                               *         *                 *       *     *     **               * \n");
	printf("                               *         *                 *       *      *    **               * \n");
	printf("                               *         ************      *       *       *   **    ************ \n\n");
    printf("                          _________________________________________________________________________");
    printf("\n\n\n   ");
    
    printf(" \n\n                             OYUN KURALLARI:      \n\n");
	printf("                             1 >>  'a-d' & 'A-D' tuslarini sað-sol hareket ettirir..\n   ");
	printf("                          2 >>  'w' & 'W' tuslari þekli çevirir..\n  ");
	printf("                           3 >>  'p' & 'P' tuslari oyunu durdurur..\n   ");
	printf("                          4 >>   Baþlatmak için 'x' || 'X' tuslarýný kullanýnýz.\n   ");
	printf("                          5 >>   Oyundan çýkmak için 'e' || 'E' tuslarýný kullanýnýz.\n   ");
	printf("                          6 >>   Oyun bitince bir tuþa basmana gerek yok! Kendisini Restart ederek Ana Ekrana geri dönecektir. :)  \n   ");
    printf("\n\n\n  Coding by DUYGU ERDURAN ");
	
  if ( OyunBitti == 0 )  // ACILISTA  PROGRAMI SONLANDIRMAK 
   { 
	   do 
	   {
	     tus = _getch();
		 if(tus == 'e' || tus == 'E' || tus == 'x' || tus == 'X') 
		   {
		     return;
	    	}
		 printf("duzgun tusa basiniz");
	    } while ((tus != 'x') && (tus != 'X'));
	}
	else 
   {
	  printf(" ******** PUAN :",Puan);
	  Bos_Cerceve ( );
      OyunBitti = 0;
      Puan = 0;
      Level = 1;

     do {  // X/x TUSUNA BASILMADAN BASLAMAYACAK OLAN DONGU 
		 tus = _getch();  
		 printf("duzgun tusa basiniz");	
    	} while ((tus != 'x') && (tus != 'X'));
      getch();
      int main(); // OYUN BITTIGINDE MAINE TEKRAR DONER. ACILIS EKRANI CALISTIRIR.
    }  
 }

void Bos_Cerceve ( ) // CERCEVE FONKSIYONU
 { 	
  for ( i = 0 ; i < R ; i ++ )
    {
       for ( j = 0 ; j < C ; j ++ )
        {
          ESAS [ i ] [ j ] = ' ';
         if ( j < B )
           {
              KENAR [ i ] [ j ] = ' ';
            }
        }
    }
                                
   for ( j = 0 ; j < C ; j ++ )
   {
     ESAS [ R - 1 ] [ j ] = '|';
    }

   for ( i = 0 ; i < R ; i ++ )
   {
     ESAS [ i ] [ 0 ] = '|';
     ESAS [ i ] [ C - 1 ] = '|';
    }
       
}
  
void Grafik ( )  // GRAFIK GÖRSEL OLUSTURULAN GORSEL TEMA FONSIYONU
 { 
  system ( "CLS" );
  for ( i = 0; i < R; i ++ )
   {
     printf("\n");
     for (o=0;o<55;o++)
	   {
         printf(" ");      	
	    }
     for ( j = 0; j < C; j ++ )
       {
         printf("%c",ESAS[i][j]);
        }   
   
     if ( i != 9 && i != 14 && i != 0 && i != 7 && i != 12)
     {
       for ( j = 0 ; j < B ; j ++ )
        {
           printf("%c",KENAR[i][j]);
        }
      }
     if ( i == 0 ) { printf(" Sonra"); }
     if ( i == 7 ) { printf(" Puan");  }
     if ( i == 9 ) { printf("%d",Puan); }  
     if ( i == 12 ) { printf(" Level ");  }
     if ( i == 14 ) { printf("%d",Level); }
    }
} 

void Sola_Git ( ) // SOLA GITME FONKSIYONU
   {
     e12 -= 1; 
	 e22 -= 1; 
	 e32 -= 1; 
	 e42 -= 1;
     e11 -= 1; 
	 e21 -= 1; 
	 e31 -= 1; 
	 e41 -= 1;
   }

void Saga_Git ( ) // SAGA GITME FONKSIYONU
   { 
     e12 += 1;
	 e22 += 1;
	 e32 += 1; 
	 e42 += 1;
     e11 -= 1; 
	 e21 -= 1;
	 e31 -= 1; 
	 e41 -= 1;
    }

void Asagi_Hareket ( ) // ASAGI GITME FONKSIYONU
   {
     e11 += 1; 
     e21 += 1; 
	 e31 += 1; 
	 e41 += 1;     
   }

void Cevir ( ) // SEKILLERI DONDURME FONKSIYONU
   {
     Cevirme ++ ;
     if ( Sekil_No == 1 )
        {
         if ( Cevirme % 2 == 1 ) { e11 += 1; e12 -= 1; e31 -= 1; e32 += 1; e41 -= 2; e42 += 2; }
         if ( Cevirme % 2 == 0 ) { e11 -= 1; e12 += 1; e31 += 1; e32 -= 1; e41 += 2; e42 -= 2; }
        }
        else if ( Sekil_No == 3 )
        {
             if ( Cevirme % 4 == 1 ) { e11 += 1; e12 -= 1; e21 -= 1; e22 += 1; e41 += 1; e42 -= 1; }
             if ( Cevirme % 4 == 2 ) { e11 += 1; e12 += 1; e21 += 1; e22 -= 1; e41 -= 1; e42 += 1; }
             if ( Cevirme % 4 == 3 ) { e11 -= 1; e12 += 1; e21 -= 1; e22 += 1; e41 += 1; e42 -= 1; }
             if ( Cevirme % 4 == 0 ) { e11 -= 1; e12 -= 1; e21 += 1; e22 -= 1; e41 -= 1; e42 += 1; }
        }
        else if ( Sekil_No == 4 )
       {
         if ( Cevirme % 4 == 1 ) { e11 += 1; e12 -= 1; e31 -= 1; e32 += 1; e41 -= 2; }
         if ( Cevirme % 4 == 2 ) { e11 += 1; e12 += 2; e22 += 1; e31 -= 1; e42 -= 1; }
         if ( Cevirme % 4 == 3 ) { e11 -= 2; e12 += 1; e21 -= 1; e32 -= 1; e41 += 1; }
         if ( Cevirme % 4 == 0 ) { e12 -= 2; e21 += 1; e22 -= 1; e31 += 2; e41 +=1; e42 += 1; }
        }
       else if ( Sekil_No == 5 )
       {
         if ( Cevirme % 4 == 1 ) { e11 += 1 ; e12 -= 1 ; e31 -= 1 ; e32 += 1 ; e42 += 2 ; }
         if ( Cevirme % 4 == 2 ) { e11 += 1 ; e12 += 1 ; e31 -= 1 ; e32 -= 1 ; e41 -= 2 ; }
         if ( Cevirme % 4 == 3 ) { e11 -= 1 ; e12 += 1 ; e31 += 1 ; e32 -= 1 ; e42 -= 2 ; }
         if ( Cevirme % 4 == 0 ) { e11 -= 1 ; e12 -= 1 ; e31 += 1 ; e32 += 1 ; e41 += 2 ; }
       }
        else if ( Sekil_No == 6 )
       {
         if ( Cevirme % 2 == 1 ) { e11 -= 1; e12 += 1; e31 -= 1; e22 -= 1; e42 -= 2; }
         if ( Cevirme % 2 == 0 ) { e11 += 1; e12 -= 1; e31 += 1; e22 += 1; e42 += 2; }
        }          
       else if ( Sekil_No == 7 )
       {
         if ( Cevirme % 2 == 1 ) { e21 += 1; e32 += 1; e41 += 1; e42 += 1; }
         if ( Cevirme % 2 == 0 ) { e21 -= 1; e32 -= 1; e41 -= 1; e42 -= 1; }
        }
    }

void Rastgele_Sekil ( ) //RANDOM OLUSTURULAN SEKILLER VE SONRAKI SEKLI GOSTERME ISLEMI TANIMLANAN FONKSIYONDUR.
  {   
     srand ( time ( NULL ) );
     if ( Temas == -1)
       {	
         Sekil_No = rand () % 7 + 1;
        }
     if ( Temas != -1)
       {
         Sekil_No = Sekil_Sonraki;
       }
     if ( Sekil_No == 1 )
       {
         e11 = 0; e12 = ( C - 1 ) / 2; e21 = 1; e22 = ( C - 1 ) / 2;
         e31 = 2; e32 = ( C - 1 ) / 2; e41 = 3; e42 = ( C - 1 ) / 2;
        }           
     if ( Sekil_No == 2 )
       {
         e11 = 0; e12 = ( C - 3 ) / 2; e21 = 0; e22 = ( C - 1 ) / 2;
         e31 = 1; e32 = ( C - 3 ) / 2; e41 = 1; e42 = ( C - 1 ) / 2;
        }
     if ( Sekil_No == 3 )
       {
         e11 = 0; e12 = ( C - 1 ) / 2; e21 = 1; e22 = ( C - 3 ) / 2;  
         e31 = 1; e32 = ( C - 1 ) / 2; e41 = 1; e42 = ( C + 1 ) / 2;
       }
     if ( Sekil_No == 4 )
       {
         e11 = 0; e12 = ( C - 1 ) / 2; e21 = 1; e22 = ( C - 1 ) / 2;
         e31 = 2; e32 = ( C - 1 ) / 2; e41 = 2; e42 = ( C + 1 ) / 2;
        }
      if ( Sekil_No == 5 )
       {
         e11 = 0; e12 = ( C - 1 ) / 2; e21 = 1; e22 = ( C - 1 ) / 2;
         e31 = 2; e32 = ( C - 1 ) / 2; e41 = 2; e42 = ( C - 3 ) / 2;
        }
       if ( Sekil_No == 6 )
        {
         e11 = 0; e12 = ( C - 3 ) / 2; e21 = 0; e22 = ( C - 1 ) / 2;
         e31 = 1; e32 = ( C - 1 ) / 2; e41 = 1; e42 = ( C + 1 ) / 2;
        }
       if ( Sekil_No == 7 )
       {
         e11 = 0; e12 = ( C - 1 ) / 2; e21 = 0; e22 = ( C + 1 ) / 2;
         e31 = 1; e32 = ( C - 3 ) / 2; e41 = 1; e42 = ( C - 1 ) / 2;
        }
       Sekil_Sonraki = rand () % 7 + 1;
       if ( Sekil_Sonraki == 1 ) { k11 = 2; k12 = 2; k21 = 3; k22 = 2; k31 = 4; k32 = 2; k41 = 5; k42 = 2; }
       if ( Sekil_Sonraki == 2 ) { k11 = 2; k12 = 2; k21 = 2; k22 = 3; k31 = 3; k32 = 2; k41 = 3; k42 = 3; }
       if ( Sekil_Sonraki == 3 ) { k11 = 2; k12 = 2; k21 = 3; k22 = 2; k31 = 4; k32 = 2; k41 = 3; k42 = 3; }
       if ( Sekil_Sonraki == 4 ) { k11 = 2; k12 = 2; k21 = 3; k22 = 2; k31 = 4; k32 = 2; k41 = 4; k42 = 3; }
       if ( Sekil_Sonraki == 5 ) { k11 = 2; k12 = 3; k21 = 3; k22 = 3; k31 = 4; k32 = 3; k41 = 4; k42 = 2; }
       if ( Sekil_Sonraki == 6 ) { k11 = 2; k12 = 3; k21 = 3; k22 = 3; k31 = 3; k32 = 2; k41 = 4; k42 = 2; }
       if ( Sekil_Sonraki == 7 ) { k11 = 2; k12 = 2; k21 = 3; k22 = 2; k31 = 3; k32 = 3; k41 = 4; k42 = 3; }
   }
  
void Sekli_Sil ( ) // SATIR DOLDUGUNDA SILINMESI ICIN TANIMLANAN FONKSIYONDUR.
   {
     if ( Temas == 0 )
       {
         ESAS [ e11 ] [ e12 ] = ' '; ESAS [ e21 ] [ e22 ] = ' ';
         ESAS [ e31 ] [ e32 ] = ' '; ESAS [ e41 ] [ e42 ] = ' ';
       }

else if ( Temas != 0 && OyunBitti == 0)
   {
      KENAR [ k11 ] [ k12 ] = ' '; KENAR [ k21 ] [ k22 ] = ' ';
      KENAR [ k31 ] [ k32 ] = ' '; KENAR [ k41 ] [ k42 ] = ' ';
    }
}

void Sekli_Kodla ( ) // OLUSTURULAN MATRISLERIN GELECEK SEKILLERI AYARLANMASI BEN DUYGUNUN " D" HARFINI SECTIM.  BIRAZ CREATIVE OLSUN :) 
   {

     ESAS [ e11 ] [ e12 ] = 'D'; ESAS [ e21 ] [ e22 ] = 'D';
     ESAS [ e31 ] [ e32 ] = 'D'; ESAS [ e41 ] [ e42 ] = 'D';   

     KENAR [ k11 ] [ k12 ] = 'D'; KENAR [ k21 ] [ k22 ] = 'D';
     KENAR [ k31 ] [ k32 ] = 'D'; KENAR [ k41 ] [ k42 ] = 'D';
   } 

void Temas_Analizi ( ) //TASMAYI ONLEMEK ICIN AYARLANAN FONKSIYON HATTA DAHA FAZLA IYILESTIRILEBILIR 
   {
     a = 1; b = 0;
     if ( ESAS [ e11 + a ] [ e12 + b ] == 'D' || ESAS [ e11 + a ] [ e12 + b ] == '|' )
       {
         if ( e11 + a != e21 || e12 + b != e22 )
           {
             if ( e11 + a != e31 || e12 + b != e32 )
               {
                 if ( e11 + a != e41 || e12 + b != e42 )
                   { 
                      Temas ++;
                    }
			    }
   		    }
	    }                                                                           
     if ( ESAS [ e21 + a ] [ e22 + b ] == 'D' || ESAS [ e21 + a ] [ e22 + b ] == '|' )
       {
         if ( e21 + a != e11 || e22 + b != e12 )
           {
             if ( e21 + a != e31 || e22 + b != e32 )
               {
                 if ( e21 + a != e41 || e22 + b != e42 )
                   {
                     Temas ++ ;
                    }
			    }
		    }
	    }                                                                            
     if ( ESAS [ e31 + a ] [ e32 + b ] == 'D' || ESAS [ e31 + a ] [ e32 + b ] == '|' )
       {
         if ( e31 + a != e21 || e32 + b != e22 )
           {
             if ( e31 + a != e11 || e32 + b != e12 )
               {
                 if ( e31 + a != e41 || e32 + b != e42 )
                   {
                     Temas ++ ;
                    }
			    }
     	    }
    	}                                                                            
     if ( ESAS [ e41 + a ] [ e42 + b ] == 'D' || ESAS [ e41 + a ] [ e42 + b ] == '|' )
       {
         if ( e41 + a != e21 || e42 + b != e22 )
           {
             if ( e41 + a != e31 || e42 + b != e32 )
               {
                 if ( e41 + a != e11 || e42 + b != e12 )
                   {
                     Temas ++;
                    }
			    }
    		}
        }
       if ( Temas != 0 )
       {
         if ( e11 == 1 || e21 == 1 || e31 == 1 ||e41 == 1 )
           {
              OyunBitti ++;
            }
        }
   }
void Satir_Analizi ( ) //SATIRIN DOLUP DOLMADIGINI CHECK EDER.
   {
     for ( i = R - 2; i > 0; i -- )
       { 
          for ( j = 1; j < C - 1; j ++ )
           {
             if ( ESAS [ i ] [ j ] == ' ' )
               {
                  Bosluk ++;
               }
            }
           if ( Bosluk == 0 )
           {
             Puan ++;
             Level = Puan / 10 + 1;
             Beepmatik ++;     
             for ( a = 0; a < i - 3; a ++ )
               {
                 for ( b = 1; b < C - 1; b ++ )
                   {
                     ESAS [ i - a ] [ b ] = ESAS [ i - a - 1 ] [ b ];
                   }
                }
            }                
         Bosluk = 0;
        }
   }
   
void Oyun_Sonu ( ) // OYUN  BITTIGINDE YAPILMASI GEREKEN AYARLAR
   {
     for ( i = R / 2 - 2; i < R / 2 + 3; i ++ )
       {
         for ( j  = 1; j < C - 1; j ++ )
           {
             ESAS [ i ] [ j ] = ' ';
            }
        }
     ESAS [ R / 2 ] [ C / 2 - 5 ] = 'O'; ESAS [ R / 2 ] [ C / 2 - 4 ] = 'Y';
     ESAS [ R / 2 ] [ C / 2 - 3 ] = 'U'; ESAS [ R / 2 ] [ C / 2 - 2 ] = 'N';
     ESAS [ R / 2 ] [ C / 2 + 0 ] = 'B'; ESAS [ R / 2 ] [ C / 2 + 1 ] = 'Ý';
     ESAS [ R / 2 ] [ C / 2 + 2 ] = 'T'; ESAS [ R / 2 ] [ C / 2 + 3 ] = 'T';
     ESAS [ R / 2 ] [ C / 2 + 4 ] = 'Ý';
     Grafik ( );
     Sleep( 2500 );
     Acilis ( );
   }
   
void Pause ( ) // BU DA OYUN DURDURULDUGUNDA SIZIN ICIN OLUSTURDUGUM SUPRIZ FONKSIYON :) 
   {
     while ( ! kbhit ( ) )
       {
         system ( "CLS" );
         printf("\n\n\n\n\n\n\n\n\n  ");
         printf( "                        _________________________________________________________________________\n\n\n");
         printf("                           **********    ************ ***********  *******     **    ************ \n");
	     printf("                               *         *                 *       *      *          *            \n");
	     printf("                               *         *                 *       *     *     **    *            \n");
	     printf("                               *         ************      *       ******      **    ************ \n");
	     printf("                               *         *                 *       *     *     **               * \n");
	     printf("                               *         *                 *       *      *    **               * \n");
	     printf("                               *         ************      *       *       *   **    ************ \n\n");
         printf("                         _________________________________________________________________________");
         printf("\n\n\n   ");
         Sleep ( 600 );
         system ( "CLS" );
         printf( "\n\n\n\n\n\n\n\n\n\n\n\n                                            *******************************\n" );
	     printf(	     	   "                                            *                             *\n");
	     printf(	           "                                            *            DUYGU            *\n");
	     printf(             "                                            *                             *\n");
	     printf(			   "                                            *           ERDURAN           *\n");
	     printf(			   "                                            *                             *\n");
	     printf(			   "                                            *******************************\n");
         Sleep ( 600 ) ;
        }
   }

