#include "tworgbpicker.h"

TwoRgbPicker::TwoRgbPicker(QWidget* parent):QWidget(parent)
{
    QFont f("Verdana",16);
    label1 = new QLabel("Colore 1");
    label2 = new QLabel("Colore 2");
    label1->setFont(f);
    label2->setFont(f);

    color1= new RgbPicker;
    color2 = new RgbPicker;

    grid= new QGridLayout;
    grid->addWidget(label1,0,0,Qt::AlignHCenter);
    grid->addWidget(label2,0,1,Qt::AlignHCenter);
    grid->addWidget(color1,1,0);
    grid->addWidget(color2,1,1);

    connect(color1,SIGNAL(colorChanged(QColor*)),this,SIGNAL(color1Changed(QColor*)));
    connect(color2,SIGNAL(colorChanged(QColor*)),this,SIGNAL(color2Changed(QColor*)));

    setLayout(grid);

}

RgbPicker* TwoRgbPicker::getColor1()const{return color1;}
RgbPicker* TwoRgbPicker::getColor2()const{return color2;}
QLabel* TwoRgbPicker::getLabel1()const{return label1;}
QLabel* TwoRgbPicker::getLabel2()const{return label2;}
