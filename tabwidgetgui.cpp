#include "tabwidgetgui.h"

TabWidgetGUI::TabWidgetGUI(QWidget *parent):
    QWidget(parent)
{
    tabWidget = new QTabWidget;
    //rgbGUI = new RgbColorGui;
    colGUI = new ColorGui;
    ricettaGUI = new RicettaGui;
    matriciGUI = new MatriciGUI;
    librettoGUI = new LibrettoEsamiGUI;

    tabWidget->setStyleSheet("QTabBar::tab{height:40px; width:150px;font: 14pt}");
    //tabWidget->addTab(rgbGUI,"Colori RGB");
    tabWidget->addTab(colGUI, "Colori");
    tabWidget->addTab(ricettaGUI,"Ricette");
    tabWidget->addTab(matriciGUI,"Matrici");
    tabWidget->addTab(librettoGUI,"Libretto esami");

    connect(tabWidget,SIGNAL(currentChanged(int)),this, SLOT(updateSizes(int)));    
    connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(impostaMinSize()));

    impostaMinSize();
}

void TabWidgetGUI::show(){
    tabWidget->show();
}

void TabWidgetGUI::impostaMinSize(){
    if(!(tabWidget->windowState() == Qt::WindowMaximized)){
        switch (tabWidget->currentIndex()) {
            case 0:
                tabWidget->setMinimumSize(665,800);
                tabWidget->resize(760,820);
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
                tabWidget->setMinimumSize(900,595);
                tabWidget->resize(1095,716);
                break;

        }
    }
}

void TabWidgetGUI::updateSizes(int index){
    if(index >= 0){
        for(int i=0;i<tabWidget->count();i++)
        if(i!=index)
            tabWidget->widget(i)->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

        tabWidget->widget(index)->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        tabWidget->widget(index)->resize(tabWidget->widget(index)->minimumSizeHint());
        tabWidget->widget(index)->adjustSize();
        resize(minimumSizeHint());
        adjustSize();
    }
}

TabWidgetGUI::~TabWidgetGUI(){
    //delete rgbGUI;
    delete ricettaGUI;
    delete matriciGUI;
    delete librettoGUI;
    delete tabWidget;
}
