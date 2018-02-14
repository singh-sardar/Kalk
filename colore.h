#ifndef COLORE_H
#define COLORE_H
#include <string>
#include <math.h>

using std::string;
using std::to_string;
class Colore
{
protected:

    double static abs(double);

public:


    void static hsl2rgb(double[3],int[3]);//funzione di classe che converte hsl to rgb. implmentata di classe perche non si è deciso di implementare la classe ColoreHsl che rappresenta i colori in hsl

    virtual bool operator==(const Colore &)const ;
    virtual bool operator !=(const Colore &)const ;
    virtual Colore* operator +(const Colore&)const =0;// somma tra 2 colori se non va a buon fine ritorna colore nero
    virtual Colore* operator-(const Colore &)const =0;// differenza tra 2 colori
    virtual Colore* operator*(const Colore&)const=0;//modulazione di un colore
    virtual double DeltaE(const Colore&)const =0;
    virtual  Colore* operator *(double)const=0; //scala le componenti del colore basandosi sul parametro
    virtual  Colore* complementare()const=0;
    virtual Colore* luminositaColore()const=0;//ritorna un colore compreso tra 0 e 255 che indica se un colore è chiaro o scuro. cosi si puo decidere se mettere il testo in bianco o nero avendo di sfondo il colore this
    virtual bool coloreCaldo()const=0;
    virtual string schemaColore()const=0;
    virtual ~Colore(){}




};

#endif // COLORE_H
