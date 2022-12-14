#include "Dugum.hpp"

using namespace std;

Dugum::Dugum(Doku *doku, int veri)
{
    this->doku = doku;
    this->veri = veri;
    sol = 0;
    sag = 0;
}

Dugum::~Dugum()
{
    if (sol)
        delete sol;
    if (sag)
        delete sag;
}