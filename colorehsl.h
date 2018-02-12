#ifndef COLOREHSL_H
#define COLOREHSL_H

#include<colore.h>
class ColoreHsl:public Colore
{
private:
    int h,s,l;//(Hue, Saturation, Lightness)
public:
    ColoreHsl();//colore nero
    ColoreHsl(int, int, int);
//TESTARE LA FUNZIONE == E !=
    void setH(int);
    void setS(int);
    void setL(int);
    int getH()const;
    int getS()const;
    int getL()const;
    void modificaColore(int, int, int);
  //  ColoreHsl* operator +(const Colore&)const;// somma tra 2 colori se non va a buon fine ritorna colore nero

    string schemaColore()const;

};

#endif // COLOREHSL_H
