#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include <string>
using std::string;

class Ingrediente
{
private:
    string nome;
    double quantita;// in grammi
    double calorie;// // in riferimento a 100 grammi
    double costo;//al grammo
public:
    Ingrediente();
    Ingrediente(string ,double,double,double);

    string getNome()const;
    double getQuantita()const;
    double getCalorie()const;
    double getCosto()const;
    void setNome(string);
    void setQuantita(double);
    void setCalorie(double);
    void setCosto(double);
    static double kilo2g(double);
    string getDescrizione()const;

    Ingrediente operator+(const Ingrediente&)const;
    Ingrediente operator-(const Ingrediente&)const;
    Ingrediente operator*(int)const;
    Ingrediente operator-(double)const;
    double calorieTorali()const;
    bool operator==(const Ingrediente&)const;
    bool operator !=(const Ingrediente&)const;


};

#endif // INGREDIENTE_H
