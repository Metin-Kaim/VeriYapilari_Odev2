#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"
#include "DHucreDugum.hpp"
class Doku
{
public:
    Doku(int);
    ~Doku();
    Hucre *dizi;
    DHucreDugum *ilkHucreD;
    int hucreSayiAdedi;
};


#endif