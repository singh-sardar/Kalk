#ifndef RGBPICKER_H
#define RGBPICKER_H

#include <QWidget>
#include <QColor>
#include <QPalette>
#include <QHBoxLayout>

#include "rgbslider.h"


//rappresenta un rgb color picker con i slider
class RgbPicker:public QWidget
{
    Q_OBJECT
public:
    RgbPicker(QWidget* parent=0);
    RgbSlider* getRgbSlider()const;
    QWidget* getViewer()const;
    int getRvalue()const;
    int getGvalue()const;
    int getBvalue()const;

private:
    RgbSlider* slider;
    QWidget* viewer;
    QColor* c;
    QHBoxLayout* layout;
private slots:
    void changeColor();
signals:
    void colorChanged(QColor* c);

};

#endif // RGBPICKER_H
