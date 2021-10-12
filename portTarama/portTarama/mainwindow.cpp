#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
       ui->results->setText("");
       QString host = ui ->lineEditHost->text();
       QString startPort = ui ->lineEditStartPort->text();
       quint16 startPortInt = startPort.toUShort();
       QString endPort = ui ->lineEditEndPort->text();
       quint16 endPortInt = endPort.toUShort();
       QString timeout = ui ->lineEditTimeout->text();
       quint16 timeoutInt = timeout.toUShort();
       qInfo() << host;
       QTcpSocket socket;


       for(quint16 i = startPortInt; i < endPortInt; i++){

               socket.connectToHost(host, i);
               if(socket.waitForConnected(timeoutInt)){
                   qInfo() << "Acik Port: " << i;
                   QString openPort = QString::number(i);
                   ui->results->append("Açık Port: " + openPort);
                   socket.disconnectFromHost();
               }
       }
       ui->results->append("Tarama Tamamlandı.");
      qInfo() << "Tarama Tamamlandı.";
}

