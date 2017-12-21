#ifndef LIBRETTOESAMI_H
#define LIBRETTOESAMI_H

#include "esame.h"
#include "vettoregenerico.h"
#include <string>

class LibrettoEsami: public VettoreGenerico<Esame>{
//class LibrettoEsami{
private:
    string nomeStudente, cognomeStudente;
    unsigned int matricolaStudente;
    unsigned int targetCFU;  //rappresenta il numero totale di CFU
    unsigned int totaleCFU;  //rappresenta i CFU acquisiti

public:
    LibrettoEsami(string nomeS="",string cognomeS="",unsigned int matricolaS=0, unsigned int targCFU=0, unsigned int totCFU=0);
    LibrettoEsami* operator+(const VettoreGenerico<Esame>&) const override;
    LibrettoEsami* operator-(const VettoreGenerico<Esame>&) const override;
    LibrettoEsami* operator+=(const VettoreGenerico<Esame>&) override;
    LibrettoEsami* operator-=(const VettoreGenerico<Esame>&) override;
    double percentualeCompletamento() const;//ritorna la percentuale di completamento degli studi
    unsigned int rimanentiCFU() const;
    double mediaAritmetica() const;
    double mediaPonderata() const;
    double previsioneVotoLaurea() const;
    Esame esameMigliore() const; //ritorna l'esame col risultato migliore
    Esame esamePeggiore() const; //ritorna l'esame col risultato peggiore
    unsigned int getTargetCFU() const;
    unsigned int getTotaleCFU() const;
    unsigned int getMatricola() const;
    string getNomeStudente() const;
    string getCognomeStudente() const;
};


#endif // LIBRETTOESAMI_H
