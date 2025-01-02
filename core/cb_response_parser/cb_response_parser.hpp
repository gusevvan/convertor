#pragma once
#include <QJsonObject>
#include <QJsonDocument>
#include <QObject>
#include <QMap>
#include <QString>

class CbResponseParser: public QObject {
Q_OBJECT
private:
    QJsonDocument responseDocument; 

    void pullOutBaseCurrency(QMap<QString, qreal>& exchangeRate);
    void pullOutExchangeRate(QMap<QString, qreal>& exchangeRate);
public:
    CbResponseParser(QObject* parent = nullptr);

public slots:
    void parse(const QString& response);

signals:
    void parsed(const QMap<QString, qreal>& varHash);

};
