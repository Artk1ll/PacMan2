
#include "gameoptions.h"
#include "ui_gameoptions.h"
#include <QDebug>

gameOptions::gameOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameOptions)
{
    ui->setupUi(this);
}

gameOptions::~gameOptions()
{
    delete ui;
}

void gameOptions::on_pushButtonClient_clicked()
{
    emit setActiveWidget(CLIENT_WIDGET);
    connectionRole = CLIENT_ROLE;
}

void gameOptions::on_pushButtonServer_clicked()
{
    emit setActiveWidget(SERVER_WIDGET);
    connectionRole = SERVER_ROLE;
}

connectionRoleType gameOptions::getConnectionRole() const
{
    return connectionRole;
}

