#include "librettoesami.h"

using std::endl;
using std::string;

/*
 * Costruttore
 */
//LibrettoEsami::LibrettoEsami(): VettoreGenerico(){}
LibrettoEsami::LibrettoEsami(string nomeS,string cognomeS, unsigned int matricolaS, unsigned int targCFU):
    nomeStudente(nomeS), cognomeStudente(cognomeS), matricolaStudente(matricolaS), targetCFU(targCFU), totaleCFU(0){}

void LibrettoEsami::aggiungiElemento(const Esame& e){
    VettoreGenerico::aggiungiElemento(e);
    totaleCFU += e.getCFU();
}

bool LibrettoEsami::rimuoviElemento(const Esame& e){
    totaleCFU -= e.getCFU();
    return VettoreGenerico::rimuoviElemento(e);
}

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
    return votoTemp/getTotaleCFU();
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

Esame LibrettoEsami::esameMenoRecente() const{
    Esame esameTemp, esameMenoRecente;
    if(getSize() >= 1)
        esameMenoRecente = operator [](0);

    for(unsigned int i=0; i < getSize(); ++i){
        esameTemp = this->operator [](i);
        if(esameTemp.ottieniData() < esameMenoRecente.ottieniData())
            esameMenoRecente = esameTemp;
    }
    return esameMenoRecente;
}

Esame LibrettoEsami::esamePiuRecente() const{
    Esame esameTemp, esamePiuRecente;
    if(getSize() >= 1)
        esamePiuRecente = operator [](0);

    for(unsigned int i=0; i < getSize(); ++i){
        esameTemp = this->operator [](i);
        if(esameTemp.ottieniData() > esamePiuRecente.ottieniData())
            esamePiuRecente = esameTemp;
    }
    return esamePiuRecente;
}

LibrettoEsami* LibrettoEsami::operator+(const VettoreGenerico<Esame>& l) const{
    LibrettoEsami aux = LibrettoEsami(*this);
    aux += l;
    return new LibrettoEsami(aux);
}

LibrettoEsami& LibrettoEsami::operator +=(const VettoreGenerico<Esame>& l){
    for(unsigned int i = 0; i != l.getSize(); ++i){
        if(!cerca(l[i])){
            aggiungiElemento(l[i]);
        }
    }
    return *this;
}

LibrettoEsami* LibrettoEsami::operator +(const Esame& e) const{
    LibrettoEsami aux = LibrettoEsami(*this);
    aux += e;
    return new LibrettoEsami(aux);
}

LibrettoEsami* operator+(const Esame& e, const LibrettoEsami& l){
    return l.operator +(e);
}

LibrettoEsami* operator-(const Esame& e, const LibrettoEsami& l){
    return l.operator -(e);
}

LibrettoEsami& LibrettoEsami::operator +=(const Esame& e){
    if(!cerca(e)){
        aggiungiElemento(e);
    }
    return *this;
}

LibrettoEsami* LibrettoEsami::operator -(const Esame& e) const{
    LibrettoEsami aux = LibrettoEsami(*this);
    aux -= e;
    return new LibrettoEsami(aux);
}

LibrettoEsami& LibrettoEsami::operator -=(const Esame& e){
    if(cerca(e)){
        rimuoviElemento(e);
    }
    return *this;
}

LibrettoEsami* LibrettoEsami::operator-(const VettoreGenerico<Esame>& l) const{
    LibrettoEsami aux = LibrettoEsami(*this);
    aux -= l;
    return new LibrettoEsami(aux);
}

LibrettoEsami& LibrettoEsami::operator -=(const VettoreGenerico<Esame>& l){
    for(unsigned int i = 0; i != l.getSize(); ++i){
        if(cerca(operator [](i))){
            rimuoviElemento(l[i]);
        }
    }
    return *this;
}

ostream& operator <<(ostream& os, const LibrettoEsami& l){
    os << "\nMatricola studente: " << l.getMatricola() << endl;
    for(unsigned int i=0; i < l.getSize(); ++i){
         os << " - Esame numero " << i+1 << " - " << endl;
         os << l[i];
    }
    os << "\n";
    return os;
}
