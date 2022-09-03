#include "Dosya.h"


Dosya DosyaOku(char* dosya){

    Dosya this;
    FILE* dosya2 = fopen(dosya,"r");
    
    //eger dosya varsa heapte bellek oluşturur ve gerekli atamaları yapar (fonksiyon , değişken vs)
    if(dosya2 != NULL)
    {   
        this = (Dosya)malloc(sizeof(struct DOSYA));  

        this->dosya_adi = dosya;

        this->DosyaSatirUzunlugu = &DosyaSatirUzunlugu;
        this->ParcalaSayiya = &ParcalaSayiya;
        this->ParcalaVeOyuncuEkle = &ParcalaVeOyuncuEkle;
        this->DoayaYokEt = &DoayaYokEt;
        return this; 
        fclose(dosya2);

    }
    else
    {
        printf("dosya bulunamadi\n");
        return 0;
    }
    
    

    
}

//dosya yokedicisi
void DoayaYokEt(const Dosya this){
    if(this == NULL) return;
    free(this);
}

//sayilar dosyasını parcalayıp dizi int* döndüren fonksiyon
int* ParcalaSayiya(int sayilar_uzunluk){
    Dosya this;
    FILE* dosya3 = fopen(this->dosya_adi,"r");

    //sayilari yazdirma
    int* sayilar = malloc(sizeof(int) * sayilar_uzunluk);
    if(dosya3 != NULL)
    {   
        char a[10];
        
        
        int i =0;
        while (fgets(a, 10,dosya3))
        {
            
            
             
            int sansli = atoi(a);
            sayilar[i] = sansli;
           
            i++;
        
        }
        return sayilar;
        fclose(dosya3);
    }
    else
    {
        printf("dosya bulunamadi\n");
        return 0;
    }
}

//dosyanın satir uzunluğununu bulma - sayilar dizisi için-
int DosyaSatirUzunlugu(){
    Dosya this;

    
    FILE* dosya2 = fopen(this->dosya_adi,"r");
    int sayilar_uzunluk=0;
    if(dosya2 != NULL)
    {   char karakter[10];
        
        while (fgets(karakter , 10 , dosya2))
        {
            
            sayilar_uzunluk++;
           
        }
        
       
        fclose(dosya2);

    }
    else
    {
        printf("dosya bulunamadi\n");
        return 0;
    }

     return sayilar_uzunluk;

}

// kisiler dosyasındaki verileri parçalar ve oyuncu ekle fonksiyonuna atar
void ParcalaVeOyuncuEkle(const Oyun o , char* dosya_adi){
    Dosya this;
    FILE *dosya = fopen(dosya_adi, "r");
    
    if(dosya != NULL)
    {   char karakter[100];
        
        while (fgets(karakter, 100,dosya))
        {
            char* ch;
                      
                
            ch = strtok(karakter, "#");
            
            char* adi = ch;


            ch = strtok(NULL, "#");
         
            
            char* ptr;
            double para = strtod(ch,&ptr);

            ch = strtok(NULL, "#");
            

            char* ptr2;
            double oran = strtod(ch,&ptr2);

            ch = strtok(NULL, "#");
            

            
            int sansli = atoi(ch);
            
           

            o->oyuncuEkle(adi , para ,oran,sansli,o);

        }

        
        fclose(dosya);
    }
    else
    {
        printf("dosya bulunamadi\n");
    }
}