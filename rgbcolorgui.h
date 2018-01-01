#ifndef RGBCOLORGUI_H
#define RGBCOLORGUI_H


#include <QWidget>
#include <QGridLayout>
#include "tworgbpicker.h"
#include "coloroperationbuttons.h"
#include "colorcontroller.h"

class ColorController;
class RgbColorGui:public QWidget
{
    Q_OBJECT
public:
    RgbColorGui(QWidget* parent=0);

private:
    QGridLayout* layout;
    TwoRgbPicker* p;
    colorOperationButtons* op;
    QPushButton *saveOperando1, *saveOperando2;
    QWidget *operando1,*operando2 , *result;
    ColorController* controller;

signals:
    void btnSommaClicked(bool);
    /*void btnDifferenzaClicked(bool);
    void btnModulazioneClicked(bool);
    void btnDeltaEClicked(bool);
    void btnScalaClicked(bool);
    void btnComplementareClicked(bool);
    void btnLuminositaClicked(bool);
    void btnCaldoClicked(bool);
    void btnLabClicked(bool);
    void btnHslClicked(bool);
    void btnHexClicked(bool);
    void btnHsl2RgbClicked(bool);*/
};

#endif // RGBCOLORGUI_H
