/*
* @file             SOrganDugum.cpp
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

#include "SOrganDugum.hpp"

SOrganDugum::SOrganDugum(Organ *yeniOrgan) // Sistem sınıfında oluşturulan Organ ile düğüm arasındaki bağı kurma
{
    sonraki = 0;
    organAdres = yeniOrgan;
}

SOrganDugum::~SOrganDugum() // oluşturulan düğümü ve bağlı olduğu organı silme
{
    delete organAdres;
}