#include "Oyun.h"

Oyun new_oyunOlustur(int sayilar[] , int uzunluk){
    Oyun this;
    
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->ilk = NULL;


    this->sayilar = malloc(sizeof(int) * uzunluk); //sayilar dizisi oluşturma heapte
    this->uzunluk = uzunluk;
    int i;
    for ( i = 0; i <uzunluk; i++)
    {
        this->sayilar[i] = sayilar[i];
    }

    this->en_zengin = NULL;
    
    this->masa_parasi =0;
    this->oyuncuEkle = &oyuncuEkle;
    this->KisilerYokEt = &KisilerYokEt;
    this->yokEt = &yokEt;
    this->basla = &basla;

    return this;
}


void ekran(int sayi,int tur , double bakiye  , double masa_bakiye , char* ad){
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("                                      ##############################################################   \n");
    printf("                                      ##                    SANSLI SAYI:  %-15d         ##   \n",sayi);
    printf("                                      ##############################################################   \n");
    printf("                                      ##############################################################   \n");
    printf("                                      ##                    TUR: %-15d                  ##   \n",tur);
    printf("                                      ##                MASA BAKIYE: %-20lf TL      ##   \n",masa_bakiye);
    printf("                                      ##                                                          ##   \n");
    printf("                                      ##----------------------------------------------------------##   \n");
    printf("                                      ##                    EN ZENGIN KISI                        ##   \n");
    printf("                                      ##                    %-30s        ##   \n",ad);
    printf("                                      ##                BAKIYESI: %-20lf            ##   \n",bakiye);
    printf("                                      ##                                                          ##   \n");
    printf("                                      ##############################################################   \n");
    



}



void yokEt(const Oyun this){
    if(this == NULL) return;
    free(this);

}

void KisilerYokEt(const Oyun this){

    Kisiler gec = this->ilk;

    while (gec!=NULL)
    {
            
        Kisiler sil = gec;
        gec = gec->sonraki;
        free(sil->adi);
        free(sil);
    } 

 }



void basla(const Oyun this){
    int i = 0;
    Kisiler gec;
    
    while (i<this->uzunluk)
    {
        gec = this->ilk;
        while (gec!=0)
        {
            if(gec->para < 1000)
            {
                gec->elendiMi = True;
                gec = gec->sonraki;
            }
            else
            {
                if(gec->sayi == this->sayilar[i])
                {                
                    
                    double tmp = gec->para;
                    gec->para  = (gec->para * gec->oran * 10) - (gec->para * gec->oran) + gec->para;
                    double tmp2;
                    tmp2 = gec->para - tmp;
                    this->masa_parasi = this->masa_parasi -  tmp2;
                }
                else
                {
                    
                    this->masa_parasi +=  gec->para * gec->oran;
                    gec->para  = gec->para -  (gec->para * gec->oran); 

                    
                }


                gec=gec->sonraki;
            }
            
        

        }

        //tur sonu en zengin kisi
    
        double max = this->ilk->para;
        Kisiler gec2 = this->ilk;
        
        while (gec2!=0)
        {   
            if(max < gec2->para )
            {
                if(gec2->elendiMi == False){
                    max = gec2->para;
                    this->en_zengin = gec2;
                }
                
            }
                

            gec2 = gec2->sonraki;
        }

            double kisi_bakiye = this->en_zengin->para;
            if(kisi_bakiye < 1000)  // burada tur sonu 1000den dusuk oyuncular olursa oyuncu eleneceği için bakiye default olarak -1 oldu
                kisi_bakiye = -1;

            ekran(this->sayilar[i] , i + 1 ,kisi_bakiye, this->masa_parasi ,this->en_zengin->adi );

            i++;
        }
    


    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("                                      ##############################################################   \n");
    printf("                                      ##                    TUR: %-15d                  ##   \n",this->uzunluk);
    printf("                                      ##                MASA BAKIYE: %-20lf TL      ##   \n",this->masa_parasi);
    printf("                                      ##                                                          ##   \n");
    printf("                                      ##----------------------------------------------------------##   \n");
    printf("                                      ##                    OYUN BITTI                            ##   \n");
    printf("                                      ##                                                          ##   \n");
    printf("                                      ##                                                          ##   \n");
    printf("                                      ##                                                          ##   \n");
    printf("                                      ##############################################################   \n");
    
    

}

void oyuncuEkle(char* adi , double para, double oran, int sayi , const Oyun this){
    
    Kisiler yeni = new_Kisiler(adi , para , oran , sayi); //super

    //linked list gibi kisiler dugumlerini birbirine baglama 
    if(this->ilk == NULL)
    {
        this->ilk = yeni;
        return;    
    }

    Kisiler gec = this->ilk;

    while(gec->sonraki != NULL){
        gec = gec->sonraki;
    }

    gec->sonraki = yeni;

}




