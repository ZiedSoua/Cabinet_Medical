#ifndef RECHHOTELRESVUE_H
#define RECHHOTELRESVUE_H

#include <QWidget>
#include <QTableView>
#include <QtSql/QtSql>

class RechHotelResVue : public QWidget
{
    Q_OBJECT

public:
    explicit RechHotelResVue(QWidget *parent = 0);
    void setModelTableView(QSqlQueryModel *m);
    ~RechHotelResVue();

private:
    QTableView *view;
};

#endif // RECHHOTELRESVUE_H
