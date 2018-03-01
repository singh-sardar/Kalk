#include "hslpicker.h"

HslPicker::HslPicker(QWidget* parent): ColorPicker(parent,"H",0,360,"S",0,100,"L",0,100){
    changeColor();
}

void HslPicker::changeColor(){
    c->setHsl(getP1value(),getP2value()*2.55,getP3value()*2.55);
    //c->setAlpha(50*2.55);
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    p.setBrush(QPalette::Base, Qt::transparent);
    viewer->setPalette(p);

    emit colorChanged(c);
}
