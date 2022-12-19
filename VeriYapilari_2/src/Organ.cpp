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

Organ::Organ() // Organ oluştuğunda otomatik olarak kendisine ve birbirlerine bağlı 20 adet OrganDokuDüğümü oluşturma
{              // !!! Diğer kısımlarda olduğu gibi burada düğüme bağlı herhangi bir yapı (Doku) oluşturulmuyor.
               // Doku yapısı ayrı olarak oluşturulup buraya eklenecek.
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

Organ::~Organ() // Organ yapısını, içindeki ODokuDüğüm yapılarını ve sahip olduğu ağacı silme
{
    for (int i = 0; i < 20; i++)
    {
        ODokuDugum *sil = ilkOrganD;
        ilkOrganD = ilkOrganD->sonraki;
        delete sil;
    }
    agacSil();
}

void Organ::agacaEkle() // Her bir organ için yeni bir ağaç yapısı oluşturup bu ağaca -gerekli işlemler yapıldıktan sonra-
                                      // sahip olunan doku yapılarını ekleme
{
    agac = new BagilAgac();

    ODokuDugum *gec = ilkOrganD;
    RadixSort *rs = new RadixSort();

    while (gec != 0)
    {
        rs->radixSort(gec->dokuAdres->dizi, gec->dokuAdres->hucreSayiAdedi); // organdaki doku dizisini hücre verilerine göre sıralama
        int ortSayi2 = ceil(gec->dokuAdres->hucreSayiAdedi / 2);             // hücre uzunluğuna göre orta sayı indexini hesaplama
        int ortSayi = gec->dokuAdres->dizi[ortSayi2].veri;                   // hücredeki ortanca sayıyı bulma
        agac->ekle(gec->dokuAdres, ortSayi);                                 // ağaca ekleme işlemi
        gec = gec->sonraki;
    }
    delete rs;
}

void Organ::agacSil() // ağacı silme
{
    delete agac;
}

// Dugum *Organ::getKokAdres() // organın sahip olduğu ağacın kök adresini alma
// {
//     return kokAdres;
// }