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
    LibrettoEsami operator+(const LibrettoEsami&)const;
    LibrettoEsami operator-(const LibrettoEsami&)const;
    LibrettoEsami& operator+=(const LibrettoEsami&);
};


#endif // LIBRETTOESAMI_H
