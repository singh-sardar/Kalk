#include "hslslider.h"

HSLSlider::HSLSlider(QWidget* parent ):QWidget(parent)
{
    layout = new QVBoxLayout;
    H= new SpinSlider(0,"H",0,360);
    S= new SpinSlider(0,"S",0,100);
    L= new SpinSlider(0,"L",0,100);

    layout->addWidget(H);
    layout->addWidget(S);
    layout->addWidget(L);

    setLayout(layout);


    connect(H,SIGNAL(valueChanged(int)),this,SIGNAL(HvalueChanged(int)));
    connect(S,SIGNAL(valueChanged(int)),this,SIGNAL(SvalueChanged(int)));
    connect(L,SIGNAL(valueChanged(int)),this,SIGNAL(LvalueChanged(int)));

}

HSLSlider::~HSLSlider(){
    delete H;
    delete S;
    delete L;
    delete layout;

}

SpinSlider* HSLSlider::getH()const{return H;}
SpinSlider* HSLSlider::getS()const{return S;}
SpinSlider* HSLSlider::getL()const{return L;}

