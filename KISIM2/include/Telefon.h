#ifndef TELEFON_H
#define TELEFON_H

#include "stdio.h"
#include "stdlib.h"
#include "Rastgele.h"
struct Telefon{//Telefon isimli struct tanımladik
	int TelDigit;// Telefon.c dosyasinda deger atayayagimiz degiskenleri burada tanimladik.
	int *TelNo;
	rastgele super;//baska siniflardan fonksiyon kullanmak icin burada super yapisi olusturduk.

	int* (*telefonOlusturma)(struct Telefon*);//Bu sinifin fonksiyonlarini baska siniflarda kullanmak uzere bu sekilde yazdik.
	void (*yoket)(struct Telefon*);
};
typedef struct Telefon* telefon;

telefon TelefonKurucu();//Kurucu fonksiyon yerine gececek bu fonksiyonu tanimladik.
int * telefonOlustur(const telefon);//Daha sonra struct in icindeki elemanlara erisebilmek uzere const telefon parametresiyle beraber fonksiyonlarimizi tanimladik.
void telefonYoket(telefon);//Cop birakmamak amaciyla bir yok etme metodu tanimladik.
#endif