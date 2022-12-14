#include "OSistemDugum.hpp"
#include <iostream>
using namespace std;
OSistemDugum::OSistemDugum(Sistem *yeniSistem)
{
    sistemAdres = yeniSistem;
    sonraki = 0;
}

OSistemDugum::~OSistemDugum()
{
    delete sistemAdres;
}