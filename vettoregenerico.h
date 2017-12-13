#ifndef VETTOREGENERICO_H
#define VETTOREGENERICO_H
#include <vector>
#include <string>
using std::vector;
using std::string;
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


    //QUANDO SI IMPLEMENTANO I METODI STARE ATTENTI A DECIDERE SE PASSARE PER REF CONST
    //SVILUPPANDO COMMENTARE ADEGUAMENTE IL CODICE
    void aggiungiElemento(T);//aggiunge l' elemento T
    T popElemento(); // da adattare il tipo di ritorno in base al remove del vector
    void rimuoviElemento(const T&); // rimuove l' elemento T
    virtual string toString()const;
    int getSize()const;
    virtual VettoreGenerico operator+(const VettoreGenerico&);
    virtual VettoreGenerico operator-(const VettoreGenerico&);
    virtual VettoreGenerico operator*(const VettoreGenerico&);
    virtual VettoreGenerico operator/(const VettoreGenerico&);
    VettoreGenerico& operator[](int);
    virtual bool operator ==(const VettoreGenerico&)const;
    virtual bool operator !=(const VettoreGenerico&)const;


    virtual ~VettoreGenerico();
};

template <class T>//costruttore senza parametri
VettoreGenerico<T>::VettoreGenerico():size(vettore.size()){}

template <class T>//costruttore a un parametro di tipo vector<T>
VettoreGenerico<T>::VettoreGenerico(vector<T> v):vettore(v),size(v.size()){}




#endif // VETTOREGENERICO_H
