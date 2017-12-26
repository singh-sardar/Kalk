#include "ingrediente.h"

Ingrediente::Ingrediente():nome(""),quantita(0),calorie(0){ }
Ingrediente::Ingrediente(string name,double quantity,double cal):nome(name),quantita(quantity),calorie(cal){
    if(quantita<0.0){
        quantita=0;
        nome="Quantita negativa";
    }
    if(calorie<0.0){
        calorie=0;
        nome="Calorie negative";
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


string Ingrediente::getDescrizione(){
    return "Nome Ingrediente: "+nome+"   Quantita:"+std::to_string(quantita)+" g    calorie: "+std::to_string(calorie);
}
bool Ingrediente::operator==(const Ingrediente& i)const{
    return i.getNome()==nome &&  i.getQuantita() == quantita && i.getCalorie()==calorie ;
}
bool Ingrediente::operator!=(const Ingrediente& i)const{
    return !(*this == i);
}
