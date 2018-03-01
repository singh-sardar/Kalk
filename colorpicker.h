#ifndef COLORPICKER_H
#define COLORPICKER_H

#include "colorslider.h"

//rappresenta il singolo picker per i colori
class ColorPicker:public QWidget
{
    Q_OBJECT
public:
    ColorPicker(QWidget* parent=0, QString nomP1="Parametro 1", int minP1=0, int maxP1=255,QString nomP2="Parametro 2", int minP2=0, int maxP2=255, QString nomP3="Parametro 3", int minP3=0, int maxP3=255);
    ColorSlider* getColorSlider() const;
    QWidget* getViewer()const;
    int getP1value()const;
    QString getP1Name() const;
    int getP2value()const;
    QString getP2Name() const;
    int getP3value()const;
    QString getP3Name() const;
    virtual ~ColorPicker();

    void addSlider(SpinSlider*);


protected:
    ColorSlider* slider;
    QWidget* viewer;
    QColor* c;
    QHBoxLayout* layout;

private slots:
    virtual void changeColor() = 0;

signals:
    void colorChanged(QColor* c);

};

#endif // COLORPICKER_H
