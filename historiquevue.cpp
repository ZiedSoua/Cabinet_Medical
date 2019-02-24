#include "historiquevue.h"
#include <QFormLayout>
#include <QMessageBox>
#include "gestioncabinetmeddao.h"
#include "rechhotelresvue.h"

HistoriqueVue::HistoriqueVue(QWidget *parent) :
    QWidget(parent)
{
    nomlineedit = new QLineEdit();
    prenonlineedit = new QLineEdit();
    buthist = new QPushButton("Rechercher");
    QFormLayout *lay = new QFormLayout();
    lay->addRow("Nom :",nomlineedit);
    lay->addRow("Prénom",prenonlineedit);
    lay->addWidget(buthist);
    this->setLayout(lay);
    QObject::connect(buthist,SIGNAL(clicked(bool)),this,SLOT(ClickHist()));
}

void HistoriqueVue::ClickHist()
{
    if(!nomlineedit->text().isEmpty() && !prenonlineedit->text().isEmpty())
    {
        GestionCabinetMedDAO *gescabmed = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
        QSqlQueryModel *m = new QSqlQueryModel();
        m = gescabmed->HistoriquePatientDAO(nomlineedit->text(),prenonlineedit->text());
        bool res = false;
        if(!m->lastError().isValid())
        {
            res= true ;
        }
        emit HistoriqueTerm(res,nomlineedit->text(),prenonlineedit->text());
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

HistoriqueVue::~HistoriqueVue()
{

}
