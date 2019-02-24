#ifndef AJOUTRDVVUE_H
#define AJOUTRDVVUE_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDateTimeEdit>

class AjoutRdvVue : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutRdvVue(QWidget *parent = 0);
    ~AjoutRdvVue();
public slots:
    void ClickAjout();
signals:
    void AjoutRdvSucc(int r, QDate d, QTime t);
private:
    QLineEdit *nompatient;
    QLineEdit *prenompatient;
    QTextEdit *comment ;
    QDateEdit *daterdv ;
    QTimeEdit *timerdv ;
    QPushButton *butajout;
};

#endif // AJOUTRDVVUE_H
