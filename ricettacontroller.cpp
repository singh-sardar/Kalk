#include "ricettacontroller.h"
RicettaController::RicettaController(RicettaGui* v):view(v),model1(new Ricetta()),model2(new Ricetta()),result(new Ricetta())
{
    UpdateNomeRicetta1();
    UpdateNomeRicetta2();
    connect(view,SIGNAL(btnAddIngrediente1Clicked()),this,SLOT(AddIngredienteModel1()));
    connect(view,SIGNAL(btnAddIngrediente2Clicked()),this,SLOT(AddIngredienteModel2()));
    connect(view,SIGNAL(btnRemoveIngrediente1Clicked()),this,SLOT(RemoveIngredienteModel1()));
    connect(view,SIGNAL(btnRemoveIngrediente2Clicked()),this,SLOT(RemoveIngredienteModel2()));
    connect(view,SIGNAL(btnCosto1Clicked()),this,SLOT(CostoModel1()));
    connect(view,SIGNAL(btnCosto2Clicked()),this,SLOT(CostoModel2()));
    connect(view,SIGNAL(btnCalorie1Clicked()),this,SLOT(CalorieModel1()));
    connect(view,SIGNAL(btnCalorie2Clicked()),this,SLOT(CalorieModel2()));
    connect(view,SIGNAL(btnProporziona1Clicked()),this,SLOT(ProporzionaModel1()));
    connect(view,SIGNAL(btnProporziona2Clicked()),this,SLOT(ProporzionaModel2()));
    connect(view,SIGNAL(btnSommaClicked()),this,SLOT(Somma()));
    connect(view,SIGNAL(btnDifferenzaClicked()),this,SLOT(Differenza()));
    connect(view,SIGNAL(btnUseAsRicetta1Clicked()),this,SLOT(useAsModel1()));
    connect(view,SIGNAL(btnUseAsRicetta2Clicked()),this,SLOT(useAsModel2()));
    connect(view,SIGNAL(Ricetta1NameChanged()),this,SLOT(UpdateNomeRicetta1()));
    connect(view,SIGNAL(Ricetta2NameChanged()),this,SLOT(UpdateNomeRicetta2()));
}
RicettaController::~RicettaController(){
    if(result == model1 || result == model2){
        delete model1;
        delete model2;
    }else
    {
        delete model1;
        delete model2;
        delete result;
    }
}
void RicettaController::showMessageBox(QString title,QString text)const{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setFont(QFont("Verdana",14));

    msgBox.setText(text);
    msgBox.exec();
}
void RicettaController::UpdateRicettaView(Ricetta* r,QPlainTextEdit* p){
    p->setPlainText(r->getRicetta().c_str());
}
void RicettaController::UpdateNomeRicetta1(){
    model1->setNomeRicetta(view->getNomeRicetta1().toStdString());
    UpdateRicettaView(model1,view->getRicetta1Viewer());
}
void RicettaController::UpdateNomeRicetta2(){
    model2->setNomeRicetta(view->getNomeRicetta2().toStdString());
    UpdateRicettaView(model2,view->getRicetta2Viewer());
}
void RicettaController::AddIngredienteModel1(){
    if(view->getIngredienteDialog()->result() == QDialog::Accepted){
        ing  = new Ingrediente(view->getIngredienteDialog()->getNomeIngrediente()->displayText().toStdString(),view->getIngredienteDialog()->getQuantitaIngrediente()->value(),view->getIngredienteDialog()->getCalorieIngrediente()->value(),view->getIngredienteDialog()->getCostoIngrediente()->value());
        model1->aggiungiElemento(*ing);
        UpdateRicettaView(model1,view->getRicetta1Viewer());
    }
}
void RicettaController::AddIngredienteModel2(){
    if(view->getIngredienteDialog()->result() == QDialog::Accepted){
        ing  = new Ingrediente(view->getIngredienteDialog()->getNomeIngrediente()->displayText().toStdString(),view->getIngredienteDialog()->getQuantitaIngrediente()->value(),view->getIngredienteDialog()->getCalorieIngrediente()->value(),view->getIngredienteDialog()->getCostoIngrediente()->value());
        model2->aggiungiElemento(*ing);
        UpdateRicettaView(model2,view->getRicetta2Viewer());
    }
}

