#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

#include "stdio.h"
#include "stdlib.h"
#include "Kisi.h"

struct RastgeleKisi{//RastgeleKisi isimli struct tanimladik
    rastgele super;//baska siniflardan fonksiyon kullanmak icin burada super ve superKisi yapilarini olusturduk.
    kisi superKisi;

    void (*kisiOlusturma)(struct RastgeleKisi*);//Bu sinifin fonksiyonlarini baska siniflarda kullanmak uzere bu sekilde yazdik.
    void (*yoket)(struct RastgeleKisi*);
};
typedef struct RastgeleKisi* rastgeleKisi;

rastgeleKisi rastgeleKisiKurucu();//Kurucu fonksiyon yerine gececek bu fonksiyonu tanimladik.
void kisiOlustur(const rastgeleKisi);//Daha sonra struct in icindeki elemanlara erisebilmek uzere const rastgeleKisi parametresiyle beraber fonksiyonlarimizi tanimladik.
void rastgeleKisiYokEt(rastgeleKisi);//Cop birakmamak amaciyla bir yok etme metodu tanimladik.

#endif