#ifndef COLORERGBA_H
#define COLORERGBA_H

#include "colorergb.h"
class ColoreRgba:public ColoreRgb
{
private:
    float a; //alpha compreso tra 0.0 e 1.0

public:

    ColoreRgba();// rappresenta il colore nero
    ColoreRgba(int, int, int, float =1.0);

    void setA(float);
    float getA()const;
    ColoreRgba* operator +(const Colore&)const;// somma tra 2 colori
    ColoreRgba* operator-(const Colore &)const;// differenza tra 2 colori
    ColoreRgba* operator*(const Colore&)const;//modulazione di un colore
    ColoreRgba* operator *(double)const;//scala le componenti del colore basandosi sul parametro
    string schemaColore()const;

};

#endif // COLORERGBA_H
