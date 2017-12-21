#include "librettoesami.h"

using std::string;

/*
 * Costruttore
 */
//LibrettoEsami::LibrettoEsami(): VettoreGenerico(){}
LibrettoEsami::LibrettoEsami(string nomeS,string cognomeS, unsigned int matricolaS, unsigned int targCFU, unsigned int totCFU):
    nomeStudente(nomeS), cognomeStudente(cognomeS), matricolaStudente(matricolaS), targetCFU(targCFU), totaleCFU(totCFU){}

//Ritorna i CFU per completare il percorso di studi
unsigned int LibrettoEsami::getTargetCFU() const{
    return targetCFU;
}

//Ritorna i CFU acquisiti tramite gli esami sostenuti
unsigned int LibrettoEsami::getTotaleCFU() const{
    return totaleCFU;
}

unsigned int LibrettoEsami::getMatricola() const{
    return matricolaStudente;
}

string LibrettoEsami::getNomeStudente() const{
    return nomeStudente;
}

string LibrettoEsami::getCognomeStudente() const{
    return cognomeStudente;
}

double LibrettoEsami::percentualeCompletamento() const{
    return totaleCFU/targetCFU;
}

unsigned int LibrettoEsami::rimanentiCFU() const{
    return targetCFU-totaleCFU;
}

double LibrettoEsami::previsioneVotoLaurea() const{
    return (mediaPonderata()*110)/30;
}

double LibrettoEsami::mediaAritmetica() const{
    unsigned int i=0, votoTemp=0;
    for(; i < getSize(); ++i){
        votoTemp += (this->operator[](i)).getVoto();
    }
    return votoTemp/i;
}

double LibrettoEsami::mediaPonderata() const{
    unsigned int i=0, votoTemp=0;
    Esame esameTemp;
    for(; i < getSize(); ++i){
        esameTemp = this->operator [](i);
        votoTemp += esameTemp.getVoto() * esameTemp.getCFU();
    }
    return votoTemp/i;
}

Esame LibrettoEsami::esameMigliore() const{
    Esame esameTemp, esameMigliore;
    int pesoEsame=0;
    for(unsigned int i=0; i < getSize(); ++i){
        esameTemp = this->operator [](i);
        if(esameTemp.getVoto()*esameTemp.getCFU() > pesoEsame){
            esameMigliore = esameTemp;
            pesoEsame = esameTemp.getVoto()*esameTemp.getCFU();
        }
    }
    return esameMigliore;
}

Esame LibrettoEsami::esamePeggiore() const{
    Esame esameTemp, esamePeggiore;
    int pesoEsame=0;
    for(unsigned int i=0; i < getSize(); ++i){
        esameTemp = this->operator [](i);
        if(esameTemp.getVoto()*esameTemp.getCFU() < pesoEsame){
            esamePeggiore = esameTemp;
            pesoEsame = esameTemp.getVoto()*esameTemp.getCFU();
        }
    }
    return esamePeggiore;
}

LibrettoEsami* LibrettoEsami::operator+(const VettoreGenerico<Esame>& l) const{
    LibrettoEsami* aux = new LibrettoEsami();
    aux = *aux + l;
    return aux;
}

LibrettoEsami* LibrettoEsami::operator +=(const VettoreGenerico<Esame>& l){
    for(unsigned int i = l.getSize(); i != l.getSize(); ++i){
        if(!cerca(this->operator [](i)))
            aggiungiElemento(l[i]);
    }
    return this;
}

LibrettoEsami* LibrettoEsami::operator-(const VettoreGenerico<Esame>& l) const{
    LibrettoEsami* aux = new LibrettoEsami();
    aux = *aux - l;
    return aux;
}

LibrettoEsami* LibrettoEsami::operator -=(const VettoreGenerico<Esame>& l){
    for(unsigned int i = l.getSize(); i != l.getSize(); ++i){
        if(cerca(this->operator [](i)))
            rimuoviElemento(l[i]);
    }
    return this;
}
