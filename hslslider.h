#ifndef HSLSLIDER_H
#define HSLSLIDER_H

#include <QWidget>
#include "spinslider.h"
#include <QVBoxLayout>

//rappresenta uno slider per colori in formato HSL
class HSLSlider:public QWidget
{
    Q_OBJECT
public:
    HSLSlider(QWidget* parent  = 0);
    SpinSlider* getH() const;
    SpinSlider* getS() const;
    SpinSlider* getL() const;
    ~HSLSlider();
private:
    SpinSlider *H;  //Hue
    SpinSlider *S;  //Saturation
    SpinSlider *L;  //Lightness
    QVBoxLayout* layout;

signals:
    void HvalueChanged(int newValue);
    void SvalueChanged(int newValue);
    void LvalueChanged(int newValue);

};

#endif // HSLSLIDER_H
