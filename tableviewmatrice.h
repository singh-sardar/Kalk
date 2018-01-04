#ifndef TABLEVIEWMATRICE_H
#define TABLEVIEWMATRICE_H

#include <QWidget>
#include <QTableWidget>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class TableViewMatrice: public QWidget{
    Q_OBJECT

public:
    TableViewMatrice(QWidget* parent=0, QString lblMatrice="Matrice", int righe=2, int colonne=2, int maxRighe=100, int maxColonne=100);
    QLabel* getLableMatrice() const;
    QSpinBox* getSpinBoxRighe() const;
    QSpinBox* getSpinBoxColonne() const;
    QTableWidget* getTableWidget() const;
    ~TableViewMatrice();

private:
    QTableWidget* tableWidget;
    QSpinBox* spinBoxRighe;
    QSpinBox* spinBoxColonne;
    QLabel* labelMatrice;
    QLabel* labelSpinBoxRighe;
    QLabel* labelSpinBoxColonne;
    QVBoxLayout* verticalLayout;
    QHBoxLayout* hLPerRighe, *hLPerColonne;

private slots:
    void impostaCelle();
    void modificaNumRighe();
    void modificaNumColonne();

signals:
    //void sizeChanged(int righe, int colonne);
};

#endif // TABLEVIEWMATRICE_H
