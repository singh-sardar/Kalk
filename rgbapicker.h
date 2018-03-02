#ifndef RGBAPICKER_H
#define RGBAPICKER_H

#include <QWidget>
#include <QColor>
#include <QPalette>
#include <QHBoxLayout>

#include "colorpicker.h"
#include "rgbpicker.h"

class RgbaPicker: public RgbPicker{

    Q_OBJECT
public:
    RgbaPicker(QWidget* parent=0);
    //int getAlphaValue()const;

    void changeColor();

private:
    //SpinSlider *alpha;
};

#endif // RGBAPICKER_H
