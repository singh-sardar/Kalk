#ifndef HSLPICKER_H
#define HSLPICKER_H

#include <QWidget>
#include <QColor>
#include <QPalette>
#include <QHBoxLayout>

#include "hslslider.h"

//rappresenta il singolo picker per i colori in formato HSL
class HSLPicker:public QWidget
{
    Q_OBJECT
public:
    HSLPicker(QWidget* parent=0);
    HSLSlider* getHSLSlider() const;
    QWidget* getViewer()const;
    int getHvalue()const;
    int getSvalue()const;
    int getLvalue()const;
    ~HSLPicker();

private:
    HSLSlider* slider;
    QWidget* viewer;
    QColor* c;
    QHBoxLayout* layout;
private slots:
    void changeColor();
signals:
    void colorChanged(QColor* c);

};

#endif // HSLPICKER_H
