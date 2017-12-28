#ifndef MATRICEALGEBRICA_H
#define MATRICEALGEBRICA_H

#include "vettoregenerico.h"
#include <math.h>

using std::pow;

class MatriceAlgebrica: public VettoreGenerico<vector<int>>{
private:
    unsigned int numColonne;

public:
    MatriceAlgebrica(unsigned int numR=1, unsigned int numC=1);
    unsigned int getNumRighe() const;
    unsigned int getNumColonne() const;
    static int sommaVettori(const vector<int>&,const vector<int>&);
    /*unsigned int getMaxNumColonne() const;*/
    MatriceAlgebrica* operator +(const VettoreGenerico<vector<int>>&)const override;
    MatriceAlgebrica* operator -(const VettoreGenerico<vector<int>>&)const override;
    MatriceAlgebrica* operator*(double)const;//prodotto scalare
    MatriceAlgebrica* operator*(const VettoreGenerico<vector<int>>&)const;
    MatriceAlgebrica* operator/(double)const;
    MatriceAlgebrica* trasposta() const;
    MatriceAlgebrica* elevaAPotenza(int) const;
    double ottieniDeterminante() const;
    bool isDiagonale() const;
    bool isScalare(int) const;
};

#endif // MATRICEALGEBRICA_H
