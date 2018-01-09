#include "tabwidgetgui.h"

TabWidgetGUI::TabWidgetGUI(QWidget *parent):
    QWidget(parent)
{
    tabWidget = new QTabWidget;
    rgbGUI = new RgbColorGui;
    ricettaGUI = new RicettaGui;
    matriciGUI = new MatriciGUI;
    librettoGUI = new LibrettoEsamiGUI;

    tabWidget->setStyleSheet("QTabBar::tab{height:40px; width:150px;font: 14pt}");
    tabWidget->addTab(rgbGUI,"Colori RGB");
    tabWidget->addTab(ricettaGUI,"Ricette");
    tabWidget->addTab(matriciGUI,"Matrici");
    tabWidget->addTab(librettoGUI,"Libretto esami");

    connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(impostaMinSize()));

    impostaMinSize();
}

void TabWidgetGUI::show(){
    tabWidget->show();
}

void TabWidgetGUI::impostaMinSize(){
    switch (tabWidget->currentIndex()) {
        case 0:
            tabWidget->setMinimumSize(665,715);
            tabWidget->resize(760,720);
            break;
        case 1:
            tabWidget->setMinimumSize(694,400);
            tabWidget->resize(770,500);
            break;
        case 2:
            tabWidget->setMinimumSize(841,431);
            tabWidget->resize(1011,652);
            break;
        case 3:
            tabWidget->setMinimumSize(1095,595);
            tabWidget->resize(1095,616);
            break;

    }
}

TabWidgetGUI::~TabWidgetGUI(){
    delete rgbGUI;
    delete ricettaGUI;
    delete matriciGUI;
    delete librettoGUI;
    delete tabWidget;
}
