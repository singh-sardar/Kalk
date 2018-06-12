#ifndef COLORCONTROLLER_H
#define COLORCONTROLLER_H

#include "colorergb.h"
#include "colorehsl.h"
#include "colorergba.h"
#include "QObject"
#include "colorgui.h"

class ColorGui;
class ColorController:public QObject
{
    Q_OBJECT
public:
    ColorController(ColorGui*);
     ~ColorController();
private:
    ColorGui* view;
    Colore* model1, *model2, *result;
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

    void Rgb2HslColore();

    void ChangeResultColor();
    void ResultAsOperando();
    void ChangeColorType();
};

#endif // COLORCONTROLLER_H
