#ifndef HSLPICKER_H
#define HSLPICKER_H

#include <QWidget>
#include <QColor>
#include <QPalette>
#include <QHBoxLayout>

#include "colorpicker.h"

class HslPicker: public ColorPicker{

    Q_OBJECT
public:
    HslPicker(QWidget* parent=0);


    void changeColor();
};

#endif // HSLPICKER_H
