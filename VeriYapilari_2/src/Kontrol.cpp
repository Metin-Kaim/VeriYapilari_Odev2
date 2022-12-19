/*
* @file             Kontrol.cpp
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

#include "Kontrol.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Kontrol::Kontrol(Organizma *organizma)//Organizmaya erişim
{
    this->organizma = organizma;
    organDGec = NULL;
    sayac = -1;
}

Kontrol::~Kontrol() {}

void Kontrol::bolunmeKontrol()//mutasyon kontrolü
{
    cout << setw(25) << ""
         << "ORGANIZMA (MUTASYONA UGRADI)\n\n";

    orgGec = organizma->ilkSistemD; // organizmanın ilk OrganizmaSistemDüğümüne erişim

    while (orgGec != 0)//Tüm OrganizmaSistemDüğümlerini (Sistemleri) gezecek
    {
        for (int i = 0; i < 100; i++)//her sistemin sahip olduğu organları gezecek
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
                organDGec->organAdres->agacSil();            // eski agaci sil
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

                organDGec->organAdres->agacaEkle(); //yeni ağaç oluşturup değerleri ekleme
                delete[] dokudizisi; // oluşturulan dokuDizisini silme
            }
        }

        orgGec = orgGec->sonraki;//bir sonraki sisteme geçme
        organDGec = NULL;//her yeni sisteme geçildiğinde organDüğümlerini tutan pointerı sıfırlama
    }//while sonu // tüm organizma tarandı ve mutasyon işlemi tamamlandı

    orgGec = organizma->ilkSistemD; // tekrardan ilk sisteme geçildi

    while (orgGec != 0)//organizmadaki tüm ağaçlar sırasıyla taranarak gerekli değerler ekrana yazdırılacak
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

            sod->organAdres->agac->avlDengesi(sod->organAdres->agac->kok);//ağaç tarama kısmı
        }
        cout << endl;
        orgGec = orgGec->sonraki;
    }
}

Doku **Kontrol::postOrder(Dugum *aktif)//ağacı postOrder olarak okuyup içindeki doku değerlerini diziye alma
{
    if (aktif)
    {
        if (sayac == -1)
        {
            dokudizisi = new Doku *[20]; // her organ 20 adet doku tuttuğu için 20 uzunluklu bir dizi oluşturma
            sayac++;
        }
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        dokudizisi[sayac] = aktif->doku;
        sayac++;
    }

    return dokudizisi;
}