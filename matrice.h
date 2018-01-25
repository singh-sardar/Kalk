#ifndef MATRICE_H
#define MATRICE_H

#include "vettoregenerico.h"
#include <math.h>

using std::pow;

class Matrice: public VettoreGenerico<double>{
private:
    unsigned int numRighe;
    unsigned int numColonne;
    unsigned int indiceColonnaFinale;

public:
    Matrice(unsigned int numR=1, unsigned int numC=1, double valDef=0);
    unsigned int getNumRighe() const;
    unsigned int getNumColonne() const;
    const double& operator [](unsigned int)const;
    double& operator [](unsigned int);
    bool rimuoviElemento(double);
    void rimuoviPoz(unsigned int);
    static double sommaVettori(const vector<double>&,const vector<double>&);
    double getValore(unsigned int riga, unsigned int colonna) const;
    vector<double> getRiga(unsigned int riga) const;
    void setValore(unsigned int riga, unsigned int colonna, double valore);
    void aggiungiElemento(double);
    Matrice* operator +(const VettoreGenerico<double>&)const override;
    Matrice* operator -(const VettoreGenerico<double>&)const override;
    Matrice* operator*(double)const;//prodotto scalare
    Matrice* operator*(const VettoreGenerico<double>&)const;
    Matrice* operator/(double)const;
    Matrice* matriceTrasposta() const;
    Matrice* elevaAPotenza(int) const;
    double determinante() const;
    Matrice* matriceInversa() const;
    Matrice* matriceRidotta(unsigned int i, unsigned int j) const;
    Matrice* matriceCofattore() const;
    virtual bool isDiagonale() const;
    virtual bool isScalare(double) const;
    virtual bool isSimmetrica() const;
    string rappresentazioneStringa() const;
};

#endif // MATRICE_H
