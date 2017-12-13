#ifndef KALK_H
#define KALK_H

#include <QMainWindow>

namespace Ui {
class kalk;
}

class kalk : public QMainWindow
{
    Q_OBJECT

public:
    explicit kalk(QWidget *parent = 0);
    ~kalk();

private:
    Ui::kalk *ui;
};

#endif // KALK_H
