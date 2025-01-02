#include "update_button.hpp"

UpdateButton::UpdateButton(QWidget* parent): QWidget{parent} {
    update.setText("update");
    layout.addWidget(new QWidget());
    layout.addWidget(&update);
    layout.addWidget(new QWidget());
    setLayout(&layout);
    connect(&update, SIGNAL(pressed()), this, SIGNAL(pressed()));
}
