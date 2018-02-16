#include "colorergb.h"
string ColoreRgb::schemaColore()const{
    string s= "rgb("+to_string(getR())+","+to_string(getG())+","+to_string(getB())/*+","+to_string(static_cast<int>(getA()))*/+")";
    return s;
}
ColoreRgb::ColoreRgb():r(0),g(0),b(0)/*,a(1.0)*/
{
    updateLuminosita();
}

ColoreRgb::ColoreRgb(int red, int green, int blue/*, float alpha*/):r(red),g(green),b(blue)/*,a(alpha)*/{
    //se uno dei valori va fuori dal range allora lo riporto a 0 o in caso di alpha a 1
    if(r<0 || r> 255)
        r=0;
    if(g<0 || g> 255)
        g=0;
    if(b<0 || b> 255)
        b=0;
   /* if(a>0 || a > 1.0)
        a=1.0;*/
    updateLuminosita();
}

//funzioni per modificare un colore
void ColoreRgb::setR(int red){
    if(red>=0 && red<= 255){
        r=red;
        updateLuminosita();

    }
}
void ColoreRgb::setG(int green){
    if(green>=0 && green<=255){
        g= green;
        updateLuminosita();
    }
}
void ColoreRgb::setB(int blue){
    if(blue>=0 && blue<= 255){
        b=blue;
        updateLuminosita();

    }
}/*
void ColoreRgb::setA(float alpha){
    if(alpha>=0 && alpha <= 1.0)
        a= alpha;
}
*/
int ColoreRgb::getR()const{
    return r;
}
int ColoreRgb::getG()const{
    return g;
}
int ColoreRgb::getB()const{
    return b;
}/*
float ColoreRgb::getA()const{
    return a;
}
*/

void ColoreRgb::modificaColore(int red, int green, int blue/*, float alpha*/){
    setR(red);
    setG(green);
    setB(blue);
  //  setA(alpha);

}
/*
bool ColoreRgb::operator==(const Colore & c)const{
    return (schemaColore().compare(c.schemaColore())==0);
}
bool ColoreRgb::operator !=(const Colore & c )const{
    return !(*this== c);
}
*/
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

ColoreRgb* ColoreRgb::operator *(double s)const{//scala le componenti del colore basandosi sul parametro
    ColoreRgb* aux = new ColoreRgb(r,g,b/*,a*/);
    if(r*s>0 && r*s<=255){
        aux->setR(r*s);
    }
    if(g*s>0 && g*s<=255){
        aux->setG(g*s);
    }
    if(b*s>0 && b*s<=255){
        aux->setB(b*s);
    }
    return aux;

}
//calcola DeltaE tra 2 colori ovvero controlla quanto essi si assomigliano un valore sotto al 3% non  è molto percettibile al occhio umano
double ColoreRgb::DeltaE(const Colore& c1)const{ // se la conversione fallisce ritorna -1
    const ColoreRgb* crgb1 = dynamic_cast<const ColoreRgb*>(&c1);
    if(crgb1){
        double deltaE;
        double Lab1[3], Lab2[3];

        //rgb2lab(Lab1);
        ToLab(Lab1);
       // crgb1->rgb2lab(Lab2);
        crgb1->ToLab(Lab2);

        deltaE= sqrt(pow(Lab2[0]-Lab1[0],2) + pow(Lab2[1]-Lab1[1],2) +pow(Lab2[2]-Lab1[2],2));
        return deltaE;

    }else
        return -1;
}


ColoreRgb* ColoreRgb::complementare()const{
    //calcolo del complementare utilizzando HSL perche migliore
    ColoreRgb* aux = new ColoreRgb();
    double HSL[3];
    int RGB[3];
   // rgb2hsl(HSL);
    ToHsl(HSL);
    HSL[0]+=180;
    HSL[0]=fmod(HSL[0],360);
    hsl2rgb(HSL,RGB);
    aux->setR(RGB[0]);
    aux->setG(RGB[1]);
    aux->setB(RGB[2]);

    return aux;
}


ColoreRgb*  ColoreRgb::grayScale()const{
    //pittagora
    int value=sqrt(r * r* 0.241 + g * g * 0.691 + b * b * 0.068);
    return new ColoreRgb(value,value,value);
}

bool ColoreRgb::coloreCaldo()const{
    //caldo se il rosso > blue
    return r>b;
}
string ColoreRgb::ToHex()const{
    int rgb[3]={r,g,b};
    return rgb2hex(rgb);
}

void ColoreRgb::ToLab(double Lab[3])const{
    int rgb[3]={r,g,b};
    rgb2lab(rgb,Lab);
}
void ColoreRgb::ToHsl(double HSL[3])const{
    int rgb[3]={r,g,b};
    rgb2hsl(rgb,HSL);
}
void ColoreRgb::updateLuminosita(){
    int value=sqrt(r * r* 0.241 + g * g * 0.691 + b * b * 0.068);
    setLuminosita((100*value)/255);
}
