#pragma once
#include <QObject>
#include <QSettings>
#include "../../model/exchange_rate_model.hpp"
#include "../../core/cb_response_parser/cb_response_parser.hpp"
#include "../../core/cb_request_sender/cb_request_sender.hpp"

class ConvertorCore: public QObject {
Q_OBJECT
private:
    CbRequestSender requestSender;
    CbResponseParser parser;
public:
    ConvertorCore(ExchangeRateModel* model, QObject* parent = nullptr);

public slots:
    void updateExchangeRate();
};