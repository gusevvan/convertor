#include <QApplication>
#include "convertor/convertor.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    Convertor convertor;
    convertor.show();
    app.exec();
}
