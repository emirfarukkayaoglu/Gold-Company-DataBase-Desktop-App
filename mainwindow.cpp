#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_akkaya->setAttribute(Qt::WA_TranslucentBackground);
    MainWindow::setWindowTitle("Akkaya Veri Tabani");

    if(!mydb.isOpen()){
        ui->label_status->setText("Veri Tabanına bağlanılamadı...");
    }else{
        ui->label_status->setText("Veri Tabanına bağlanıldı...");
    }


}

MainWindow::~MainWindow()
{
    delete ui;



}
bool MainWindow::connOpen(){
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/emirf/Desktop/Akkaya/AkkayaVeriTabani/database/akkayagiris.db");
    if(!mydb.open()){
        qDebug()<<("Veri Tabanına bağlanılamadı...");
        return false;
    }else{
        ui->label_status->setText("Veri Tabanına bağlanıldı...");
        return true;
    }
}


void MainWindow::connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

void MainWindow::on_pushButton_login_clicked()
{
    QString username,password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    if(!connOpen()){
        qDebug()<<"Veri tabanı açılmamış.";
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username='"+username+"'and password='"+password+"'");
    if(query.exec()){
        int count=0;
        while(query.next()){
            count++;
        }
        if(count==1){
            ui->label_status->setText("Kullanıcı ID ve Parola başarılı.");
            connClose();
            hide();
            ana=new anasayfa(this);
            ana->show();
        }
        else if(count>=1 || count<=1){
            ui->label_status->setText("Kullanıcı ID ve Parola başarısız.");
        }
    }
}

