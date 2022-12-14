#ifndef Queue_hpp
#define Queue_hpp

class Kuyruk
{
public:
    Kuyruk();
    ~Kuyruk();
    void ekle(int);
    void cikar();
    bool bosmu();
    int getir();

private:
    void genislet(int);

    int kapasite;
    int ilk;
    int son;
    int veriSayisi;
    int *veriler;
};

#endif