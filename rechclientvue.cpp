#include "rechclientvue.h"
#include <QFormLayout>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "gestioncabinetmeddao.h"
#include "rechhotelresvue.h"


RechClientVue::RechClientVue(QWidget *parent) :
    QWidget(parent)
{
    nomlineedit = new QLineEdit();
    prenonlineedit = new QLineEdit();
    butrech = new QPushButton("Rechercher");
    QFormLayout *lay = new QFormLayout();
    lay->addRow("Nom :",nomlineedit);
    lay->addRow("Prénom",prenonlineedit);
    lay->addWidget(butrech);
    this->setLayout(lay);
    QObject::connect(butrech,SIGNAL(clicked(bool)),this,SLOT(ClickRechercher()));
}

void RechClientVue::ClickRechercher()
{
    if(!nomlineedit->text().isEmpty() && !prenonlineedit->text().isEmpty())
    {
        GestionCabinetMedDAO *gescabmed = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
        QSqlQueryModel *m = new QSqlQueryModel();
        m = gescabmed->RechercherPatientDAO(nomlineedit->text(),prenonlineedit->text());
        bool res = false ;
        if(!m->lastError().isValid())
            res = true ;
        emit Rechtermine(res);
        if(res)
        {
            RechHotelResVue *rechres = new RechHotelResVue();
            rechres->setModelTableView(m);
            rechres->show();
        }
    }
    else
    {
        QMessageBox *alerte= new QMessageBox() ;
        alerte->setText("Champs obligatoires vides ");
        alerte->show();
    }
}

RechClientVue::~RechClientVue()
{

}
