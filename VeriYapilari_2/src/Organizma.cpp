/*
* @file             Organizma.cpp
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

#include "Organizma.hpp"
#include "Sistem.hpp"
#include "iostream"
using namespace std;

Organizma::Organizma() // düğümleri tutacak olan pointerı oluşturup sıfırlama
{
    ilkSistemD = 0; // Sistem düğümünü tutan pointer
}

void Organizma::sistemOlustur() // yeni bir sistem düğümünü oluşturup bunu önceki düğümlere bağlama
{
    OSistemDugum *yeni_sl = new OSistemDugum(new Sistem()); // yeni bir OrganizmaSistemDüğümü oluşturma ve yeni bir sistem oluşturma
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

Organizma::~Organizma() // Organizmayı ve tüm OrganizmaSistemDüğümlerini silme
{
    while (ilkSistemD != 0)
    {
        OSistemDugum *sil = ilkSistemD;
        ilkSistemD = ilkSistemD->sonraki;
        delete sil;
    }
}