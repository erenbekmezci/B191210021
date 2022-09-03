#ifndef KISILER_H
#define KISILER_H

#include "stdio.h"
#include "stdlib.h"


//kisiler sınıfı aynı zamanda linked list dugumu
typedef enum Bool {False , True} boolean;
struct KISILER
{
    char* adi;
    boolean elendiMi;
    double para;
    int sayi;
    double oran;

    struct KISILER* sonraki; //sonraki işaretçisi
};
typedef struct KISILER* Kisiler;

Kisiler new_Kisiler(char * adi,double , double , int);

#endif