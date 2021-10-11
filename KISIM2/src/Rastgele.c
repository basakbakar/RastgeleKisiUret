#include "Rastgele.h"


rastgele RastgeleKurucu(){
	rastgele this;
	this=(rastgele)malloc(sizeof(struct Rastgele));
	this->last=0;
    this->sayac = 0;//bu rastgele bi sayı olacak 
    time_t currenTime;
    time(&currenTime);
    struct tm *mytime = localtime(&currenTime);//Saniye tutulmasini sagladik.
    this->last=mytime->tm_sec;//seed olmak için atadik
	
	this->UretimRandom=&uretimRandom;//Header file'da tanimini yaptigimiz fonksiyonu gosteren yapilara burada erisip gostermeleri gereken fonksiyonlarin adreslerini atadik.
	this->yoket=&rastgeleYoket;
	return this;
}
int uretimRandom(const rastgele this,int mod){
	this->sayac++;
    this->last=(this->last*32719+3)%32479;//saniye seed i kullanarak random sayı oluşturduk
    return (this->last)%mod;//girilen mod ile kullanicinin istediği random sayiyi elde ettik
}
void rastgeleYoket(rastgele this){//Yok etme fonksiyonuyla copleri temizledik.
	if(this==NULL) return;
	free(this);
}