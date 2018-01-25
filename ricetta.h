#ifndef RICETTA_H
#define RICETTA_H
#include "vettoregenerico.h"
#include "ingrediente.h"

class Ricetta: public VettoreGenerico<Ingrediente>
{
private:
    string nomeRicetta;


public:
    Ricetta();
    Ricetta(const vector<Ingrediente> &,string );

    void setNomeRicetta(string);
    string getNomeRicetta()const;
    string getRicetta()const;

    Ricetta* operator+(const VettoreGenerico<Ingrediente>&) const;
    Ricetta* operator-(const VettoreGenerico<Ingrediente>&) const;
    bool operator ==(const VettoreGenerico<Ingrediente>&)const;
    bool operator !=(const VettoreGenerico<Ingrediente>&)const;
    virtual double calorieRicetta()const;
    virtual double costoRicetta()const;
    virtual Ricetta operator*(int)const;

};

#endif // RICETTA_H
