#include "TCkimlik.h"


TCkimlik TCKimlikKurucu(){//Kurucu fonksiyonumuzun govdesini burada yazdik
	TCkimlik this;//kurucu fonksiyonumuzdaki degerlere ulasabilecegimiz this yapisini burada olusturduk.
	this=(TCkimlik)malloc(sizeof(struct TCKimlik));
	this->TCdigit=11;//TCkimlik.h dosyasinda tanimladigimiz degiskenlere buradan eriserek deger atadik.
	
	this->super=RastgeleKurucu();//Rastgele sinifinin fonksiyonlarina burada erisim sagladik.
	this->TCno=(int*)malloc(sizeof(int)*11);//Header file'da tanimladigimiz diziye daha genis bir tanim yaparak boyutunu yazdik.
	
	this->TCkontrol=&TCKontrol;//Header file'da tanimini yaptigimiz fonksiyonu gosteren yapilara burada erisip gostermeleri gereken fonksiyonlarin adreslerini atadik.
	this->TcOlusturma=&TcOlustur;
	this->yoket=&TCyoket;
	return this;
}
int * TcOlustur(const TCkimlik this){// tc kimlik no yu bu fonksiyonla olusturduk.
	for(int i=0;i<this->TCdigit;i++)//Dizi elemanlarina rastgele deger atadik.
	{
		this->TCno[i]=this->super->UretimRandom(this->super,10);
	}
	while(this->TCno[0]==0)//ilk eleman 0 olamaz
	this->TCno[0]=this->super->UretimRandom(this->super,10);
        
    this->TCno[9]=((((this->TCno[0]+this->TCno[2]+this->TCno[4]+this->TCno[6]+this->TCno[8])*7)-(this->TCno[1]+this->TCno[3]+this->TCno[5]+this->TCno[7]))%10);//10. digite atamayi bu kuralla yatık
        
    while((((this->TCno[0]+this->TCno[1]+this->TCno[2]+this->TCno[3]+this->TCno[4]+this->TCno[5]+this->TCno[6]+this->TCno[7]+this->TCno[8]+this->TCno[9])%10)!=this->TCno[10])||(((this->TCno[0]+this->TCno[2]+this->TCno[4]+this->TCno[6]+this->TCno[8])*8)%10!=this->TCno[10]))
    this->TCno[10]=this->super->UretimRandom(this->super,10);//son digite kontrollu bir sekilde atama  yaptik.
        
    return this->TCno;
}
bool TCKontrol(const TCkimlik this,int *arr){//Bu fonksiyonda parametre ile aldigimiz bir tc kimlik no dizisinin imei no kurallarina uyup uymadigini kontrol ettik.
	int length=sizeof arr/sizeof *arr;
	if(arr[0]==0)//ilk eleman 0 olamaz
		return false;
	else if(length!=11)//dizi boyutu 11 digit olmali
		return false;
	else if(((arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9])%10)!=arr[10])//son digiti kontrol ettik
		return false;
	else if((((arr[0]+arr[2]+arr[4]+arr[6]+arr[8])*7)-(arr[1]+arr[3]+arr[5]+arr[7]))%10!=arr[9])//10. digiti kontol ettik
		return false;
	else return (((arr[0]+arr[2]+arr[4]+arr[6]+arr[8])*8)%10 == arr[10]);
}
void TCyoket(TCkimlik this){//Yok etme islemini burada yaptik.
	if(this==NULL) return;
	this->super->yoket(this->super);
	free(this);
}