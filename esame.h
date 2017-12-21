#ifndef ESAME_H
#define ESAME_H

#include <string>

using std::string;

class Esame{
private:
    int CFU;
    int voto;//rappresenta il voto relativo all'esame
    bool lode;
    string nomeMateria;
    string nomeCorso;
    string nomeProfessore;

public:
    Esame(int c=1,int v=18,string nomeM="",string nomeC="",string nomeP="");
    string getNomeCorso() const;
    string getNomeMateria() const;
    string getNomeProfessore() const;
    int getVoto() const;
    bool getLode() const;
    int getCFU() const;
    bool operator ==(const Esame&) const;
    bool operator !=(const Esame&) const;
};

#endif // ESAME_H
