#include "Doku.hpp"
#include <iostream>
using namespace std;
Doku::Doku(int hucreSayiAdedi)
{
    this->hucreSayiAdedi=hucreSayiAdedi;
    dizi = new Hucre[hucreSayiAdedi];
    ilkHucreD=0;
    for (int i = 0; i < hucreSayiAdedi; i++)
    {
        DHucreDugum *yeniHucreD = new DHucreDugum(new Hucre());

        if (ilkHucreD == 0)
            ilkHucreD = yeniHucreD;
        else
        {
            DHucreDugum *gec_sl = ilkHucreD;

            while (gec_sl->sonraki != 0) // gec son dugumu gostermekte
            {
                gec_sl = gec_sl->sonraki;
            }

            gec_sl->sonraki = yeniHucreD;
        }
            dizi[i]=*(yeniHucreD->hucreAdresi);

    }
}

Doku::~Doku()
{
    for (int i = 0; i < hucreSayiAdedi; i++)
    {
        DHucreDugum *sil = ilkHucreD;
        ilkHucreD=ilkHucreD->sonraki;
        delete sil;
    }
    
}

Hucre *Doku::getHucreVeriDizisi()
{
    //Hucre *dizi = new Hucre[hucreSayiAdedi];
    // DHucreDugum *gec = ilkHucreD;
    // int sayac = 0;
    // while (gec != 0)
    // {
    //     dizi[sayac] = *(gec->hucreAdresi);
    //     sayac++;
    //     gec = gec->sonraki;
    // }
    return dizi;
}