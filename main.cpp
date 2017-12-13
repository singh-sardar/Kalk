#include "kalk.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    kalk w;
    w.show();

    return a.exec();
}
