#include "InterfaceGarduino.h"
#include <QtWidgets>
InterfaceGarduino::InterfaceGarduino(QWidget *parent)
    :QMainWindow(parent)
{
    //Fenêtre principale
    setWindowTitle("Controleur Garduino");
    resize(600, 400);
    createMenu();

    //Layout principal et vertical
    QWidget * mainWidget = new QWidget;
    QVBoxLayout* principalLayout = new QVBoxLayout(mainWidget);
    setCentralWidget(mainWidget);


    //Sous-Layouts
    principalLayout->setMenuBar(menuBar);
    auto espaceModes  = new QHBoxLayout;
    principalLayout->addLayout(espaceModes);



    auto milieu = new QHBoxLayout;
    principalLayout->addLayout(milieu);
	
	auto droit = new QVBoxLayout;
	



    principalLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Minimum, QSizePolicy::Expanding));

    auto espaceBoutons  = new QHBoxLayout;
    principalLayout->addLayout(espaceBoutons);

    auto espaceStatut = new QHBoxLayout;
    principalLayout->addLayout(espaceStatut);

    //2 Groupbox
    auto etatsActuels = new QGroupBox();
    etatsActuels->setTitle("États actuels");

    auto etatsDesires = new QGroupBox();
    //etatsActuels->setTitle("États désirés");
	/*Titre état actuel commenté puisqu'il ne va pas au bon endroit...*/
	auto manuel = new QGroupBox();
	manuel->setTitle("Mode manuel");

    //Boutons
    auto bouton1 = new QPushButton("Automatique");
    auto bouton2 = new QPushButton("Manuel");
    auto bouton3 = new QPushButton("Arrêt d'urgence");
    auto pompeOn = new QPushButton("On");
    auto pompeOff = new QPushButton("Off");
    auto lampeOn = new QPushButton("On");
    auto lampeOff = new QPushButton("Off");
    auto bouton8 = new QPushButton("Démarrer");
    auto bouton9 = new QPushButton("Quitter");

    //Labels
    auto label2 = new QLabel(" Température (°C)",etatsActuels);
    auto label3 = new QLabel(" Humidité (%)",etatsActuels);
    auto label4 = new QLabel(" Luminosité naturelle (%)",etatsActuels);
    auto label5 = new QLabel(" Luminosité totale (%)",etatsActuels);
    auto label6 = new QLabel(" Lumière",etatsActuels);
    auto label7 = new QLabel(" Pompe",etatsActuels);

	auto label8 = new QLabel("Température désirée (°C)", etatsDesires);
    auto label9 = new QLabel("Humidité désirée (%)", etatsDesires);
    auto label10 = new QLabel("Nombre d'heures de lumière désiré", etatsDesires);
	auto pompeLabel = new QLabel("Pompe", manuel);
	auto lampeLabel = new QLabel("Lampe", manuel);


    //Lignes de texte
    auto text1 = new QLineEdit(etatsActuels);
    auto text2 = new QLineEdit(etatsActuels);
    auto text3 = new QLineEdit(etatsActuels);
    auto text4 = new QLineEdit(etatsActuels);
    auto text5 = new QLineEdit(etatsActuels);
    auto text6 = new QLineEdit(etatsActuels);

    auto text8 = new QLineEdit(etatsDesires);
    auto text9 = new QLineEdit(etatsDesires);
    auto text10 = new QLineEdit(etatsDesires);



    //Layout de Espace Modes
    espaceModes->addWidget(bouton1);
    espaceModes->addWidget(bouton2);


	//Layout de États désirés
	auto etatsDesiresLayout = new QGridLayout();

	etatsDesiresLayout->addWidget(label8, 2, 0);
	etatsDesiresLayout->addWidget(label9, 3, 0);
	etatsDesiresLayout->addWidget(label10, 4, 0);

	etatsDesiresLayout->addWidget(text8, 2, 1);
	etatsDesiresLayout->addWidget(text9, 3, 1);
	etatsDesiresLayout->addWidget(text10, 4, 1);

	etatsDesires->setLayout(etatsDesiresLayout);
	droit->addWidget(etatsDesires);

	//Layout de Mode Manuel

	auto manuelLayout = new QGridLayout();

	manuelLayout->addWidget(pompeLabel, 0, 0);
	manuelLayout->addWidget(pompeOn, 0, 1);
	manuelLayout->addWidget(pompeOff, 0, 2);
	manuelLayout->addWidget(lampeLabel, 1, 0);
	manuelLayout->addWidget(lampeOn, 1, 1);
	manuelLayout->addWidget(lampeOff, 1, 2);

	manuel->setLayout(manuelLayout);
	droit->addWidget(manuel);

    //Layout de États Actuels
    auto etatsActuelsLayout = new QGridLayout();

    etatsActuelsLayout ->addWidget(label2,2,0);
    etatsActuelsLayout ->addWidget(label3,3,0);
    etatsActuelsLayout ->addWidget(label4,4,0);
    etatsActuelsLayout ->addWidget(label5,5,0);
    etatsActuelsLayout ->addWidget(label6,6,0);
    etatsActuelsLayout ->addWidget(label7,7,0);

    etatsActuelsLayout ->addWidget(text1,2,1);
    etatsActuelsLayout ->addWidget(text2,3,1);
    etatsActuelsLayout ->addWidget(text3,4,1);
    etatsActuelsLayout ->addWidget(text4,5,1);
    etatsActuelsLayout ->addWidget(text5,6,1);
    etatsActuelsLayout ->addWidget(text6,7,1);

    etatsActuels->setLayout(etatsActuelsLayout);
    milieu->addWidget(etatsActuels);
	milieu->addLayout(droit);

    

    //Layout Bouton en bas
    espaceBoutons->addWidget(bouton3);
    espaceBoutons->addWidget(bouton8);
    espaceBoutons->addWidget(bouton9);

