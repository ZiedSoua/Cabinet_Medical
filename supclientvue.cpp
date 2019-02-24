#include "supclientvue.h"
#include <QFormLayout>
#include <QMessageBox>
#include "gestioncabinetmeddao.h"

SupClientVue::SupClientVue(QWidget *parent) :
    QWidget(parent)
{
    nomlineedit = new QLineEdit();
    prenomlineedit = new QLineEdit();
    butsup = new QPushButton("Supprimer");
    QFormLayout *lay = new QFormLayout();
    lay->addRow("Nom :",nomlineedit);
    lay->addRow("Prénom",prenomlineedit);
    lay->addWidget(butsup);
    this->setLayout(lay);
    QObject::connect(butsup,SIGNAL(clicked(bool)),this,SLOT(ClickSupprimer()));
}

void SupClientVue::ClickSupprimer()
{
    if(!nomlineedit->text().isEmpty() && !prenomlineedit->text().isEmpty())
    {
        GestionCabinetMedDAO *gescabDAO = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
        bool r = gescabDAO->SupprimerPatientDAO(nomlineedit->text(),prenomlineedit->text());
        emit SupClientSucc(r, nomlineedit->text(),prenomlineedit->text());
    }
    else
    {
        QMessageBox *alerte= new QMessageBox() ;
        alerte->setText("Champs obligatoires vides ");
        alerte->show();
    }
}

SupClientVue::~SupClientVue()
{

}
