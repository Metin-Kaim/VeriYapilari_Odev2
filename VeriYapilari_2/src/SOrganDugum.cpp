#include "SOrganDugum.hpp"
#include "iostream"
using namespace std;
SOrganDugum::SOrganDugum(Organ *yeniOrgan)
{
    sonraki = 0;
    organAdres = yeniOrgan;
}

SOrganDugum::~SOrganDugum()
{
    delete organAdres;
}