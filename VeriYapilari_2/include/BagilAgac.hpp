#ifndef BagilAgac_hpp
#define BagilAgac_hpp
#include "Dugum.hpp"
#include "Doku.hpp"

class BagilAgac
{
public:
    BagilAgac();
    ~BagilAgac();
    void ekle(Doku *, int);
    Dugum *kok;
    int yukseklikBulma(Dugum *);
    void avlDengesi(Dugum*);

private:
    void ekle(Doku *, int, Dugum *);
};

#endif