#include "kalk.h"
#include "ui_kalk.h"

kalk::kalk(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kalk)
{
    ui->setupUi(this);
}

kalk::~kalk()
{
    delete ui;
}
