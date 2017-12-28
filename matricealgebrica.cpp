#include "matricealgebrica.h"

MatriceAlgebrica::MatriceAlgebrica(unsigned int numR, unsigned int numC):
    VettoreGenerico(vector<vector<int>>(numR, vector<int>(numC))), numColonne(numC), numRighe(numR)
{
}

unsigned int MatriceAlgebrica::getNumRighe() const{
    return numRighe;
}

unsigned int MatriceAlgebrica::getNumColonne() const{
    return numColonne;
}

int MatriceAlgebrica::sommaVettori(const vector<int>& v1, const vector<int>& v2){
    int temp=0;
    if(v1.size() == v2.size()){
        for(unsigned int i=0; i < v1.size(); ++i){
            temp += v1[i]*v2[i];
        }
    }
    return temp;
}

unsigned int MatriceAlgebrica::getMaxNumColonne() const{
    unsigned int tempMax = 0;
    for(unsigned int i=0; i < getSize(); i++){
        if((this->operator [](i)).size() < tempMax){
            tempMax = (this->operator [](i)).size();
        }
    }
    return tempMax;
}

MatriceAlgebrica* MatriceAlgebrica::operator +(const VettoreGenerico<vector<int>>& m) const{
    const MatriceAlgebrica* tempM = dynamic_cast<const MatriceAlgebrica*>(&m);
    if(tempM && (tempM->getNumRighe() == getNumRighe()) && (tempM->getNumColonne() == getNumColonne())){
        MatriceAlgebrica* aux = new MatriceAlgebrica(*this);
        for(unsigned int i = 0; i < getNumRighe(); ++i){
            for(unsigned int j=0; j < getNumColonne(); ++j){
                (aux->operator [](i))[j] += (tempM->operator [](i))[j];
            }
        }
        return aux;
    }else{
        return 0;
    }
}

MatriceAlgebrica* MatriceAlgebrica::operator -(const VettoreGenerico<vector<int>>& m) const{
    const MatriceAlgebrica* tempM = dynamic_cast<const MatriceAlgebrica*>(&m);
    if(tempM && (tempM->getNumRighe() == getNumRighe()) && (tempM->getNumColonne() == getNumColonne())){
        MatriceAlgebrica* aux = new MatriceAlgebrica(*this);
        for(unsigned int i = 0; i < getNumRighe(); ++i){
            for(unsigned int j=0; j < getNumColonne(); ++j){
                (aux->operator [](i))[j] += (tempM->operator [](i))[j];
            }
        }
        return aux;
    }else{
        return 0;
    }
}

MatriceAlgebrica* MatriceAlgebrica::operator *(double n) const{
    MatriceAlgebrica* aux = new MatriceAlgebrica(*this);
    for(unsigned int i = 0; i < getNumRighe(); ++i){
        for(unsigned int j=0; j < getNumColonne(); ++j){
            (aux->operator [](i))[j] *= n;
        }
    }
    return aux;
}

MatriceAlgebrica* MatriceAlgebrica::operator *(const VettoreGenerico<vector<int>>& m) const{
    const MatriceAlgebrica* tempM = dynamic_cast<const MatriceAlgebrica*>(&m);
    //il prodotto è possibile solo se il numero di colonne del primo operando è uguale al numero di righe del secondo operando
    if(tempM && (getNumColonne() == tempM->getNumRighe())){
        MatriceAlgebrica* aux = new MatriceAlgebrica(getNumRighe(), tempM->getNumColonne());
        for(unsigned int i = 0; i < aux->getNumRighe(); ++i){
            for(unsigned int j=0; j < aux->getNumColonne(); ++j){
                vector<int> tempVector;
                for(unsigned int k=0; k < tempM->getNumRighe(); ++k){
                    tempVector.push_back((tempM->operator [](k))[j]);
                }
                (aux->operator [](i))[j] = MatriceAlgebrica::sommaVettori(this->operator [](i),tempVector);
            }
        }
        return aux;
    }else{
        return 0;
    }
}

MatriceAlgebrica* MatriceAlgebrica::operator /(double n) const{
    return *this * (1/n);
}

MatriceAlgebrica* MatriceAlgebrica::trasposta() const{
    MatriceAlgebrica* aux = new MatriceAlgebrica(getNumColonne(), getNumRighe());
    for(unsigned int i=0; i < getNumRighe(); ++i){
        for(unsigned int j=0; j < getNumColonne(); ++j){
            (aux->operator [](j))[i] = (this->operator [](i))[j];
        }
    }
    return aux;
}
