CONFIG += c++20

HEADERS += app/convertor/convertor.hpp \
           core/cb_request_sender/cb_request_sender.hpp \
           core/cb_response_parser/cb_response_parser.hpp \
           core/convertor_core/convertor_core.hpp \
           interface/convertor_gui/convertor_gui.hpp \
           interface/parts/currency_switcher/currency_switcher.hpp \
           interface/parts/multiplier/multiplier.hpp \
           interface/parts/update_button/update_button.hpp \
           interface/utils/koeff_calculator/koeff_calculator.hpp \
           model/exchange_rate_model.hpp

SOURCES += app/main.cpp \
           app/convertor/convertor.cpp \
           core/cb_request_sender/cb_request_sender.cpp \
           core/cb_response_parser/cb_response_parser.cpp \
           core/convertor_core/convertor_core.cpp \
           interface/convertor_gui/convertor_gui.cpp \
           interface/parts/currency_switcher/currency_switcher.cpp \
           interface/parts/multiplier/multiplier.cpp \
           interface/parts/update_button/update_button.cpp \
           interface/utils/koeff_calculator/koeff_calculator.cpp \
           model/exchange_rate_model.cpp

TARGET = convertor

QMAKE_CXXFLAGS += -Wall -Wextra

QT += core widgets network
