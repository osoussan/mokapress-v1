#ifndef DEBUGDIALOG_H
#define DEBUGDIALOG_H

#include <QDialog>
#include <QLocalServer>

namespace OCC {

namespace Ui {
class DebugDialog;
}

class DebugDialog : public QDialog
{
     Q_OBJECT

public:
    explicit DebugDialog(QWidget *parent = 0);
    ~DebugDialog();

public slots:
    void slotInfoButtonPressed();
    void slotWebButtonPressed();
private:
    Ui::DebugDialog *_ui;
    QLocalServer _localServer;

};
}

#endif // SHAREDIALOG_H
