#include "ODokuDugum.hpp"
#include "iostream"
using namespace std;
ODokuDugum::ODokuDugum()
{
    dokuAdres = 0;
    sonraki = 0;
}

ODokuDugum::~ODokuDugum()
{
    delete dokuAdres;
}