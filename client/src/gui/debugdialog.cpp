#include "ui_debugdialog.h"
#include "debugdialog.h"
#include <QLocalSocket>


namespace OCC {
DebugDialog::DebugDialog(QWidget *parent)
    :QDialog(parent),
      _ui(new Ui::DebugDialog)
{
    _ui->setupUi(this);
    connect(_ui->info, SIGNAL(clicked(bool)), SLOT(slotInfoButtonPressed()));
    connect(_ui->pageweb, SIGNAL(clicked(bool)), SLOT(slotWebButtonPressed()));
}

void DebugDialog::slotInfoButtonPressed()
{
    QString socketPath;
    socketPath = QLatin1String("\\\\.\\pipe\\")
    + QLatin1String("ownCloud");
    QLocalSocket * socket = new QLocalSocket();
    socket->connectToServer(socketPath);
    if(socket->waitForConnected(1000))
    {
        QString localMessage = tr("INFO:%1\n").arg("C:\\Users\\prout\\Mokapress\\test");
        QByteArray bytesToSend = localMessage.toUtf8();
        qint64 sent = socket->write(bytesToSend);
        if( sent != bytesToSend.length() ) {
            qDebug() << "WARN: Could not send all data on socket for " << localMessage;
        }
    }
}

void DebugDialog::slotWebButtonPressed()
{
    QString socketPath;
    socketPath = QLatin1String("\\\\.\\pipe\\")
    + QLatin1String("ownCloud");
    QLocalSocket * socket = new QLocalSocket();
    socket->connectToServer(socketPath);
    if(socket->waitForConnected(1000))
    {
        QString localMessage = tr("WEB:%1\n").arg("C:\\Users\\prout\\Mokapress\\patate.txt");
        QByteArray bytesToSend = localMessage.toUtf8();
        qint64 sent = socket->write(bytesToSend);
        if( sent != bytesToSend.length() ) {
            qDebug() << "WARN: Could not send all data on socket for " << localMessage;
        }
    }
}

DebugDialog::~DebugDialog()
{
    _localServer.close();
    delete _ui;

}
}
