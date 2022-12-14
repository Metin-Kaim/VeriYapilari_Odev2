#ifndef ODokuDugum_hpp
#define ODokuDugum_hpp
#include "Doku.hpp"

class ODokuDugum
{
public:
    ODokuDugum();   
    ~ODokuDugum();

    Doku *dokuAdres;
    ODokuDugum *sonraki;
};

#endif