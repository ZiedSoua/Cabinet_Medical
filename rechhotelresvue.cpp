#include "rechhotelresvue.h"
#include <QGridLayout>

RechHotelResVue::RechHotelResVue(QWidget *parent) :
    QWidget(parent)
{
    view = new QTableView();
    QGridLayout *lay = new QGridLayout();
    lay->addWidget(view,0,0);
    this->setLayout(lay);
}

void RechHotelResVue::setModelTableView(QSqlQueryModel *m)
{
    view->setModel(m);
}

RechHotelResVue::~RechHotelResVue()
{
}
