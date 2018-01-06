#ifndef ESAMEDIALOG_H
#define ESAMEDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>

class EsameDialog: public QDialog{
    Q_OBJECT

public:
    EsameDialog(QWidget* parent=0);
    QSpinBox* getSpinBoxGiorno() const;
    QSpinBox* getSpinBoxMese() const;
    QSpinBox* getSpinBoxAnno() const;
    QSpinBox* getSpinBoxVoto() const;
    QSpinBox* getSpinBoxCFU() const;
    QLineEdit* getLineEditMateria() const;
    QLineEdit* getLineEditCorso() const;
    QLineEdit* getLineEditProfessore() const;

private:
    QLineEdit* lineEditNomeMateria;
    QLineEdit* lineEditNomeCorso;
    QLineEdit* lineEditNomeProfessore;

    QSpinBox* spinGiorno;
    QSpinBox* spinMese;
    QSpinBox* spinAnno;
    QSpinBox* spinVoto;
    QSpinBox* spinCFU;

    QGridLayout* layout;
    QPushButton* ok;
    QPushButton* cancel;

    QLabel* lblNomeMateria;
    QLabel* lblNomeCorso;
    QLabel* lblNomeProfessore;
    QLabel* lblGiorno;
    QLabel* lblMese;
    QLabel* lblAnno;
    QLabel* lblVoto;
    QLabel* lblCFU;

private slots:
    void btnOK();
    void btnCancel();
};

#endif // ESAMEDIALOG_H
