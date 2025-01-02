#pragma once
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class UpdateButton: public QWidget {
Q_OBJECT
private:
    QPushButton update;
    QHBoxLayout layout;
public:
    UpdateButton(QWidget* parent = nullptr);

signals:
    void pressed();
};