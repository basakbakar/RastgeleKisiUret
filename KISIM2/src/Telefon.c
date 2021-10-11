#include "Telefon.h"

telefon TelefonKurucu(){//Kurucu fonksiyonumuzun govdesini burada yazdik
	telefon this;//kurucu fonksiyonumuzdaki degerlere ulasabilecegimiz this yapisini burada olusturduk.
	this=(telefon)malloc(sizeof(struct Telefon));
	this->TelDigit=12;//Telefon.h dosyasinda tanimladigimiz degiskenlere buradan eriserek deger atadik.
	
	this->super=RastgeleKurucu();//Rastgele sinifinin fonksiyonlarina burada erisim sagladik.
	this->TelNo=(int*)malloc(sizeof(int)*12);//Header file'da tanimladigimiz diziye daha genis bir tanim yaparak boyutunu yazdik.

	this->telefonOlusturma=&telefonOlustur;//Header file'da tanimini yaptigimiz fonksiyonu gosteren yapilara burada erisip gostermeleri gereken fonksiyonlarin adreslerini atadik.
	this->yoket=&telefonYoket;
	return this;
}
int * telefonOlustur(const telefon this){//  telefon numarasini bu fonksiyonla olusturduk.
        int rastgeleHat;
		rastgeleHat=this->super->UretimRandom(this->super,31);//Turkiye'deki 31 hattan birini rastgele dondursun istedik
        int Hat[31]={501, 505, 506, 507, 551, 552, 553, 554, 555, 559,530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 561, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549};
        this->TelNo[0]=9;this->TelNo[1]=0;//dizinin ilk iki digitine Turkiye'deki numaralara uyumlu olsun diye 90 atadık
        this->TelNo[2]=Hat[rastgeleHat]/100;//bu kisimda rastgele donen hattı basamaklarina ayirip telefon numarasinin sonraki digitlerine atadik.
        this->TelNo[3]=(Hat[rastgeleHat]/10)%10;
        this->TelNo[4]=Hat[rastgeleHat]%10;
        
        for(int i=5;i<12;i++)//kalan digitlere rastgele rakam atamasi yaptik
        {
            this->TelNo[i]=this->super->UretimRandom(this->super,10);
        }

        
        return this->TelNo;
}
void telefonYoket(telefon this){//Yok etme islemini burada yaptik.
	if(this==NULL) return;
	this->super->yoket(this->super);
	free(this->TelNo);
	free(this);
}