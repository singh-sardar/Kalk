#ifndef RGBSLIDER_H
#define RGBSLIDER_H

#include <QWidget>
#include "spinslider.h"
#include <QVBoxLayout>


//rappresenta uno slider rgb
class RgbSlider:public QWidget
{
    Q_OBJECT
public:
    RgbSlider(QWidget* parent  = 0);
    SpinSlider* getR()const;
    SpinSlider* getG()const;
    SpinSlider* getB()const;
    ~RgbSlider();
private:
    SpinSlider *R,*G,*B;
    QVBoxLayout* layout;

signals:
    void RvalueChanged(int newValue);
    void GvalueChanged(int newValue);
    void BvalueChanged(int newValue);

};

#endif // RGBSLIDER_H
