#ifndef DOSYA_H
#define DOSYA_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Oyun.h"
#include "Kisiler.h"
struct DOSYA  //dosya sınıfı
{
    char* dosya_adi;
    int (*DosyaSatirUzunlugu)(); 
    int* (*ParcalaSayiya)(int);
    void (*ParcalaVeOyuncuEkle)(struct OYUN* , char* dosya_adi);
    void (*DoayaYokEt)(struct DOSYA*);
};

typedef struct DOSYA* Dosya;

void DoayaYokEt(const Dosya);

Dosya DosyaOku(char* dosya);
int DosyaSatirUzunlugu();

int* ParcalaSayiya(int);

void ParcalaVeOyuncuEkle(const Oyun , char* dosya_adi);

#endif