//---------------Vincent ci-bas


    QStatusBar *statut = new QStatusBar();
    setStatusBar(statut);
    espaceStatut->addWidget(statut);
    statusBar()->showMessage("", 0);
    //message assigne a chaque clic pour chacun des differents boutons
    btnMsg1 = new const QString("Automatique");
    btnMsg2 = new const QString("Manuel");
    btnMsg3 = new const QString("Arrêt d'urgence");
    btnMsg4 = new const QString("Pompe On");
    btnMsg5 = new const QString("Pompe Off");
    btnMsg6 = new const QString("Lumiere On");
    btnMsg7 = new const QString("Lumiere Off");
    btnMsg8 = new const QString("Demarrage de l'application");
    btnMsg9 = new const QString("Quitter");

    //mapping du clic de bouton vers une slot qui appelle une autre slot a l'aide d'un signal intermediaire
    QObject::connect(bouton1, SIGNAL(clicked()), this, SLOT(btn1Clicked()));
    QObject::connect(this, SIGNAL(btn1MsgEmit(const QString &)), this, SLOT(btn1Print(const QString &)));
    QObject::connect(bouton2, SIGNAL(clicked()), this, SLOT(btn2Clicked()));
    QObject::connect(this, SIGNAL(btn2MsgEmit(const QString &)), this, SLOT(btn2Print(const QString &)));
    QObject::connect(bouton3, SIGNAL(clicked()), this, SLOT(btn3Clicked()));
    QObject::connect(this, SIGNAL(btn3MsgEmit(const QString &)), this, SLOT(btn3Print(const QString &)));
    QObject::connect(pompeOn, SIGNAL(clicked()), this, SLOT(btn4Clicked()));
    QObject::connect(this, SIGNAL(btn4MsgEmit(const QString &)), this, SLOT(btn4Print(const QString &)));
    QObject::connect(pompeOff, SIGNAL(clicked()), this, SLOT(btn5Clicked()));
    QObject::connect(this, SIGNAL(btn5MsgEmit(const QString &)), this, SLOT(btn5Print(const QString &)));
    QObject::connect(lampeOn, SIGNAL(clicked()), this, SLOT(btn6Clicked()));
    QObject::connect(this, SIGNAL(btn6MsgEmit(const QString &)), this, SLOT(btn6Print(const QString &)));
    QObject::connect(lampeOff, SIGNAL(clicked()), this, SLOT(btn7Clicked()));
    QObject::connect(this, SIGNAL(btn7MsgEmit(const QString &)), this, SLOT(btn7Print(const QString &)));
    QObject::connect(bouton8, SIGNAL(clicked()), this, SLOT(btn8Clicked()));
    QObject::connect(this, SIGNAL(btn8MsgEmit(const QString &)), this, SLOT(btn8Print(const QString &)));
    QObject::connect(bouton9, SIGNAL(clicked()), this, SLOT(btn9Clicked()));
    QObject::connect(this, SIGNAL(btn9MsgEmit(const QString &)), this, SLOT(btn9Print(const QString &)));
}

void InterfaceGarduino::btn1Clicked() {
    this->btn1MsgEmit(*btnMsg1);
}
void InterfaceGarduino::btn1Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn2Clicked() {
    this->btn2MsgEmit(*btnMsg2);
}
void InterfaceGarduino::btn2Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn3Clicked() {
    this->btn3MsgEmit(*btnMsg3);
}
void InterfaceGarduino::btn3Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn4Clicked() {
    this->btn4MsgEmit(*btnMsg4);
}
void InterfaceGarduino::btn4Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn5Clicked() {
    this->btn5MsgEmit(*btnMsg5);
}
void InterfaceGarduino::btn5Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn6Clicked() {
    this->btn6MsgEmit(*btnMsg6);
}
void InterfaceGarduino::btn6Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn7Clicked() {
    this->btn7MsgEmit(*btnMsg7);
}
void InterfaceGarduino::btn7Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn8Clicked() {
    this->btn8MsgEmit(*btnMsg8);
}
void InterfaceGarduino::btn8Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}

void InterfaceGarduino::btn9Clicked() {
    this->btn9MsgEmit(*btnMsg9);
}
void InterfaceGarduino::btn9Print(const QString &msg) {
    statusBar()->showMessage(msg,0);
}



//Simon ci-bas
//Menu
void InterfaceGarduino::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu("Fichier", this);
    helpMenu = new QMenu("Aide", this);
    openAction = fileMenu->addAction("Ouvrir une configuration existente");
    saveAction = fileMenu->addAction("Sauvegarder la configuration actuelle");
    startAction = fileMenu->addAction("Démarrer");
    stopAction = fileMenu->addAction("Arrêter");
    closeAction = fileMenu->addAction("Quitter");
    guideAction = helpMenu->addAction("Guide d'utilisation");

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);


    connect(openAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(startAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(stopAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(guideAction, SIGNAL(triggered()), this, SLOT(accept()));
}
