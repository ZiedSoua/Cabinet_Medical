#ifndef CALENDRIERVUE_H
#define CALENDRIERVUE_H

#include <QWidget>
#include <QPushButton>
#include <QDateEdit>
#include <QRadioButton>

class CalendrierVue : public QWidget
{
    Q_OBJECT

public:
    explicit CalendrierVue(QWidget *parent = 0);
    ~CalendrierVue();
public slots:
    void Clickpers();
    void Clickjour();
    void Clickmois();
    void ClickValider();

private:
    QPushButton *butjour;
    QPushButton *butmois;
    QDateEdit *datepers ;
    QRadioButton *pers ;
    QPushButton *butvalider;
};

#endif // CALENDRIERVUE_H
