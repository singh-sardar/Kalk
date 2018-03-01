#ifndef TWOCOLORPICKER_H
#define TWOCOLORPICKER_H

#include <QWidget>
#include "colorpicker.h"
#include "rgbpicker.h"
#include "hslpicker.h"
#include "rgbapicker.h"
#include <QGridLayout>
#include <QLabel>

#include <typeinfo>

class TwoColorPicker:public QWidget
{
    //color picker per 2 colori
    Q_OBJECT
public:
    TwoColorPicker(QWidget* parent=0);
    ColorPicker* getColor1()const;
    ColorPicker* getColor2()const;
    QLabel* getLabel1()const;
    QLabel* getLabel2()const;
    void changeColorType(ColorPicker*);
    ~TwoColorPicker();

private:
    ColorPicker *color1,*color2;
    QLabel* label1,*label2;
    QGridLayout* grid;
signals:
    void color1Changed(QColor* c);
    void color2Changed(QColor* c);
};

#endif // TWOCOLORPICKER_H
