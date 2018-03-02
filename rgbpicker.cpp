#include "rgbpicker.h"

RgbPicker::RgbPicker(QWidget* parent){

    addSlider(new SpinSlider(this,"R",0,255));
    addSlider(new SpinSlider(this,"G",0,255));
    addSlider(new SpinSlider(this,"B",0,255));

    //AlphaSlider = new SpinSlider(0,"Alpha",minAlpha,maxAlpha);

    /*
    layout->addWidget(P1);
    layout->addWidget(P2);
    layout->addWidget(P3);
    */
    //layout->addWidget(AlphaSlider);

    changeColor();
}

void RgbPicker::changeColor(){
    //c->setRgb(getP1value(),getP2value(),getP3value());
    c->setRgb(getSliderValue(0),getSliderValue(1),getSliderValue(2));
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    viewer->setPalette(p);
    emit colorChanged(c);
}
