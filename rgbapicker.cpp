#include "rgbapicker.h"

RgbaPicker::RgbaPicker(QWidget* parent): RgbPicker(parent){
    alpha = new SpinSlider(this,"Alpha",0,255);
    alpha->getSpinBox()->setValue(alpha->getSpinBox()->maximum());

    addSlider(alpha);
    connect(alpha,SIGNAL(valueChanged(int)),this,SLOT(changeColor()));
    changeColor();
}

void RgbaPicker::changeColor(){
    c->setRgb(getP1value(),getP2value(),getP3value());
    c->setAlpha(alpha->getSlider()->value());
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    viewer->setPalette(p);
    emit colorChanged(c);
}

int RgbaPicker::getAlphaValue()const{
    return alpha->getSlider()->value();
}
