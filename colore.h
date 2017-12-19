#ifndef COLORE_H
#define COLORE_H


class Colore
{
private:
    int r, g, b; //rappresentano un colore in formato red, green,blue
    float a; //alpha compreso tra 0.0 e 1.0

public:
    Colore();// rappresenta il colore nero
    Colore(int, int, int, float =1.0);


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
    Colore operator +(const Colore&);// somma tra 2 colori
    Colore operator-(const Colore &);// differenza tra 2 colori
    Colore operator*(const Colore&);//modulazione di un colore
    Colore operator/(const Colore&);//modulazione di un colore
    Colore& operator *(int);//scala le componenti del colore basandosi sul intero
    Colore complementare()const;
    Colore splitComplementare()const;
    bool Caldo();//ritorna true se il colore è un colore caldo
    int ScuroChiaro();//ritorna un intero compreso tra 0 e 255 che indica se un colore è chiaro o scuro. cosi si puo decidere se mettere il testo in bianco o nero avendo di sfondo il colore this

     //colore analogo To search

    //Decidere se mettere le conversioni da rgba a hex/hsl come metodi o come classi derivate


};

#endif // COLORE_H
