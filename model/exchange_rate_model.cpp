#include "exchange_rate_model.hpp"

ExchangeRateModel::ExchangeRateModel(const QMap<QString, qreal>& exchangeRate, QObject* parent):
                                    QAbstractListModel{parent}, exchangeRate{exchangeRate} {}

QVariant ExchangeRateModel::data(const QModelIndex& index, int nRole) const {
    if (!index.isValid()) {
        return QVariant();
    }
    if (index.row() < 0 || index.row() >= exchangeRate.size()) {
        return QVariant();
    }
    return (nRole == Qt::DisplayRole || nRole == Qt::EditRole) ? exchangeRate.keys().at(index.row()) : QVariant();
}

int ExchangeRateModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return exchangeRate.size();
}

qreal ExchangeRateModel::currencyPrice(const QString& currency) {
    return exchangeRate.value(currency);
}

void ExchangeRateModel::updateExchangeRate(const QMap<QString, qreal>& exchangeRate) {
    this->exchangeRate = exchangeRate;
}
