#ifndef OSistemDugum_hpp
#define OSistemDugum_hpp
#include "Sistem.hpp"
class OSistemDugum
{
public:
    OSistemDugum(Sistem*);
    ~OSistemDugum();
    Sistem *sistemAdres;
    OSistemDugum *sonraki;
};

#endif