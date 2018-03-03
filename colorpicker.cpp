#include "colorpicker.h"
#include <QDebug>
ColorPicker::ColorPicker(QWidget* parent):QWidget(parent)
{
    //layout = new QHBoxLayout;

    layoutH = new QHBoxLayout;
    layoutV = new QVBoxLayout;
    vector = new QVector<SpinSlider*>;
    //slider = new ColorSlider(this);
    viewer = new QWidget;
    viewer->setMinimumSize(100,100);
    viewer->setAutoFillBackground(true);
    c= new  QColor;


    //layout->addWidget(slider);
    layoutH->addLayout(layoutV);
    layoutH->addWidget(viewer);

    //connect(slider,SIGNAL(colorSliderChanged()),this,SLOT(changeColor()));

    /*
    slider = new ColorSlider(parent,nomP1,minP1,maxP1,nomP2,minP2,maxP2,nomP3,minP3,maxP3);
    viewer = new QWidget;
    viewer->setMinimumSize(100,100);
    viewer->setAutoFillBackground(true);
    //viewer->setStyleSheet("border: 1px double black; background-color: white");
    c= new  QColor;

    layout->addWidget(slider);
    layout->addWidget(viewer);

    connect(slider,SIGNAL(P1valueChanged(int)),this,SLOT(changeColor()));
    connect(slider,SIGNAL(P2valueChanged(int)),this,SLOT(changeColor()));
    connect(slider,SIGNAL(P3valueChanged(int)),this,SLOT(changeColor()));
    //changeColor();
    */



    //layout = new QVBoxLayout;

    //setLayout(layout);

    setLayout(layoutH);

}

ColorPicker::~ColorPicker(){
    //delete slider;
    delete viewer;
    delete c;
    //delete layout;

    delete layoutV;
    delete layoutH;
    delete vector;
}

//ColorSlider* ColorPicker::getColorSlider()const{return slider;}
QWidget* ColorPicker::getViewer()const{return viewer;}

/*
int ColorPicker::getP1value()const{return slider->getParametro1()->getSlider()->value();}
QString ColorPicker::getP1Name() const{return slider->getNomeParametro1();}
int ColorPicker::getP2value()const{return slider->getParametro2()->getSlider()->value();}
QString ColorPicker::getP2Name() const{return slider->getNomeParametro2();}
int ColorPicker::getP3value()const{return slider->getParametro3()->getSlider()->value();}
QString ColorPicker::getP3Name() const{return slider->getNomeParametro3();}
*/

int ColorPicker::getSliderValue(int i)const{
    //return slider->getSlider(i)->getSlider()->value();
    return vector->at(i)->getSlider()->value();
}

QString ColorPicker::getSliderName(int i) const{
    //return slider->getNome(i);
    return vector->at(i)->getLable()->text();
}

void ColorPicker::addSlider(SpinSlider* s){
    vector->append(s);

    //connect(s,SIGNAL(valueChanged(int)),this,SIGNAL(colorSliderChanged()));
    connect(s,SIGNAL(valueChanged(int)),this,SLOT(changeColor()));

    layoutV->addWidget(s);
}