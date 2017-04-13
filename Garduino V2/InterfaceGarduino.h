#ifndef INTERFACEGARDUINO_H
#define INTERFACEGARDUINO_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QSpinBox>
#include <QSpacerItem>
#include <QPushButton>
#include <QStatusBar>
#include <QString>
#include <queue>

class InterfaceGarduino : public QMainWindow
{
    Q_OBJECT

public:
    InterfaceGarduino(QWidget *parent =0);

public slots:
    void btn1Clicked();
    void btn1Print(const QString & );
    void btn2Clicked();
    void btn2Print(const QString &);
    void btn3Clicked();
    void btn3Print(const QString &);
    void btn4Clicked();
    void btn4Print(const QString &);
    void btn5Clicked();
    void btn5Print(const QString &);
    void btn6Clicked();
    void btn6Print(const QString &);
    void btn7Clicked();
    void btn7Print(const QString &);
    void btn8Clicked();
    void btn8Print(const QString &);
    void btn9Clicked();
    void btn9Print(const QString &);

signals:
    void btn1MsgEmit(const QString &);
    void btn2MsgEmit(const QString &);
    void btn3MsgEmit(const QString &);
    void btn4MsgEmit(const QString &);
    void btn5MsgEmit(const QString &);
    void btn6MsgEmit(const QString &);
    void btn7MsgEmit(const QString &);
    void btn8MsgEmit(const QString &);
    void btn9MsgEmit(const QString &);

private:
    const QString *btnMsg1, *btnMsg2, *btnMsg3, *btnMsg4, *btnMsg5, *btnMsg6, *btnMsg7, *btnMsg8, *btnMsg9;
};

#endif // INTERFACEGARDUINO_H
