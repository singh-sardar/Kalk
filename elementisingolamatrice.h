#ifndef BUTTONSINGOLAMATRICE_H
#define BUTTONSINGOLAMATRICE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>

class ElementiSingolaMatrice: public QWidget{

    Q_OBJECT
public:
    ElementiSingolaMatrice(QWidget *parent=0);
    QLabel* getLabelInputNumerici() const;
    QLineEdit* getLineEditNumerici() const;
    ~ElementiSingolaMatrice();

private:
    QPushButton *btnMatriceCofattori;
    QPushButton *btnMatriceInversa;
    QPushButton *btnMatriceTrasposta;
    QPushButton *btnDeterminante;
    QPushButton *btnElevaAPotenza;
    QPushButton *btnDivisioneScalare;
    QPushButton *btnIsSimmetrica;
    QPushButton *btnIsDiagonale;
    QPushButton *btnIsScalare;
    QPushButton *btnMoltiplicazioneScalare;
    QGridLayout* gridLayout;
    QLabel *labelInputNumerici;
    QLineEdit *inputNumerici;

signals:
    void btnMatriceCofattoriClicked(bool);
    void btnMatriceInversaClicked(bool);
    void btnMatriceTraspostaClicked(bool);
    void btnDeterminanteClicked(bool);
    void btnElevaAPotenzaClicked(bool);
    void btnDivisioneScalareClicked(bool);
    void btnIsSimmetricaClicked(bool);
    void btnIsDiagonaleClicked(bool);
    void btnIsScalareClicked(bool);
    void btnMoltiplicazioneScalareClicked(bool);

private slots:
    void inputNumericoChanged(QString);
};

#endif // BUTTONSINGOLAMATRICE_H
