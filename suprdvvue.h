#ifndef SUPRDVVUE_H
#define SUPRDVVUE_H

#include <QWidget>
#include <QDateEdit>
#include <QTimeEdit>
#include <QPushButton>

class SupRdvVue : public QWidget
{
    Q_OBJECT

public:
    explicit SupRdvVue(QWidget *parent = 0);
    ~SupRdvVue();
public slots :
    void ClickSup();
signals:
    void SupRdv(bool r , QDate d, QTime t);
private:
    QDateEdit *daterdv ;
    QTimeEdit *timerdv ;
    QPushButton *butsup;
};

#endif // SUPRDVVUE_H
