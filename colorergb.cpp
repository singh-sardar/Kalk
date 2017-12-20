#include "colorergb.h"
string ColoreRgb::schemaColore()const{
    string s= "rgb("+to_string(getR())+","+to_string(getG())+","+to_string(getB())+","+to_string(getA())+")";
    return s;
}
ColoreRgb::ColoreRgb():r(0),g(0),b(0),a(1.0)
{
}

ColoreRgb::ColoreRgb(int red, int green, int blue, float alpha):r(red),g(green),b(blue),a(alpha){
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
void ColoreRgb::setR(int red){
    if(red>=0 && red<= 255)
        r=red;
}
void ColoreRgb::setG(int green){
    if(green>=0 && green<=255)
        g= green;
}
void ColoreRgb::setB(int blue){
    if(blue>=0 && blue<= 255)
        b=blue;
}
void ColoreRgb::setA(float alpha){
    if(alpha>=0 && alpha <= 1.0)
        a= alpha;
}

int ColoreRgb::getR()const{
    return r;
}
int ColoreRgb::getG()const{
    return g;
}
int ColoreRgb::getB()const{
    return b;
}
float ColoreRgb::getA()const{
    return a;
}


void ColoreRgb::modificaColore(int red, int green, int blue, float alpha){
    setR(red);
    setG(green);
    setB(blue);
    setA(alpha);

}

bool ColoreRgb::operator==(const Colore & c)const{
    return (schemaColore().compare(c.schemaColore())==0);
}
bool ColoreRgb::operator !=(const Colore & c )const{
    return !(*this== c);
}

ColoreRgb* ColoreRgb::operator +(const Colore& c)const{
    ColoreRgb* aux= new ColoreRgb();

    const ColoreRgb* tmp = dynamic_cast<const ColoreRgb*>(&c);
    if(tmp){
        aux->setR(0.5*r+tmp->getR()*0.5);
        aux->setG(0.5*g+tmp->getG()*0.5);
        aux->setB(0.5*b+tmp->getB()*0.5);
    }
    return aux;
}

ColoreRgb* ColoreRgb::operator -(const Colore& c)const{
    //sintesi sottrativa di un colore. cioè data una luce di un certo colore. e data la quantita di luce che assorbe la superfice di riflessione ottengo la luce che verra percepita dal occhio
    ColoreRgb* aux= new ColoreRgb();

    const ColoreRgb* tmp = dynamic_cast<const ColoreRgb*>(&c);
    if(tmp){
        int valoreLuce = r-tmp->getR();

        if(valoreLuce<0)
            valoreLuce=0;
        aux->setR(valoreLuce);

        valoreLuce= g -tmp->getG();
        if(valoreLuce<0)
            valoreLuce=0;
        aux->setG(valoreLuce);

        valoreLuce = b -tmp->getB();
        if(valoreLuce<0)
            valoreLuce=0;
        aux->setB(valoreLuce);
    }
    return aux;
}

ColoreRgb* ColoreRgb::operator *(const Colore& c)const{
    ColoreRgb* aux= new ColoreRgb();

    const ColoreRgb* tmp = dynamic_cast<const ColoreRgb*>(&c);
    if(tmp){
        aux->setR((r*tmp->getR())/255);
        aux->setG((g*tmp->getG())/255);
        aux->setB((b*tmp->getB())/255);
    }
    return aux;
}

