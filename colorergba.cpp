#include "colorergba.h"


ColoreRgba::ColoreRgba():ColoreRgb(0,0,0),a(1.0){}
ColoreRgba::ColoreRgba(int red, int green, int blue, float alpha):ColoreRgb(red,green,blue),a(alpha){
    if(a<0 || a > 1.0)
        a=1.0;
}

void ColoreRgba::setA(float alpha){
    if(alpha>=0 && alpha <= 1.0)
        a= alpha;
}
float ColoreRgba::getA()const{
    return a;
}


string ColoreRgba::schemaColore()const{
    float a = getA();
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << a;
    string s= "rgba("+to_string(getR())+","+to_string(getG())+","+to_string(getB())+","+stream.str()+")";
    return s;
}


ColoreRgba* ColoreRgba::operator +(const Colore& c)const{
    ColoreRgba* aux= new ColoreRgba();

    const ColoreRgba* tmp = dynamic_cast<const ColoreRgba*>(&c);
    if(tmp){
        ColoreRgb* baseOp;
        baseOp=ColoreRgb::operator +(*tmp);
        aux->modificaColore(baseOp->getR(),baseOp->getG(),baseOp->getB());
        delete baseOp;
        aux->setA(0.5*a+tmp->getA()*0.5);
    }
    return aux;
}

ColoreRgba* ColoreRgba::operator -(const Colore& c)const{
    ColoreRgba* aux= new ColoreRgba();

    const ColoreRgba* tmp = dynamic_cast<const ColoreRgba*>(&c);
    if(tmp){
        ColoreRgb* baseOp;
        baseOp=ColoreRgb::operator -(*tmp);
        aux->modificaColore(baseOp->getR(),baseOp->getG(),baseOp->getB());
        delete baseOp;
        aux->setA(a-tmp->getA());
    }
    return aux;
}

ColoreRgba* ColoreRgba::operator *(const Colore& c)const{
    ColoreRgba* aux= new ColoreRgba();

    const ColoreRgba* tmp = dynamic_cast<const ColoreRgba*>(&c);
    if(tmp){
        ColoreRgb* baseOp;
        baseOp=ColoreRgb::operator *(*tmp);
        aux->modificaColore(baseOp->getR(),baseOp->getG(),baseOp->getB());
        delete baseOp;
        aux->setA(a*tmp->getA());
    }
    return aux;
}

ColoreRgba* ColoreRgba::operator *(double s)const{//scala le componenti del colore basandosi sul parametro
    ColoreRgba* aux= new ColoreRgba(getR(),getG(),getB());
    ColoreRgb* baseOp;
    baseOp=ColoreRgb::operator *(s);
    aux->modificaColore(baseOp->getR(),baseOp->getG(),baseOp->getB());
    delete baseOp;
    aux->setA(a*s);
    return aux;

}

ColoreRgba* ColoreRgba::clone() const{
    return new ColoreRgba(*this);
}
