#ifndef Kontrol_hpp
#define Kontrol_hpp
#include "Organizma.hpp"
#include "RadixSort.hpp"
class Kontrol
{
public:
    Kontrol(Organizma*);
    ~Kontrol();
    void bolunmeKontrol();
private:
    Organizma* organizma;
    ODokuDugum *dokuDGec;
    SOrganDugum *organDGec;
    Hucre *dizi;
    Doku **postOrder(Dugum*);
    int sayac;
    OSistemDugum *orgGec;
    Doku **dokudizisi;
};

#endif