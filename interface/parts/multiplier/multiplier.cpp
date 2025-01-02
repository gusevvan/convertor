#include "multiplier.hpp"

Multiplier::Multiplier(QWidget* parent): QWidget{parent}, koeff{1} {
    QBoxLayout* layout = new QBoxLayout{QBoxLayout::LeftToRight};
    connect(&numberInput, SIGNAL(textChanged(const QString&)), this, SLOT(calculate(const QString&)));
    numberInput.setValidator(new QDoubleValidator(0, 1000, 2, this));
    numberInput.setText("0");
    numberOutput.setReadOnly(true);
    layout->addWidget(&numberInput);
    layout->addWidget(&numberOutput);
    setLayout(layout);
}

void Multiplier::calculate(const QString& str) {
    numberOutput.setText(QString::number(koeff * str.toDouble()));
}

void Multiplier::setKoeff(qreal newKoeff) {
    koeff = newKoeff;
    emit calculate(numberInput.text());
}