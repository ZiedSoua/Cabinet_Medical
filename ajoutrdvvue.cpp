#include "ajoutrdvvue.h"
#include <QFormLayout>
#include <QMessageBox>
#include "gestioncabinetmeddao.h"

AjoutRdvVue::AjoutRdvVue(QWidget *parent) :
    QWidget(parent)
{
    nompatient = new QLineEdit();
    prenompatient = new QLineEdit();
    comment = new QTextEdit();
    daterdv = new QDateEdit();
    daterdv->setDisplayFormat("dd-MM-yyyy");
    timerdv = new QTimeEdit();
    timerdv->setDisplayFormat("HH:mm");
    butajout = new QPushButton("Ajout RDV");
     QFormLayout *lay= new QFormLayout();
     lay->addRow(("Nom patient :"),nompatient);
     lay->addRow(("Prenom patient :"),prenompatient);
     lay->addRow(("Date RDV :"),daterdv);
     lay->addRow(("Heure RDV :"),timerdv);
     lay->addRow(("Commentaire :"),comment);
     lay->addRow(butajout);
     this->setLayout(lay);
     QObject::connect(butajout,SIGNAL(clicked(bool)),this,SLOT(ClickAjout()));
}

void AjoutRdvVue::ClickAjout()
{
    if(!nompatient->text().isEmpty() && !prenompatient->text().isEmpty() && !daterdv->text().isEmpty() && !timerdv->text().isEmpty())
    {
        if(daterdv->date().operator >=(QDate::currentDate()))
        {
            int res  ;
            GestionCabinetMedDAO *gcabmedDAO = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
            res = gcabmedDAO->AjoutRdvDAO(nompatient->text(),prenompatient->text(),daterdv->date(),timerdv->time(),comment->toPlainText());
            emit AjoutRdvSucc(res,daterdv->date(),timerdv->time());
        }
        else
        {
            QMessageBox *alerte= new QMessageBox() ;
            alerte->setText("Date non valide ");
            alerte->show();
        }
    }
    else
    {
        QMessageBox *alerte= new QMessageBox() ;
        alerte->setText("Champs obligatoires vides ");
        alerte->show();
    }
}

AjoutRdvVue::~AjoutRdvVue()
{

}
