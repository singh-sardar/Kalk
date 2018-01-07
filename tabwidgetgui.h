#ifndef TABWIDGETGUI_H
#define TABWIDGETGUI_H

#include <QTabWidget>
#include "tworgbpicker.h"
#include "coloroperationbuttons.h"
#include "rgbcolorgui.h"
#include "ricettagui.h"
#include "matricigui.h"
#include "librettoesamigui.h"

class TabWidgetGUI: QWidget{

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

};

#endif // TABWIDGETGUI_H
