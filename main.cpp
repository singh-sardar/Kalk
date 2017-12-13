#include "kalk.h"
#include <QApplication>
#include "vettoregenerico.h"

int main(int argc, char *argv[])
{
    VettoreGenerico<int> v();
    QApplication a(argc, argv);
    kalk w;
    w.show();

    return a.exec();
}
