#include "twocolorpicker.h"

TwoColorPicker::TwoColorPicker(QWidget* parent):QWidget(parent)
{
    QFont f("Verdana",16);
    label1 = new QLabel("Colore 1");
    label2 = new QLabel("Colore 2");
    label1->setFont(f);
    label2->setFont(f);

    color1 = new RgbPicker;
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
TwoColorPicker::~TwoColorPicker(){
    delete color1;
    delete color2;
    delete label1;
    delete label2;
    delete grid;
}
void TwoColorPicker::changeColorType(ColorPicker* c){
    delete color1;
    delete color2;


    if(typeid(*c) == typeid(RgbPicker)){
        color1 = new RgbPicker;
        color2 = new RgbPicker;
    }else if(typeid(*c) == typeid(HslPicker)){
        color1 = new HslPicker;
        color2 = new HslPicker;
    }else if(typeid(*c) == typeid(RgbaPicker)){
        color1= new RgbaPicker;
        color2 = new RgbaPicker;
    }

    delete c;

    if(color1 && color2){
        grid->removeItem(grid->itemAtPosition(1,0));
        grid->addWidget(color1,1,0);

        grid->removeItem(grid->itemAtPosition(1,1));
        grid->addWidget(color2,1,1);
    }
}
ColorPicker* TwoColorPicker::getColor1()const{return color1;}
ColorPicker* TwoColorPicker::getColor2()const{return color2;}
QLabel* TwoColorPicker::getLabel1()const{return label1;}
QLabel* TwoColorPicker::getLabel2()const{return label2;}
