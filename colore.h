#ifndef COLORE_H
#define COLORE_H
#include <string>
using std::string;
using std::to_string;
class Colore
{


public:


    virtual bool operator==(const Colore &)const =0;
    virtual bool operator !=(const Colore &)const =0;
    virtual Colore* operator +(const Colore&)const =0;// somma tra 2 colori se non va a buon fine ritorna colore nero
    virtual Colore* operator-(const Colore &)const =0;// differenza tra 2 colori
    virtual Colore* operator*(const Colore&)const=0;//modulazione di un colore
    virtual double DeltaE(const Colore&)const =0;
    virtual  Colore* operator *(double)=0;
        //scala le componenti del colore basandosi sul parametro
    /*virtual  Colore* complementare()const=0;
    virtual Colore* splitComplementare()const=0;
    virtual bool Caldo()const=0;//ritorna true se il colore è un colore caldo
    virtual int ScuroChiaro()const=0;//ritorna un intero compreso tra 0 e 255 che indica se un colore è chiaro o scuro. cosi si puo decidere se mettere il testo in bianco o nero avendo di sfondo il colore this
    */
    virtual string schemaColore()const=0;
    virtual ~Colore(){}
    //colore analogo To search

    //Decidere se mettere le conversioni da rgba a hex/hsl come metodi o come classi derivate


};

#endif // COLORE_H
