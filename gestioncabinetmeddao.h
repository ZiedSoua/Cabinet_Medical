#ifndef GESTIONCABINETMEDDAO_H
#define GESTIONCABINETMEDDAO_H

#include <QtSql>
#include <QtSql/QtSql>
#include <QDate>
#include <QTime>

class GestionCabinetMedDAO
{
private:
    QSqlDatabase db ;
    QString dbnom ;
    QString dbip ;
    QString dbuser ;
    QString dbpass;
public:
    GestionCabinetMedDAO();
    GestionCabinetMedDAO(QString nomdb,QString ip,QString user,QString pass);
    bool AjoutPatientDAO(QString nom, QString prenom, QString datenaissance, QString tel, QString com);
    bool SupprimerPatientDAO(QString nom, QString prenom);
    QSqlQueryModel* RechercherPatientDAO(QString nom, QString prenom);
    int AjoutRdvDAO(QString nom , QString prenom, QDate daterdv , QTime timerdv , QString comm);
    bool SupprimerRdvDAO(QDate daterdv,QTime timerdv);
    QSqlQueryModel* HistoriquePatientDAO(QString nom,QString prenom);
    QSqlQueryModel* CalendrierAjourdhui();
    QSqlQueryModel* CalendrierMois();
    QSqlQueryModel* CalendrierPers(QDate d);
};

#endif // GESTIONCABINETMEDDAO_H
