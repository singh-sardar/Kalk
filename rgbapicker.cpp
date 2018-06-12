#include "rgbapicker.h"

RgbaPicker::RgbaPicker(QWidget* parent): RgbPicker(parent){

    addSlider(new SpinSlider(this,"Alpha",0,255,255));

    changeColor();
}

void RgbaPicker::changeColor(){
    c->setRgb(getSliderValue(0),getSliderValue(1),getSliderValue(2),getSliderValue(3));
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    viewer->setPalette(p);
    emit colorChanged(c);
}
