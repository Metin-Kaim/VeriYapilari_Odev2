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
}

void Organ::agacaEkle(bool sadeceAVL)
{
    BagilAgac *yeniAgac = new BagilAgac();
    agac = yeniAgac;
    ODokuDugum *gec = ilkOrganD;
    RadixSort *rs = new RadixSort();
    while (gec != 0)
    {
        // Hucre *dizi = gec->dokuAdres->getHucreVeriDizisi();
        // cout<<dizi[0].veri<<" "<<dizi[1].veri<<endl;
        rs->radixSort(gec->dokuAdres->dizi, gec->dokuAdres->hucreSayiAdedi);
        int ortSayi2 = ceil(gec->dokuAdres->hucreSayiAdedi / 2);
        int ortSayi = gec->dokuAdres->dizi[ortSayi2].veri;
        yeniAgac->ekle(gec->dokuAdres, ortSayi);
        gec = gec->sonraki;
    }

    kokAdres = yeniAgac->kok;
    if (sadeceAVL)
        yeniAgac->avlDengesi(kokAdres);
    // cout<<"-";
}

Dugum *Organ::getKokAdres()
{
    return kokAdres;
}