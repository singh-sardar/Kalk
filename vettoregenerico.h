#ifndef VETTOREGENERICO_H
#define VETTOREGENERICO_H
#include <vector>
#include <string>
#include <algorithm>


using std::vector;
using std::string;
using std::find;
/*
 * classe base rappresentante un vettore generico di tipo T
 * */
template <class T>
class VettoreGenerico
{
private:
    vector<T> vettore;
    int size;

public:
    VettoreGenerico();
    VettoreGenerico(vector<T>);



    virtual void aggiungiElemento(const T&);//aggiunge l' elemento T in coda
    T popBackElemento(); //rimuove un elemento in coda dal vettore e lo ritorna per valore
    bool cerca(const T&);//ritorna true se un elemento è presente nel vettore
    bool rimuoviElemento(const T&); // rimuove l' elemento T

/*
    virtual string toString()const;
    int getSize()const;
    virtual VettoreGenerico operator+(const VettoreGenerico&);
    virtual VettoreGenerico operator-(const VettoreGenerico&);
    virtual VettoreGenerico operator*(const VettoreGenerico&);
    virtual VettoreGenerico operator/(const VettoreGenerico&);
    VettoreGenerico& operator[](int);
    virtual bool operator ==(const VettoreGenerico&)const;
    virtual bool operator !=(const VettoreGenerico&)const;
*/

    virtual ~VettoreGenerico();
};


template <class T>
VettoreGenerico<T>::~VettoreGenerico(){}

//#H
//costruttore senza parametri
template <class T>
VettoreGenerico<T>::VettoreGenerico():size(vettore.size()){}

//#H
//costruttore con un parametro di tipo vector<T>
template <class T>//costruttore a un parametro di tipo vector<T>
VettoreGenerico<T>::VettoreGenerico(vector<T> v):vettore(v),size(v.size()){}

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




#endif // VETTOREGENERICO_H
