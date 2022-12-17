/*
* @file             DHucreDugum.hpp
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