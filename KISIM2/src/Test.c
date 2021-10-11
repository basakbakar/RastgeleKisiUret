#include "Kisi.h"
#include "RastgeleKisi.h"
#include <stdio.h>
int main()
{
	int choice;
    printf("1-Rastgele Kisi Uret\n2-Uretilmis Dosya Kontrol Et\n3-CIKIS"); //Kullanicidan secenek isteyecegimiz menuyu burada yazdik
	
    scanf("%d",&choice); //kullanicidan secenek aldik
    while(choice!=3){
    switch (choice) { 
    case 1: { 
        break; 
    } 
    case 2: { 
        break; 
    } 
    case 3: {//Cikis
        break; 
    } 
    default: 
        printf("wrong Input\n"); //secenekler 1, 2 veya 3 olabilir.
    } 
    return 0; 
	scanf("%d",&choice);
	}
}
