#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QBoxLayout>
#include <QDoubleValidator>

class Multiplier: public QWidget {
Q_OBJECT
private:
    QLineEdit numberInput;
    QLineEdit numberOutput;
    qreal koeff;

public:
    Multiplier(QWidget* parent = nullptr);

public slots:
    void calculate(const QString& str);

    void setKoeff(qreal newKoeff);
};