#ifndef IMEINO_H
#define IMEINO_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "Rastgele.h"

struct IMEINo {//IMEINo isimli struct tanımladik
    int IMEIDigit;// IMEINo.c dosyasinda deger atayayagimiz degiskenleri burada tanimladik.
    int IMEICiftDigit;
    int IMEITekDigit;
    int* IMEINoDizisi;
    rastgele super;//Rastgele sinifindan fonksiyon kullanmak icin burada super yapisi olusturduk.

    bool (*kontrol)(struct IMEINo*,int*);//Bu sinifin fonksiyonlarini baska siniflarda kullanmak uzere bu sekilde yazdik.
    int* (*olustur)(struct IMEINo*);
    void (*yoket)(struct IMEINo*);
};
typedef struct IMEINo* imeiNo;

imeiNo imeiNoKurucu();//Kurucu fonksiyon yerine gececek bu fonksiyonu tanımladık.
bool IMEIKontrol(const imeiNo,int*);//Daha sonra struct in icindeki elemanlara erisebilmek uzere const imeiNo parametresiyle beraber fonksiyonlarimizi tanimladik.
int* IMEINoOlustur(const imeiNo);
void IMEINoYoket(imeiNo);//Cop birakmamak amaciyla bir yok etme metodu tanımladik.

#endif