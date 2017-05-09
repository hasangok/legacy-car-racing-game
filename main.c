#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

int yolbolumleri[10]={60,120,180,240,300,360,420,480,540,600};
int blt1[3]={140,120,100}, blt2[3]={340,320,300}, blt3[3]={540,520,500}, blt4[3]={660,640,620};

struct konum
{
       int sol, sag, yukari, asagi;
} ciz;

int giris(void)
{
     FILE *puanlar;
     char secim, oncekiskor[80], oncekizaman[80];
     double saniye=0; int puan=0;
     puanlar=fopen("puanlar.txt", "r"); 
     menu:
     setfillstyle(1,BLACK);
     bar(0,600,1000,0);
     settextstyle(1,0,6);
     outtextxy(200,150,"Hasan's Speed");
     settextstyle(0,0,0);
     outtextxy(560,190,"Underground :)");
     outtextxy(250,220,"Yar��mak hi� bu kadar heyecanl� olmam��t�!!!");
     outtextxy(390,250,"Se�iminizi Yap�n:");
     outtextxy(390,280,"1: Oyuna Ba�la");
     outtextxy(390,300,"2: Bir �nceki Skor");
     outtextxy(390,320,"3: Bilgiler");
     outtextxy(390,340,"4: ��k��");
     secim=getch();
     if(secim==49) return 1;
     else if(secim==50) {
                   setfillstyle(1,BLACK);
                   bar(0,600,800,0);
                   settextstyle(1,0,6);
                   outtextxy(200,150,"Hasan's Speed");
                   settextstyle(0,0,0);
                   outtextxy(560,190,"Underground :)");
                   outtextxy(320,220,"Bir �nceki oyuncunun kay�tlar�");
                   outtextxy(220,300,"Oyunda ge�irdi�i s�re(sn)");
                   line(220,320,445,320);
                   outtextxy(530,300,"Kazand��� Puan:");
                   line(530,320,665,320);
                   fscanf(puanlar,"%lf %d",&saniye, &puan);
                   sprintf(oncekiskor,"%d",puan);
                   sprintf(oncekizaman,"%lf",saniye);
                   outtextxy(530,340,oncekiskor);
                   outtextxy(220,340,oncekizaman);
                   fclose(puanlar);
                   secim=getch();
                   goto menu;
                   }
     else if(secim==51) {
                   setfillstyle(1,BLACK);
                   bar(0,600,800,0);
                   settextstyle(1,0,6);
                   outtextxy(200,150,"Hasan's Speed");
                   settextstyle(0,0,0);
                   outtextxy(560,190,"Bilgiler");
                   outtextxy(170,220,"Araban�n sa�l�kl� hareket edebilmesi i�in tu�lara bas�l� tutmay�n.");
                   outtextxy(170,240,"H�z�n�za g�re puan�n�za +1, +3, +5, +10 ve +15 de�erleri eklenir.");
                   outtextxy(170,260,"Yol d���na ��karsan�z puan�n�z 50 eksilir, h�z�n�z azal�r.");
                   outtextxy(170,280,"Oyun s�resi minimum 1 dakika, maksimum 3 dakika aras�ndad�r.");
                   outtextxy(170,300,"Bu s�re rastgele �retilecektir. Art�k ne ��karsa �ans�n�za :)");
                   secim=getch();
                   goto menu;
                   }
     else if(secim==52) return 3;
     else if(secim==27) return 0;
     else goto menu;
}

void oncekiskor(int *puaniptr, char zaman[])
{
     FILE *puanlar;
     char puanyaz[10];
     puanlar = fopen("puanlar.txt", "r");
     fscanf(puanlar,"%s %d",zaman,*puaniptr);
     sprintf(puanyaz,"%d",*puaniptr);
     outtextxy(968,560,puanyaz);
     fclose(puanlar);
     getch();
}

struct konum konumhesapla(char yon, int *hizptr, int *puaniptr)
{
       if(yon==72) {
                   if(ciz.asagi>=520)
                   {
                   ciz.yukari-=2;
                   ciz.asagi-=2;
                   }
                   }
       if(yon==80) {
                   if(ciz.yukari<=595)
                   {
                   ciz.yukari+=2;
                   ciz.asagi+=2;
                   }                               
                   }
       if(yon==75) {
                   ciz.sol-=10;
                   ciz.sag-=10;
                   }
       if(yon==77) {
                   ciz.sol+=10;
                   ciz.sag+=10;                                    
                   }
       if(ciz.sol<=210||ciz.sag>=500) {
                                      *hizptr+=50;
                                      *puaniptr-=50;
                                      }
}

