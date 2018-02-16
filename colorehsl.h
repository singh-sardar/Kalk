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
    ColoreHsl* operator +(const Colore&)const;// somma tra 2 colori se non va a buon fine ritorna colore nero
    ColoreHsl* operator-(const Colore &)const ; //sottrazione tra le varie componenti del colore
    ColoreHsl* operator*(const Colore&)const;//moltiplicazione tra le componenti del colore
    double DeltaE(const Colore&)const;
    ColoreHsl* operator *(double)const; //scala le componenti del colore basandosi sul parametro
    ColoreHsl* complementare()const;
    ColoreHsl* grayScale()const;//ritorna un colore con  L compreso tra 0 e 100 che indica se un colore è chiaro o scuro. cosi si puo decidere se mettere il testo in bianco o nero avendo di sfondo il colore this
    bool coloreCaldo()const;
    string schemaColore()const;
    void updateLuminosita();
    void ToRgb(int [3])const;

    //nn so se mettere to HEX


};

#endif // COLOREHSL_H
