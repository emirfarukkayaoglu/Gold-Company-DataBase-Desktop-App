#include "satissayfasi.h"
#include "ui_satissayfasi.h"
#include "mainwindow.h"
#include <QString>>

SatisSayfasi::SatisSayfasi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SatisSayfasi)
{
    ui->setupUi(this);
    SatisSayfasi::setWindowTitle("Satış Sayfası");
    showdata();
    toplam_satis();




}

SatisSayfasi::~SatisSayfasi()
{
    delete ui;

}

void SatisSayfasi::toplam_satis(){
    MainWindow conn;
    conn.connOpen();
    QSqlQuery query;
    if(!query.prepare("SELECT SatisFiyati FROM satissayfasi")){
            qDebug()<<"Select id basarisiz oldu.";
            }
    if(!query.exec()){
                qDebug()<<"Execute edilemedi.";
            }
    int count=0;
    while(query.next()){

    count = count + query.value(0).toInt();
    }
    QString tutar = QString::number(count);
    ui->label_toplamtutar->setText(tutar);
    conn.connClose();
}

void SatisSayfasi::showdata(){
    MainWindow conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *query=new QSqlQuery(conn.mydb);

    query->prepare("select *from satissayfasi");

    query->exec();

    modal->setQuery(*query);
    ui->tableView_satis->setModel(modal);
    conn.connClose();




}

void SatisSayfasi::on_pushButton_save_clicked()
{
    MainWindow conn;
    conn.connOpen();
    QSqlQuery query;
    if(!query.prepare("INSERT INTO satissayfasi (id, AyariVeCesidi, Gram, SatisFiyati, Personel, Tarih) "
                     "VALUES (:id, :AyariVeCesidi, :Gram, :SatisFiyati, :Personel, :Tarih)")){
            qDebug()<<"Başarısız çalışıyor.";
}
    query.bindValue(":id", (ui->lineEdit_id->text()).toInt());
    query.bindValue(":AyariVeCesidi", ui->lineEdit_ayarivecesidi->text());
    query.bindValue(":Gram", ui->lineEdit_gram->text());
    query.bindValue(":SatisFiyati", (ui->lineEdit_satisfiyati->text()).toInt());
    query.bindValue(":Personel", ui->lineEdit_personel->text());
    query.bindValue(":Tarih", ui->lineEdit_tarih->text());
    if(!query.exec()){
                qDebug()<<"Son hata";
            }

    conn.connClose();
    toplam_satis();

}


void SatisSayfasi::on_pushButton_clicked()
{
    showdata();
}

void SatisSayfasi::verileri_aratilinca_goster(QString var1,QString var2,QString var3,QString var4,QString var5,QString var6){
    ui->lineEdit_id->setText(var1);
    ui->lineEdit_ayarivecesidi->setText(var2);
    ui->lineEdit_gram->setText(var3);
    ui->lineEdit_satisfiyati->setText(var4);
    ui->lineEdit_personel->setText(var5);
    ui->lineEdit_tarih->setText(var6);

}

void SatisSayfasi::on_pushButton_ara_clicked()
{
    QString satis_no=ui->lineEdit_ara->text();

    MainWindow conn;
    conn.connOpen();
    QSqlQuery query;
    if(!query.prepare("SELECT id, AyariVeCesidi, Gram, SatisFiyati, Personel, Tarih FROM satissayfasi WHERE id="+satis_no)){
            qDebug()<<"Select id basarisiz oldu.";
            }
    if(!query.exec()){
                qDebug()<<"Execute edilemedi.";
            }
    int count=0;
    while(query.next()){
    qDebug() <<query.size();

    QString id=query.value(0).toString();
    QString ayari_ve_cesidi=query.value(1).toString();
    QString gram=query.value(2).toString();
    QString satis_fiyati=query.value(3).toString();
    QString personel=query.value(4).toString();
    QString tarih=query.value(5).toString();
    verileri_aratilinca_goster(id,ayari_ve_cesidi,gram,satis_fiyati,personel,tarih);
    count++;
    }

    qDebug()<<count;
    conn.connClose();
    toplam_satis();
}

void SatisSayfasi::on_pushButton_update_clicked()
{   QString satis_no=ui->lineEdit_ara->text();
    QString id,ayari_ve_cesidi,gram,satis_fiyati,personel,tarih;
    id=ui->lineEdit_id->text();
    ayari_ve_cesidi=ui->lineEdit_ayarivecesidi->text();
    gram=ui->lineEdit_gram->text();
    satis_fiyati=ui->lineEdit_satisfiyati->text();
    personel=ui->lineEdit_personel->text();
    tarih=ui->lineEdit_tarih->text();


    MainWindow conn;
    conn.connOpen();
    QSqlQuery query;
    if(!query.prepare("UPDATE satissayfasi SET id="+id+", AyariVeCesidi='"+id+"', Gram='"+gram+"', SatisFiyati="+satis_fiyati+", Personel='"+personel+"', Tarih='"+tarih+"' WHERE id ="+satis_no)){
        qDebug()<<"Güncelleme sorgusu basarisiz.";
    }
    if(!query.exec()){
                qDebug()<<"Execute edilemedi.";
            }
    conn.connClose();
    on_pushButton_clicked();
    toplam_satis();
}


void SatisSayfasi::on_pushButton_delete_clicked()
{
    QString satis_no=ui->lineEdit_ara->text();
    MainWindow conn;
    conn.connOpen();
    QSqlQuery query;
    if(!query.prepare("DELETE FROM satissayfasi WHERE id ="+satis_no)){
        qDebug()<<"Delete sorgusu basarisiz.";
    }
    if(!query.exec()){
                qDebug()<<"Execute edilemedi.";
            }
    conn.connClose();
    on_pushButton_clicked();
    toplam_satis();
}


void SatisSayfasi::on_pushButton_trash_clicked()
{
    ui->lineEdit_id->setText("");
    ui->lineEdit_ayarivecesidi->setText("");
    ui->lineEdit_gram->setText("");
    ui->lineEdit_satisfiyati->setText("");
    ui->lineEdit_personel->setText("");
    ui->lineEdit_tarih->setText("");

}

