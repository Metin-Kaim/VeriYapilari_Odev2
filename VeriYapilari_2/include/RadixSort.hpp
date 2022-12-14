#ifndef RadixSort_hpp
#define RadixSort_hpp
#include "Hucre.hpp"
class RadixSort
{
public:
    void radixSort(Hucre*,int);
    ~RadixSort();
private:
    int getMax(Hucre*,int);
};

#endif