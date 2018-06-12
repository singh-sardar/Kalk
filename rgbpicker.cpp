#include "rgbpicker.h"

RgbPicker::RgbPicker(QWidget* parent): ColorPicker(parent){

    addSlider(new SpinSlider(this,"R",0,255));
    addSlider(new SpinSlider(this,"G",0,255));
    addSlider(new SpinSlider(this,"B",0,255));

    changeColor();
}

void RgbPicker::changeColor(){
    c->setRgb(getSliderValue(0),getSliderValue(1),getSliderValue(2));
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    viewer->setPalette(p);
    emit colorChanged(c);
}
