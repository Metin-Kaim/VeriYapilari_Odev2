#ifndef DHucreDugum_hpp
#define DHucreDugum_hpp
#include "Hucre.hpp"

class DHucreDugum
{
public:
    DHucreDugum(Hucre*);
    ~DHucreDugum();

    Hucre *hucreAdresi;
    DHucreDugum *sonraki;
};

#endif