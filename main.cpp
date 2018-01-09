#include "kalk.h"
#include <QApplication>

//include classi logica calcolatrice
#include "vettoregenerico.h"
#include "colore.h"
#include "colorergb.h"
#include "librettoesami.h"
#include "ingrediente.h"
#include "ricetta.h"
//#include "matricealgebrica.h"
#include "matrice.h"



//include for  gui
#include "tworgbpicker.h"
#include "coloroperationbuttons.h"
#include "rgbcolorgui.h"
#include "ricettagui.h"
#include "matricigui.h"
#include "librettoesamigui.h"
#include "tabwidgetgui.h"

//include qt
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QPalette>
#include <string>
#include <qtabwidget.h>

using std::string;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabWidgetGUI widgetGUI;
    widgetGUI.show();
    return a.exec();
}

