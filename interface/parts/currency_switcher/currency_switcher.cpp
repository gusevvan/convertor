#include "currency_switcher.hpp"

CurrencySwitcher::CurrencySwitcher(QAbstractItemModel* model, QWidget* parent): QWidget{parent} {
    QHBoxLayout* layout = new QHBoxLayout;
    fromSwitch.setModel(model);
    layout->addWidget(&fromSwitch);
    layout->addWidget(new QWidget());
    toSwitch.setModel(model);
    layout->addWidget(&toSwitch);
    connect(&fromSwitch, SIGNAL(currentTextChanged(const QString&)), this, SIGNAL(fromSwitched(const QString&)));
    connect(&toSwitch, SIGNAL(currentTextChanged(const QString&)), this, SIGNAL(toSwitched(const QString&)));
    setLayout(layout);
}