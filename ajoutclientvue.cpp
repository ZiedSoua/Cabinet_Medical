#include "ajoutclientvue.h"
#include <QFormLayout>
#include <QMessageBox>
#include "gestioncabinetmeddao.h"

AjoutClientVue::AjoutClientVue(QWidget *parent) :
    QWidget(parent)
{
    nomlineedit = new QLineEdit();
    prenomlineedit = new QLineEdit();
    datenaisslineedit = new QLineEdit();
    datenaisslineedit->setPlaceholderText("dd:MM:yyyy (24:03:1994)");
    tellineedit = new QLineEdit();
    comments = new QTextEdit();
    butval = new QPushButton("Valider");
    QFormLayout *lay= new QFormLayout();
    lay->addRow(("Nom :"),nomlineedit);
    lay->addRow(("Prenom :"),prenomlineedit);
    lay->addRow("Telephone :",tellineedit);
    lay->addRow("Date de naissance :", datenaisslineedit);
    lay->addRow("Commentaires :",comments);
    lay->addRow(butval);
    this->setLayout(lay);
    QObject::connect(butval,SIGNAL(clicked(bool)),this,SLOT(ClickAjouter()));
}

void AjoutClientVue::ClickAjouter()
{
    if(!nomlineedit->text().isEmpty() && !prenomlineedit->text().isEmpty() && !datenaisslineedit->text().isEmpty() && !tellineedit->text().isEmpty())
    {
        GestionCabinetMedDAO *gcabmedDAO = new GestionCabinetMedDAO("cabinet_med","127.0.0.1","root","");
        bool r = gcabmedDAO->AjoutPatientDAO(nomlineedit->text(),prenomlineedit->text(),datenaisslineedit->text(),tellineedit->text(),comments->toPlainText());
        emit SucAjout(r,nomlineedit->text(),prenomlineedit->text());
    }
    else
    {
        QMessageBox *alerte= new QMessageBox() ;
        alerte->setText("Champs obligatoires vides ");
        alerte->show();
    }
}


AjoutClientVue::~AjoutClientVue()
{

}
