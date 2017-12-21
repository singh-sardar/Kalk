#ifndef COLORERGB_H
#define COLORERGB_H
#include "colore.h"
#include <math.h>

class ColoreRgb:public Colore
{
private:
    int r, g, b; //rappresentano un colore in formato red, green,blue
    float a; //alpha compreso tra 0.0 e 1.0

    double pivotXYZ(double)const;//funzione di utilita per rgb2lab
    double PivotRgb(double)const;
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
    ColoreRgb* operator *(int);//scala le componenti del colore basandosi sul intero
    double DeltaE(const Colore&)const;//calcola il delta E tra due colori
    void rgb2lab(double [3])const; //trasforma un colore in formato lab e i valori vengono inseriti nel array passato
    ColoreRgb* complementare()const;
    ColoreRgb* splitComplementare()const;
    bool Caldo()const;//ritorna true se il colore è un colore caldo
    int ScuroChiaro()const;//ritorna un intero compreso tra 0 e 255 che indica se un colore è chiaro o scuro. cosi si puo decidere se mettere il testo in bianco o nero avendo di sfondo il colore this
    string schemaColore()const;


    //colore analogo To search

    //Decidere se mettere le conversioni da rgba a hex/hsl come metodi o come classi derivate

};

#endif // COLORERGB_H
/*
  LONG = B * 65536 + G * 256 + R

              0            0      255
              255*256
              65.280


              65025 è totale




'Convert LONG to RGB:
 B = LONG \ 65536====0
 G = (LONG - B * 65536) \ 256== 254
 R = LONG - B * 65536 - G * 256   1


 * */
