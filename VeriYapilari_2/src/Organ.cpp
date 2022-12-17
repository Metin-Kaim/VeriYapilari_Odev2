/*
* @file             Organ.cpp
* @description      Verilen "veri.txt" adlı dosaydaki verileri okuyarak bunları hücre yapılarında tutmak
                    ve bu hücre yapılarını doku yapılarında, bu doku yapılarını organ yapılarında,
                    organ yapılarını da sistem yapılarında ve son olarak sistemleri de bir adet organizma yapısnda tutmak.
                    Ardından bu verileri ağaç yapılarına ekleyerek ekrana belli bir şekil çıkarmak ve enter tuşuna basıldığında
                    Bu şeklin belli şartlar dahilinde mutasyona uğramasını sağlamak.                                           
* @course           1. Öğretim A grubu
* @assignment       2. Ödev
* @date             17.12.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#include "Organ.hpp"
#include "Doku.hpp"
#include "iostream"
#include "BagilAgac.hpp"
#include "math.h"
#include "RadixSort.hpp"
using namespace std;
Organ::Organ()
{
    kokAdres = 0;
    ilkOrganD = 0;
    agac = 0;
    for (int i = 0; i < 20; i++)
    {
        ODokuDugum *yeniOrganDugum = new ODokuDugum();
        if (ilkOrganD == 0)
        {
            ilkOrganD = yeniOrganDugum;
        }
        else
        {
            ODokuDugum *gec_sl = ilkOrganD;
            while (gec_sl->sonraki != 0) // gec son dugumu gostermekte
            {
                gec_sl = gec_sl->sonraki;
            }

            gec_sl->sonraki = yeniOrganDugum;
        }
    }
}

Organ::~Organ()
{
    for (int i = 0; i < 20; i++)
    {
        ODokuDugum *sil = ilkOrganD;
        ilkOrganD = ilkOrganD->sonraki;
        delete sil;
    }
    agacSil();
}

void Organ::agacaEkle(bool sadeceAVL)
{
    agac = new BagilAgac();

    ODokuDugum *gec = ilkOrganD;
    RadixSort *rs = new RadixSort();
    
    while (gec != 0)
    {
        // Hucre *dizi = gec->dokuAdres->getHucreVeriDizisi();
        // cout<<dizi[0].veri<<" "<<dizi[1].veri<<endl;
        rs->radixSort(gec->dokuAdres->dizi, gec->dokuAdres->hucreSayiAdedi);
        int ortSayi2 = ceil(gec->dokuAdres->hucreSayiAdedi / 2);
        int ortSayi = gec->dokuAdres->dizi[ortSayi2].veri;
        agac->ekle(gec->dokuAdres, ortSayi);
        gec = gec->sonraki;
    }
    delete rs;

    // kokAdres = yeniAgac->kok;
    //  if (sadeceAVL)
    //      yeniAgac->avlDengesi(kokAdres);
    //  // cout<<"-";
}

void Organ::agacSil()
{
    delete agac;
}

Dugum *Organ::getKokAdres()
{
    return kokAdres;
}