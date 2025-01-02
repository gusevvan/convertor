#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include "../../model/exchange_rate_model.hpp"
#include "../../interface/parts/update_button/update_button.hpp"
#include "../../interface/parts/multiplier/multiplier.hpp"
#include "../../interface/parts/currency_switcher/currency_switcher.hpp"
#include "../../interface/utils/koeff_calculator/koeff_calculator.hpp"

class ConvertorGUI: public QWidget {
Q_OBJECT
private:
    QVBoxLayout layout;
public:
    ConvertorGUI(ExchangeRateModel* model, QWidget* parent = nullptr);

signals:
    void updateButtonPressed();
};