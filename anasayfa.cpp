#include "anasayfa.h"
#include "ui_anasayfa.h"

anasayfa::anasayfa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::anasayfa)
{
    ui->setupUi(this);
    anasayfa::setWindowTitle("Anasayfa");
}

anasayfa::~anasayfa()
{
    delete ui;

}

void anasayfa::on_pushButton_satis_clicked()
{
    hide();
    satissayfasi = new SatisSayfasi();
    satissayfasi->show();
}

