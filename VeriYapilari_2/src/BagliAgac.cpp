/*
* @file             BagliAgac.cpp
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

#include "BagilAgac.hpp"
#include <iostream>

using namespace std;
BagilAgac::BagilAgac() // ağaç oluştuğunda kökü sıfırlama
{
    kok = 0;
}

BagilAgac::~BagilAgac() // BağılAğacı ve kök düğümü silme
{
    delete kok;
}

void BagilAgac::ekle(Doku *doku, int ortSayi) // Dışarıya açık olan ekleme fonksiyonu // Private olan ekleme fonksiyonunu çağırıyor
{
    ekle(doku, ortSayi, kok);
}

void BagilAgac::ekle(Doku *doku, int ortSayi, Dugum *aktifDugum) // Private olan ekleme fonksiyonu
{
    if (kok == 0) // ağaçta hiç düğüm yoksa
    {
        kok = new Dugum(doku, ortSayi);
        return;
    }

    // ağaçta düğüm varsa

    if (aktifDugum->veri >= ortSayi) // sola ekleme
    {
        if (aktifDugum->sol == 0) // sol taraf boş ise
            aktifDugum->sol = new Dugum(doku, ortSayi);
        else
            ekle(doku, ortSayi, aktifDugum->sol);
    }
    else if (aktifDugum->veri < ortSayi) // sağa ekleme
    {
        if (aktifDugum->sag == 0) // sağ taraf boş ise
            aktifDugum->sag = new Dugum(doku, ortSayi);
        else
            ekle(doku, ortSayi, aktifDugum->sag);
    }
}

int BagilAgac::yukseklikBulma(Dugum *aktifDugum)
{
    if (aktifDugum)
    {
        return 1 + (yukseklikBulma(aktifDugum->sol), yukseklikBulma(aktifDugum->sag));
    }

    return -1;
}

void BagilAgac::avlDengesi(Dugum *aktifDugum) // Ağacı tarayıp avl dengesine göre konsola değer yazdırma
{
    if (abs(yukseklikBulma(aktifDugum->sag) - yukseklikBulma(aktifDugum->sol)) > 1)
    {
        cout << "#";
        return;
    }
    cout << " ";
}