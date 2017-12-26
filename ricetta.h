#ifndef RICETTA_H
#define RICETTA_H
#include "vettoregenerico.h"
#include "ingrediente.h"

class Ricetta: public VettoreGenerico<Ingrediente>
{
public:
    Ricetta();
    Ricetta(const vector<Ingrediente> &);

    Ricetta* operator+(const VettoreGenerico<Ingrediente>&) const;
   /* Ricetta* operator-(const VettoreGenerico<Ingrediente>&) const;
    bool operator ==(const VettoreGenerico<Ingrediente>&)const;
    bool operator !=(const VettoreGenerico<Ingrediente>&)const;*/


};

#endif // RICETTA_H
