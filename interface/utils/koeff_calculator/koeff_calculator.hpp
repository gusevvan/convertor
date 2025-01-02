#pragma once
#include <QWidget>
#include <QString>
#include "../../../model/exchange_rate_model.hpp"


class KoeffCalculator: public QObject {
Q_OBJECT
private:
    ExchangeRateModel* exchangeRateModel;
    QString from;
    QString to;
public:
    KoeffCalculator(ExchangeRateModel* exchangeRateModel, QObject* parent = nullptr);

public slots:
    void setFrom(const QString& str);

    void setTo(const QString& str);

    void calculateKoeff();

signals:
    void koeffChanged(qreal koeff);
};
