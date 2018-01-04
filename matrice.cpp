#include "matrice.h"

using std::to_string;

Matrice::Matrice(unsigned int numR, unsigned int numC, double valDef):
    VettoreGenerico(vector<double>(numR*numC,valDef)), numRighe(numR),numColonne(numC), indiceColonnaFinale(0)
{
}

unsigned int Matrice::getNumRighe() const{
    return numRighe;
}

unsigned int Matrice::getNumColonne() const{
    return numColonne;
}

unsigned int Matrice::getNumElementi() const{
    return getSize();
}

double Matrice::getValore(unsigned int riga, unsigned int colonna) const{
    return VettoreGenerico::operator [](riga*numColonne+colonna);
}

void Matrice::setValore(unsigned int riga, unsigned int colonna, double valore){
    VettoreGenerico::operator [](riga*numColonne+colonna) = valore;
}

double Matrice::sommaVettori(const vector<double>& v1, const vector<double>& v2){
    double temp=0;
    if(v1.size() == v2.size()){
        for(unsigned int i=0; i < v1.size(); ++i){
            temp += v1[i]*v2[i];
        }
    }
    return temp;
}

void Matrice::aggiungiElemento(double d){
    if((indiceColonnaFinale == numColonne) || indiceColonnaFinale==0){
        numRighe++;
        indiceColonnaFinale=0;
        VettoreGenerico::aggiungiElemento(d);
        indiceColonnaFinale++;
        for(unsigned int i=numColonne, j=indiceColonnaFinale; i-j>0; ++j){
            VettoreGenerico::aggiungiElemento(0);
        }
    }else{
        setValore(numRighe-1,indiceColonnaFinale,d);
        indiceColonnaFinale++;
    }
}

bool Matrice::rimuoviElemento(double d){
    bool trovato=false;
    for(unsigned int i=0; i < getNumRighe() && !trovato; ++i){
        for(unsigned int j=0; j < getNumColonne() && !trovato; ++j){
            if(getValore(i,j)==d){
                trovato=true;
                setValore(i,j,0);
            }
        }
    }
    return trovato;
}

void Matrice::rimuoviPoz(unsigned int indice){
    VettoreGenerico::operator [](indice) = 0;
}

Matrice* Matrice::operator +(const VettoreGenerico<double>& m) const{
    const Matrice* tempM = dynamic_cast<const Matrice*>(&m);
    if(tempM && (tempM->getNumRighe() == getNumRighe()) && (tempM->getNumColonne() == getNumColonne())){
        Matrice* aux = new Matrice(*this);
        for(unsigned int i = 0; i < getNumRighe(); ++i){
            for(unsigned int j=0; j < getNumColonne(); ++j){
                //(aux->operator [](i))[j] += (tempM->operator [](i))[j];
                aux->setValore(i,j,(aux->getValore(i,j) + tempM->getValore(i,j)));
            }
        }
        return aux;
    }
    return 0;
}

Matrice* Matrice::operator -(const VettoreGenerico<double>& m) const{
    const Matrice* tempM = dynamic_cast<const Matrice*>(&m);
    if(tempM && (tempM->getNumRighe() == getNumRighe()) && (tempM->getNumColonne() == getNumColonne())){
        Matrice* aux = new Matrice(*this);
        for(unsigned int i = 0; i < getNumRighe(); ++i){
            for(unsigned int j=0; j < getNumColonne(); ++j){
                aux->setValore(i,j,(aux->getValore(i,j) - tempM->getValore(i,j)));
            }
        }
        return aux;
    }else{
        return 0;
    }
}

Matrice* Matrice::operator *(double n) const{
    Matrice* aux = new Matrice(*this);
    for(unsigned int i = 0; i < getNumRighe(); ++i){
        for(unsigned int j=0; j < getNumColonne(); ++j){
            aux->setValore(i,j,(aux->getValore(i,j) * n));
        }
    }
    return aux;
}

vector<double> Matrice::getRiga(unsigned int riga) const{
    vector<double> tempV;
    if(riga <= numRighe){
        for(unsigned int i=0; i < numColonne; ++i){
            tempV.push_back(getValore(riga,i));
        }
    }
    return tempV;
}

Matrice* Matrice::operator *(const VettoreGenerico<double>& m) const{
    const Matrice* tempM = dynamic_cast<const Matrice*>(&m);
    //il prodotto è possibile solo se il numero di colonne del primo operando è uguale al numero di righe del secondo operando
    if(tempM && (getNumColonne() == tempM->getNumRighe())){
        Matrice* aux = new Matrice(getNumRighe(), tempM->getNumColonne());
        for(unsigned int i = 0; i < aux->getNumRighe(); ++i){
            for(unsigned int j=0; j < aux->getNumColonne(); ++j){
                vector<double> tempVector;
                for(unsigned int k=0; k < tempM->getNumRighe(); ++k){
                    tempVector.push_back(tempM->getValore(k,j));
                }
                aux->setValore(i,j,Matrice::sommaVettori(getRiga(i),tempVector));
            }
        }
        return aux;
    }else{
        return 0;
    }
}

