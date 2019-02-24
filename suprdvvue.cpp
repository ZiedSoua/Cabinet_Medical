#include "suprdvvue.h"
#include <QFormLayout>
#include "gestioncabinetmeddao.h"
#include <QMessageBox>

SupRdvVue::SupRdvVue(QWidget *parent) :
    QWidget(parent)
{
    daterdv = new QDateEdit();
    daterdv->setDisplayFormat("dd-MM-yyyy");
    timerdv = new QTimeEdit();
    timerdv->setDisplayFormat("HH:mm");
    butsup = new QPushButton("Supprimer RDV");
    QFormLayout *lay= new QFormLayout();
    lay->addRow(("Date du RDV :"),daterdv);
    lay->addRow(("Heure du RDV :"),timerdv);
    lay->addRow(butsup);
    this->setLayout(lay);
    QObject::connect(butsup,SIGNAL(clicked(bool)),this,SLOT(ClickSup()));
}

void SupRdvVue::ClickSup()
{
    bool r = false ;
    if(daterdv->date().operator >=(QDate::currentDate()))
    {
        GestionCabinetMedDAO *gescabMed = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
        r= gescabMed->SupprimerRdvDAO(daterdv->date(),timerdv->time());
        emit SupRdv(r,daterdv->date(),timerdv->time());
    }
    else
    {
        QMessageBox *alerte= new QMessageBox() ;
        alerte->setText("La date doit être ultérieure à aujourd'hui");
        alerte->show();
    }
}

SupRdvVue::~SupRdvVue()
{
}
