#pragma once
#include <QWidget>
#include <QMap>
#include <QString>
#include <QAbstractListModel>

class ExchangeRateModel: public QAbstractListModel {
Q_OBJECT
private:
    QMap<QString, qreal> exchangeRate;

public:
    ExchangeRateModel(const QMap<QString, qreal>& exchangeRate, QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int nRole) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    qreal currencyPrice(const QString& currency);

public slots:
    void updateExchangeRate(const QMap<QString, qreal>& exchangeRate);
};
