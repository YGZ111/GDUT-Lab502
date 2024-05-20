#include "control_page.h"
#include "ui_control_page.h"

control_page::control_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::control_page)
{
    ui->setupUi(this);
}

control_page::~control_page()
{
    delete ui;
}
