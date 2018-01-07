#include "tabwidgetgui.h"

TabWidgetGUI::TabWidgetGUI(QWidget *parent):
    QWidget(parent)
{
    tabWidget = new QTabWidget;
    rgbGUI = new RgbColorGui;
    ricettaGUI = new RicettaGui;
    matriciGUI = new MatriciGUI;
    librettoGUI = new LibrettoEsamiGUI;

    //tabWidget->setTabPosition(QTabWidget::West);
    tabWidget->tabBar()->setFont(QFont("Verdana",16));
    tabWidget->addTab(rgbGUI,"Colori RGB");
    tabWidget->addTab(ricettaGUI,"Ricette");
    tabWidget->addTab(matriciGUI,"Matrici");
    tabWidget->addTab(librettoGUI,"Libretto esami");
    tabWidget->setMinimumSize(900,700);
    tabWidget->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
}

void TabWidgetGUI::show(){
    tabWidget->show();
}

TabWidgetGUI::~TabWidgetGUI(){
    delete rgbGUI;
    delete ricettaGUI;
    delete matriciGUI;
    delete librettoGUI;
    delete tabWidget;
}
