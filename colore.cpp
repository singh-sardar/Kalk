#include "colore.h"

Colore::Colore():r(0),g(0),b(0),a(1.0)
{
}

Colore::Colore(int red, int green, int blue, float alpha):r(red),g(green),b(blue),a(alpha){
    //se uno dei valori va fuori dal range allora lo riporto a 0 o in caso di alpha a 1
    if(r<0 || r> 255)
        r=0;
    if(g<0 || g> 255)
        g=0;
    if(b<0 || b> 255)
        b=0;
    if(a>0 || a > 1.0)
        a=1.0;
}

//funzioni per modificare un colore
void Colore::setR(int red){
    if(red>=0 && red<= 255)
        r=red;
}
void Colore::setG(int green){
    if(green>=0 && green<=255)
        g= green;
}
void Colore::setB(int blue){
    if(blue>=0 && blue<= 255)
        b=blue;
}
void Colore::setA(float alpha){
    if(alpha>=0 && alpha <= 1.0)
        a= alpha;
}

int Colore::getR()const{
    return r;
}
int Colore::getG()const{
    return g;
}
int Colore::getB()const{
    return b;
}
float Colore::getA()const{
    return a;
}


void Colore::modificaColore(int red, int green, int blue, float alpha){
    setR(red);
    setG(green);
    setB(blue);
    setA(alpha);

}

bool Colore::operator==(const Colore & c)const{
    return r==c.getR() && g==c.getG() && b==c.getB() && a==c.getA();
}
bool Colore::operator !=(const Colore & c )const{
    return !(*this== c);
}

Colore Colore::operator +(const Colore& c){
    Colore aux;
    aux.setR(0.5*r+c.getR()*0.5);
    aux.setG(0.5*g+c.getG()*0.5);
    aux.setB(0.5*b+c.getB()*0.5);
    return aux;
}

