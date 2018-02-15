#include "colore.h"

void  Colore::hsl2rgb(double HSL[3],int RGB[3]){
    //algoritomo di conversione
    double  RGB1[3];
    HSL[1]/=100.0;
    HSL[2]/=100.0;
    if (HSL[1] == 0.0)
    {
        RGB[0] = RGB[1]= RGB[2] = HSL[2] * 255;
    }
    else
    {


        double chroma = (1 - abs(2 * HSL[2] - 1)) * HSL[1];
        double x = chroma * (1 - (abs(fmod(HSL[0] / 60,2)-1) ));
        double m = HSL[2] - chroma/2;

        if(HSL[0]>=0.0&&HSL[0]<60.0){
            RGB1[0]=chroma;
            RGB1[1]=x;
            RGB1[2]=0;
        }
        if(HSL[0]>=60.0&&HSL[0]<120.0){
            RGB1[0]=x;
            RGB1[1]=chroma;
            RGB1[2]=0;
        }
        if(HSL[0]>=120.0&&HSL[0]<180.0){
            RGB1[0]=0;
            RGB1[1]=chroma;
            RGB1[2]=x;
        }
        if(HSL[0]>=180.0&&HSL[0]<240.0){
            RGB1[0]=0;
            RGB1[1]=x;
            RGB1[2]=chroma;
        }
        if(HSL[0]>=240.0&&HSL[0]<300.0){
            RGB1[0]=x;
            RGB1[1]=0;
            RGB1[2]=chroma;
        }
        if(HSL[0]>=300.0&&HSL[0]<360.0){
            RGB1[0]=chroma;
            RGB1[1]=0;
            RGB1[2]=x;
        }
        RGB[0]=(RGB1[0]+m)*255;
        RGB[1]=(RGB1[1]+m)*255;
        RGB[2]=(RGB1[2]+m)*255;

    }


    return;
}

double Colore::abs(double d){
    return d>= 0 ? d:-d;
}


double Colore::pivotXYZ(double q)
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
double Colore::PivotRgb(double n)
{
    return (n > 0.04045 ? pow((n + 0.055) / 1.055, 2.4) : n / 12.92) * 100.0;
}
double  Colore::Min(double a ,double b){
    return a<b ? a:b;
}
double  Colore::Max(double a,double b){
    return a>b ? a:b;
}

void Colore::rgb2lab(int rgb_in[3],double Lab[3]){

    double RGB[3];
    double XYZ[3];
    double adapt[3];

    //riferimenti del bianco
    adapt[0] = 95.0467;
    adapt[1] = 100.0000;
    adapt[2] = 108.8969;

    //riporto il colore da scala 0 - 255 a 0 - 1.0
    RGB[0] = PivotRgb(rgb_in[0] /255.0);
    RGB[1] = PivotRgb(rgb_in[1] /255.0);
    RGB[2] = PivotRgb(rgb_in[2] /255.0);

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
void Colore::rgb2hsl(int rgb_in[3],double HSL[3]){
    double RGB[3];
    //Portare RGB in ranga tra 0 -1.0
    RGB[0] = rgb_in[0] /255.0;
    RGB[1] = rgb_in[1] /255.0;
    RGB[2] = rgb_in[2] /255.0;

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
bool Colore::operator==(const Colore & c)const{
    return (schemaColore().compare(c.schemaColore())==0);
}
bool Colore::operator !=(const Colore & c )const{
    return !(*this== c);
}
