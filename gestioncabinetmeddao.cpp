#include "gestioncabinetmeddao.h"

GestionCabinetMedDAO::GestionCabinetMedDAO()
{

}

GestionCabinetMedDAO::GestionCabinetMedDAO(QString nomdb, QString ip, QString user, QString pass)
{
    dbnom = nomdb ;
    dbip = ip;
    dbuser = user ;
    dbpass = pass ;
}

bool GestionCabinetMedDAO::AjoutPatientDAO(QString nom, QString prenom, QString datenaissance, QString tel, QString com)
{
    bool res = false ;
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    if(db.open())
    {
        qDebug()<<"Database is opened";
        QString q = "INSERT INTO `patient`(`nom`, `prenom`, `telephone`, `date_naissance`, `commentaire`) VALUES ('"+nom+"','"+prenom+"','"+tel+"','"+datenaissance+"','"+com+"')";
        QSqlQuery query ;
        query.exec(q);
        if(!query.lastError().isValid())
            res = true ;
        qDebug()<<q ;
    }
    else
    {
        qDebug()<<"fail open database";
    }
    return res ;
}

bool GestionCabinetMedDAO::SupprimerPatientDAO(QString nom, QString prenom)
{
    bool res = false ;
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    if(db.open())
    {
        qDebug()<<"Database is opened";
        QString q = "DELETE FROM `patient` WHERE nom='"+nom+"' and prenom='"+prenom+"'";
        QSqlQuery query ;
        query.exec(q);
        if(!query.lastError().isValid())
            res = true ;
        qDebug()<<q;
    }
    else
    {
        qDebug()<<"fail open database";
    }
    return res ;
}

QSqlQueryModel* GestionCabinetMedDAO::RechercherPatientDAO(QString nom, QString prenom)
{
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    QSqlQueryModel *model = new QSqlQueryModel();
    if(db.open())
    {
        qDebug()<<"Database is opened";
        QString query = "SELECT * from `patient` where nom=";
        query.append("'"+nom+"' and prenom='"+prenom+"'");
        qDebug()<<query ;
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("non"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("telephone"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_naissance"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("commentaire"));
     }
    else
    {
        qDebug()<<"fail open database";
    }
    return model;
}

int GestionCabinetMedDAO::AjoutRdvDAO(QString nom, QString prenom, QDate daterdv, QTime timerdv, QString comm)
{
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    int res = 0 ;
    if(db.open())
    {

        qDebug()<<"Database is opened";
        QString q0 = "SELECT daterdv, heurerdv FROM `rdv` WHERE daterdv='"+daterdv.toString("yyyy-MM-dd")+"' and heurerdv='"+timerdv.toString()+"'";
        QSqlQuery query0;
        qDebug()<<q0;
        query0.exec(q0);
        if(query0.numRowsAffected()==1)
            res=2;
        else if(query0.numRowsAffected()==0)
        {
            QString q = "SELECT id FROM `patient` WHERE nom='"+nom+"' and prenom='"+prenom+"'";
            QSqlQuery query(q) ;
            qDebug()<<q ;
            int id=0;
            if(query.first())
            {
                id = query.value(0).toInt();
            }
            if(id!=0)
            {
                QString date = daterdv.toString("yyyy:MM:dd");
                QString time = timerdv.toString();
                QString q1= "INSERT INTO `rdv`(`idpatient`, `daterdv`, `heurerdv`, `commentairerdv`) VALUES ('"+QString::number(id)+"','"+date+"','"+time+"','"+comm+"')";
                qDebug()<<q1 ;
                QSqlQuery query2 ;
                query2.exec(q1);
                if(!query2.lastError().isValid())
                {
                    res = 1;
                }
            }
        }
    }
    return res ;
}

bool GestionCabinetMedDAO::SupprimerRdvDAO(QDate daterdv, QTime timerdv)
{
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    bool res = false ;
    if(db.open())
    {
        qDebug()<<"Database is opened";
        QString q = "DELETE FROM `rdv` WHERE daterdv='"+daterdv.toString("yyyy-MM-dd")+"' and heurerdv='"+timerdv.toString()+"'";
        QSqlQuery query ;
        query.exec(q);
        qDebug()<<q;
        if(query.numRowsAffected()!=-1 && query.numRowsAffected()!=0)
            res = true ;
    }
    else
    {
        qDebug()<<"fail open database";
    }
    return res ;
}

QSqlQueryModel* GestionCabinetMedDAO::HistoriquePatientDAO(QString nom, QString prenom)
{
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    QSqlQueryModel *model = new QSqlQueryModel();
    if(db.open())
    {
        QString q = "SELECT id FROM `patient` WHERE nom='"+nom+"' and prenom='"+prenom+"'";
        QSqlQuery query(q) ;
        qDebug()<<q ;
        int id=0;
        if(query.first())
        {
            id = query.value(0).toInt();
        }
        if(id!=0)
        {
            QString q1 = "SELECT daterdv,heurerdv,commentairerdv FROM `rdv` WHERE idpatient='"+QString::number(id)+"'";
            qDebug()<<q1;
            model->setQuery(q1);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Date RDV"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Heure RDV"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Commentaire du RDV"));
        }
    }
    return model ;
}

QSqlQueryModel* GestionCabinetMedDAO::CalendrierAjourdhui()
{
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    QSqlQueryModel *model = new QSqlQueryModel();
    if(db.open())
    {
        qDebug()<<"Database is opened";
        QString q1 = "SELECT rdv.heurerdv,patient.nom,patient.prenom,rdv.commentairerdv FROM `rdv`, `patient` WHERE rdv.daterdv='"+QDate::currentDate().toString("yyyy-MM-dd")+"' and rdv.idpatient=patient.id";
        qDebug()<<q1 ;
        model->setQuery(q1);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Heure"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom Patient"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom Patient"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("commentaire"));
    }
    return model ;
}

QSqlQueryModel* GestionCabinetMedDAO::CalendrierMois()
{
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    QSqlQueryModel *model = new QSqlQueryModel();
    if(db.open())
    {
        qDebug()<<"Database is opened";
        QDate m = QDate::currentDate().addMonths(1);
        QString q1 = "SELECT rdv.daterdv,rdv.heurerdv,patient.nom,patient.prenom,rdv.commentairerdv FROM `rdv`, `patient` WHERE rdv.daterdv > '"+QDate::currentDate().toString("yyyy-MM-dd")+"' and rdv.daterdv <'"+m.toString("dd-MM-yyyy")+"' and rdv.idpatient=patient.id";
        qDebug()<<q1 ;
        model->setQuery(q1);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Jour"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Heure"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom Patient"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prenom Patient"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("commentaire"));
    }
    return model ;
}

QSqlQueryModel* GestionCabinetMedDAO::CalendrierPers(QDate d)
{
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(dbip);
    db.setDatabaseName(dbnom);
    db.setPassword(dbpass);
    db.setUserName(dbuser);
    QSqlQueryModel *model = new QSqlQueryModel();
    if(db.open())
    {
        qDebug()<<"Database is opened";
        QString q1 = "SELECT rdv.daterdv,rdv.heurerdv,patient.nom,patient.prenom,rdv.commentairerdv FROM `rdv`, `patient` WHERE rdv.daterdv > '"+QDate::currentDate().toString("yyyy-MM-dd")+"' and rdv.daterdv <'"+d.toString("yyyy-MM-dd")+"' and rdv.idpatient=patient.id";
        qDebug()<<q1 ;
        model->setQuery(q1);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Jour"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Heure"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom Patient"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prenom Patient"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("commentaire"));
    }
    return model ;
}
