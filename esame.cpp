#include "esame.h"
using std::ostream;
using std::endl;
using std::string;

Esame::Esame(int c,int v,string nomeM,string nomeC,string nomeP):
    Esame(Data(),c,v,nomeM,nomeC,nomeP)
{

}

Esame::Esame(const Data& d,int c, int v,string nomeM,string nomeC, string nomeP):
    data(d),CFU(c>=1?c:1), voto(v>=18?v:18), nomeMateria(nomeM), nomeCorso(nomeC), nomeProfessore(nomeP)
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

bool Esame::operator ==(const Esame& e) const{
   return nomeCorso == e.getNomeCorso() && nomeMateria == e.getNomeMateria();
}

bool Esame::operator !=(const Esame& e) const{
    return !(*this == e);
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

//E' sommare 2 esami significa sommare 2 voti e sommare 2 voti è come fare la loro media.
Esame Esame::operator+(const Esame& e)const{
    Esame tmp(*this);
    if(nomeMateria == e.getNomeMateria() && nomeCorso == e.getNomeCorso() && nomeProfessore == e.getNomeProfessore() && data== e.data){
        tmp.voto = (voto+e.getVoto())/2;
    }
}
