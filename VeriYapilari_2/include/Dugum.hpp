#ifndef Dugum_hpp
#define Dugum_hpp
#include "Doku.hpp"
class Dugum
{
public:
    Dugum(Doku*, int);
    Doku *doku;
    int veri;
    Dugum* sol;
    Dugum* sag;
};

#endif