Matrice* Matrice::operator /(double n) const{
    return (*this) * (1/n);
}

Matrice* Matrice::matriceTrasposta() const{
    Matrice* aux = new Matrice(getNumColonne(), getNumRighe());
    for(unsigned int i=0; i < getNumRighe(); ++i){
        for(unsigned int j=0; j < getNumColonne(); ++j){
            aux->setValore(j,i,this->getValore(i,j));
        }
    }
    return aux;
}

Matrice* Matrice::matriceRidotta(unsigned int i, unsigned int j) const{
    Matrice* min = new Matrice(numRighe-1,numColonne-1);

    for(unsigned int row=0; row < min->getNumRighe(); ++row){
        for(unsigned int col=0; col < min->getNumColonne(); ++col){
            if(col >= j && row >= i)
                min->setValore(row,col,getValore(row+1,col+1));
            if (col >= j && row<i)
                min->setValore(row,col, getValore(row, col+1));
            if(col < j && row>=i)
                min->setValore(row,col, getValore(row+1,col));
            if(row < i && col < j)
                min->setValore(row,col, getValore(row, col));
        }
    }
    return min;
}

Matrice* Matrice::matriceCofattore() const{
    if((numRighe == numColonne) && numRighe > 2){
        Matrice* mat1 = new Matrice(numRighe, numColonne);
        for(unsigned int i=0; i < mat1->getNumRighe(); ++i){
            for(unsigned int j=0; j < mat1->getNumColonne(); ++j){
                Matrice* mat2 = matriceRidotta(i,j);

                if((i%2==0 && j%2==0) || i==j){
                    mat1->setValore(i,j,mat2->determinante());
                }else{
                    mat1->setValore(i,j,-(mat2->determinante()));
                }
            }
        }
        return mat1;
    }
    return 0;
}

double Matrice::determinante() const{
    double t=0;
    if((numRighe == numColonne) && numRighe > 2){
        for(unsigned int i=0; i < numColonne;++i){
            Matrice* min = matriceRidotta(0,i);
            if(i%2==0){
                t+= (getValore(0,i)*min->determinante());
            }else{
                t-= (getValore(0,i)*min->determinante());
            }
        }
    }else{//matrice 2*2
        t+= ((getValore(0,0)*getValore(1,1))-(getValore(1,0)*getValore(0,1)));
    }
    return t;
}

Matrice* Matrice::matriceInversa() const{
    if(determinante() != 0.0 && (numColonne==numRighe)){
        if(numColonne > 2){
            Matrice* cofat = matriceCofattore();
            Matrice* trasp = cofat->matriceTrasposta();
            return (*trasp)/determinante();
        }else{
            Matrice* mat = new Matrice(numRighe, numColonne);
            mat->setValore(0,0,getValore(1,1)/determinante());
            mat->setValore(0,1,-getValore(0,1)/determinante());
            mat->setValore(1,0,-getValore(1,0)/determinante());
            mat->setValore(1,1,getValore(0,0)/determinante());
            return mat;
        }
    }
    return 0;
}

bool Matrice::isDiagonale() const{
    if(getNumRighe() == getNumColonne()){
        bool diversoDaZero = true;
        for(unsigned int i = 0; i < getNumRighe() && diversoDaZero; ++i){
            for(unsigned int j=0; j < getNumColonne(); ++j){
                if(getValore(i,j) != 0.0 && i!=j){
                    diversoDaZero = false;
                }
            }
        }
        return diversoDaZero;
    }
    return false;
}

string Matrice::rappresentazioneStringa() const{
    string t = "Numero righe: " + to_string(getNumRighe()) + " Numero colonne: " + to_string(getNumColonne());
    for(unsigned int i=0; i < getNumRighe(); ++i){
        t += "\n";
        for(unsigned int j=0; j < getNumColonne(); ++j){
            t += to_string(getValore(i,j)) + " ";
        }
    }
    return t;
}

bool Matrice::isScalare(double n) const{
    if(isDiagonale()){
        bool flag = true;
        for(unsigned int i=0; i < getNumRighe() && flag; ++i){
            for(unsigned int j=0; j < getNumColonne(); ++j){
                if(i==j && (getValore(i,j) != n)){
                    flag = false;
                }
            }
        }
        return flag;
    }
    return false;
}

bool Matrice::isSimmetrica() const{
    return (*this == *(this->matriceTrasposta()));
}

Matrice* Matrice::elevaAPotenza(int n) const{
    Matrice* aux = new Matrice(*this);
    for(unsigned int i=0; i < getNumRighe(); ++i){
        for(unsigned int j=0; j < getNumColonne(); ++j){
            aux->setValore(i,j,pow(getValore(i,j),n));
        }
    }
    return aux;
}
