#include "RastgeleKisi.h"

rastgeleKisi rastgeleKisiKurucu(){//Kurucu fonksiyonumuzun govdesini burada yazdik
    rastgeleKisi this;//kurucu fonksiyonumuzdaki degerlere ulasabilecegimiz this yapisini burada olusturduk.
    this=(rastgeleKisi)malloc(sizeof(struct RastgeleKisi));

    this->kisiOlusturma=&kisiOlustur;//Header file'da tanimini yaptigimiz fonksiyonu gosteren yapilara burada erisip gostermeleri gereken fonksiyonlarin adreslerini atadik.
    this->superKisi->rastgeleIsimAlma=&rastgeleIsimAl;

    return this;
}

void kisiOlustur(const rastgeleKisi this){//Kisi olusturacagimiz fonksiyon
    FILE *fptr;
    char* sentence;
    fptr = fopen("Kisiler.txt", "w");//yazacagimiz fonksiyonu burada actik
 
    if (fptr == NULL) {//programdan kontrollu cikisi burada sagladik.
        printf("Error!");
        exit(1);
    }
    
    fclose(fptr);//dosya kapadik
}