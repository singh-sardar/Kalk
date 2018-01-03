#ifndef COLORCONTROLLER_H
#define COLORCONTROLLER_H


#include "colorergb.h"
#include "QObject"
#include "rgbcolorgui.h"

class RgbColorGui;
class ColorController:public QObject
{
    Q_OBJECT
public:
    ColorController(RgbColorGui*);
     ~ColorController();
private:
    RgbColorGui* view;
    ColoreRgb* model1,* model2,*result;
     void showMessageBox(QString,QString)const;
    void updateOneOperandResult(QString);


private slots:
    void SaveOperando1();
    void SaveOperando2();
    void SommaColori();
    void DifferenzaColori();
    void ModulazioneColori();
    void DeltaEColori();


    void ScalaColore();
    void ComplementareColore();
    void LuminositaColore();
    void CaldoColore();
    void LabColore();
    void HslColore();
    void HexColore();
    void Hsl2RgbColore();

    void ChangeResultColor();
    void ResultAsOperando();
};

#endif // COLORCONTROLLER_H
