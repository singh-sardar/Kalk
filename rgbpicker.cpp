#include "rgbpicker.h"
#include <QDebug>
RgbPicker::RgbPicker(QWidget* parent):QWidget(parent)
{
    layout = new QHBoxLayout;
    slider = new RgbSlider;
    viewer = new QWidget;
    viewer->setMinimumSize(100,100);
    viewer->setAutoFillBackground(true);
    c= new  QColor;
    layout->addWidget(slider);
    layout->addWidget(viewer);



    connect(slider,SIGNAL(RvalueChanged(int)),this,SLOT(changeColor()));
    connect(slider,SIGNAL(GvalueChanged(int)),this,SLOT(changeColor()));
    connect(slider,SIGNAL(BvalueChanged(int)),this,SLOT(changeColor()));
    changeColor();

    setLayout(layout);

}

RgbSlider* RgbPicker::getRgbSlider()const{return slider;}
QWidget* RgbPicker::getViewer()const{return viewer;}

void RgbPicker::changeColor(){
    c->setRgb(slider->getR()->getSlider()->value(),slider->getG()->getSlider()->value(),slider->getB()->getSlider()->value());
    QPalette p= viewer->palette();
    p.setColor(QPalette::Window,*c);
    viewer->setPalette(p);
    emit colorChanged(c);
}
