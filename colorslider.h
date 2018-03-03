#ifndef COLORSLIDER_H
#define COLORSLIDER_H

#include <QWidget>
#include "spinslider.h"
#include <QVBoxLayout>
#include <QVector>

//rappresenta uno slider per colori
class ColorSlider:public QWidget
{
    Q_OBJECT
public:
    //ColorSlider(QWidget* parent  = 0, QString nomP1="Parametro 1", int minP1=0, int maxP1=255,QString nomP2="Parametro 2", int minP2=0, int maxP2=255, QString nomP3="Parametro 3", int minP3=0, int maxP3=255);
    ColorSlider(QWidget* parent  = 0);
    /*
    SpinSlider* getParametro1() const;
    QString getNomeParametro1() const;
    SpinSlider* getParametro2() const;
    QString getNomeParametro2() const;
    SpinSlider* getParametro3() const;
    QString getNomeParametro3() const;
    */

    ~ColorSlider();

    SpinSlider* getSlider(int i) const;
    QString getNome(int i)const;
    void addSpinSlider(SpinSlider*);
private:
    /*
    SpinSlider *P1;
    QString nomeP1;
    SpinSlider *P2;
    QString nomeP2;
    SpinSlider *P3;
    QString nomeP3;
    */

    QVector<SpinSlider*> *vector;

    QVBoxLayout* layout;

signals:
    /*
    void P1valueChanged(int newValue);
    void P2valueChanged(int newValue);
    void P3valueChanged(int newValue);
    */

    void colorSliderChanged();
};

#endif // COLORSLIDER_H
