#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menuGoster(char yemekAdlari[4][20], float fiyatlar[4]) {
    int i;
    printf("\n--- GUNUN MENUSU ---\n");
    for(i = 0; i < 4; i++) {
     
        printf("%d. %s \t -> %.2f TL\n", i+1, yemekAdlari[i], fiyatlar[i]);
    }
    printf("--------------------\n");
}

float satinAl(float mevcutPara, float urunFiyati) {
    if (mevcutPara >= urunFiyati) {
        mevcutPara = mevcutPara - urunFiyati;
        printf("\n*** Afiyet olsun! Satin alma basarili. ***\n");
    } else {
        printf("\n!!! YETERSIZ BAKIYE! Bu urunu alamazsiniz. !!!\n");
    }
    return mevcutPara; 
}

int main() {
    
    char isim[50];
    float bakiye = 0.0;
    int secim, yemekSecimi;
    
    
    char yemekler[4][20] = {"Tost", "Ayran", "Doner", "Cay"}; 
    float fiyatlar[4] = {35.50, 7.50, 60.00, 5.00};

    
    printf("KYK Kantin Sistemine Hosgeldiniz!\n");
    printf("Adiniz: ");
    fgets(isim, 50, stdin);
    isim[strcspn(isim, "\n")] = 0;

    printf("Baslangic bakiyenizi girin (TL): ");
    scanf("%f", &bakiye);
    
    while(1) {
        printf("\nSayin %s, Mevcut Bakiye: %.2f TL\n", isim, bakiye);
        printf("1. Menuyu Gor ve Satin Al\n");
        printf("2. Para Yukle\n");
        printf("3. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == 3) {
            printf("Cikis yapiliyor. Iyi dersler %s!\n", isim);
            break;
        }
        
        else if (secim == 1) {
            
            menuGoster(yemekler, fiyatlar);
            
            printf("Hangi urunu almak istersiniz? (1-4): ");
            scanf("%d", &yemekSecimi);
            
            
            int indeks = yemekSecimi - 1;

            if (indeks < 0 || indeks > 3) {
                printf("Hatali secim!\n");
            } else {
                
                bakiye = satinAl(bakiye, fiyatlar[indeks]);
            }
        }
        
        else if (secim == 2) {
            float yuklenecek;
            printf("Ne kadar yukleyeceksiniz?: ");
            scanf("%f", &yuklenecek);
            
            if(yuklenecek > 0) {
                bakiye += yuklenecek; 
                printf("Para yuklendi.\n");
            } else {
                printf("Gecersiz tutar.\n");
            }
        }
    }

    return 0;
}
