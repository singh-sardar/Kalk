#include "librettoesami.h"

using std::string;

/*
 * Costruttore
 */
//LibrettoEsami::LibrettoEsami(): VettoreGenerico(){}
LibrettoEsami::LibrettoEsami(string nomeS,string cognomeS, unsigned int matricolaS, unsigned int targCFU, unsigned int totCFU):
    nomeStudente(nomeS), cognomeStudente(cognomeS), matricolaStudente(matricolaS), targetCFU(targCFU), totaleCFU(totCFU){}


LibrettoEsami LibrettoEsami::operator+(const LibrettoEsami& l) const{
    LibrettoEsami aux;
    aux += l;
    return aux;
}

LibrettoEsami& LibrettoEsami::operator +=(const LibrettoEsami& l){
    auto cit= vettore.begin();
    for(; cit != l.vettore.end(); ++cit){
        //if(!cerca(*cit))
            aggiungiElemento(*cit);
    }
    return *this;
}

LibrettoEsami LibrettoEsami::operator-(const LibrettoEsami& l) const{
    LibrettoEsami aux;
    auto cit= l.vettore.begin();
    for(; cit != l.vettore.end(); ++cit){
        //if(cerca(*cit))
            aux.rimuoviElemento(*cit);
    }
    return aux;
}
