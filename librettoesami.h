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
    LibrettoEsami(string nomeS="",string cognomeS="",unsigned int matricolaS=0, unsigned int targCFU=0);
    void aggiungiElemento(const Esame&) override;
    bool rimuoviElemento(const Esame&);
    LibrettoEsami* operator+(const VettoreGenerico<Esame>&) const override;
    LibrettoEsami* operator +(const Esame&) const;
    LibrettoEsami* operator-(const VettoreGenerico<Esame>&) const override;
    LibrettoEsami* operator -(const Esame&) const;
    LibrettoEsami& operator+=(const VettoreGenerico<Esame>&) override;
    LibrettoEsami& operator +=(const Esame&);
    LibrettoEsami& operator-=(const VettoreGenerico<Esame>&) override;
    LibrettoEsami& operator -=(const Esame&);
    double percentualeCompletamento() const;//ritorna la percentuale di completamento degli studi
    unsigned int rimanentiCFU() const;
    double mediaAritmetica() const;
    double mediaPonderata() const;
    double previsioneVotoLaurea() const;
    int numeroEsamiSostenuti() const;
    Esame esameMigliore() const; //ritorna l'esame col risultato migliore
    Esame esamePeggiore() const; //ritorna l'esame col risultato peggiore
    Esame esamePiuRecente() const;//ritorna l'esame che è stato svolto più recentemente
    Esame esameMenoRecente() const;//ritorna l'esame che è stato svolto meno recentemente
    unsigned int getTargetCFU() const;
    unsigned int getTotaleCFU() const;
    unsigned int getMatricola() const;
    string getNomeStudente() const;
    string getCognomeStudente() const;
};

ostream& operator <<(ostream&, const LibrettoEsami&);
LibrettoEsami* operator+(const Esame&, const LibrettoEsami&);
LibrettoEsami* operator-(const Esame&, const LibrettoEsami&);

#endif // LIBRETTOESAMI_H
