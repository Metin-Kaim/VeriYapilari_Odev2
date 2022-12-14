#include "Kontrol.hpp"
#include <iostream>
#include <iomanip>
#include "BagilAgac.hpp"

using namespace std;

Kontrol::Kontrol(Organizma *organizma)
{
    this->organizma = organizma;
    organDGec = NULL;
    sayac = -1;
}

Kontrol::~Kontrol(){}

void Kontrol::bolunmeKontrol()
{
    cout << setw(25) << ""
         << "ORGANIZMA (MUTASYONA UGRADI)\n\n";
    orgGec = organizma->ilkSistemD;

    while (orgGec != 0)
    {
        for (int i = 0; i < 100; i++)
        {
            if (organDGec == NULL)
            {
                organDGec = orgGec->sistemAdres->ilkOrganD;
            }
            else
                organDGec = organDGec->sonraki;

            if (organDGec->organAdres->agac->kok->veri % 50 == 0) // mutasyona ugrayan ikili arama agaci
            {
                sayac = -1;
                postOrder(organDGec->organAdres->agac->kok); // dokuDizisi dizisi ilgili organın doku nesneleriyle dolu
                organDGec->organAdres->agacSil();//eski agaci sil
                for (int j = 0; j < 20; j++)
                {
                    for (int k = 0; k < dokudizisi[j]->hucreSayiAdedi; k++)
                    {
                        if (dokudizisi[j]->dizi[k].veri % 2 == 0)
                        {
                            dokudizisi[j]->dizi[k].veri = dokudizisi[j]->dizi[k].veri / 2;
                        }
                    }
                }

                organDGec->organAdres->agacaEkle(false);
                delete[] dokudizisi;
             }
        }

        orgGec = orgGec->sonraki;
        organDGec = NULL;
        //cout << endl;
    }

    orgGec = organizma->ilkSistemD;

    while (orgGec != 0)
    {
        SOrganDugum *sod = 0;
        for (int i = 0; i < 100; i++)
        {
            if (sod == NULL)
            {
                sod = orgGec->sistemAdres->ilkOrganD;
            }
            else
                sod = sod->sonraki;

            sod->organAdres->agac->avlDengesi(sod->organAdres->agac->kok);
        }
        cout << endl;
        orgGec = orgGec->sonraki;
    }
}

Doku **Kontrol::postOrder(Dugum *aktif)
{
    if (aktif)
    {
        if (sayac == -1)
        {
            dokudizisi = new Doku *[20];
            sayac++;
        }
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        dokudizisi[sayac] = aktif->doku;
        sayac++;
    }

    return dokudizisi;
}