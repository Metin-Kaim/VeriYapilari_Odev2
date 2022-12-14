#include "Sistem.hpp"
#include "Organ.hpp"
#include "iostream"
using namespace std;
Sistem::Sistem()
{
    ilkOrganD = 0;
    for (int i = 0; i < 100; i++)
    {
        SOrganDugum *yeniOrganDugum = new SOrganDugum(new Organ());
        if (ilkOrganD == 0)
            ilkOrganD = yeniOrganDugum;
        else
        {
            SOrganDugum *gec_sl = ilkOrganD;

            while (gec_sl->sonraki != 0) // gec son dugumu gostermekte
            {
                gec_sl = gec_sl->sonraki;
            }

            gec_sl->sonraki = yeniOrganDugum;
        }
    }
}

Sistem::~Sistem()
{
    for (int i = 0; i < 100; i++)
    {
        SOrganDugum *sil = ilkOrganD;
        ilkOrganD = ilkOrganD->sonraki;
        delete sil;
    }
}