#ifndef KISI_H
#define KISI_H

#include "Rastgele.h"
#include "TCkimlik.h"
#include "IMEINo.h"
#include "Telefon.h"
#include "stdio.h"
#include "stdlib.h"

struct Kisi{//Kisi isimli struct tanımladik
	char* isimler[10000];// Kisi.c dosyasinda deger atayayagimiz degiskeni burada tanımladık.
	rastgele super;//baska siniflardan fonksiyon kullanmak icin burada super, superTc, superImei, ve superTel yapilari olusturduk.
	TCkimlik superTc;
	imeiNo superImei;
	telefon superTel;
	
	int (* isimSayisiAlma)(struct Kisi*);//Bu sinifin fonksiyonlarini baska siniflarda kullanmak uzere bu sekilde yazdik.
	char* (*rastgeleIsimAlma)(struct Kisi*);
	int* (*tcKimlikNoOlusturma)(struct Kisi*);
	int (*yasOlusturma)(struct Kisi*);
	int* (*telefonNoOlusturma)(struct Kisi*);
	int* (*imeiNoOlusturma)(struct Kisi*);
	void (*yoket)(struct Kisi*);
};
typedef struct Kisi* kisi;

kisi kisiKurucu();//Kurucu fonksiyon yerine gececek bu fonksiyonu tanimladik.
int isimSayisiAl(const kisi);//Daha sonra struct in icindeki elemanlara erisebilmek uzere const kisi parametresiyle beraber fonksiyonlarimizi tanimladik.
char* rastgeleIsimAl(const kisi);
int* tcKimlikNoOlustur(const kisi);
int yasOlustur(const kisi);
int* telefonNoOlustur(const kisi);
int* imeiNoOlustur(const kisi);
void kisiYokEt(kisi);//Cop birakmamak amaciyla bir yok etme metodu tanimladik.

#endif