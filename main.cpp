#include <QApplication>

#include "tabwidgetgui.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabWidgetGUI widgetGUI;
    widgetGUI.show();
    return a.exec();
}

