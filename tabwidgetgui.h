#ifndef TABWIDGETGUI_H
#define TABWIDGETGUI_H

#include <QTabWidget>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "colorgui.h"
#include "ricettagui.h"
#include "matricigui.h"
#include "librettoesamigui.h"

class TabWidgetGUI: public QWidget{

    Q_OBJECT
private:
    QTabWidget* tabWidget;
    ColorGui* colGUI;
    RicettaGui* ricettaGUI;
    MatriciGUI* matriciGUI;
    LibrettoEsamiGUI* librettoGUI;

public:
    TabWidgetGUI(QWidget* parent = 0);
    void show();
    ~TabWidgetGUI();

private slots:
    void impostaMinSize();
    void updateSizes(int);
};

#endif // TABWIDGETGUI_H
