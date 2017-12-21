#include "esame.h"

using std::string;

Esame::Esame(int c, int v,string nomeM,string nomeC, string nomeP): CFU(c>=1?c:1), voto(v>=18?v:18), nomeMateria(nomeM), nomeCorso(nomeC), nomeProfessore(nomeP)
{
    lode = (voto > 30) ? true : false;
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

bool Esame::operator ==(const Esame& e) const{
   return nomeCorso == e.getNomeCorso() && nomeMateria == e.getNomeMateria();
}

bool Esame::operator !=(const Esame& e) const{
    return !(*this == e);
}
