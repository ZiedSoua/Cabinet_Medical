#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include "ajoutclientvue.h"
#include "rechclientvue.h"
#include "supclientvue.h"
#include "ajoutrdvvue.h"
#include "suprdvvue.h"
#include "historiquevue.h"
#include "calendriervue.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots :
    void ClickCrClient();
    void ClickSupClient();
    void ClickRechClient();
    void ClickHistorique();
    void AjoutSuc(bool r ,QString nomp, QString prenomp);
    void SupSucc(bool r, QString nomp, QString prenomp);
    void RechpatientTermine(bool r);
    void HistTerm(bool r, QString n, QString p);
    void ClickAjoutRdv();
    void AjoutRdvSucc(int r, QDate d, QTime t);
    void ClickSupRdv();
    void SupRdv(bool r,QDate d,QTime t);
    void ClickCalendrier();
private:
    QPushButton *butCrClient;
    QPushButton *butSupClient;
    QPushButton *butRechClient;
    QPushButton *butCrRDV;
    QPushButton *butSupRDV;
    QPushButton *buthistoriquepatient;
    QPushButton *butcalendrier;
    AjoutClientVue *ajClientVue;
    RechClientVue *rchclientVue;
    SupClientVue *supClientVue;
    AjoutRdvVue *ajRDV;
    SupRdvVue *supRDVVue;
    HistoriqueVue *HistVue;
    CalendrierVue *CalVue ;
};

#endif // MAINWINDOW_H
