#include "Kisi.h"
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

kisi kisiKurucu(){//Kurucu fonksiyonumuzun govdesini burada yazdik
    kisi this;//kurucu fonksiyonumuzdaki degerlere ulasabilecegimiz this yapisini burada olusturduk.
    this=(kisi)malloc(sizeof(struct Kisi));
	this->super=RastgeleKurucu();;//Rastgele sinifinin fonksiyonlarina burada erisim sagladik.
	this->superTc=TCKimlikKurucu();
	this->superImei=imeiNoKurucu();
	this->superTel=TelefonKurucu();

    this->isimSayisiAlma=&isimSayisiAl;//Header file'da tanimini yaptigimiz fonksiyonu gosteren yapilara burada erisip gostermeleri gereken fonksiyonlarin adreslerini atadik.
    this->rastgeleIsimAlma=&rastgeleIsimAl;
    this->tcKimlikNoOlusturma=&tcKimlikNoOlustur;
    this->yasOlusturma=&yasOlustur;
    this->telefonNoOlusturma=&telefonNoOlustur;
    this->imeiNoOlusturma=&imeiNoOlustur;
    
    return this;
}


int isimSayisiAl(const kisi this){//random_isimler.txt dosyasindan isimleri satir satir okuduk
    const char *fileName = "random_isimler.txt";//fonsiyonda daha rahat degisiklik yapabilmek adina  dosyayi degiskene atadik.
    FILE *file = fopen(fileName, "r");//dosyayi actik
    char line[256];
    int sayac=0;
    while (fgets(line, sizeof(line), file)) {//satirlari burada aldikca dönmeye devam ettirdik
        this->isimler[sayac]=line;//her gelen satir isimler dizisine ekleniyor
      sayac++;//sayac satir sayisi devam ettikce artar
    }

    fclose(file);//dosyayı kapattik

    return sayac;//Sayac satir sayisi kadar donuyor.
}

char* rastgeleIsimAl(const kisi this)//isimler dizisinin random donen bir indeksini dondurduk
{
  return this->isimler[this->super->UretimRandom(this->super,isimSayisiAl(this))];
}

int* tcKimlikNoOlustur(const kisi this){//Tc kimlik no tam haliyle yu burada olusturduk.
    for(int i=0;i<this->superTc->TCdigit;i++){
	printf("%d",this->superTc->TcOlusturma(this->superTc)[i]);}
}

int yasOlustur(const kisi this){//0-100 arasi bir yasi rastgele donen fonksiyonla dondurduk.
    return this->super->UretimRandom(this->super,100);    
}
int* telefonNoOlustur(const kisi this){//telefon numarasini tam haliyle burada olusturduk.
    for(int i=0;i<this->superTel->TelDigit;i++){
	printf("%d",this->superTel->telefonOlusturma(this->superTel)[i]);}
}
int* imeiNoOlustur(const kisi this){//imei numarasini tam haliyle burada olusturduk.
    for(int i=0;i<this->superImei->IMEIDigit;i++){
	printf("%d",this->superImei->olustur(this->superImei)[i]);}
}
void kisiYokEt(kisi this){//Yok etme islemini burada yaptik.
if(this==NULL) return;
    this->super->yoket(this->super);
    this->superTc->yoket(this->superTc);
    this->superImei->yoket(this->superImei);
    this->superTel->yoket(this->superTel);
    free(this);
}