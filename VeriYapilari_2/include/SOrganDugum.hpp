#ifndef SOrganDugum_hpp
#define SOrganDugum_hpp
#include "Organ.hpp"
class SOrganDugum
{
public:
    SOrganDugum(Organ*);//new organ
    ~SOrganDugum();
    
    Organ *organAdres;
    SOrganDugum *sonraki;
};

#endif