void araba(void)
{
     setfillstyle(1,WHITE);
     bar(ciz.sol,ciz.yukari,ciz.sag,ciz.asagi);
}

void puan(int *hizptr, int *puaniptr)
{
     char puaniyaz[10];
     if(*hizptr>=800) *puaniptr+=1;
     if(*hizptr>600&&*hizptr<800) *puaniptr+=2;
     if(*hizptr>400&&*hizptr<600) *puaniptr+=3;
     if(*hizptr>200&&*hizptr<400) *puaniptr+=5;
     if(*hizptr>50&&*hizptr<200) *puaniptr+=7;
     if(*hizptr<=50) *puaniptr+=10;
     sprintf(puaniyaz,"%d",*puaniptr);
     outtextxy(880,560,puaniyaz);
}
     
void sagtaraf(void)
{
     settextstyle(11,0,0);
     outtextxy(860,100,"Araba Yar���");
     outtextxy(850,130,"Hasan's Speed");
     outtextxy(810,300,"NOT: Sa�l�kl� hareket i�in");
     outtextxy(810,320,"tu�lara bas�l� tutmay�n. :)");
     outtextxy(810,560,"Puan�n�z:");
     outtextxy(810,580,"Oyunda Ge�en S�re:");
}

void bitismenusu(void)
{
     setfillstyle(1,BLACK);
     bar(0,600,800,0);
     settextstyle(1,0,6);
     outtextxy(150,150,"Hasan's Speed");
     settextstyle(0,0,0);
     outtextxy(530,190,"Underground");
     outtextxy(150,240,"Puan ve s�re bilgilerini sa� men�de g�r�yorsunuz.");
     outtextxy(150,260,"Men�ye d�nmek i�in bir tu�a bas�n�z...");
     getch();
}

