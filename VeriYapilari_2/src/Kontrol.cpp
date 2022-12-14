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

            if (organDGec->organAdres->getKokAdres()->veri % 50 == 0) // mutasyona ugrayan ikili arama agaci
            {
                // cout<<endl<<organDGec->organAdres->getKokAdres()->veri<<endl;
                sayac = -1;
                postOrder(organDGec->organAdres->getKokAdres()); // dokuDizisi dizisi ilgili organın doku nesneleriyle dolu
                for (int j = 0; j < 20; j++)
                {
                    //dokudizisi[j]->getHucreVeriDizisi();
                    for (int k = 0; k < dokudizisi[j]->hucreSayiAdedi; k++)
                    {
                        if (dokudizisi[j]->dizi[k].veri % 2 == 0)
                        {
                            dokudizisi[j]->dizi[k].veri = dokudizisi[j]->dizi[k].veri / 2;
                    //cout << dokudizisi[j]->dizi[k].veri<<" ";

                        }
                    }
                    // cout<<hucreDizisi[0].veri<<" "<<hucreDizisi[1].veri<<" "<<hucreDizisi[2].veri<<endl;
                }

                organDGec->organAdres->agacaEkle(true);
                // agac silme
            }
            else
            {
                organDGec->organAdres->agac->avlDengesi(organDGec->organAdres->getKokAdres());
            }
        }

        orgGec = orgGec->sonraki;
        organDGec = NULL;
        cout << endl;
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