#include "colorslider.h"

ColorSlider::ColorSlider(QWidget* parent):
    QWidget(parent)
{
    /*
    layout = new QVBoxLayout;


    P1= new SpinSlider(0,nomeP1,minP1,maxP1);
    P2= new SpinSlider(0,nomeP2,minP2,maxP2);
    P3= new SpinSlider(0,nomeP3,minP3,maxP3);
    //AlphaSlider = new SpinSlider(0,"Alpha",minAlpha,maxAlpha);

    layout->addWidget(P1);
    layout->addWidget(P2);
    layout->addWidget(P3);
    //layout->addWidget(AlphaSlider);

    setLayout(layout);


    connect(P1,SIGNAL(valueChanged(int)),this,SIGNAL(P1valueChanged(int)));
    connect(P2,SIGNAL(valueChanged(int)),this,SIGNAL(P2valueChanged(int)));
    connect(P3,SIGNAL(valueChanged(int)),this,SIGNAL(P3valueChanged(int)));
    //connect(AlphaSlider,SIGNAL(valueChanged(int)),this,SIGNAL(AlphaValueChanged(int)));
    */

    vector = new QVector<SpinSlider*>;

    layout = new QVBoxLayout;

    setLayout(layout);
}

ColorSlider::~ColorSlider(){
    /*
    delete P1;
    delete P2;
    delete P3;
    */
    //delete AlphaSlider;
    delete vector;
    delete layout;
}

SpinSlider* ColorSlider::getSlider(int i) const{
    return vector->at(i);
}

QString ColorSlider::getNome(int i) const{
    return vector->at(i)->getLable()->text();
}

/*
SpinSlider* ColorSlider::getParametro1()const{return P1;}
QString ColorSlider::getNomeParametro1()const{return nomeP1;}
SpinSlider* ColorSlider::getParametro2()const{return P2;}
QString ColorSlider::getNomeParametro2()const{return nomeP2;}
SpinSlider* ColorSlider::getParametro3()const{return P3;}
QString ColorSlider::getNomeParametro3()const{return nomeP3;}
*/

//SpinSlider* ColorSlider::getAlphaSlider()const{return AlphaSlider;}

void ColorSlider::addSpinSlider(SpinSlider* s){
    vector->append(s);

    connect(s,SIGNAL(valueChanged(int)),this,SIGNAL(colorSliderChanged()));

    layout->addWidget(s);
}
