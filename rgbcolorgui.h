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
    int getColor1Rvalue()const;
    int getColor1Gvalue()const;
    int getColor1Bvalue()const;
    int getColor2Rvalue()const;
    int getColor2Gvalue()const;
    int getColor2Bvalue()const;
    QWidget* getResultViewer()const;
    QWidget* getOperand1Viewer()const;
    QWidget* getOperand2Viewer()const;
    QLabel* getResultLabel()const;
    double getHValue()const;
    double getSValue()const;
    double getLValue()const;
    double getFattoreScalaValue()const;

    ~RgbColorGui();
private:
    QGridLayout* layout;
    TwoRgbPicker* p;
    colorOperationButtons* op;
    QPushButton *saveOperando1, *saveOperando2,*useResultAsOperando;
    QWidget *operando1,*operando2 , *result;
    ColorController* controller;
    QLabel* resultLabel;
    QLabel* lbl;


signals:
    void btnSommaClicked(bool);
    void btnDifferenzaClicked(bool);
    void btnModulazioneClicked(bool);
    void btnDeltaEClicked(bool);
    void btnScalaClicked(bool);
    void btnComplementareClicked(bool);
    void btnLuminositaClicked(bool);
    void btnCaldoClicked(bool);
    void btnLabClicked(bool);
    void btnHslClicked(bool);
    void btnHexClicked(bool);
    void btnHsl2RgbClicked(bool);
    void btnSaveOperando1Clicked(bool);
    void btnSaveOperando2Clicked(bool);
    void btnUseResultAsOperandoClicked(bool);

};

#endif // RGBCOLORGUI_H