int main(void)
{
    FILE *puanlar;
    initwindow(1000,600);
    enbas : double baslangiczamani=time(NULL), gecensure, eksure;
    ciz.sag=400, ciz.sol=350, ciz.yukari=590, ciz.asagi=530;
    int koordinat=0, hiz=400, *hizptr=&hiz;
    int puani=0, *puaniptr=&puani;
    char yon, zaman[30];
    int i=0, saniye=0, uyolsol=300, uyolsag=400, secim=0, finisy=250, finissol=260, finissag=440, direk=2;
    eksure=1+rand()%120;
    goto hasan;
    setcolor(9);
    oyun: while(1)
    {
            puanlar = fopen("puanlar.txt", "w+");
            koordinat=rand()%10;
            do {
            setfillstyle(1,8);
            bar(0,600,800,0); //yol
            setfillstyle(1,9);
            bar(0,250,800,0);  //gok
            setfillstyle(1,WHITE);
            fillellipse(blt1[0],110,30,20);
            fillellipse(blt1[1],90,30,20);
            fillellipse(blt1[2],110,30,20);
            
            fillellipse(blt2[0],150,50,30);
            fillellipse(blt2[1],120,50,30);
            fillellipse(blt2[2],150,50,30);
            
            fillellipse(blt3[0],110,30,20);
            fillellipse(blt3[1],90,30,20);
            fillellipse(blt3[2],110,30,20);
            
            fillellipse(blt4[0],170,50,30);
            fillellipse(blt4[1],140,50,30);
            fillellipse(blt4[2],170,50,30);
            line(0,250,800,250); //ufuk �igizi
            line(800,0,800,600); //sa� ayra�
            sagtaraf();
            setlinestyle(2,0,0);
            line((uyolsol+uyolsag)/2,250,350,600); //yol �igizi
            setlinestyle(0,0,0);
            line(200,600,uyolsol,250);
            line(uyolsag,250,500,600);
            araba();
            puan(&hiz,&puani);
            if(difftime(gecensure,baslangiczamani)>=60.000000+eksure&&uyolsol==300){ do {
                                                                              delay(200);
                                                                              setfillstyle(1,8);
                                                                              bar(0,600,800,0); //yol
                                                                              setfillstyle(1,9);
                                                                              bar(0,250,800,0);  //gok
                                                                              setfillstyle(1,WHITE);
                                                                              fillellipse(blt1[0],110,30,20);
                                                                              fillellipse(blt1[1],90,30,20);
                                                                              fillellipse(blt1[2],110,30,20);
                                                                              fillellipse(blt2[0],150,50,30);
                                                                              fillellipse(blt2[1],120,50,30);
                                                                              fillellipse(blt2[2],150,50,30);
                                                                              fillellipse(blt3[0],110,30,20);
                                                                              fillellipse(blt3[1],90,30,20);
                                                                              fillellipse(blt3[2],110,30,20);
                                                                              fillellipse(blt4[0],170,50,30);
                                                                              fillellipse(blt4[1],140,50,30);
                                                                              fillellipse(blt4[2],170,50,30);
                                                                              line(0,250,800,250); //ufuk �igizi
                                                                              line(800,0,800,600); //sa� ayra�
                                                                              sagtaraf();
                                                                              setlinestyle(2,0,0);
                                                                              line((uyolsol+uyolsag)/2,250,350,600); //yol �igizi
                                                                              setlinestyle(0,0,0);
                                                                              line(200,600,uyolsol,250);
                                                                              line(uyolsag,250,500,600);
                                                                              araba();
                                                                              setfillstyle(1,RED);
                                                                              bar(finissol,finisy,finissag,finisy+100);
                                                                              setfillstyle(1,BLACK);
                                                                              bar(finissol,finisy,finissol+direk,finisy+200);//soldirek
                                                                              bar(finissag,finisy,finissag-direk,finisy+200);//sa�direk
                                                                              finisy+=10;
                                                                              finissol-=5;
                                                                              finissag+=5;
                                                                              direk+=1;
                                                                              } while(finisy<=600);
                                                                              goto bitis;
                                                                              }
            gecensure=time(NULL);
            sprintf(zaman,"%lf", difftime(gecensure,baslangiczamani));
            outtextxy(968,580,zaman);
            if(uyolsol>yolbolumleri[koordinat])
            {
                                               uyolsol-=5;
                                               uyolsag-=5;
                                               ciz.sag+=1;
                                               ciz.sol+=1;
            }
            if(uyolsag<yolbolumleri[koordinat])
            {
                                               uyolsol+=5;
                                               uyolsag+=5;
                                               ciz.sag-=1;
                                               ciz.sol-=1;
            }
            if(kbhit())
            {
            yon=getch();
            if(yon==72) {
                        konumhesapla(yon,&hiz,&puani);
                        if(hiz>=100) hiz-=50;
                        } //yukari
            if(yon==80) {
                        konumhesapla(yon,&hiz,&puani);
                        if(hiz<=1000) hiz+=50;
                        } //asagi
            if(yon==75) {
                        konumhesapla(yon,&hiz,&puani);
                        for(int i=0;i<3;i++) {
                        blt1[i]+=2;
                        blt2[i]+=2;
                        blt3[i]+=2;
                        blt4[i]+=2; }
                        } //sol
            if(yon==77) {
                        konumhesapla(yon,&hiz,&puani);
                        for(int i=0;i<3;i++) {
                        blt1[i]-=2;
                        blt2[i]-=2;
                        blt3[i]-=2;
                        blt4[i]-=2; }
                        } //sag
            if(yon==27) {
                        fprintf(puanlar,"%lf %10d",difftime(gecensure,baslangiczamani),puani);
                        fclose(puanlar);
                        baslangiczamani=0, gecensure=0, eksure=0, puani=0, i=0, saniye=0;
                        goto enbas;
                        }
            }
            delay(hiz); } while(uyolsol>yolbolumleri[koordinat]||uyolsag<yolbolumleri[koordinat]);
    }
    bitis: {
           fprintf(puanlar,"%lf %10d",difftime(gecensure,baslangiczamani),puani);
           fclose(puanlar);
           baslangiczamani=time(NULL), gecensure=time(NULL), eksure=0, puani=0, i=0, saniye=0;
           bitismenusu();
           getch();
           goto hasan;
           }
    hasan: secim=giris();
    if(secim==1) goto oyun;
    if(secim==3) return 0;
}
