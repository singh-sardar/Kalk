#include "ricetta.h"

Ricetta::Ricetta(const vector<Ingrediente> & v):VettoreGenerico(v){}

//fare la meno, calcolo calorie tot ricetta, calcolo soldi ricetta, calcolo quantita da comprare come stico
Ricetta* Ricetta::operator+(const VettoreGenerico<Ingrediente>& vgr) const{

    Ricetta* aux= new Ricetta(*this);

    const Ricetta* r = dynamic_cast<const Ricetta*>(&vgr);
    if(r){
        for(int i = 0 ; i < r->getSize(); i++){
            for(int  j = 0; j < aux->getSize();j++){

            }
        }





    }


    return aux;

}
