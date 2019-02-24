#include "calendriervue.h"
#include <QFormLayout>
#include "gestioncabinetmeddao.h"
#include "rechhotelresvue.h"
#include <QMessageBox>

CalendrierVue::CalendrierVue(QWidget *parent) :
    QWidget(parent)
{
    butjour = new QPushButton("Planning d'Aujourd'hui");
    butmois = new QPushButton("Planning de ce mois");
    datepers = new QDateEdit();
    datepers->setDisplayFormat("dd:MM:yyyy");
    datepers->setDisabled(true);
    pers = new QRadioButton("Personnalisé :");
    pers->setChecked(false);
    QFormLayout *lay= new QFormLayout();
    lay->addRow(butjour);
    lay->addRow(butmois);
    lay->addRow(pers);
    lay->addRow(("Date RDV :"),datepers);
    butvalider = new QPushButton("Valider");
    butvalider->setDisabled(true);
    lay->addRow(butvalider);
    this->setLayout(lay);
    QObject::connect(pers,SIGNAL(clicked(bool)),this,SLOT(Clickpers()));
    QObject::connect(butjour,SIGNAL(clicked(bool)),this,SLOT(Clickjour()));
    QObject::connect(butmois,SIGNAL(clicked(bool)),this,SLOT(Clickmois()));
    QObject::connect(butvalider,SIGNAL(clicked(bool)),this,SLOT(ClickValider()));
}

void CalendrierVue::Clickpers()
{
    if(pers->isChecked())
    {
        datepers->setDisabled(false);
        butvalider->setDisabled(false);
    }
    else
    {
        datepers->setDisabled(true);
        butvalider->setDisabled(true);
    }
}

void CalendrierVue::ClickValider()
{
    if(datepers->date().operator >=(QDate::currentDate()))
    {
        GestionCabinetMedDAO *gescabmed = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
        QSqlQueryModel *m = new QSqlQueryModel();
        m = gescabmed->CalendrierPers(datepers->date());
        if(!m->lastError().isValid())
        {
            RechHotelResVue *rechres = new RechHotelResVue();
            rechres->setModelTableView(m);
            rechres->show();
        }
        else
        {
            QMessageBox *alerte= new QMessageBox() ;
            alerte->setText("Erreur ");
            alerte->show();
        }
    }
}

void CalendrierVue::Clickjour()
{
    GestionCabinetMedDAO *gescabmed = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
    QSqlQueryModel *m = new QSqlQueryModel();
    m = gescabmed->CalendrierAjourdhui();
    if(!m->lastError().isValid())
    {
        RechHotelResVue *rechres = new RechHotelResVue();
        rechres->setModelTableView(m);
        rechres->show();
    }
    else
    {
        QMessageBox *alerte= new QMessageBox() ;
        alerte->setText("Erreur ");
        alerte->show();
    }
}

void CalendrierVue::Clickmois()
{
    GestionCabinetMedDAO *gescabmed = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
    QSqlQueryModel *m = new QSqlQueryModel();
    m = gescabmed->CalendrierMois();
    if(!m->lastError().isValid())
    {
        RechHotelResVue *rechres = new RechHotelResVue();
        rechres->setModelTableView(m);
        rechres->show();
    }
    else
    {
        QMessageBox *alerte= new QMessageBox() ;
        alerte->setText("Erreur ");
        alerte->show();
    }
}

CalendrierVue::~CalendrierVue()
{

}
