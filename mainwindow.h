#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDesktopServices>
#include <QList>
#include <QMessageBox>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void initStyle();
    void printToFile(QByteArray data);

protected:
    void findPorts();
    bool initSerialPort();
    void sendMsg(const QString &msg);
    void flushText();

public slots:
    void recvMsg();

private slots:

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QString dataProcess(QString);
};
#endif // MAINWINDOW_H
