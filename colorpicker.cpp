#include "colorpicker.h"
#include <QDebug>
ColorPicker::ColorPicker(QWidget* parent,QString nomP1, int minP1, int maxP1,QString nomP2, int minP2, int maxP2, QString nomP3, int minP3, int maxP3):QWidget(parent)
{
    layout = new QHBoxLayout;
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

    setLayout(layout);

}

ColorPicker::~ColorPicker(){
    delete slider;
    delete viewer;
    delete c;
    delete layout;
}

ColorSlider* ColorPicker::getColorSlider()const{return slider;}
QWidget* ColorPicker::getViewer()const{return viewer;}

int ColorPicker::getP1value()const{return slider->getParametro1()->getSlider()->value();}
QString ColorPicker::getP1Name() const{return slider->getNomeParametro1();}
int ColorPicker::getP2value()const{return slider->getParametro2()->getSlider()->value();}
QString ColorPicker::getP2Name() const{return slider->getNomeParametro2();}
int ColorPicker::getP3value()const{return slider->getParametro3()->getSlider()->value();}
QString ColorPicker::getP3Name() const{return slider->getNomeParametro3();}

void ColorPicker::addSlider(SpinSlider* s){
    slider->addSpinSlider(s);
}
