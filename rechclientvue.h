#ifndef RECHCLIENTVUE_H
#define RECHCLIENTVUE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class RechClientVue : public QWidget
{
    Q_OBJECT

public:
    explicit RechClientVue(QWidget *parent = 0);
    ~RechClientVue();
public slots :
    void ClickRechercher();
signals:
    void Rechtermine(bool r);
private:
    QPushButton *butrech ;
    QLineEdit *nomlineedit;
    QLineEdit *prenonlineedit;
};

#endif // RECHCLIENTVUE_H
