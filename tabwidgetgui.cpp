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
        case 1:
            tabWidget->setMinimumSize(665,741);
            tabWidget->resize(720,711);
            break;
        case 2:
            tabWidget->setMinimumSize(694,365);
            tabWidget->resize(802,486);
            break;
        case 3:
            tabWidget->setMinimumSize(841,431);
            tabWidget->resize(1011,752);
            break;
        case 4:
            tabWidget->setMinimumSize(1095,595);
            tabWidget->resize(1095,816);
            break;
        default:
            tabWidget->setMinimumSize(900,700);
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
