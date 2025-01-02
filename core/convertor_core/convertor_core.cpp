#include "convertor_core.hpp"

ConvertorCore::ConvertorCore(ExchangeRateModel* model, QObject* parent): QObject{parent} {
    QSettings settings("convertor.conf", QSettings::IniFormat);
    requestSender.setCbUrl(settings.value("cbUrl").toString());
    QObject::connect(&requestSender, SIGNAL(replyHandled(const QString&)), &parser, SLOT(parse(const QString&)));
    QObject::connect(&parser, SIGNAL(parsed(const QMap<QString, qreal>&)),
                     model, SLOT(updateExchangeRate(const QMap<QString, qreal>&)));
}

void ConvertorCore::updateExchangeRate() {
    requestSender.sendRequest();
}
