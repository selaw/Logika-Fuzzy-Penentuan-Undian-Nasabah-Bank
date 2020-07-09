#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

class fuzzy {

float NasabahPointSedikit = 0;
float NasabahPointCukup = 0;
float NasabahPointBesar = 0;
float NasabahSaldoSedikit = 0;
float NasabahSaldoCukup = 0;
float NasabahSaldoBanyak = 0;
float NasabahUmurBaru = 0;
float NasabahUmurLama = 0;
float NasabahUmurSetia = 0;

 struct Nilai_Kelayakan{
    float NK = 0;
    char label[100];
    char rules[100];
    }N[30];

public :
    int U=0;
    void HitungPoint(float point){
        if (point <= 150 ){
            NasabahPointSedikit = 1;
        }else{
            if (point < 200 ){
                NasabahPointSedikit = (float) ((-point + 200)/50);
            }
        else{NasabahPointSedikit = 0;}
        }

        if(point <= 150 || point>= 400){
            NasabahPointCukup = 0;
        } else{
            if (point> 150 && point < 200){
                NasabahPointCukup = (float) ((point - 150 )/50);
            }else {
                if (point> 350 && point < 400){
                    NasabahPointCukup = (float) ((-point + 400)/50);
                } else {
                    NasabahPointCukup= 1;
                }
            }
        }

        if(point <= 350){
            NasabahPointBesar = 0;
        } else {
            if(point > 350 && point < 400){
                NasabahPointBesar = (float) ((point - 350)/50);
            } else NasabahPointBesar = 1;
        }
    }
    //SALDO
    void HitungSaldo(float saldo){
        if (saldo <= 10){
            NasabahSaldoSedikit = 1;
        }else{
            if(saldo < 20){
                NasabahSaldoSedikit = (float) ((-saldo + 20)/10);
            }
            else {
                NasabahSaldoSedikit = 0;
            }
        }
        if(saldo <= 10 || saldo>= 100){
            NasabahSaldoCukup = 0;
        } else{
            if (saldo> 10 && saldo < 20){
                NasabahSaldoCukup = (float) ((saldo - 10 )/10);
            }else {
                if (saldo> 80 && saldo < 100){
                    NasabahSaldoCukup = (float) ((-saldo + 100)/20);
                } else {
                    NasabahSaldoCukup = 1;
                }
            }
        }
        if(saldo <= 80){
            NasabahSaldoBanyak = 0;
        } else {
            if(saldo > 80 && saldo < 100){
                NasabahSaldoBanyak = (float) ((saldo - 80)/20);
            } else NasabahSaldoBanyak = 1;
        }
    }
    //UMUR
     void HitungUmur(float umur){
        if (umur <= 1){
            NasabahUmurBaru = 1;
        }else{
            if(umur < 3){
                NasabahUmurBaru = (float) ((-umur + 3)/2);
            }
            else {
                NasabahUmurBaru = 0;
            }
        }
        if(umur <= 1 || umur>= 7){
            NasabahUmurLama = 0;
        } else{
            if (umur> 1 && umur < 3){
                NasabahUmurLama = (float) ((umur - 1 )/2);
            }else {
                if (umur> 5 && umur < 7){
                    NasabahUmurLama = (float) ((-umur + 7)/2);
                } else {
                    NasabahUmurLama = 1;
                }
            }
        }
        if(umur <= 5){
            NasabahUmurSetia = 0;
        } else {
            if(umur > 5 && umur < 7){
                NasabahUmurSetia = (float) ((umur - 5)/2);
            } else NasabahUmurSetia = 1;
        }
    }
    //RULE

