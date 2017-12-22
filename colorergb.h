#ifndef COLORERGB_H
#define COLORERGB_H
#include "colore.h"
#include <math.h>
#include <string>
#include <stdlib.h>

using std::string;
class ColoreRgb:public Colore
{
private:
    int r, g, b; //rappresentano un colore in formato red, green,blue
    float a; //alpha compreso tra 0.0 e 1.0

    double static pivotXYZ(double);//funzione di utilita per rgb2lab
    double static PivotRgb(double);
    double static Min(double,double);
    double static Max(double,double);

public:
    ColoreRgb();// rappresenta il colore nero
    ColoreRgb(int, int, int, float =1.0);


    void setR(int);
    void setG(int);
    void setB(int);
    void setA(float);
    int getR()const;
    int getG()const;
    int getB()const;
    float getA()const;
    void modificaColore(int, int, int , float=1.0);


    bool operator==(const Colore &)const;
    bool operator !=(const Colore &)const;
    ColoreRgb* operator +(const Colore&)const;// somma tra 2 colori
    ColoreRgb* operator-(const Colore &)const;// differenza tra 2 colori
    ColoreRgb* operator*(const Colore&)const;//modulazione di un colore
    ColoreRgb* operator *(double);//scala le componenti del colore basandosi sul parametro
    double DeltaE(const Colore&)const;//calcola il delta E tra due colori
    ColoreRgb* complementare()const;
    bool coloreCaldo()const;//ritorna true se il colore è un colore caldo
    ColoreRgb* luminositaColore()const;//ritorna un intero compreso tra 0 e 255 che indica la scala in grigio del colore
    string schemaColore()const;

    void rgb2lab(double [3])const; //trasforma un colore in formato lab e i valori vengono inseriti nel array passato
    void rgb2hsl(double [3])const;
    string rgb2hex()const;



};

#endif // COLORERGB_H

