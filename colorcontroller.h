#ifndef COLORCONTROLLER_H
#define COLORCONTROLLER_H


#include "colorergb.h"
#include "colore.h"
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
    Colore* model;

private slots:
    void SommaColori();
};

#endif // COLORCONTROLLER_H
