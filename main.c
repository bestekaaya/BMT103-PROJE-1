#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct insan//struct bildirimi
{
    char isim[25];
    char soyisim[25];
    int dogumtarihi;
    int olumtarihi;
};
struct insan x[10000];//struct insan x[10000] dizisini global olarak tanımlama
int main()
{

    char* isim[100]={
        "Ayse","Ali","Fatma","Mehmet","Zeynep","Osman","Nil","Mert","Nazen","Burak",
        "Pelin","Fırat","Mine","Ferit","Seyran","Cagatay","Su","Murat","Selin","Serhat",
        "Canan","Cemal","Hulya","Fatih","Leyla","Kenan","Busra","Sercan","Narin","Omer",
        "Eylem","Serdar","Sevda","Muhammed","Cansu","Dogukan","Selda","Samet","Zehra","Mansur",
        "Asude","Edis","Emin","Emine","Efsun","Berk","Oguz","Irem","Ahmet","Hakan",
        "Koray","Ela","Nur","Kerem","Ilayda","Asli","Sema","Gulnisa","Kerim","Sumeyye",
        "Arda","Tulay","Alperen","Alp","Gorkem","Nisa","Selen","Aybuke","Elif","Mahmut",
        "Safiye","Efe","Berkcan","Aleyna","Deniz","Tamer","Suleyman","Caner","Can","Damla",
        "Ibrahim","Deren","Demir","Hasan","Huseyin","Adem","Tugce","Talat","Bekir","Bulut",
        "Selcuk","Derya","Melike","Merve","Okan","Cınar","Hatice","Soner","Buse","Kemal"
    };
    char* soyisim[100]={
        "Sarikaya","Ozoncel","Demir","Kirmizi","Kaya","Erol","Toprak","Ozkan","Yuce","Ozturk",
        "Karaca","Caliskanoglu","Aslan","Arslan","Turgut","Kilinc","Eren","Kurt","Kara","Yilmaz",
        "Coskun","Gultekin","Cakir","Tekin","Ezmeci","Calis","Ustuner","Yildirim","Karakus","Adiguzel",
        "Aydin","Goksel","Yasar","Kaplan","Kuru","Comert","Gocer","Aktan","Cakmak","Kucuksahin",
        "Sahin","Er","Cavus","Sucu","Evren","Karakas","Corman","Yegen","Limon","Guven",
        "Atay","Ozen","Akgun","Onur","Cinar","Gozubuyuk","Gezici","Karakurt","Polat","Saglam",
        "Firat","Erdem","Darici","Dogru","Karakeci","Dolas","Inan","Guzel","Ozer","Avci",
        "Ciftci","Altunbas","Kocakaya","Gunes","Simsek","Balik","Unutmaz","Gurbuz","Taskiran","Kucuk",
        "Tastan","Tasar","Deniz","Alis","Celiker","Yaldiz","Taskin","Ketenci","Akay","Akyuz",
        "Gunduz","Zengin","Kaygisuz","Suvarioglu","Eken","Safyurek","Yesin","Mutlu","Atak","Biyikli"
    };
    srand(time(NULL));//program her çalıştığında farklı çıktı almamızı sağlayacak fonksiyon
    FILE *veriler;//dosyayı tanımlama
    veriler=fopen("dosya.txt","wb");//dosyayı açma
    if(veriler==NULL){//dosya oluştu mu?
        printf("Dosya olusturulamadi.\n");
    return 1;
}        //veri atama
          for(int i=0;i<10000;i++)
            {

                strcpy(x[i].isim,isim[rand()%100]);
                strcpy(x[i].soyisim,soyisim[rand()%100]);

                x[i].dogumtarihi=1930+rand()%96;
                x[i].olumtarihi=x[i].dogumtarihi+(rand()%90);
              if (x[i].olumtarihi>2025)//kasaba sakini yaşıyor mu?
              {
                  x[i].olumtarihi=0;
              }
                fprintf(veriler,"%s %s %d %d\n",x[i].isim,x[i].soyisim,x[i].dogumtarihi,x[i].olumtarihi);//dosyaya veri atama
             }

            printf("Kasaba veritabani dosyasi olusturuldu.\n");
    fclose(veriler);//dosyayı kapatma
    FILE *kazananlar;//dosyayı tanımlama
    kazananlar=fopen("kazanan.txt","w");//dosyayı açma
    if(kazananlar==NULL)//dosya oluştu mu?
    {
        printf("Dosya olusturulamadi.\n");
        return 1;
    }
    printf("----------PIYANGO SONUCU----------\n");
    int kazanansayisi=0;
    int kazananindis[4];

     while (kazanansayisi<4){
     int k=rand()%10000;//struct insan x[10000] dizisinden rastgele bir kasaba sakinini (indis) seçme işlemi
         int dahaoncesecildi=0;
        //çekiliş koşullarının kontrolü
        if (x[k].olumtarihi==0 && (2025-x[k].dogumtarihi>=18))
        {
            //daha önce seçildi mi kontrolü
            for (int i=0;i<kazanansayisi;i++)
        {
                if (kazananindis[i]==k)//kazananindis[4] dizisinde kontrol edilen kişinin indisi yer alıyor mu?
                {
                    dahaoncesecildi=1;
                    break;
                }
        }
            if (dahaoncesecildi==0)
            {
                kazananindis[kazanansayisi]=k;//koşulları sağlayan kişinin indisinin kazananindis[4] dizisine atanması
                fprintf(kazananlar,"%s %s\n",x[k].isim,x[k].soyisim);//dosyaya veri atanması
                printf("%d.Kazanan: %s %s\n",kazanansayisi+1,x[k].isim,x[k].soyisim);//çekiliş sonucunun ekrana yazdırılması
                kazanansayisi++;
            }
        }
      }
    printf("Kazananlar dosyayi olusturuldu.\n");
        fclose(kazananlar);//dosyanın kapanması
    return 0;
}