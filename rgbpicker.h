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


    void changeColor();
};

#endif // RGBPICKER_H
