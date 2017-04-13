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
#include <queue>


class InterfaceGarduino : public QMainWindow
{
    Q_OBJECT

public:
    InterfaceGarduino(QWidget *parent =0);

public slots:
    void printLog();
//QStatusBar& statusBar, QString &message
private:
    //std::queue<QLabel> *file;

};

#endif // INTERFACEGARDUINO_H
