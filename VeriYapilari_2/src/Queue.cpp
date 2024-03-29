/*
* @file             Queue.cpp
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

#include "Queue.hpp"

Kuyruk::Kuyruk()
{
    ilk = 0;
    son = -1;
    veriler = 0;
    veriSayisi = 0;
    kapasite = 0;
    genislet(5);
}

Kuyruk::~Kuyruk()
{
    delete[] veriler;
}

void Kuyruk::ekle(int veri)
{
    if (son == kapasite - 1)
        genislet(kapasite);
    son++;
    veriler[son] = veri;
    veriSayisi++;
}

void Kuyruk::cikar()
{
    if (veriSayisi != 0)
    {
        ilk++;
        veriSayisi--;
    }
}

int Kuyruk::getir() // ilk veriyi getirme
{
    if (veriSayisi != 0)
        return veriler[ilk];
}

bool Kuyruk::bosmu()
{
    if (veriSayisi == 0)
        return true;
    return false;
}

void Kuyruk::genislet(int boyut)
{
    int *yeniAlan = new int[boyut + kapasite];
    int yeniIndex = 0;
    for (int i = ilk; i <= son; i++)
    {
        yeniAlan[yeniIndex] = veriler[i];
        yeniIndex++;
    }
    if (veriler)
        delete[] veriler;
    son = veriSayisi - 1;
    ilk = 0;
    veriler = yeniAlan;
    kapasite += boyut;
}