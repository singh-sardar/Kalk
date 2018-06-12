#include "colorpicker.h"
#include <QDebug>
ColorPicker::ColorPicker(QWidget* parent):QWidget(parent)
{

    layoutH = new QHBoxLayout;
    layoutV = new QVBoxLayout;
    vector = new QVector<SpinSlider*>;
    viewer = new QWidget;
    viewer->setMinimumSize(100,100);
    viewer->setAutoFillBackground(true);
    c= new  QColor;

    layoutH->addLayout(layoutV);
    layoutH->addWidget(viewer);

    setLayout(layoutH);

}

ColorPicker::~ColorPicker(){
    delete viewer;
    delete c;

    delete layoutV;
    delete layoutH;
    delete vector;
}

QWidget* ColorPicker::getViewer()const{return viewer;}

int ColorPicker::getSliderValue(int i)const{
    return vector->at(i)->getSlider()->value();
}

QString ColorPicker::getSliderName(int i) const{
    return vector->at(i)->getLable()->text();
}

void ColorPicker::addSlider(SpinSlider* s){
    vector->append(s);

    connect(s,SIGNAL(valueChanged(int)),this,SLOT(changeColor()));

    layoutV->addWidget(s);
}
