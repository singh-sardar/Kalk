#ifndef RGBCOLORGUI_H
#define RGBCOLORGUI_H


#include <QWidget>
#include <QGridLayout>
#include "tworgbpicker.h"
#include "coloroperationbuttons.h"
class RgbColorGui:public QWidget
{
public:
    RgbColorGui(QWidget* parent=0);

private:
    QGridLayout* layout;
    TwoRgbPicker* p;
    colorOperationButtons* op;
    QPushButton *saveOperando1, *saveOperando2;
    QWidget *operando1,*operando2 , *result;


};

#endif // RGBCOLORGUI_H
