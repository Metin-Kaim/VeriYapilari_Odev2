#include "DHucreDugum.hpp"

DHucreDugum::DHucreDugum(Hucre *yeniHucre)
{
    hucreAdresi = yeniHucre;
    sonraki = 0;
}

DHucreDugum::~DHucreDugum()
{
    delete hucreAdresi;
}