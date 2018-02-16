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
   // float a; //alpha compreso tra 0.0 e 1.0

public:
    ColoreRgb();// rappresenta il colore nero
    ColoreRgb(int, int, int/*, float =1.0*/);


    void setR(int);
    void setG(int);
    void setB(int);
   // void setA(float);
    int getR()const;
    int getG()const;
    int getB()const;
//    float getA()const;
    void modificaColore(int, int, int /*, float=1.0*/);

/*
    bool operator==(const Colore &)const;
    bool operator !=(const Colore &)const;*/
    ColoreRgb* operator +(const Colore&)const;// somma tra 2 colori
    ColoreRgb* operator-(const Colore &)const;// differenza tra 2 colori
    ColoreRgb* operator*(const Colore&)const;//modulazione di un colore
    ColoreRgb* operator *(double)const;//scala le componenti del colore basandosi sul parametro
    double DeltaE(const Colore&)const;//calcola il delta E tra due colori
    ColoreRgb* complementare()const;
    bool coloreCaldo()const;//ritorna true se il colore è un colore caldo
    ColoreRgb* grayScale()const;//ritorna un colore compreso tra 0 e 255 che indica la scala in grigio del colore
    string schemaColore()const;
    void updateLuminosita();
    string ToHex()const;
    void ToLab(double [3])const; //trasforma un colore in formato lab e i valori vengono inseriti nel array passato
    void ToHsl(double [3])const;


};

#endif // COLORERGB_H

