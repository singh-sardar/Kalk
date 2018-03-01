#include "rgbpicker.h"

RgbPicker::RgbPicker(QWidget* parent): ColorPicker(parent,"R",0,255,"G",0,255,"B",0,255){
    changeColor();
}

void RgbPicker::changeColor(){
    c->setRgb(getP1value(),getP2value(),getP3value());
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    viewer->setPalette(p);
    emit colorChanged(c);
}
