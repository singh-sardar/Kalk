#ifndef RGBPICKER_H
#define RGBPICKER_H

#include <QWidget>
#include <QColor>
#include <QPalette>
#include <QHBoxLayout>

#include "colorpicker.h"

class RgbPicker: public ColorPicker{
    Q_OBJECT

public:
    RgbPicker(QWidget* parent=0);
    SpinSlider* getRSlider()const;
    SpinSlider* getGSlider()const;
    SpinSlider* getBSlider()const;

    void changeColor();
};

#endif // RGBPICKER_H
