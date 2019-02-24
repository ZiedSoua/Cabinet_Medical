#include "mainwindow.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QGroupBox *box1 = new QGroupBox(QObject::tr("Gestion patient :"));
    butCrClient = new QPushButton("Creer Nouveau Patient");
    butSupClient = new QPushButton("Supprimer Patient");
    butRechClient = new QPushButton("Rechercher Client");
    buthistoriquepatient = new QPushButton("Historique d'un Patient");
    QHBoxLayout *lay1 = new QHBoxLayout();
    lay1->addWidget(butCrClient);
    lay1->addWidget(butSupClient);
    lay1->addWidget(butRechClient);
    lay1->addWidget(buthistoriquepatient);
    box1->setLayout(lay1);
    QGroupBox *box2 = new QGroupBox(QObject::tr("Gestion RDV :"));
    butCrRDV = new QPushButton("Planifier RDV");
    butSupRDV = new QPushButton("Supprimer RDV");
    butcalendrier = new QPushButton("Calendrier");
    QHBoxLayout *lay2 = new QHBoxLayout();
    lay2->addWidget(butCrRDV);
    lay2->addWidget(butSupRDV);
    lay2->addWidget(butcalendrier);
    box2->setLayout(lay2);
    QGridLayout *lay = new QGridLayout();
    lay->addWidget(box1,1,1);
    lay->addWidget(box2,2,1);
    QWidget *window = new QWidget();
    window->setLayout(lay);
    this->setCentralWidget(window);
    QPixmap bacgr("C:\\Users\\Zied\\Documents\\Cabinet_Med\\background.jpg");
    QPalette pal;
    pal.setBrush(QPalette::Background,bacgr);
    this->setPalette(pal);
    this->resize(1000,500);
    QObject::connect(butCrClient,SIGNAL(clicked(bool)),this,SLOT(ClickCrClient()));
    QObject::connect(butRechClient,SIGNAL(clicked(bool)),this,SLOT(ClickRechClient()));
    QObject::connect(butSupClient,SIGNAL(clicked(bool)),this,SLOT(ClickSupClient()));
    QObject::connect(butCrRDV,SIGNAL(clicked(bool)),this,SLOT(ClickAjoutRdv()));
    QObject::connect(butSupRDV,SIGNAL(clicked(bool)),this,SLOT(ClickSupRdv()));
    QObject::connect(buthistoriquepatient,SIGNAL(clicked(bool)),this,SLOT(ClickHistorique()));
    QObject::connect(butcalendrier,SIGNAL(clicked(bool)),this,SLOT(ClickCalendrier()));
}

void MainWindow::ClickCrClient()
{
    ajClientVue = new AjoutClientVue();
    ajClientVue->show();
    QObject::connect(ajClientVue,SIGNAL(SucAjout(bool,QString,QString)),this,SLOT(AjoutSuc(bool,QString,QString)));
}

void MainWindow::ClickRechClient()
{
    rchclientVue = new RechClientVue();
    rchclientVue->show();
    QObject::connect(rchclientVue,SIGNAL(Rechtermine(bool)),this,SLOT(RechpatientTermine(bool)));
}

void MainWindow::ClickSupClient()
{
    supClientVue = new SupClientVue();
    supClientVue->show();
    QObject::connect(supClientVue,SIGNAL(SupClientSucc(bool,QString,QString)),this,SLOT(SupSucc(bool,QString,QString)));
}

void MainWindow::ClickHistorique()
{
    HistVue = new HistoriqueVue();
    HistVue->show();
    QObject::connect(HistVue,SIGNAL(HistoriqueTerm(bool,QString,QString)),this,SLOT(HistTerm(bool,QString,QString)));
}

void MainWindow::AjoutSuc(bool r, QString nomp, QString prenomp)
{
    QMessageBox *box = new QMessageBox();
    if(r)
        box->setText("Patient Ajouté :"+nomp+" "+prenomp);
    else
        box->setText("Patient non ajouté");
    box->show();
    ajClientVue->close();
}

void MainWindow::SupSucc(bool r ,QString nomp, QString prenomp)
{
    QMessageBox *box = new QMessageBox();
    if (r)
    box->setText("Patient Supprimé :"+nomp+" "+prenomp);
    else
        box->setText("Patient non ajouté : Il a des RDV planifié");
    box->show();
    supClientVue->close();
}

void MainWindow::RechpatientTermine(bool r)
{
    if(r==false)
    {
        QMessageBox *box = new QMessageBox();
        box->setText("Erreur recherche");
        box->show();
    }
    rchclientVue->close();
}

void MainWindow::HistTerm(bool r, QString n, QString p)
{
    if(r==false)
    {
        QMessageBox *box = new QMessageBox();
        box->setText("Patient n'existe pas ou bien n'a pas de RDV ");
        box->show();
    }
    HistVue->close();
}

void MainWindow::ClickAjoutRdv()
{
    ajRDV = new AjoutRdvVue();
    ajRDV->show();
    QObject::connect(ajRDV,SIGNAL(AjoutRdvSucc(int,QDate,QTime)),this,SLOT(AjoutRdvSucc(int,QDate,QTime)));
}

void MainWindow::AjoutRdvSucc(int r, QDate d, QTime t)
{
    QMessageBox *box = new QMessageBox();
    if(r==1)
        box->setText("RDV Ajouté pour: "+d.toString()+" à "+t.toString());
    else if (r==0)
        box->setText("RDV non ajouté : Client n'existe pas");
    else if(r==2)
        box->setText("un RDV est déja plannifié à cette horaire");
    box->show();
    ajRDV->close();
}

void MainWindow::ClickSupRdv()
{
    supRDVVue = new SupRdvVue();
    supRDVVue->show();
    QObject::connect(supRDVVue,SIGNAL(SupRdv(bool,QDate,QTime)),this,SLOT(SupRdv(bool,QDate,QTime)));
}

void MainWindow::SupRdv(bool r, QDate d, QTime t)
{
    QMessageBox *box = new QMessageBox();
    if(r)
        box->setText("RDV Supprimé pour le: "+d.toString()+" à "+t.toString());
    else
        box->setText("RDV non supprimé : RDV n'existe pas");
    box->show();
    supRDVVue->close();
}

void MainWindow::ClickCalendrier()
{
    CalVue = new CalendrierVue();
    CalVue->show();
}

MainWindow::~MainWindow()
{

}
