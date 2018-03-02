#include "hslpicker.h"

HslPicker::HslPicker(QWidget* parent){
    addSlider(new SpinSlider(this,"H",0,360));
    addSlider(new SpinSlider(this,"S",0,100));
    addSlider(new SpinSlider(this,"L",0,100));

    changeColor();
}

void HslPicker::changeColor(){
    //c->setHsl(getP1value(),getP2value()*2.55,getP3value()*2.55);
    c->setHsl(getSliderValue(0),getSliderValue(1)*2.55,getSliderValue(2)*2.55);
    //c->setAlpha(50*2.55);
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    p.setBrush(QPalette::Base, Qt::transparent);
    viewer->setPalette(p);

    emit colorChanged(c);
}
