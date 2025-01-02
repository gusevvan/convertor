#include "convertor_gui.hpp"

ConvertorGUI::ConvertorGUI(ExchangeRateModel* model, QWidget* parent): QWidget{parent} {
    Multiplier* multiplier = new Multiplier{};
    CurrencySwitcher* switcher = new CurrencySwitcher{model};
    UpdateButton* updateButton = new UpdateButton{};
    KoeffCalculator* calculator = new KoeffCalculator{model};
    layout.addWidget(updateButton);
    layout.addWidget(switcher);
    layout.addWidget(multiplier);
    connect(switcher, SIGNAL(toSwitched(const QString&)), calculator, SLOT(setTo(const QString&)));
    connect(switcher, SIGNAL(fromSwitched(const QString&)), calculator, SLOT(setFrom(const QString&)));
    connect(calculator, SIGNAL(koeffChanged(qreal)), multiplier, SLOT(setKoeff(qreal)));
    connect(updateButton, SIGNAL(pressed()), this, SIGNAL(updateButtonPressed()));
    setLayout(&layout);
}