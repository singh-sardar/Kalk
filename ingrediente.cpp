#include "ingrediente.h"

Ingrediente::Ingrediente():nome(""),quantita(0),calorie(0){ }
Ingrediente::Ingrediente(string name,double quantity,double cal,double euro):nome(name),quantita(quantity),calorie(cal),costo(euro){
    if(quantita<0.0){
        quantita=0;
        nome="Quantita negativa";
    }
    if(calorie<0.0){
        calorie=0;
        nome="Calorie negative";
    }
    if(costo<0.0){
        costo=0;
        nome="Costo negativo";
    }

}

string Ingrediente::getNome()const{
    return nome;
}
double Ingrediente::getQuantita()const{
    return quantita;
}
double Ingrediente::getCalorie()const{
    return calorie;
}
double Ingrediente::getCosto()const{
    return costo;
}

void Ingrediente::setNome(string title){
    nome=title;
}
void Ingrediente::setQuantita(double q){
    if(q>0.0)
        quantita= q;

}
void Ingrediente::setCalorie(double cal){
    if(cal>0.0)
        calorie= cal;
}
double Ingrediente::kilo2g(double kg){
    return kg*1000;
}
void Ingrediente::setCosto(double c){
    if(c>0.0)
        costo = c;
}

Ingrediente Ingrediente::operator+(const Ingrediente& i)const{
    Ingrediente tmp(*this);
    if(i.getNome()==nome){
        tmp.setQuantita(tmp.getQuantita()+i.getQuantita());
    }
    return tmp;
}
Ingrediente Ingrediente::operator-(const Ingrediente& i)const{
    Ingrediente tmp(*this);
    if(i.getNome()==nome){
        tmp.setQuantita(tmp.getQuantita()- i.getQuantita());
    }
    return tmp;
}
Ingrediente Ingrediente::operator*(int q)const{
    Ingrediente tmp(*this);
    tmp.setQuantita(tmp.getQuantita()*q);
    return tmp;
}
Ingrediente Ingrediente::operator-(double q)const{
    Ingrediente tmp(*this);
    tmp.setQuantita(tmp.getQuantita()-q);
    return tmp;
}
double Ingrediente::calorieTorali()const{
    return (calorie/100)*quantita;
}


string Ingrediente::getDescrizione()const{
    return "Nome Ingrediente: "+nome+"   Quantita:"+std::to_string(quantita)+" g    calorie: "+std::to_string(calorie)+"   Costo: "+std::to_string(costo);
}
bool Ingrediente::operator==(const Ingrediente& i)const{
    return i.getNome()==nome && i.getCalorie()==calorie && i.getCosto() == costo;
}
bool Ingrediente::operator!=(const Ingrediente& i)const{
    return !(*this == i);
}
