#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*
Hasta takip sistemi
Hasta  no,ad, yas ve hastalik bilgisini tutacak bir struct olustur.
Dosya icerisinde hasta no'ya gore arama yap
Hasta kaydý sil
Hasta kaydý duzenle
*/

struct Hasta{
    int no;
    char ad[20];
    int yas;
    char hastalik[20];
};
struct Hasta boshasta ={0 , "" , 0 , ""};
struct Hasta kisi;
/*if((ptr = fopen("hastaKayit.dat","r+")) !=  NULL)
    {
        printf("hasta no:");scanf("%d",&hastaID);
        fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET); //Koordinata gitme
        fread( &kisi , sizeof(struct Hasta), 1 , ptr);
        if(kisi.no != 0 )
        {
            printf("%d numarasinda hasta mevcut\n",hastaID);
        }
        else if(hastaID >100 || hastaID <1)
        {
            printf("1-100 numara arasina hasta kayit yapabilirsiniz.\n");
            printf("Donmek icin herhangi bir tusa basin.\n");
            getch();
        }
        else{
            printf("Ad Yas Hastalik :"); scanf("%s %d %s",kisi.ad,&kisi.yas,kisi.hastalik);
            kisi.no=hastaID;
            fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET); //Koordinata gitme
            fwrite( &kisi , sizeof(struct Hasta), 1 , ptr);
            printf("Kayit yapildi\n");
        }
        fclose(ptr);*/
FILE *ptr;
void ekle()
{
    int hastaID;
    if((ptr=fopen("Hastakayit.dat","r+")) != NULL)
    {
        printf("Lutfen hasta no'yu giriniz.\n"); scanf("%d",&hastaID);
        fseek(ptr,(hastaID -1) * sizeof(struct Hasta),SEEK_SET);
        fread( &kisi,sizeof(struct Hasta),1,ptr);
        if(kisi.no != 0)
        {
            printf("Bu numarada bir hasta kayitlidir.\n");
        }
        else if(hastaID<1 || hastaID > 100)
        {
            printf("Lutfen 1-100 arasinda hasta kayit giriniz.\n");
            return ;
        }
        else {
            printf("Hastanin ADI\nYAS\n\HASTALIK\n");
            scanf("%s %d %s",kisi.ad,&kisi.yas,kisi.hastalik);
            fseek( ptr,(hastaID -1) * sizeof(struct Hasta),SEEK_SET);
            fwrite( &kisi,sizeof(struct Hasta),1,ptr);
            printf("Hasta kayit basarili\n");
        }
        fclose(ptr);
    }



}




void sil()
{
    int hastaID;
    if((ptr = fopen("hastaKayit.dat","r+")) != NULL)
    {
        printf("Silinecek hasta no  :") ; scanf("%d",&hastaID);
        fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET);
        fread(&kisi, sizeof(struct Hasta),1,ptr);
        if(kisi.no == 0)
            {
                printf("%d numarasinda kayitli hasta yok \n", hastaID);
            }
        else{
            fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET);
            fwrite(&boshasta,sizeof(struct Hasta),1,ptr);
            printf("Kayit silindi \n");
        }
    }
    fclose(ptr);
}
void guncelle()
{
    int hastaID;
    if((ptr = fopen("hastaKayit.dat","r+")) != NULL)
    {
        printf("Guncellenecek hasta no  :") ; scanf("%d",&hastaID);
        fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET);
        fread(&kisi, sizeof(struct Hasta),1,ptr);
        if(kisi.no == 0)
            {
                printf("%d numarasinda kayitli hasta yok \n", hastaID);
            }
        else{
            fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET);
            fread(&kisi,sizeof(struct Hasta),1,ptr);
            printf("%d numarali hasta bilgileri : \n");
            printf("Ad : %s\n",kisi.ad);
            printf("Yas: %d\n",kisi.yas);
            printf("Hastaligi: %s\n",kisi.hastalik);

            printf("Ad/Yas/Hastalik : ");scanf("%s%d%s",kisi.ad,&kisi.yas,kisi.hastalik);
            kisi.no = hastaID;
            fseek(ptr,(hastaID -1) * sizeof(struct Hasta),SEEK_SET);
            fwrite(&kisi, sizeof(struct Hasta),1,ptr);
            printf("Guncelleme yapildi\n");
        }
    }
}
void hastaAra()
{
    int hastaID;
    if((ptr = fopen("hastaKayit.dat","r+")) != NULL)
    {
        printf("Aradiginiz hastanin numarasi  :") ; scanf("%d",&hastaID);
        fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET);
        fread(&kisi, sizeof(struct Hasta),1,ptr);
        if(kisi.no == 0)
            {
                printf("%d numarasinda kayitli hasta yok \n", hastaID);
            }
        else{
            fseek(ptr,(hastaID -1) * sizeof(struct Hasta), SEEK_SET);
            fread(&kisi,sizeof(struct Hasta),1,ptr);
            printf("%d numarali hasta bilgileri : \n");
            printf("Ad : %s\n",kisi.ad);
            printf("Yas: %d\n",kisi.yas);
            printf("Hastaligi: %s\n",kisi.hastalik);


        }
    }
}
void yazdir()
{
    system("cls");
    if((ptr = fopen("hastaKayit.dat","r+")) != NULL)
    {
        printf("%-10s %-20s %-5s %-20s\n", "NUMARA", "AD", "YAS", "HASTALIK");
        while(fread(&kisi, sizeof(struct Hasta), 1, ptr) == 1)
        {
            if(kisi.no != 0) // Boş kayıtları atlamak için
            {
                printf("%-10d %-20s %-5d %-20s\n", kisi.no, kisi.ad, kisi.yas, kisi.hastalik);
            }
        }
        fclose(ptr);
    }
}
void listeOlustur(){
        if((ptr = fopen("hastaKayit.dat","w")) != NULL)
       {
           int i;
           for(int i=0;i<100;i++)
           {
               fwrite(&boshasta,sizeof(struct Hasta),1,ptr);
           }
           printf("100 hasta kaydi icin gerekli yer ayarlandi.\n");
           fclose(ptr);
       }

}
int main()
{
        int secim = -1;
        while(secim != 0)
        {
            printf("\t\t 1-Hasta Ekle\n");
            printf("\t\t 2-Hasta Sil\n");
            printf("\t\t 3-Hasta Guncelle\n");
            printf("\t\t 4-Hasta Ara\n");
            printf("\t\t 5-Hasta Yazdir\n");
            printf("\t\t 6-Kayit listesi olustur\n");
            printf("Lutfen bir secim yapiniz.\n");
            scanf("%d",&secim);

            switch(secim)
            {
                case 1 : ekle(); break;
                case 2 : sil(); break;
                case 3 : guncelle(); break;
                case 4 : hastaAra(); break;
                case 5 : yazdir();  break;
                case 6 : listeOlustur(); break;
                default:
                    printf("Hatali secim yaptiniz.\n");
            }


        }
}



