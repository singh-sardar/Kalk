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
    voto = (voto <= 30 ? voto: 30);
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

unsigned int Esame::getCFU() const{
    return CFU;
}

unsigned int Esame::getVoto() const{
    return voto;
}

Data Esame::getData() const{
    return data;
}

void Esame::setNomeCorso(string n){
    if(!n.empty())
        nomeCorso = n;
}

void Esame::setNomeMateria(string n){
    if(!n.empty())
        nomeMateria = n;
}

void Esame::setNomeProfessore(string n){
    if(!n.empty())
        nomeProfessore = n;
}

void Esame::setVoto(int v){
    voto = (v >= 18 ? v : 18);
    voto = (voto <= 30 ? voto : 30);
}

void Esame::setData(const Data& d){
    data = Data(d);
}

bool Esame::operator ==(const Esame& e) const{
   return nomeCorso == e.getNomeCorso() && nomeMateria == e.getNomeMateria();
}

bool Esame::operator !=(const Esame& e) const{
    return !(*this == e);
}

string Esame::getRappresentazioneStringa() const{
    string t;
    t += "\n - CFU: " + to_string(getCFU()) + ";";
    t += "\n - Voto: " + to_string(getVoto()) + ";";
    t += "\n - Nome Materia: " + getNomeMateria() + ";";
    t += "\n - Nome Professore: " + getNomeProfessore() + ";";
    t += "\n - Nome Corso: " + getNomeCorso() + ";";
    t += "\n - Data: " + data.getRappresentazioneStringa() + ";";
    return t;
}
