#include "spinslider.h"


SpinSlider::SpinSlider(QWidget* parent,QString desc,int min,int max ):QWidget(parent)
{
    QFont f("Verdana",16),f1("Verdana",14);
    f1.setBold(false);
    f.setBold(false);
    layout= new QHBoxLayout;
    desc_lable = new QLabel;
    desc_lable->setFont(f);
    desc_lable->setText(desc);
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(min,max);
    slider->setValue(min);
    spin_box = new QSpinBox();
    spin_box->setFont(f1);
    spin_box->setRange(min,max);
    spin_box->setValue(min);
    layout->addWidget(desc_lable);
    layout->addWidget(slider);
    layout->addWidget(spin_box);


    connect(slider,SIGNAL(valueChanged(int)),spin_box,SLOT(setValue(int)));
    connect(spin_box,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    connect(slider,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));

    setLayout(layout);

}


QLabel* SpinSlider::getLable() const{
    return desc_lable;
}
QSlider* SpinSlider::getSlider() const{
    return slider;
}
QSpinBox* SpinSlider::getSpinBox() const{
    return spin_box;
}
