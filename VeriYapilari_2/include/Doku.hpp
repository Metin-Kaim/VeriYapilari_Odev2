/*
* @file             Doku.hpp
* @description      Verilen "veri.txt" adlı dosaydaki verileri okuyarak bunları hücre yapılarında tutmak
                    ve bu hücre yapılarını doku yapılarında, bu doku yapılarını organ yapılarında,
                    organ yapılarını da sistem yapılarında ve son olarak sistemleri de bir adet organizma yapısnda tutmak.
                    Ardından bu verileri ağaç yapılarına ekleyerek ekrana belli bir şekil çıkarmak ve enter tuşuna basıldığında
                    Bu şeklin belli şartlar dahilinde mutasyona uğramasını sağlamak.                                           
* @course           1. Öğretim A grubu
* @assignment       2. Ödev
* @date             17.12.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

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