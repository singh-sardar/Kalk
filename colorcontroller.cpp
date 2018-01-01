#include "colorcontroller.h"
#include <QMessageBox>
ColorController::ColorController(RgbColorGui* v):view(v),model(new ColoreRgb())
{
    QObject::connect(view,SIGNAL(btnSommaClicked(bool)),this,SLOT(SommaColori()));
}
void ColorController::SommaColori(){
    QMessageBox msgBox;
    msgBox.setText("Me got Clicked");
    msgBox.exec();
}
