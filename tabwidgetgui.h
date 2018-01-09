#ifndef TABWIDGETGUI_H
#define TABWIDGETGUI_H

#include <QTabWidget>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "tworgbpicker.h"
#include "coloroperationbuttons.h"
#include "rgbcolorgui.h"
#include "ricettagui.h"
#include "matricigui.h"
#include "librettoesamigui.h"

class TabWidgetGUI: public QWidget{

    Q_OBJECT
private:
    QTabWidget* tabWidget;
    RgbColorGui* rgbGUI;
    RicettaGui* ricettaGUI;
    MatriciGUI* matriciGUI;
    LibrettoEsamiGUI* librettoGUI;

public:
    TabWidgetGUI(QWidget* parent = 0);
    void show();
    ~TabWidgetGUI();

private slots:
    void impostaMinSize();

};

#endif // TABWIDGETGUI_H
