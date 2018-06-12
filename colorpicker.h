#ifndef COLORPICKER_H
#define COLORPICKER_H

#include "spinslider.h"


//rappresenta il singolo picker per i colori
class ColorPicker:public QWidget
{
    Q_OBJECT
public:
    ColorPicker(QWidget* parent=0);
    QWidget* getViewer()const;

    int getSliderValue(int i)const;
    QString getSliderName(int i)const;
    SpinSlider* getSlider(int i)const;

    virtual ~ColorPicker();




protected:
    QWidget* viewer;
    QColor* c;

    QVBoxLayout* layoutV;
    QHBoxLayout* layoutH;
    QVector<SpinSlider*> *vector;

    void addSlider(SpinSlider*);

private slots:
    virtual void changeColor() = 0;

signals:
    void colorChanged(QColor* c);

};

#endif // COLORPICKER_H
