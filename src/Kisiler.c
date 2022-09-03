#include "Kisiler.h"
#include "string.h"
//kisiler sınıfının kurucusu ve heapte bellek açma
Kisiler new_Kisiler(char* adi,double parasi, double yatirdigi_oran , int sansli_sayi){
    Kisiler this;

    this = (Kisiler)malloc(sizeof(struct KISILER));
 
    this->adi = malloc(sizeof(char) * 100);  // Memory for the string
    strcpy(this->adi, adi);    

    this->elendiMi = False;
    this->para = parasi;
    this->oran = yatirdigi_oran;
    this->sayi = sansli_sayi;
    this->sonraki = NULL;

    return this;
}