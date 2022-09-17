#ifndef SATISSAYFASI_H
#define SATISSAYFASI_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class SatisSayfasi;
}

class SatisSayfasi : public QMainWindow
{
    Q_OBJECT
public:
    QSqlQueryModel *modal;
    void showdata();
public:
    explicit SatisSayfasi(QWidget *parent = nullptr);
    ~SatisSayfasi();
    void verileri_aratilinca_goster(QString var1,QString var2,QString var3,QString var4,QString var5,QString var6);
    void toplam_satis();
private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_clicked();

    void on_pushButton_ara_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_trash_clicked();

private:
    Ui::SatisSayfasi *ui;


};

#endif // SATISSAYFASI_H
