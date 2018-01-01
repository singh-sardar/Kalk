#include "colorcontroller.h"
#include <QMessageBox>
ColorController::ColorController(RgbColorGui* v):view(v),model1(new ColoreRgb()),model2(new ColoreRgb()),result(new ColoreRgb())
{
    connect(view,SIGNAL(btnSaveOperando1Clicked(bool)),this,SLOT(SaveOperando1()));
    connect(view,SIGNAL(btnSaveOperando2Clicked(bool)),this,SLOT(SaveOperando2()));
    connect(view,SIGNAL(btnSommaClicked(bool)),this,SLOT(SommaColori()));
    connect(view,SIGNAL(btnSommaClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnDifferenzaClicked(bool)),this,SLOT(DifferenzaColori()));
    connect(view,SIGNAL(btnDifferenzaClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnModulazioneClicked(bool)),this,SLOT(ModulazioneColori()));
    connect(view,SIGNAL(btnModulazioneClicked(bool)),this,SLOT(ChangeResultColor()));
    connect(view,SIGNAL(btnDeltaEClicked(bool)),this,SLOT(DeltaEColori()));
    connect(view,SIGNAL(btnDeltaEClicked(bool)),this,SLOT(ChangeResultColor()));

}
void ColorController::SommaColori(){
    result =  *model1+ *model2;
}


void ColorController::SaveOperando1(){
    model1->setR(view->getColor1Rvalue());
    model1->setG(view->getColor1Gvalue());
    model1->setB(view->getColor1Bvalue());


    QColor* c = new QColor;
    QPalette p= view->getOperand1Viewer()->palette();

    c->setRgb(model1->getR(),model1->getG(),model1->getB());
    p.setColor(QPalette::Window,*c);
    view->getOperand1Viewer()->setPalette(p);
}

void ColorController::SaveOperando2(){

    model2->setR(view->getColor2Rvalue());
    model2->setG(view->getColor2Gvalue());
    model2->setB(view->getColor2Bvalue());


    QColor* c = new QColor;
    QPalette p= view->getOperand2Viewer()->palette();

    c->setRgb(model2->getR(),model2->getG(),model2->getB());
    p.setColor(QPalette::Window,*c);
    view->getOperand2Viewer()->setPalette(p);
}
void ColorController::DifferenzaColori(){
    result = *model1 - *model2;
}
void ColorController::ModulazioneColori(){
    result = *model1 * *model2;
}
void ColorController::DeltaEColori(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("DELTA E Cie76 ");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setFont(QFont("Verdana",14));
    QString s= "I due colori differisco di ";
    s+=to_string(model1->DeltaE(*model2)).c_str();
            s+=" %";
    msgBox.setText(s);
    msgBox.exec();
}





void ColorController::ChangeResultColor(){
    QColor* c = new QColor;
    QPalette p= view->getResultViewer()->palette();

    c->setRgb(result->getR(),result->getG(),result->getB());
    p.setColor(QPalette::Window,*c);
    view->getResultViewer()->setPalette(p);
}
