#include "rgbslider.h"

RgbSlider::RgbSlider(QWidget* parent ):QWidget(parent)
{
    layout = new QVBoxLayout;
    R= new SpinSlider(0,"R",0,255);
    G= new SpinSlider(0,"G",0,255);
    B= new SpinSlider(0,"B",0,255);

    layout->addWidget(R);
    layout->addWidget(G);
    layout->addWidget(B);

    setLayout(layout);


    connect(R,SIGNAL(valueChanged(int)),this,SIGNAL(RvalueChanged(int)));
    connect(G,SIGNAL(valueChanged(int)),this,SIGNAL(GvalueChanged(int)));
    connect(B,SIGNAL(valueChanged(int)),this,SIGNAL(BvalueChanged(int)));

}
SpinSlider* RgbSlider::getR()const{return R;}
SpinSlider* RgbSlider::getG()const{return G;}
SpinSlider* RgbSlider::getB()const{return B;}

