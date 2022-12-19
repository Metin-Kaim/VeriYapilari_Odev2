/*
* @file             Doku.cpp
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

#include "Doku.hpp"

Doku::Doku(int hucreSayiAdedi) // alınan sayıya göre hücre düğümü ve hücre oluşturma
{
    this->hucreSayiAdedi = hucreSayiAdedi;
    dizi = new Hucre[hucreSayiAdedi]; // hücreleri tutacak olan dizi
    ilkHucreD = 0;
    for (int i = 0; i < hucreSayiAdedi; i++)
    {
        DHucreDugum *yeniHucreD = new DHucreDugum(new Hucre());

        if (ilkHucreD == 0)
            ilkHucreD = yeniHucreD;
        else // düğümleri birbirine bağlama
        {
            DHucreDugum *gec_sl = ilkHucreD;

            while (gec_sl->sonraki != 0)
            {
                gec_sl = gec_sl->sonraki;
            } // gec son dugumu gostermekte

            gec_sl->sonraki = yeniHucreD;
        }
        dizi[i] = *(yeniHucreD->hucreAdresi); // oluşturulan hücreyi diziye atama
    }
}

Doku::~Doku() // Dokuyu, sahip olduğu hücre düğümlerini ve diziyi silme
{
    for (int i = 0; i < hucreSayiAdedi; i++)
    {
        DHucreDugum *sil = ilkHucreD;
        ilkHucreD = ilkHucreD->sonraki;
        delete sil;
    }
    delete[] dizi;
}