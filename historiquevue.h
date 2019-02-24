#ifndef HISTORIQUEVUE_H
#define HISTORIQUEVUE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class HistoriqueVue : public QWidget
{
    Q_OBJECT

public:
    explicit HistoriqueVue(QWidget *parent = 0);
    ~HistoriqueVue();
public slots:
    void ClickHist();
signals:
    void HistoriqueTerm(bool r,QString n, QString p);
private:
    QPushButton *buthist ;
    QLineEdit *nomlineedit;
    QLineEdit *prenonlineedit;
};

#endif // HISTORIQUEVUE_H
