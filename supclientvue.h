#ifndef SUPCLIENTVUE_H
#define SUPCLIENTVUE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class SupClientVue : public QWidget
{
    Q_OBJECT

public:
    explicit SupClientVue(QWidget *parent = 0);
    ~SupClientVue();
public slots :
    void ClickSupprimer();
signals:
    void SupClientSucc(bool r ,QString pnom,QString pprenom);
private:
    QPushButton *butsup ;
    QLineEdit *nomlineedit;
    QLineEdit *prenomlineedit;
};

#endif // SUPCLIENTVUE_H
