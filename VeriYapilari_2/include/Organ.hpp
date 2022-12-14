#ifndef Organ_hpp
#define Organ_hpp
#include "ODokuDugum.hpp"
#include "Dugum.hpp"
#include "BagilAgac.hpp"

class Organ
{
public:
    Organ();
    ~Organ();

    void agacaEkle(bool);
    void agacSil();

    ODokuDugum *ilkOrganD;

    Dugum *getKokAdres();

    BagilAgac *agac;

private:
    Dugum *kokAdres;
};

#endif