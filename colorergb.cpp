#include "colorergb.h"
string ColoreRgb::schemaColore()const{
    string s= "rgba("+to_string(getR())+","+to_string(getG())+","+to_string(getB())+","+to_string(static_cast<int>(getA()))+")";
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

ColoreRgb* ColoreRgb::operator *(double s){//scala le componenti del colore basandosi sul parametro
    ColoreRgb* aux = new ColoreRgb(r,g,b,a);
    if(r*s>0 && r*s<255){
        aux->setR(r*s);
    }
    if(g*s>0 && g*s<255){
        aux->setG(g*s);
    }
    if(b*s>0 && b*s<255){
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

        rgb2lab(Lab1);
        crgb1->rgb2lab(Lab2);

        deltaE= sqrt(pow(Lab2[0]-Lab1[0],2) + pow(Lab2[1]-Lab1[1],2) +pow(Lab2[2]-Lab1[2],2));
        return deltaE;

    }else
        return -1;
}


void ColoreRgb::rgb2lab(double Lab[3])const{

    double RGB[3];
    double XYZ[3];
    double adapt[3];

    //riferimenti del bianco
    adapt[0] = 95.0467;
    adapt[1] = 100.0000;
    adapt[2] = 108.8969;

    //riporto il colore da scala 0 - 255 a 0 - 1.0
    RGB[0] = PivotRgb(r /255.0);
    RGB[1] = PivotRgb(g /255.0);
    RGB[2] = PivotRgb(b /255.0);

    //RGB TO XYZ
    XYZ[0] = 0.412424 * RGB[0] + 0.357579 * RGB[1] + 0.180464 * RGB[2];
    XYZ[1] = 0.212656 * RGB[0] + 0.715158 * RGB[1] + 0.0721856 * RGB[2];
    XYZ[2] = 0.0193324 * RGB[0] + 0.119193 * RGB[1] + 0.950444 * RGB[2];

    //LAB
    Lab[0] = 116 * pivotXYZ( XYZ[1] / adapt[1] ) - 16;
    if(Lab[0]<0)
        Lab[0]=0;
    Lab[1] = 500 * ( pivotXYZ( XYZ[0] / adapt[0] ) - pivotXYZ( XYZ[1] / adapt[1] ) );
    Lab[2] = 200 * ( pivotXYZ( XYZ[1] / adapt[1] ) - pivotXYZ( XYZ[2] / adapt[2] ) );
    return;
}

double ColoreRgb::pivotXYZ(double q)
{
    double value;
    if ( q > 0.008856 ) {
        value = pow ( q, 0.333333 );
        return value;
    }
    else {
        value = (903.3*q+16)/116;
        return value;
    }

}
double ColoreRgb::PivotRgb(double n)
{
    return (n > 0.04045 ? pow((n + 0.055) / 1.055, 2.4) : n / 12.92) * 100.0;
}



void ColoreRgb::rgb2hsl(double HSL[3])const{
    double RGB[3];
    //Portare RGB in ranga tra 0 -1.0
    RGB[0] = r /255.0;
    RGB[1] = g /255.0;
    RGB[2] = b /255.0;

    //calcolo del min e max e del delta
    double min = Min(Min(RGB[0], RGB[1]), RGB[2]);
    double max = Max(Max(RGB[0], RGB[1]), RGB[2]);
    double delta = max - min;

    //calcolo del L
    HSL[2] = (max + min) / 2.0;

    if (delta == 0.0)
    {   //in caso di delta = 0 => H = S = 0
        HSL[0] = 0.0;
        HSL[1] = 0.0;
    }
    else
    {
      //Formula di calcolo DEL S se delta !=0
        HSL[1] = ((2*HSL[2]) >=1.0) ? (delta / (1.0 -(2.0*HSL[2]-1.0))) : (delta / (1.0 +(2.0*HSL[2]-1.0)));

        double hue;
        //Calcolo del H
        if (RGB[0] == max)
        {
            hue = ((RGB[1] - RGB[2]) / 6.0) / delta;
        }
        else if (RGB[1] == max)
        {
            hue = (1.0 / 3.0) + ((RGB[2] - RGB[0]) / 6.0) / delta;
        }
        else
        {
            hue = (2.0 / 3.0) + ((RGB[0] - RGB[1]) / 6.0) / delta;
        }

        if (hue < 0.0)
            hue += 1;
        if (hue > 1.0)
            hue -= 1;

        HSL[0] =(hue  *360);
    }
    //trasformazione in precentuale di SL
    HSL[1]= HSL[1]*100;
    HSL[2]= HSL[2]*100;
    return;
}

double  ColoreRgb::Min(double a ,double b){
    return a<b ? a:b;
}
double  ColoreRgb::Max(double a,double b){
    return a>b ? a:b;
}

ColoreRgb* ColoreRgb::complementare()const{
    //calcolo del complementare utilizzando HSL perche migliore
    ColoreRgb* aux = new ColoreRgb();
    double HSL[3];
    int RGB[3];
    rgb2hsl(HSL);
    HSL[0]+=180;
    HSL[0]=fmod(HSL[0],400);
    hsl2rgb(HSL,RGB);
    aux->setR(RGB[0]);
    aux->setG(RGB[1]);
    aux->setB(RGB[2]);

    return aux;
}


ColoreRgb*  ColoreRgb::luminositaColore()const{
    //pittagora
    int value=sqrt(r * r* 0.241 + g * g * 0.691 + b * b * 0.068);
    return new ColoreRgb(value,value,value);
}

bool ColoreRgb::coloreCaldo()const{
    //caldo se il rosso > blue
    return r>b;
}


string ColoreRgb::rgb2hex()const{
    string s= "#";
    char tmp[30];
    int len=0;
    len=sprintf(tmp,"%x",r);

    s+= tmp;
    if(len==1){
        s="#0";
                s+=tmp;
    }
    len=sprintf(tmp,"%x",g);

    s+= tmp;
    if(len==1){
        s+='0';
        s[4]= s[3];
        s[3]='0';
    }
    len=sprintf(tmp,"%x",b);

    s+= tmp;
    if(len==1){
        s+='0';
        s[6]= s[5];
        s[5]='0';
    }
    return s;
}