    void RULE(){
    float A; int i;
    //NASABAH POINT SEDIKIT SALDO SEDIKIT==================================================================
    if((NasabahPointSedikit !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurBaru !=0) ){
         i=1; A = min(NasabahPointSedikit,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 1"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
    if((NasabahPointSedikit !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurLama !=0) ){
         i=2; A = min(NasabahPointSedikit,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 2"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
    if((NasabahPointSedikit !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurSetia !=0) ){
         i=3; A = min(NasabahPointSedikit,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 3"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
   //NASABAH POINT SEDIKIT SALDO CUKUP
     if((NasabahPointSedikit !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurBaru !=0) ){
         i=4; A = min(NasabahPointSedikit,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 4"); strcpy(N[i].label,"TIDAK LAYAK");  U=U+1;}
     if((NasabahPointSedikit !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurLama !=0) ){
         i=5; A = min(NasabahPointSedikit,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 5"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
     if((NasabahPointSedikit !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurSetia !=0) ){
         i=6; A = min(NasabahPointSedikit,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 6"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
    //NASABAH POINT SEDIKIT SALDO BANYAK
     if((NasabahPointSedikit !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurBaru !=0) ){
         i=7; A = min(NasabahPointSedikit,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 7"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
     if((NasabahPointSedikit !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurLama !=0) ){
         i=8; A = min(NasabahPointSedikit,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 8"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
     if((NasabahPointSedikit !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurSetia !=0) ){
         i=9; A = min(NasabahPointSedikit,NasabahSaldoBanyak);N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 9"); strcpy(N[i].label,"LAYAK"); U=U+1; }
       //NASABAH POINT CUKUP SALDO SEDIKIT=================================================================
    if((NasabahPointCukup !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurBaru !=0) ){
         i=10; A = min(NasabahPointCukup,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 10"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
    if((NasabahPointCukup !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurLama !=0) ){
         i=11; A = min(NasabahPointCukup,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 11"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
    if((NasabahPointCukup !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurSetia !=0) ){
         i=12; A = min(NasabahPointCukup,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 12"); strcpy(N[i].label,"TIDAK LAYAK");}
    //NASABAH POINT CUKUP SALDO CUKUP
     if((NasabahPointCukup !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurBaru !=0) ){
         i=13; A = min(NasabahPointCukup,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 13"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
     if((NasabahPointCukup !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurLama !=0) ){
         i=14; A = min(NasabahPointCukup,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 14"); strcpy(N[i].label,"LAYAK"); U=U+1; }
     if((NasabahPointCukup !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurSetia !=0) ){
         i=15; A = min(NasabahPointCukup,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 15"); strcpy(N[i].label,"LAYAK"); U=U+1; }
    //NASABAH POINT CUKUP SALDO BANYAK
     if((NasabahPointCukup !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurBaru !=0) ){
         i=16; A = min(NasabahPointCukup,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 16"); strcpy(N[i].label,"LAYAK"); U=U+1; }
     if((NasabahPointCukup !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurLama !=0) ){
         i=17; A = min(NasabahPointCukup,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 17"); strcpy(N[i].label,"LAYAK"); U=U+1; }
     if((NasabahPointCukup !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurSetia !=0) ){
         i=18; A = min(NasabahPointCukup,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 18"); strcpy(N[i].label,"LAYAK"); U=U+1; }
   //NASABAH POINT BANYAK SALDO SEDIKIT====================================================================
    if((NasabahPointBesar !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurBaru !=0) ){
         i=19; A = min(NasabahPointBesar,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 19"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
    if((NasabahPointBesar !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurLama !=0) ){
         i=20; A = min(NasabahPointBesar,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 20"); strcpy(N[i].label,"LAYAK"); U=U+1; }
    if((NasabahPointBesar !=0) && (NasabahSaldoSedikit != 0) && (NasabahUmurSetia !=0) ){
         i=21; A = min(NasabahPointBesar,NasabahSaldoSedikit); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 21"); strcpy(N[i].label,"TIDAK LAYAK"); U=U+1; }
    //NASABAH POINT BANYAK SALDO CUKUP
     if((NasabahPointBesar !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurBaru !=0) ){
         i=22; A = min(NasabahPointBesar,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 22"); strcpy(N[i].label,"LAYAK"); U=U+1; }
     if((NasabahPointBesar !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurLama !=0) ){
         i=23; A = min(NasabahPointBesar,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 23"); strcpy(N[i].label,"LAYAK"); U=U+1; }
     if((NasabahPointBesar !=0) && (NasabahSaldoCukup != 0) && (NasabahUmurSetia !=0) ){
         i=24; A = min(NasabahPointBesar,NasabahSaldoCukup); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 24"); strcpy(N[i].label,"LAYAK"); U=U+1; }
    //NASABAH POINT BANYAK SALDO BANYAK
     if((NasabahPointBesar !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurBaru !=0) ){
         i=25; A = min(NasabahPointBesar,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurBaru);
         strcpy(N[i].rules,"RULE 25"); strcpy(N[i].label,"LAYAK"); U=U+1; }
     if((NasabahPointBesar !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurLama !=0) ){
         i=26; A = min(NasabahPointBesar,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurLama);
         strcpy(N[i].rules,"RULE 26"); strcpy(N[i].label,"LAYAK"); U=U+1; }
     if((NasabahPointBesar !=0) && (NasabahSaldoBanyak != 0) && (NasabahUmurSetia !=0) ){
         i=27; A = min(NasabahPointBesar,NasabahSaldoBanyak); N[i].NK = min(A,NasabahUmurSetia);
         strcpy(N[i].rules,"RULE 27"); strcpy(N[i].label,"LAYAK"); U=U+1;  }
    }
    float LMAX=0;
     float TLMAX=0;

    void cetak(){
    int i;
    cout<<"======POINT======"<<endl;
    cout<<"SEDIKIT  = "<<NasabahPointSedikit<<endl;
    cout<<"CUKUP    = "<<NasabahPointCukup<<endl;
    cout<<"BESAR    = "<<NasabahPointBesar<<endl;

    cout<<"======SALDO======"<<endl;
    cout<<"SEDIKIT  = "<<NasabahSaldoSedikit<<endl;
    cout<<"CUKUP    = "<<NasabahSaldoCukup<<endl;
    cout<<"BESAR    = "<<NasabahSaldoBanyak<<endl;

    cout<<"======UMUR======"<<endl;
    cout<<"Baru     = "<<NasabahUmurBaru<<endl;
    cout<<"Lama     = "<<NasabahUmurLama<<endl;
    cout<<"Setia    = "<<NasabahUmurSetia<<endl;
    cout<<"\n";
    cout<<"RULE YANG DIGUNAKAN :\n";
    for(i=0; i<=27; i++){
    if ((N[i].NK != 0) && (N[i].NK <= 1 ) && (N[i].NK >0) ){
    cout<<""<<N[i].rules<<" Dengan Nilai Kelayakan = "<<N[i].NK<<" "<<N[i].label<<endl; }
    }


    for(i=0; i<=27; i++){
         if(strcmp(N[i].label,"LAYAK")==0){
            LMAX = max(LMAX,N[i].NK);
        }
        else if(strcmp(N[i].label,"TIDAK LAYAK")==0){
             TLMAX = max(TLMAX,N[i].NK);
        }
    }
    cout<<"Nilai Output Fuzzy :\n";
    cout<<"NK LAYAK = "<<LMAX<<endl;
    cout<<"NK TIDAK LAYAK = "<<TLMAX<<endl;


    }
    float defuzzifikasi(int sampel){
            float pengaliX, pengaliY;
            float hasilPembilang = 0;
            float hasilPenyebut = 0;
            float hasilDefuzzifikasi;
            int titik_sampel = 0;
            int jumlah_sampelX = 0;
            int jumlah_sampelY = 0;
            float pengaliZ[1000], titik_sampelZ[1000];
            int delta = 0;
            int k = 0;
            pengaliX = TLMAX;

            pengaliY = LMAX;
            delta = 100 / sampel;
            titik_sampel = titik_sampel +  delta;
            for(int i = 1;i <= sampel; i++){
                if(titik_sampel <= 50){
                    hasilPembilang += titik_sampel * pengaliX;
                    jumlah_sampelX =jumlah_sampelX + 1;
                }else if(titik_sampel >= 80){
                    hasilPembilang += titik_sampel * pengaliY;
                    jumlah_sampelY += 1;
                }else if((titik_sampel > 50) && (titik_sampel < 80)){
                    if(pengaliX > pengaliY){
                        titik_sampelZ[k] = titik_sampel;
                        pengaliZ[k] = (float)(((80 - titik_sampelZ[k])/30));
                        hasilPembilang += titik_sampelZ[k] * pengaliZ[k];
                    }else{
                        titik_sampelZ[k] = titik_sampel;
                        pengaliZ[k] = (float)(((titik_sampelZ[k] - 50)/30));
                        hasilPembilang += titik_sampelZ[k] * pengaliZ[k];
                    }
                    k += 1;
                }
                titik_sampel += delta;
            }
            hasilPenyebut = (jumlah_sampelX * pengaliX) + (jumlah_sampelY * pengaliY);
            for(int i = 0;i < k;i++){
                hasilPenyebut += pengaliZ[i];
            }
            cout << "\nHasil Pembilang\t\t= " << hasilPembilang << endl;
            cout << "Hasil Penyebut\t\t= " << hasilPenyebut << endl;
            hasilDefuzzifikasi = hasilPembilang / hasilPenyebut;
            return hasilDefuzzifikasi;
        }
        void grafik(float na){
    cout<<"\n BERIKUT GRAFIKNYA :\n";
    float TL = 0;
    float L = 0;
    TL = 300- (TLMAX * 200);
    L = 300 - (LMAX * 200);
     float hasil = na;
     hasil = ((hasil/100) * 400);
    int gd = DETECT, gm;
   initgraph(&gd, &gm, "INI GAMBARNYA");
    // TITIK
    int x_circle = hasil;
    int y_circle = 300;
    setfillstyle(SOLID_FILL,RED);
    circle(x_circle,y_circle,5);
    floodfill(x_circle,y_circle,WHITE);
    // line for x1, y1, x2, y2
    line(100, 100, 200, 100); // atas tidak layak
    line(100, 300, 570, 300); // bawah
    line(100, 60, 100, 300);
    //garis silang
    line(200, 100, 320, 300);
    line(200, 300, 320, 100);
    //garis lurus atas Layak
    line(320, 100, 570, 100);

     line(100, TL, 260, TL );
    line(260, L, 500, L);


     setlinestyle(DOTTED_LINE, 0, 1);
     line(200, 100, 200, 300);
     line(320, 100, 320, 300);
     line(500, 100, 500, 300);
    getch();
    closegraph();
        }
};
int main()
{
    float poin,sal,age;
    int sampel;
    float na;
    fuzzy fz;

    cout << "Masukkan Jumlah Point : ";
    cin >> poin;
    cout << "Masukkan Jumlah Saldo (Juta) : ";
    cin >> sal;
    cout << "Masukkan Umur Menjadi Nasabah (Tahun) : ";
    cin >> age;

    fz.HitungPoint(poin);
    fz.HitungSaldo(sal);
    fz.HitungUmur(age);
    fz.RULE();
    fz.cetak();
    cout << "\n=====DEFUZZIFIKASI=====\n";
	cout<< "\nMasukkan jumlah sampel\t="; cin >> sampel;
	cout << endl;
    na = fz.defuzzifikasi(sampel);
	cout<< "Nilai Akhir \t\t= " << na;
	fz.grafik(na);
    return 0;
}
