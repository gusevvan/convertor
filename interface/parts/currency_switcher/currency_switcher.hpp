#pragma once
#include <QWidget>
#include <QComboBox>
#include <QString>
#include <QAbstractItemModel>
#include <QHBoxLayout>

class CurrencySwitcher: public QWidget {
Q_OBJECT
private:
    QComboBox fromSwitch;
    QComboBox toSwitch;

public:
    CurrencySwitcher(QAbstractItemModel* model, QWidget* parent = nullptr);

signals:
    void fromSwitched(const QString& str);

    void toSwitched(const QString& str);

};
