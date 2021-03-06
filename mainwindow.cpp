#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameOptionsWidget = new gameOptions;
    gameWindowWidget = new gameWindow;
    serverWindowWidget = new serverWindow;
    clientwindowWidget = new clientwindow;

    gameWindowWidget->setGameServer(serverWindowWidget);
    gameWindowWidget->setGameClient(clientwindowWidget);

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(gameOptionsWidget);
    stackedWidget->addWidget(gameWindowWidget);
    stackedWidget->addWidget(serverWindowWidget);
    stackedWidget->addWidget(clientwindowWidget);

    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex(GAME_OPTION_WIDGET);

    connect(gameOptionsWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(clientwindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(serverWindowWidget, SIGNAL(setActiveWidget(int)), stackedWidget, SLOT(setCurrentIndex(int)));

    connect(stackedWidget, SIGNAL(currentChanged(int)), this, SLOT(stackedWidgetChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stackedWidgetChanged(int widgetNum)
{
    if (widgetNum == GAME_WIDGET)
    {
        gameWindowWidget->setConnectionRole(gameOptionsWidget->getConnectionRole());
        qDebug() << gameWindowWidget->getConnectionRole();
        gameWindowWidget->startGame();
    }
}



