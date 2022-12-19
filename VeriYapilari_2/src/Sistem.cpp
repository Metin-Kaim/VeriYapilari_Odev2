/*
* @file             Sistem.cpp
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

#include "Sistem.hpp"

Sistem::Sistem() // sistem oluştuğunda otomatik olarak 100 adet SistemOrganDüğümü ve yine 100 adet Organ oluşturma
{
    ilkOrganD = 0;
    for (int i = 0; i < 100; i++)
    {
        SOrganDugum *yeniOrganDugum = new SOrganDugum(new Organ());
        if (ilkOrganD == 0)
            ilkOrganD = yeniOrganDugum;
        else // Düğümleri birbirine bağlama
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

Sistem::~Sistem() // Sistemi ve sistemin bağlı olduğu tüm SOrganDüğümleri de silme
{
    for (int i = 0; i < 100; i++)
    {
        SOrganDugum *sil = ilkOrganD;
        ilkOrganD = ilkOrganD->sonraki;
        delete sil;
    }
}