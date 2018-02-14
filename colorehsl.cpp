#include "colorehsl.h"
string ColoreHsl::schemaColore()const{
    string s= "hsl("+to_string(getH())+","+to_string(getS())+","+to_string(getL())+")";
    return s;
}
ColoreHsl::ColoreHsl():h(0),s(0),l(0){}
ColoreHsl::ColoreHsl(int hue ,  int sat, int light):h(hue),s(sat),l(light){
    if(h<0|| h >= 360)
        h=0;
    if(s<0|| s > 100)
        s=0;
    if(l<0|| l > 100)
        l=0;

}

void ColoreHsl::setH(int hue){
    if(hue>=0&&hue <360)
        h=hue;
}
void ColoreHsl::setS(int sat){
    if(sat>=0&&sat <=100)
        s=sat;
}
void ColoreHsl::setL(int light){
    if(light>=0&&light <=100)
        l=light;
}
int ColoreHsl::getH()const{ return h;}
int ColoreHsl::getS()const{return s;}
int ColoreHsl::getL()const{return l;}
void ColoreHsl::modificaColore(int hue, int sat, int light){
    setH(hue);
    setS(sat);
    setL(light);
}

ColoreHsl* ColoreHsl::operator +(const Colore& c)const{
   //media dei hue
   //se la la differenza tra gli hue è > 180 => add mezzo giro (360/2 = 180) in modulo 360.else

//algoritmo ricavato da idea:
//RGB colour space uses a Cartesian coordinate system while HSL and HSV use polar coordinates. "Half way" is fairly simple in Cartesian coordinates, you just average them pairwise. It gets more complex in polar coordinates. You think of "half way" in different terms, for instance, it's halfway point of an arc ? If an arc, there are two, and four "rules" for choosing one of the two so do you go the short way, the long way, clockwise from the first colour, or counterclockwise from the first colour.
//To find the "straight line" you pretty much have to convert to a Cartesian coordinate system. The simplest arc version would be to average the heights (L) and radii (S), and bisect the smaller angle between the hues. The result will be more saturated than the straight line version.

    ColoreHsl* aux= new ColoreHsl();

    const ColoreHsl* tmp = dynamic_cast<const ColoreHsl*>(&c);
    if(tmp){
        int mediaH = 0.5*h +0.5*tmp->getH();
        if(abs(h-tmp->getH())>180)
            aux->setH((mediaH+180)%360);
        else
            aux->setH(mediaH);
        aux->setS(0.5*s+tmp->getS()*0.5);
        aux->setL(0.5*l+tmp->getL()*0.5);
    }
    return aux;
}

ColoreHsl* ColoreHsl::operator-(const Colore & c)const {
    ColoreHsl* aux= new ColoreHsl();

    const ColoreHsl* tmp = dynamic_cast<const ColoreHsl*>(&c);
    if(tmp){
        int diff = h-tmp->getH();

        if(diff>0)
            aux->setH(diff);

        diff= s -tmp->getS();
        if(diff>0)
            aux->setS(diff);

        diff =l-tmp->getL();
        if(diff>0)
            aux->setL(diff);
    }
    return aux;
}


ColoreHsl* ColoreHsl::operator*(const Colore& c)const{
    ColoreHsl* result = new ColoreHsl;
    const ColoreHsl* temp= dynamic_cast<const ColoreHsl*>(&c);
    if(temp){
        result->modificaColore((temp->getH()*h)%360,(temp->getS()*s)%100,(temp->getL()*l)%100);
    }
    return result;
}



ColoreHsl* ColoreHsl::operator *(double scale) const{
    ColoreHsl* result = new ColoreHsl(h,s,l);
    if(h*scale>=0 && h*scale<360){
        result->setH(h*scale);
    }
    if(s*scale>=0 && s*scale<101){
        result->setS(s*scale);
    }
    if(l*scale>=0 && l*scale<101){
        result->setL(l*scale);
    }
    return result;
}


ColoreHsl* ColoreHsl::complementare()const{
    ColoreHsl*  result= new ColoreHsl(*this);
    result->setH((h+180)%360);
    return result;
}

ColoreHsl* ColoreHsl::luminositaColore()const{
    ColoreHsl* result = new ColoreHsl(0,0,l);
    return result;
}

bool ColoreHsl::coloreCaldo()const{
    return h<180;
}
double ColoreHsl::DeltaE(const Colore&)const{

}
