#ifndef ANASAYFA_H
#define ANASAYFA_H

#include <QDialog>
#include "satissayfasi.h"

namespace Ui {
class anasayfa;
}

class anasayfa : public QDialog
{
    Q_OBJECT

public:
    explicit anasayfa(QWidget *parent = nullptr);
    ~anasayfa();

private slots:
    void on_pushButton_satis_clicked();

private:
    Ui::anasayfa *ui;
    SatisSayfasi *satissayfasi;
};

#endif // ANASAYFA_H
