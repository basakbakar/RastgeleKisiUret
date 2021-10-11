#ifndef RASTGELE_H
#define RASTGELE_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"//sistem zamanini kullanmak icin tanimladik.

struct Rastgele{

    int last;
    int sayac;
    
	int (*UretimRandom)(struct Rastgele*,int);//Bu sinifin fonksiyonlarini baska siniflarda kullanmak uzere bu sekilde yazdik.
	void (*yoket)(struct Rastgele*);
};
typedef struct Rastgele* rastgele;

rastgele RastgeleKurucu();//Kurucu fonksiyon yerine gececek bu fonksiyonu tanımladık.
int uretimRandom(const rastgele,int);//Daha sonra struct in icindeki elemanlara erisebilmek uzere const imeiNo parametresi ve integer bir bir parametreyle beraber fonksiyonlarimizi tanimladik.
void rastgeleYoket(rastgele);//Cop birakmamak amaciyla bir yok etme metodu tanımladik.

#endif