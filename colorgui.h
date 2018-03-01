#ifndef COLORGUI_H
#define COLORGUI_H

#include <QWidget>
#include <QGridLayout>
#include <QComboBox>
#include "twocolorpicker.h"
#include "coloroperationbuttons.h"
#include "colorcontroller.h"

class ColorController;
class ColorGui:public QWidget
{
    Q_OBJECT
public:
    ColorGui(QWidget* parent=0);
    int getColor1P1value()const;
    int getColor1P2value()const;
    int getColor1P3value()const;
    int getColor2P1value()const;
    int getColor2P2value()const;
    int getColor2P3value()const;
    QWidget* getResultViewer()const;
    QWidget* getOperand1Viewer()const;
    QWidget* getOperand2Viewer()const;
    QLabel* getResultLabel()const;
    double getHValue()const;
    double getSValue()const;
    double getLValue()const;

    int getRValue()const;
    int getGValue()const;
    int getBValue()const;
    TwoColorPicker* getColorPicker()const;
    colorOperationButtons* getOperationButtons()const;

    double getFattoreScalaValue()const;

    ~ColorGui();
private:
    QGridLayout* layout;
    TwoColorPicker* p;
    colorOperationButtons* op;
    QPushButton *saveOperando1, *saveOperando2,*useResultAsOperando;
    QWidget *operando1,*operando2 , *result;
    ColorController* controller;
    QLabel* resultLabel;
    QLabel* lbl;

    QComboBox* cb;


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

    void btnRgb2HslClicked(bool);
    void colorTypeChanged();

private slots:
    void changeColorType(int);

};

#endif // COLORGUI_H
