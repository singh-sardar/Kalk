#ifndef VETTOREGENERICO_H
#define VETTOREGENERICO_H
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::find;
using std::ostream;
using std::endl;
/*
 * classe base rappresentante un vettore generico di tipo T
 * */
template <class T>
class VettoreGenerico
{
private:
    vector<T> vettore;

public:
    VettoreGenerico();
    VettoreGenerico(const vector<T>&);
    virtual void aggiungiElemento(const T&);
    T popBackElemento();
    bool rimuoviElemento(const T&);
    void rimuoviPoz(unsigned int);
    bool cerca(const T&);
    const T& operator [](int)const;
    T& operator [](int);
    unsigned int getSize() const;
    virtual VettoreGenerico<T>* operator+(const VettoreGenerico<T>&) const=0;
    virtual VettoreGenerico<T>& operator+=(const VettoreGenerico<T>&) ;
    virtual VettoreGenerico<T>* operator-(const VettoreGenerico<T>&) const=0;
    virtual VettoreGenerico<T>& operator-=(const VettoreGenerico<T>&);
    virtual bool operator ==(const VettoreGenerico<T>&)const;
    virtual bool operator !=(const VettoreGenerico<T>&)const;
    virtual ~VettoreGenerico();
    /*TODO:
     * DECIDERE SE IMPLEMENTARE LE SEGUENTI FUNZIONI
         toString();
         operator*(const VettoreGenerico&);
         operator/(const VettoreGenerico&);
         ordinaVector();

     */
};

template <class T>
ostream& operator<<(ostream& os, const VettoreGenerico<T>& vG){
    for(unsigned int i=0; i < vG.getSize(); ++i){
        os << vG[i] << endl;
    }
    return os;
}

//#H
template <class T>
VettoreGenerico<T>::~VettoreGenerico(){}

//#H
template <class T>
void VettoreGenerico<T>::rimuoviPoz(unsigned int i){
    if(i>=0 && i < getSize())
        vettore.erase(vettore.begin() + i);

}

//#H
//costruttore senza parametri
template <class T>
VettoreGenerico<T>::VettoreGenerico(){}

//#H
//costruttore con un parametro di tipo vector<T>
template <class T>//costruttore a un parametro di tipo vector<T>
VettoreGenerico<T>::VettoreGenerico(const vector<T>& v):vettore(v){}

//#H
//Aggiunge un elemento di tipo T in coda
template <class T>
void VettoreGenerico<T>::aggiungiElemento(const T& element){
    vettore.push_back(element);
}

//#H
//Elimina e ritorna l' elemento in coda
template <class T>
T VettoreGenerico<T>::popBackElemento(){
    T aux = vettore.back();
    vettore.pop_back();
    return aux;

}

//#H
//ritorna true se l' elemento di tipo T è presente altrimenti false
template <class T>
bool VettoreGenerico<T>::cerca(const T& element) {
    return (find(vettore.begin(), vettore.end(), element)!= vettore.end());
}

//#H
//rimuove l'elemento di tipo T dal vettore e ritorna true solo se l'elemento era presente nel vettore ed è stato rimosso
template <class T>
bool VettoreGenerico<T>::rimuoviElemento(const T& element){
    typename vector<T>::iterator it = find(vettore.begin(), vettore.end(), element);
    if( it != vettore.end()) {
        vettore.erase(it);
        return true;
    }else {
        return false;
    }
}

//#H
//somma 2 vettori e ritorna un terzo vettore che contiene la somma elemento per elemento. se i due vettori hanno lunghezza differente ritorna un vettore vuoto
/*
template <class T>
VettoreGenerico<T>* VettoreGenerico<T>::operator+(const VettoreGenerico<T>& vG)const{
    VettoreGenerico<T>* aux = new VettoreGenerico<T>();
    if(vettore.size()==vG.getSize()){
        for(unsigned int i = 0; i < vettore.size();i++){
            aux->aggiungiElemento(vettore[i]+vG.vettore[i]);
        }
    }
    return aux;

    VettoreGenerico aux = VettoreGenerico(*this);
    aux += vG;
    return new VettoreGenerico(aux);*/
/*
}
*/
//#P
//esegue la assegnazione al vettore in seguito alla somma degli elementi di un altro vettore
template <class T>
VettoreGenerico<T>& VettoreGenerico<T>::operator +=(const VettoreGenerico<T>& vG){
    if(vettore.size()==vG.getSize()){
        for(unsigned int i = 0; i < vettore.size();i++){
            //aggiungiElemento(vettore[i]+vG.vettore[i]);

            //vettore[i] = vettore[i] + vG[i];
        }
    }
    return *this;
}

//#H
//sottrae 2 vettori e ritorna un terzo vettore che contiene la differenza elemento per elemento. se i due vettori hanno lunghezza differente ritorna un vettore vuoto
/*template <class T>
VettoreGenerico<T>* VettoreGenerico<T>::operator-(const VettoreGenerico<T>& vG)const{
    VettoreGenerico aux = VettoreGenerico(*this);
    aux -= vG;
    return new VettoreGenerico(aux);
}
*/

template <class T>
VettoreGenerico<T>& VettoreGenerico<T>::operator-=(const VettoreGenerico<T>& vG){
    if(vettore.size()==vG.getSize()){
        for(unsigned int i = 0; i < vettore.size();i++){
            //vettore[i] = vettore[i] - vG[i];
        }
    }
    return *this;
}

//#P
//getSize()
template<class T>
unsigned int VettoreGenerico<T>::getSize() const{
    return vettore.size();
}

//#P
//operator ==
template <class T>
bool VettoreGenerico<T>::operator==(const VettoreGenerico<T>& vG) const{
    if(vettore.size() != vG.getSize()){
        return false;
    }
    bool diverso = true;
    for(unsigned int i=0; i < vettore.size()&& diverso; ++i){
        if(vettore[i] != vG[i])
            diverso = false;
    }
    return diverso;
}

//#P
//operator !=
template <class T>
bool VettoreGenerico<T>::operator !=(const VettoreGenerico<T>& vG) const{
    return !(*this==vG);
}


//#P
//ritorna l' elemento i const
template <class T>
const T& VettoreGenerico<T>::operator [](int i)const{
   return vettore[i];
}

//#H
//ritorna l' elemento i
template <class T>
T& VettoreGenerico<T>::operator [](int i){
   return vettore[i];
}

#endif // VETTOREGENERICO_H
