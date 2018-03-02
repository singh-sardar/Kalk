#ifndef COLORPICKER_H
#define COLORPICKER_H

#include "colorslider.h"


//rappresenta il singolo picker per i colori
class ColorPicker:public QWidget
{
    Q_OBJECT
public:
    ColorPicker(QWidget* parent=0);
    ColorSlider* getColorSlider() const;
    QWidget* getViewer()const;

    int getSliderValue(int i)const;
    QString getSliderName(int i)const;

    /*
    int getP1value()const;
    QString getP1Name() const;
    int getP2value()const;
    QString getP2Name() const;
    int getP3value()const;
    QString getP3Name() const;
    */

    virtual ~ColorPicker();




protected:
    ColorSlider* slider;
    QWidget* viewer;
    QColor* c;
    QHBoxLayout* layout;

    void addSlider(SpinSlider*);

private slots:
    virtual void changeColor() = 0;

signals:
    void colorChanged(QColor* c);

};

#endif // COLORPICKER_H
