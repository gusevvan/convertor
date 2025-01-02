#include <QWidget>
#include "../../model/exchange_rate_model.hpp"
#include "../../interface/convertor_gui/convertor_gui.hpp"
#include "../../core/convertor_core/convertor_core.hpp"

class Convertor: public QWidget {
Q_OBJECT
private:
    ConvertorGUI* GUI;
    ConvertorCore* core;
    ExchangeRateModel* model;

public:
    Convertor(QWidget* parent = nullptr);

    ~Convertor();
};
