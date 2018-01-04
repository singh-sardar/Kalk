#include "esame.h"
using std::ostream;
using std::endl;
using std::string;

Esame::Esame(string nomeM,string nomeC,string nomeP,unsigned int c,unsigned int v):
    Esame(nomeM,nomeC,nomeP,Data(),c,v)
{

}

Esame::Esame(string nomeM,string nomeC, string nomeP,const Data& d,unsigned int c,unsigned int v):
    CFU(c>=1?c:1), voto(v>=18?v:18),nomeMateria(nomeM), nomeCorso(nomeC), nomeProfessore(nomeP), data(d)
{
    lode = (voto > 30) ? true : false;
    if(lode)
        voto = 30;
}

string Esame::getNomeCorso() const{
    return nomeCorso;
}

string Esame::getNomeMateria() const{
    return nomeMateria;
}

string Esame::getNomeProfessore() const{
    return nomeProfessore;
}

int Esame::getCFU() const{
    return CFU;
}

int Esame::getVoto() const{
    return voto;
}

bool Esame::getLode() const{
    return lode;
}

Data Esame::ottieniData() const{
    return data;
}

void Esame::setNomeCorso(string n){
    nomeCorso = n;
}

void Esame::setNomeMateria(string n){
    nomeMateria = n;
}

void Esame::setNomeProfessore(string n){
    nomeProfessore = n;
}

void Esame::setCFU(int c){
    if(c >= 1)
        CFU = c;
}

void Esame::setVoto(int v){
    if(v >= 18)
        voto = v;
}

void Esame::setData(const Data& d){
    data = d;
}

bool Esame::operator ==(const Esame& e) const{
   return nomeCorso == e.getNomeCorso() && nomeMateria == e.getNomeMateria();
}

bool Esame::operator !=(const Esame& e) const{
    return !(*this == e);
}

string Esame::esameToString() const{
    string t = "CFU: " + to_string(getCFU()) + "; ";
    t += "Voto: " + to_string(getVoto()) + "; ";
    t.append(string("Lode: ") + (getLode() ? "Si" : "No") + "; ");
    t += "Nome Materia: " + getNomeMateria() + "; ";
    t += "Nome Professore: " + getNomeProfessore() + "; ";
    t += "Nome Corso: " + getNomeCorso() + "; ";
    return t;
}

ostream& operator<<(ostream& os, const Esame& d){
    os<<"CFU: " <<d.getCFU() << endl;
    os << "Voto: " << d.getVoto() << endl;
    os << "Lode: " << (d.getLode() ? "Si" : "No") << endl;
    os << "Nome Materia: " << d.getNomeMateria() << endl;
    os << "Nome Professore: " << d.getNomeProfessore() << endl;
    os << "Nome Corso: " << d.getNomeCorso() << endl;
    return os;
}

//Somma dei parziali
Esame Esame::operator+(const Esame& e)const{
    Esame tmp(*this);
    if(nomeMateria == e.getNomeMateria() && nomeCorso == e.getNomeCorso() && nomeProfessore == e.getNomeProfessore()){
        tmp.voto = (voto+e.getVoto())/2;
    }
    return tmp;
}
