#include "cb_response_parser.hpp"

CbResponseParser::CbResponseParser(QObject* parent): QObject{parent} {}

void CbResponseParser::parse(const QString& response) {
    responseDocument = QJsonDocument::fromJson(response.toUtf8());
    QMap<QString, qreal> exchangeRate;
    pullOutBaseCurrency(exchangeRate);
    pullOutExchangeRate(exchangeRate);
    emit parsed(exchangeRate);
}

void CbResponseParser::pullOutBaseCurrency(QMap<QString, qreal>& exchangeRate) {
    auto baseCurrency{responseDocument["base"].toString()};
    exchangeRate[baseCurrency] = 1;
}   

void CbResponseParser::pullOutExchangeRate(QMap<QString, qreal>& exchangeRate) {
    auto responseRates{responseDocument["rates"].toObject()};
    QVariantMap parsedRates{responseRates.toVariantMap()};
    for (auto currency: parsedRates.keys()) {
        exchangeRate[currency] = parsedRates[currency].toDouble();
    }
}