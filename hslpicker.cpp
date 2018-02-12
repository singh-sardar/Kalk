#include "hslpicker.h"
#include <QDebug>
HSLPicker::HSLPicker(QWidget* parent):QWidget(parent)
{
    layout = new QHBoxLayout;
    slider = new HSLSlider;
    viewer = new QWidget;
    viewer->setMinimumSize(100,100);
    viewer->setAutoFillBackground(true);
    c= new  QColor;
    layout->addWidget(slider);
    layout->addWidget(viewer);

    connect(slider,SIGNAL(HvalueChanged(int)),this,SLOT(changeColor()));
    connect(slider,SIGNAL(SvalueChanged(int)),this,SLOT(changeColor()));
    connect(slider,SIGNAL(LvalueChanged(int)),this,SLOT(changeColor()));
    changeColor();

    setLayout(layout);

}

HSLPicker::~HSLPicker(){
    delete slider;
    delete viewer;
    delete c;
    delete layout;
}

HSLSlider* HSLPicker::getHSLSlider()const{return slider;}
QWidget* HSLPicker::getViewer()const{return viewer;}

void HSLPicker::changeColor(){
    c->setHsl(getHvalue(),getSvalue(),getLvalue());
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    viewer->setPalette(p);
    emit colorChanged(c);
}
int HSLPicker::getHvalue()const{return slider->getH()->getSlider()->value();}
int HSLPicker::getSvalue()const{return slider->getS()->getSlider()->value();}
int HSLPicker::getLvalue()const{return slider->getL()->getSlider()->value();}
