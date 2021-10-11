#ifndef TCKIMLIK_H
#define TCKIMLIK_H

#include "Rastgele.h"
#include <stdbool.h>

struct TCKimlik{//TCKimlik isimli struct tanimladik
	int TCdigit;// TCkimlik.c dosyasinda deger atayayagimiz degiskenleri burada tanimladik.
	int *TCno;
	rastgele super;//baska siniflardan fonksiyon kullanmak icin burada super yapisi olusturduk.
	
	bool (*TCkontrol)(struct TCKimlik*,int *);//Bu sinifin fonksiyonlarini baska siniflarda kullanmak uzere bu sekilde yazdik.
	int* (*TcOlusturma)(struct TCKimlik*);
	void (*yoket)(struct TCKimlik*);
};
typedef struct TCKimlik* TCkimlik;

TCkimlik TCKimlikKurucu();//Kurucu fonksiyon yerine gececek bu fonksiyonu tanimladik.
int * TcOlustur(const TCkimlik);//Daha sonra struct in icindeki elemanlara erisebilmek uzere const TCkimlik parametresiyle beraber fonksiyonlarimizi tanimladik.
bool TCKontrol(const TCkimlik,int *);
void TCyoket(TCkimlik);//Cop birakmamak amaciyla bir yok etme metodu tanimladik.

#endif