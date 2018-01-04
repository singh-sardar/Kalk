#ifndef MATRICIGUI_H
#define MATRICIGUI_H

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QPushButton>
#include "tableviewmatrice.h"
#include "elementisingolamatrice.h"
#include "matricicontroller.h"

class MatriciController;
class MatriciGUI: public QWidget
{
    Q_OBJECT

public:
    MatriciGUI(QWidget *parent=0);
    QTableWidget *getTableWidget1() const;
    QTableWidget *getTableWidget2() const;
    QTableWidget *getTableWidgetRisultato() const;
    QLabel* getLabelRisultato() const;
    QLineEdit* getLineEditMatrice1() const;
    QLineEdit* getLineEditMatrice2() const;

private:
    TableViewMatrice* tableWidget1, *tableWidget2;
    QTableWidget *tableWidgetRisultato;
    ElementiSingolaMatrice *controlliWidget1, *controlliWidget2;
    QPushButton *btnSomma, *btnDifferenza, *btnMoltiplicazione;
    QGridLayout *gridLayout;
    MatriciController* controllerMatrici;
    QVBoxLayout *verticalLayout, *verticalLayoutMatriceRisultato;
    QLabel* labelRisultato, *labelMatriceRisultato;

signals:
    void btnSommaClicked(bool);
    void btnDifferenzaClicked(bool);
    void btnMoltiplicazioneClicked(bool);

    void btnMatriceCofattoriClicked1(bool);
    void btnMatriceInversaClicked1(bool);
    void btnMatriceTraspostaClicked1(bool);
    void btnDeterminanteClicked1(bool);
    void btnElevaAPotenzaClicked1(bool);
    void btnDivisioneScalareClicked1(bool);
    void btnIsSimmetricaClicked1(bool);
    void btnIsDiagonaleClicked1(bool);
    void btnIsScalareClicked1(bool);
    void btnMoltiplicazioneScalareClicked1(bool);

    void btnMatriceCofattoriClicked2(bool);
    void btnMatriceInversaClicked2(bool);
    void btnMatriceTraspostaClicked2(bool);
    void btnDeterminanteClicked2(bool);
    void btnElevaAPotenzaClicked2(bool);
    void btnDivisioneScalareClicked2(bool);
    void btnIsSimmetricaClicked2(bool);
    void btnIsDiagonaleClicked2(bool);
    void btnIsScalareClicked2(bool);
    void btnMoltiplicazioneScalareClicked2(bool);
};

#endif // MATRICIGUI_H
