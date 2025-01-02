#include "convertor.hpp"

Convertor::Convertor(QWidget* parent): QWidget{parent} {
    model = new ExchangeRateModel{{}};
    GUI = new ConvertorGUI{model, this};
    core = new ConvertorCore{model};
    QObject::connect(GUI, SIGNAL(updateButtonPressed()), core, SLOT(updateExchangeRate()));
    GUI->show();
}


Convertor::~Convertor() {
    delete GUI;
    delete model;
}
