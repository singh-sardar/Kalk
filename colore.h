#ifndef COLORE_H
#define COLORE_H
#include <string>
#include <math.h>

using std::string;
using std::to_string;
class Colore
{
private:
    //aggiungo un capo dati luminosita ?
    double static pivotXYZ(double);//funzione di utilita per rgb2lab
    double static PivotRgb(double);
    double static Min(double,double);
    double static Max(double,double);
    int luminosita;//campo con valore tra 0 e 100 . se < 50 allora colore scuro

protected:
    double static abs(double);
    void setLuminosita(int);

public:

    Colore(int=0);
    int getLuminosita()const;
    virtual void updateLuminosita()=0;
    virtual bool operator==(const Colore &)const ;
    virtual bool operator !=(const Colore &)const ;
    virtual Colore* operator +(const Colore&)const =0;// somma tra 2 colori se non va a buon fine ritorna colore nero
    virtual Colore* operator-(const Colore &)const =0;// differenza tra 2 colori
    virtual Colore* operator*(const Colore&)const=0;//modulazione di un colore
    virtual double DeltaE(const Colore&)const =0;
    virtual  Colore* operator *(double)const=0; //scala le componenti del colore basandosi sul parametro
    virtual  Colore* complementare()const=0;
    virtual Colore* grayScale()const=0;//ritorna un colore compreso tra 0 e 255 che indica se un colore è chiaro o scuro. cosi si puo decidere se mettere il testo in bianco o nero avendo di sfondo il colore this
    virtual bool coloreCaldo()const=0;
    virtual string schemaColore()const=0;
    virtual void ToLab(double [3])const=0;
    virtual string ToHex()const=0;
    virtual ~Colore(){}


    //funzioni statiche di classe sui colori
    void static rgb2lab(int[3],double [3]); //trasforma un colore in formato lab e i valori vengono inseriti nel array passato
    void static rgb2hsl(int[3],double [3]);
    void static hsl2rgb(double[3],int[3]);//funzione di classe che converte hsl to rgb.
    string static rgb2hex(int[3]);




};

#endif // COLORE_H
