/*
* @file             main.cpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme.
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#include "Organizma.hpp"
#include "Doku.hpp"
#include "Kontrol.hpp"

using namespace std;
int main()
{
    system("CLS");
    cout << setw(35) << ""
         << "ORGANIZMA\n\n";
    int satirSayisiKontrol = 0;
    int organSayaci = 0;
    bool organFlag = false;
    int dokuDugumuSayaci = 0;

    Organizma *organizma = new Organizma();
    organizma->sistemOlustur();
    ODokuDugum *dokuDGec = 0;   /////////////////
    SOrganDugum *organDGec = 0; ////////

    ifstream dosya;
    dosya.open("./veri.txt");

    while (!dosya.eof())
    {
        string satir;
        int sayiBaslangic = 0;
        int sayiAdedi = 0;

        getline(dosya, satir);

        if (satir == "") // Satirin boş olup olmadigini kontrol eden yapi.
        {
            continue;
        }
        satirSayisiKontrol++;

        // if (satirSayisiKontrol == 101)
        // {
        //     organizma->sistemOlustur();
        //     a++;
        //     satirSayisiKontrol = 1;
        // }

        for (int i = 0; i < satir.length(); i++) // bir satirda kac adet sayi oldugunu hesaplama
        {
            string islem = satir.substr(i, 1);
            if (islem != " ")
            {
                if (i == (satir.length()) - 1) // satir sonu
                    sayiAdedi++;
            }
            else
            { // boşluk ise
                sayiAdedi++;
            }
        }

        Doku *doku = new Doku(sayiAdedi); //

        DHucreDugum *gec = doku->ilkHucreD;
        int sayac=0;
        for (int i = 0; i < satir.length(); i++) // okunan satirdaki sayilari "sayilar" adli diziye aktarma
        {
            string islem = satir.substr(i, 1);
            if (islem == " ")
            { // boşluk ise
            doku->dizi[sayac].veri=stoi(satir.substr(sayiBaslangic, i - sayiBaslangic));
            sayac++;
                //gec->hucreAdresi->veri = stoi(satir.substr(sayiBaslangic, i - sayiBaslangic));
                gec = gec->sonraki;
                sayiBaslangic = i + 1;
            }
            else if (islem != " ")
            {
                if (i == (satir.length()) - 1) // satir sonu
                {
            doku->dizi[sayac].veri=stoi(satir.substr(sayiBaslangic, i - sayiBaslangic+1));
            sayac++;
                    // gec->hucreAdresi->veri = stoi(satir.substr(sayiBaslangic, i - sayiBaslangic + 1));
                    gec = gec->sonraki;
                    sayiBaslangic = i + 1;
                }
            }
        } // ilgili satır için okuma işlemi bitti

        if (organSayaci == 100 && organFlag == true)
        {
            organizma->sistemOlustur();
            //cout << endl;
            organSayaci = 0;
            organFlag = false;
        }

        OSistemDugum *orgGec = organizma->ilkSistemD;
        while (orgGec->sonraki != 0)
        {
            orgGec = orgGec->sonraki;
        } // orgGec son dugumu gosteriyor.

        if (organSayaci == 0)
        {
            organDGec = orgGec->sistemAdres->ilkOrganD;
            organSayaci++;
        }
        else if (organFlag)
        {
            organSayaci++;
            organDGec = organDGec->sonraki;
            organFlag = false;
        }

        if (dokuDugumuSayaci == 0)
        {
            dokuDGec = organDGec->organAdres->ilkOrganD;
            dokuDugumuSayaci++;
        }
        else
        {
            dokuDGec = dokuDGec->sonraki;
            dokuDugumuSayaci++;
        }
        dokuDGec->dokuAdres = doku; // doku, dokuDugume baglaniyor

        if (dokuDugumuSayaci == 20)
        {
            organDGec->organAdres->agacaEkle(false);
            // cout << organDGec->organAdres->kokAdres->veri<<" ";
            organFlag = true;
            dokuDugumuSayaci = 0;
        }
    }
    dosya.close();

    OSistemDugum *osd = organizma->ilkSistemD;
    
    while(osd!=0)
    {SOrganDugum *sod=0;
        for (int i = 0; i < 100; i++)
        {
            //cout<<"a";
            if (sod == NULL)
            {
                sod = osd->sistemAdres->ilkOrganD;
            }
            else
                sod = sod->sonraki;

            sod->organAdres->agac->avlDengesi(sod->organAdres->agac->kok);
            
        }
        cout << endl;
        osd=osd->sonraki;
    }
    
    cout << "\n\n";
    string myString;
    do
    {
        getline(cin, myString);
    } while (myString.length() != 0);

    system("CLS");
    
    Kontrol *k = new Kontrol(organizma);
    k->bolunmeKontrol();
    delete organizma;
    cout << "\n-----------------------------\n\nPROGRAM BITTI...\n\n-----------------------------" << endl;
}