void RicettaController::RemoveIngredienteModel1(){
    if(view->getIngredienteDialog()->result() == QDialog::Accepted){
        ing  = new Ingrediente(view->getIngredienteDialog()->getNomeIngrediente()->displayText().toStdString(),view->getIngredienteDialog()->getQuantitaIngrediente()->value(),view->getIngredienteDialog()->getCalorieIngrediente()->value(),view->getIngredienteDialog()->getCostoIngrediente()->value());
        model1->rimuoviElemento(*ing);
        UpdateRicettaView(model1,view->getRicetta1Viewer());
        delete ing;
    }
}
void RicettaController::RemoveIngredienteModel2(){
    if(view->getIngredienteDialog()->result() == QDialog::Accepted){
        ing  = new Ingrediente(view->getIngredienteDialog()->getNomeIngrediente()->displayText().toStdString(),view->getIngredienteDialog()->getQuantitaIngrediente()->value(),view->getIngredienteDialog()->getCalorieIngrediente()->value(),view->getIngredienteDialog()->getCostoIngrediente()->value());
        model2->rimuoviElemento(*ing);
        UpdateRicettaView(model2,view->getRicetta2Viewer());
        delete ing;
    }
}
void RicettaController::CostoModel1(){
    QString s = "Il Costo totale della ricetta ";
    s+= model1->getNomeRicetta().c_str();
    s+=" è di ";
    s+=std::to_string(model1->costoRicetta()).c_str();
    s+= " euro";

    showMessageBox("Costo Ricetta",s);
}
void RicettaController::CostoModel2(){
    QString s = "Il Costo totale della ricetta ";
    s+= model2->getNomeRicetta().c_str();
    s+=" è di ";
    s+=std::to_string(model2->costoRicetta()).c_str();
    s+= " euro";

    showMessageBox("Costo Ricetta",s);
}
void RicettaController::CalorieModel1(){
    QString s = "Le Calorie contenute nella ricetta ";
    s+= model1->getNomeRicetta().c_str();
    s+=" sono ";
    s+=std::to_string(model1->calorieRicetta()).c_str();
    s+= " cal";

    showMessageBox("Costo Ricetta",s);
}
void RicettaController::CalorieModel2(){
    QString s = "Le Calorie contenute nella ricetta ";
    s+= model2->getNomeRicetta().c_str();
    s+=" sono ";
    s+=std::to_string(model2->calorieRicetta()).c_str();
    s+= " cal";

    showMessageBox("Costo Ricetta",s);
}
void RicettaController::ProporzionaModel1(){
    delete result;
    result=new Ricetta(*model1*view->getPropRicetta1Value());
    UpdateRicettaView(result,view->getResultViewer());

}
void RicettaController::ProporzionaModel2(){
    delete result;
    result=new Ricetta(*model2*view->getPropRicetta2Value());
    UpdateRicettaView(result,view->getResultViewer());
}
void RicettaController::Somma(){
    delete result;
    result=*model1+*model2;
    UpdateRicettaView(result,view->getResultViewer());

}
void RicettaController::Differenza(){
    delete result;
    result=*model1-*model2;
    UpdateRicettaView(result,view->getResultViewer());
}
void RicettaController::useAsModel1(){
    *model1=*result;
    view->getLineEdit1Nome()->setText(model1->getNomeRicetta().c_str());
    UpdateRicettaView(model1,view->getRicetta1Viewer());

}
void RicettaController::useAsModel2(){
    *model2=*result;
     view->getLineEdit2Nome()->setText(model2->getNomeRicetta().c_str());
    UpdateRicettaView(model2,view->getRicetta2Viewer());
}
