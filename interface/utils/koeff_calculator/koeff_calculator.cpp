#include "koeff_calculator.hpp"

KoeffCalculator::KoeffCalculator(ExchangeRateModel* exchangeRateModel, QObject* parent):
                                 QObject{parent}, exchangeRateModel{exchangeRateModel} {}

void KoeffCalculator::setFrom(const QString& str) {
    from = str;
    emit calculateKoeff();
}

void KoeffCalculator::setTo(const QString& str) {
    to = str;
    emit calculateKoeff();
}

void KoeffCalculator::calculateKoeff() {
    emit koeffChanged(exchangeRateModel->currencyPrice(to) / exchangeRateModel->currencyPrice(from));
}