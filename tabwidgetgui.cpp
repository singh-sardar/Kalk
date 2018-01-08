#include "tabwidgetgui.h"

TabWidgetGUI::TabWidgetGUI(QWidget *parent):
    QWidget(parent)
{
    tabWidget = new QTabWidget;
    rgbGUI = new RgbColorGui;
    ricettaGUI = new RicettaGui;
    matriciGUI = new MatriciGUI;
    librettoGUI = new LibrettoEsamiGUI;

    /*
    btnRGBGUI = new QPushButton("Colori RGB");
    btnRGBGUI->setFixedSize(50,25);
    btnRicetteGUI = new QPushButton("Ricette");
    btnMatriciGUI = new QPushButton("Matrici");
    btnLibrettoEsamiGUI = new QPushButton("Libretto esami");

    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(btnRGBGUI,0,0);
    gridLayout->addWidget(btnRicetteGUI,1,0);
    gridLayout->addWidget(btnMatriciGUI,2,0);
    gridLayout->addWidget(btnLibrettoEsamiGUI,3,0);
    gridLayout->addWidget(rgbGUI,0,1,4,2,Qt::AlignCenter);

    setLayout(gridLayout);
*/

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
        break;
    case 2:
        tabWidget->setMinimumSize(694,365);
        break;
    case 3:
        tabWidget->setMinimumSize(841,431);
        break;
    case 4:
        tabWidget->setMinimumSize(1095,595);
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
