#ifndef AJOUTCLIENTVUE_H
#define AJOUTCLIENTVUE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class AjoutClientVue : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutClientVue(QWidget *parent = 0);
    ~AjoutClientVue();
public slots :
    void ClickAjouter();
signals:
    void SucAjout(bool r,QString nomp, QString prenomp);
private:
    QPushButton *butval ;
    QLineEdit *nomlineedit;
    QLineEdit *datenaisslineedit;
    QLineEdit *prenomlineedit;
    QLineEdit *tellineedit;
    QTextEdit *comments;
};

#endif // AJOUTCLIENTVUE_H
