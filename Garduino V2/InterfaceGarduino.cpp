#include "InterfaceGarduino.h"

InterfaceGarduino::InterfaceGarduino(QWidget *parent)
    :QMainWindow(parent)
{
    //Fenêtre principale
    setWindowTitle("Controleur Garduino Version Alpha");//cvhndfn
    resize(600, 400);


    //Layout principal et vertical
    QWidget * mainWidget = new QWidget;
    QVBoxLayout* principalLayout = new QVBoxLayout(mainWidget);
    setCentralWidget(mainWidget);


    //Sous-Layouts
    auto espaceModes  = new QHBoxLayout;
    principalLayout->addLayout(espaceModes);

    //principalLayout->addItem(new QSpacerItem(0,6,QSizePolicy::Minimum, QSizePolicy::Minimum));//Marche pas full comme prévu

    auto milieu = new QHBoxLayout;
    principalLayout->addLayout(milieu);

    //principalLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Minimum, QSizePolicy::Expanding));

    auto espaceBoutons  = new QHBoxLayout;
    principalLayout->addLayout(espaceBoutons);

    auto espaceStatut = new QHBoxLayout;
    principalLayout->addLayout(espaceStatut);

    //2 Groupbox
    auto etatsActuels = new QGroupBox();
    etatsActuels->setTitle("États actuels");

    auto etatsDesires = new QGroupBox();
    etatsActuels->setTitle("États désirés");

    //Boutons
    auto bouton1 = new QPushButton("Automatique");
    auto bouton2 = new QPushButton("Manuel");
    auto bouton3 = new QPushButton("Arrêt d'urgence");
    auto bouton4 = new QPushButton("On");
    auto bouton5 = new QPushButton("Off");
    auto bouton6 = new QPushButton("On");
    auto bouton7 = new QPushButton("Off");
    auto bouton8 = new QPushButton("Démarrer");
    auto bouton9 = new QPushButton("Quitter");

    //Labels
    auto label2 = new QLabel(" Température",etatsActuels);
    auto label3 = new QLabel(" Humidité",etatsActuels);
    auto label4 = new QLabel(" Luminosité naturelle",etatsActuels);
    auto label5 = new QLabel(" Luminosité",etatsActuels);
    auto label6 = new QLabel(" Lumière",etatsActuels);
    auto label7 = new QLabel(" Pompe",etatsActuels);

    auto label8 = new QLabel(" Température", etatsDesires);
    auto label9 = new QLabel(" Humidité", etatsDesires);
    auto label10 = new QLabel(" Heures de lumière", etatsDesires);


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


    //Layout de États désirés
    auto etatsDesiresLayout = new QGridLayout();

    etatsDesiresLayout ->addWidget(label8,2,0);
    etatsDesiresLayout ->addWidget(label9,3,0);
    etatsDesiresLayout ->addWidget(label10,4,0);

    etatsDesiresLayout ->addWidget(text8,2,1);
    etatsDesiresLayout ->addWidget(text9,3,1);
    etatsDesiresLayout ->addWidget(text10,4,1);

    etatsDesires->setLayout(etatsDesiresLayout);
    milieu->addWidget(etatsDesires);

    //Layout de Mode Manuel


    //Layout Bouton en bas
    espaceBoutons->addWidget(bouton3);
    espaceBoutons->addWidget(bouton8);
    espaceBoutons->addWidget(bouton9);

    //Barre de statut  //Ne fonctionne pas  ... Layout?
    QStatusBar *statut = new QStatusBar();
    setStatusBar(statut);
    espaceStatut->addWidget(statut);

//    const QString *Qdemarrer = new QString("Demarrage de l'application");
    QObject::connect(bouton8, SIGNAL(clicked()), this, SLOT(printLog()));
}

void InterfaceGarduino::printLog() {
    // auto log = new QLabel(message);
//    this->file->push(log);
    // statusBar.addWidget(log);
    //QStatusBar& statusBar, QString  &message
    statusBar()->showMessage("helloWorld");
}
