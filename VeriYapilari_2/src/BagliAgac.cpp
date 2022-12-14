#include "BagilAgac.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
BagilAgac::BagilAgac()
{
    kok = 0;
}

void BagilAgac::ekle(Doku *doku, int ortSayi)
{
    ekle(doku, ortSayi, kok);
}

void BagilAgac::ekle(Doku *doku, int ortSayi, Dugum *aktifDugum)
{
    if (kok == 0)
    {
        kok = new Dugum(doku, ortSayi);
        return;
    }

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

void BagilAgac::avlDengesi(Dugum *aktifDugum)
{
    if (abs(yukseklikBulma(aktifDugum->sag) - yukseklikBulma(aktifDugum->sol)) > 1)
    {
        cout << "#";
        return;
    }
    cout << " ";
}