#include <iostream>
#include "Queue.hpp"

using namespace std;

// Yapıcı fonksiyon
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

int Kuyruk::getir()
{
    if (veriSayisi != 0)
        return veriler[ilk];
    throw out_of_range("Kuyruk Bos");
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