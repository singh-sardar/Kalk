#ifndef RICETTAGUI_H
#define RICETTAGUI_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpinBox>
#include "ingredientedialog.h"
#include "ricettacontroller.h"
class RicettaController;
class RicettaGui:public QWidget
{
    Q_OBJECT
public:
    RicettaGui(QWidget* parent = 0);
    IngredienteDialog* getIngredienteDialog()const;
    QPlainTextEdit* getRicetta1Viewer()const;
    QPlainTextEdit* getRicetta2Viewer()const;
    QPlainTextEdit* getResultViewer()const;
    QString getNomeRicetta1()const;
    QString getNomeRicetta2()const;
    int getPropRicetta1Value()const;
    int getPropRicetta2Value()const;
    QLineEdit *getLineEdit1Nome()const;
    QLineEdit *getLineEdit2Nome()const;
    ~RicettaGui();
private:

    QPlainTextEdit* ricetta1;
    QPlainTextEdit* ricetta2;
    QPlainTextEdit* ricettaResult;
    QLineEdit *ricetta1Nome;
    QLineEdit *ricetta2Nome;
    QPushButton* addIngrediente1;
    QPushButton* addIngrediente2;
    QPushButton* removeIngrediente1;
    QPushButton* removeIngrediente2;
    QPushButton* calorie1;
    QPushButton* calorie2;
    QPushButton* costo1;
    QPushButton* costo2;
    QPushButton* sommaRicette;
    QPushButton* differenzaRicette;
    QPushButton* proporziona1;
    QPushButton* proporziona2;
    QGridLayout* layout;
    QPushButton* useResultAsRicetta1;
    QPushButton* useResultAsRicetta2;
    QHBoxLayout* l1;
    QSpinBox* prop1;
    QSpinBox* prop2;
    IngredienteDialog* ingDialog;
    RicettaController* Controller;

signals:
    void btnAddIngrediente1Clicked();
    void btnAddIngrediente2Clicked();
    void btnRemoveIngrediente1Clicked();
    void btnRemoveIngrediente2Clicked();
    void btnCosto1Clicked();
    void btnCosto2Clicked();
    void btnCalorie1Clicked();
    void btnCalorie2Clicked();
    void btnProporziona1Clicked();
    void btnProporziona2Clicked();
    void btnSommaClicked();
    void btnDifferenzaClicked();
    void btnUseAsRicetta1Clicked();
    void btnUseAsRicetta2Clicked();
    void Ricetta1NameChanged();
    void Ricetta2NameChanged();

private slots:
    void showDialogIngrediente();


};

#endif // RICETTAGUI_H
