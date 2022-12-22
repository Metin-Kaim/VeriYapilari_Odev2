/*
* @file             main.cpp
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

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#include "Organizma.hpp"
#include "Doku.hpp"
#include "Kontrol.hpp"

using namespace std;
int main()
{
    system("CLS");
    cout << setw(35) << ""
         << "ORGANIZMA\n\n";

    int organSayaci = 0;      // organları sırayla gezmeyi sağlıyor
    bool organFlag = false;   // Organlar ve sistemler arası geçişi sağlıyor (duruma göre)
    int dokuDugumuSayaci = 0; // ilgili organın kaçıncı dügümünde oldugunu gösteriyor

    Organizma *organizma = new Organizma(); // organizma oluşturma
    organizma->sistemOlustur();             // organizmanın ilk sistemini oluşturma
    ODokuDugum *dokuDGec = 0;               // organdan dokuları kontrol etmek için
    SOrganDugum *organDGec = 0;             // Sistemden organları kontrol etmek için

    ifstream dosya;
    dosya.open("./veri.txt");
    while (!dosya.eof())
    {
        string satir;
        int sayiBaslangic = 0; // veri.txt dosyasındaki ilgili degerleri alma
        int sayiAdedi = 0;     // satirdaki sayı adedi

        getline(dosya, satir);

        if (satir == "") // Satirin boş olup olmadigini kontrol eden yapi.
        {
            continue;
        }

        for (int i = 0; i < satir.length(); i++) // bir satirda kac adet sayi oldugunu hesaplama
        {
            string islem = satir.substr(i, 1);
            if (islem != " ")
            {
                if (i == (satir.length()) - 1) // satir sonu
                    sayiAdedi++;
            }
            else
            { // boşluk ise
                sayiAdedi++;
            }
        }

        Doku *doku = new Doku(sayiAdedi); 

        DHucreDugum *gec = doku->ilkHucreD;
        int sayac = 0;
        for (int i = 0; i < satir.length(); i++) // okunan satirdaki sayilari "sayilar" adli diziye aktarma
        {
            string islem = satir.substr(i, 1);
            if (islem == " ")
            { // boşluk ise
                doku->dizi[sayac].veri = stoi(satir.substr(sayiBaslangic, i - sayiBaslangic));
                sayac++;
                gec = gec->sonraki;
                sayiBaslangic = i + 1;
            }
            else if (islem != " ")
            {
                if (i == (satir.length()) - 1) // satir sonu
                {
                    doku->dizi[sayac].veri = stoi(satir.substr(sayiBaslangic, i - sayiBaslangic + 1));
                    sayac++;
                    gec = gec->sonraki;
                    sayiBaslangic = i + 1;
                }
            }
        } // ilgili satır için okuma işlemi bitti

        if (organSayaci == 100 && organFlag == true) // eger ki organin içindeki tüm dokular gezildiyse(organFlag==true) ve ilgili sistemin
                                                     // tüm organları(organSayacı==100) gezildiyse yeni bir sistem oluştur.
        {
            organizma->sistemOlustur();
            organSayaci = 0;
            organFlag = false;
        }

        OSistemDugum *orgGec = organizma->ilkSistemD;
        while (orgGec->sonraki != 0) // sürekli olarak son sistemi göstericek
        {
            orgGec = orgGec->sonraki;
        } // orgGec son dugumu gosteriyor.

        if (organSayaci == 0) // organsayaci 0 ise organDGec pointer'ını ilk organa atıyor
        {
            organDGec = orgGec->sistemAdres->ilkOrganD;
            organSayaci++;
        }
        else if (organFlag) // bir sistem içindeki 100 organ arasında geçiş yapmayı sağlıyor (flag yardımıyla)
                            // organ içindeki dokular tamamen gezildiğinde flag açılıyor ve organDGec aynı sistem içindeki bir sonraki
                            // organı(organ düğümünü) gösteriyor
        {
            organSayaci++;
            organDGec = organDGec->sonraki;
            organFlag = false; // dokular tamamen gezilmedikçe flag açılmayacak
        }

        if (dokuDugumuSayaci == 0) // dokuDugumuSayaci eger ki 0 ise dokuDGec pointer'ını ilgili organın ilk dokusuna atıyor.
        {
            dokuDGec = organDGec->organAdres->ilkOrganD;
            dokuDugumuSayaci++;
        }
        else // eger dokuDugumuSayaci 0 degil ise sürekli olarak bir sonrakine gidecek (her organ için 20 defa)
        {
            dokuDGec = dokuDGec->sonraki;
            dokuDugumuSayaci++;
        }
        dokuDGec->dokuAdres = doku; // doku, dokuDugume baglaniyor

        if (dokuDugumuSayaci == 20) // dokuDugumSayaci 20 oldugunda ilgili organın tüm dokuları okunmuş oluyor ve organFlag açılıyor
        {
            organDGec->organAdres->agacaEkle(); // tüm dokular okundugunda dokuları agaca ekleme için agacaEkle fonksiyonu cagiriliyor
            organFlag = true;
            dokuDugumuSayaci = 0; // flag sayesinde bir sonraki dönüşte bir sonraki organa gecildiginde dokuları baştan başlayarak gezebilmek için 0'lama işlemi yapılıyor
        }
    }
    dosya.close();

    OSistemDugum *osd = organizma->ilkSistemD; // organizmanın ilk sistemine geliyor

    while (osd != 0) // organizmayı ekrana çıkaracak döngü
    {
        SOrganDugum *sod = 0;         // sistem organ düğüm
        for (int i = 0; i < 100; i++) // ilgili sistemin organlarını gezme
        {
            if (sod == NULL)
            {
                sod = osd->sistemAdres->ilkOrganD; // ilgili sistemin ilk organına erişim
            }
            else
                sod = sod->sonraki; // ilgili sistemin sonraki organlarına erişim

            sod->organAdres->agac->avlDengesi(sod->organAdres->agac->kok); // ağacı avl dengesine göre tarama işlemi
        }
        cout << endl;
        osd = osd->sonraki; // bir sonraki sistem düğümü
    }

    cout << "\n\n";
    string myString; //"enter" tuşunu alma -start-
    do
    {
        getline(cin, myString);
    } while (myString.length() != 0); //"enter" tuşunu alma -end-

    system("CLS");

    Kontrol *k = new Kontrol(organizma);
    k->bolunmeKontrol(); // mutasyon kısmı
    cout << endl
         << endl;
    delete k;
    delete organizma;
}