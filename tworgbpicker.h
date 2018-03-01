#ifndef TWORGBPICKER_H
#define TWORGBPICKER_H

#include <QWidget>
#include "rgbpicker.h"
#include <QGridLayout>
#include <QLabel>

/*
class TwoRgbPicker:public QWidget
{
    //color picker per 2 colori
    Q_OBJECT
public:
    TwoRgbPicker(QWidget* parent=0);
    RgbPicker* getColor1()const;
    RgbPicker* getColor2()const;
    QLabel* getLabel1()const;
    QLabel* getLabel2()const;
    ~TwoRgbPicker();

private:
    RgbPicker *color1,*color2;
    QLabel* label1,*label2;
    QGridLayout* grid;
signals:
    void color1Changed(QColor* c);
    void color2Changed(QColor* c);
};
*/

#endif // TWORGBPICKER_H
