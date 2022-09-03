#include "Oyun.h"
#include "Dosya.h"
#include "string.h"
int main(){

    
    Dosya dosya = DosyaOku(".//doc//Sayilar.txt");
    int sayilar_uzunluk = dosya->DosyaSatirUzunlugu();

    int* sayilar = dosya->ParcalaSayiya(sayilar_uzunluk);
    
    
    

    Oyun o  = new_oyunOlustur(sayilar , sayilar_uzunluk);

   
    dosya->ParcalaVeOyuncuEkle(o , ".//doc//Kisiler.txt");
    
    o->basla(o);
    o->KisilerYokEt(o); //kisiler dugumleri yok ediliyor
    o->yokEt(o); //oyun yokedicisi

    dosya->DoayaYokEt(dosya); //dosya yok edicisi
    

    

    





}