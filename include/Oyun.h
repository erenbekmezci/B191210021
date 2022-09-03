#ifndef OYUN_H
#define OYUN_H
#include "Kisiler.h"

//oyun sınıfı aynı zamanda linked list

struct OYUN
{
    Kisiler ilk;
    int* sayilar;
    int uzunluk;
    Kisiler en_zengin;
    double masa_parasi;

    void (*oyuncuEkle)(char* adi, double , double , int,struct OYUN*);//kisileri linked list gibi ekler

    void (*basla)(struct OYUN*); //kisiler dugumlerini cagirir ve ekrana bilgileri ayzar

    void (*KisilerYokEt)(struct OYUN*); //kisiler dugumlerini yok eder - bu yüzden kisiler sınıfı için ayrı bir yokedici tanımlamadım

    void (*yokEt)(struct OYUN*); //oyun sınıfının yok edicisi

    //void (*ekran)(int ,int, double , double , char* ad);  ekran fonksiyonu private oldugu için oyun.h ta tanımlanmadı
};

typedef struct OYUN* Oyun;

Oyun new_oyunOlustur(int sayilar[] , int);

void basla(const Oyun);

void oyuncuEkle(char* adi, double , double , int , const Oyun);

void KisilerYokEt(const Oyun);

void yokEt(const Oyun);

//void ekran(int ,int, double , double , char* ad);

#endif