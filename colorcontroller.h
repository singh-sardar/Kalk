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
private:
    RgbColorGui* view;
    ColoreRgb* model1,* model2,*result;

private slots:
    void SaveOperando1();
    void SaveOperando2();
    void SommaColori();
    void DifferenzaColori();
    void ModulazioneColori();
    void DeltaEColori();

    void ChangeResultColor();
};

#endif // COLORCONTROLLER_H
