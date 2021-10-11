#include "IMEINo.h"
#include "Rastgele.h"
#include "stdio.h"

imeiNo imeiNoKurucu(){//Kurucu fonksiyonumuzun govdesini burada yazdik
    imeiNo this;//kurucu fonksiyonumuzdaki degerlere ulasabilecegimiz this yapisini burada olusturduk.
    this=(imeiNo)malloc(sizeof(struct IMEINo));
    this->IMEIDigit=15;//IMEINo.h dosyasinda tanimladigimiz degiskenlere buradan eriserek deger atadik.
    this->IMEITekDigit=0;
    this->IMEICiftDigit=0;
    
    this->IMEINoDizisi=(int*)malloc(sizeof(int)*this->IMEIDigit);//Header file'da tanimladigimiz diziye daha genis bir tanim yaparak boyutunu yazdik.
    this->super=RastgeleKurucu();//Rastgele sinifinin fonksiyonlarina burada erisim sagladik.

    this->olustur=&IMEINoOlustur;//Header file'da tanimini yaptigimiz fonksiyonu gosteren yapilara burada erisip gostermeleri gereken fonksiyonlarin adreslerini atadik.
    this->kontrol=&IMEIKontrol;
    this->yoket=&IMEINoYoket;

    return this;
}


int* IMEINoOlustur(const imeiNo this){// imei no yu bu fonksiyonla olusturduk.

    for(int i=0;i<this->IMEIDigit-1;i++)
        {
        this->IMEINoDizisi[i]=this->super->UretimRandom(this->super,10);//15 boyutlu dizinin ilk 14 elemanina Rastgele sinifindan bir fonksiyon ile burada atama yaptik
        }

        int i;
        for(i=0;i<this->IMEIDigit-2;i++)//imei nin son elemanini hesaplamak icin burada cift sayii indeksleri topladik
        {
            this->IMEICiftDigit+=this->IMEINoDizisi[i];
            i++;
        }
        
        for(i=1;i<this->IMEIDigit-1;i++)//imei nin son elemanini hesaplamak icin burada tek sayili indeksleri topladik
        {
            this->IMEITekDigit+=((2*this->IMEINoDizisi[i]/10)+(2*this->IMEINoDizisi[i]%10));
            i++;
        }
        
        this->IMEINoDizisi[14]=(((this->IMEICiftDigit+this->IMEITekDigit)/10+1)*10-(this->IMEICiftDigit+this->IMEITekDigit))%10;//imei dizisinin son elemanini burada hesapladik.
             
        return this->IMEINoDizisi;
}

bool IMEIKontrol(const imeiNo this,int* arr){//Bu fonksiyonda parametre ile aldigimiz bir imei no dizisinin imei no kurallarina uyup uymadigini kontrol ettik.
        if(sizeof(arr)!=this->IMEIDigit)//Dizinin imei digiti boyutunda mi oldugunu kontrol ettik
            return false;
        for(int i=0;i<this->IMEIDigit-2;i++)//Cift sayili indeksleri topladik.
        {
            this->IMEICiftDigit+=arr[i];
            i++;
        }
        
        for(int i=1;i<this->IMEIDigit-1;i++)//Tek sayili indeksleri topladik.
        {
            this->IMEITekDigit+=((2*arr[i]/10)+(2*arr[i]%10));
            i++;
        }
        return arr[14] == ((((this->IMEICiftDigit+this->IMEITekDigit)/10+1)*10-(this->IMEICiftDigit+this->IMEITekDigit))%10);//son digit in imei kuralina uyup uymamasina göre fonksiyonu dondurduk.
}

void IMEINoYoket(imeiNo this){//Yok etme islemini burada yaptik.
    if(this==NULL) return;
    this->super->yoket(this->super);
    free(this->IMEINoDizisi);
    free(this);
}