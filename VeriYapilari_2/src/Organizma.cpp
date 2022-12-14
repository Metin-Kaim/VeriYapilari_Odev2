#include "Organizma.hpp"
#include "Sistem.hpp"
#include "iostream"
using namespace std;

Organizma::Organizma()
{
    ilkSistemD=0;
}

void Organizma::sistemOlustur()
{
    OSistemDugum *yeni_sl = new OSistemDugum(new Sistem());
    if (ilkSistemD == 0)
        ilkSistemD = yeni_sl;
    else // eger ki halihazirda dugum var ise
    {
        OSistemDugum *gec_sl = ilkSistemD;

        while (gec_sl->sonraki != 0) // gec son dugumu gostermekte
        {
            gec_sl = gec_sl->sonraki;
        }

        gec_sl->sonraki = yeni_sl;
    }
}

Organizma::~Organizma()
{
    while(ilkSistemD!=0)
    {
        OSistemDugum *sil=ilkSistemD;
        ilkSistemD=ilkSistemD->sonraki;
        delete sil;
    }
}