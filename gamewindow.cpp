#include "gamewindow.h"
#include "ui_gamewindow.h"

Tile tileArr[MAP_TILES_WIDTH * MAP_TILES_HEIGHT];


int nonWalkableMapTiles[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

gameWindow::gameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    int mapArr[MAP_TILES_WIDTH * MAP_TILES_HEIGHT]
           = {1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 13, 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 1 , 2 , 2 , 3 , 0 , 1 , 2 , 2 , 2 , 3 , 0 , 4 , 0 , 1 , 2 , 2 , 2 , 3 , 0 , 1 , 2 , 2 , 3 , 0 , 4 ,
              4 , 0 , 6 , 2 , 2 , 5 , 0 , 6 , 2 , 2 , 2 , 5 , 0 , 9 , 0 , 6 , 2 , 2 , 2 , 5 , 0 , 6 , 2 , 2 , 5 , 0 , 4 ,
              4 , 0 , 0 , 0 , 0 , 17, 0 , 17, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 17, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 10, 2 , 2 , 8 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 10, 2 , 2 , 8 , 0 , 4 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              6 , 2 , 2 , 2 , 2 , 3 , 0 , 4 , 4 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 4 , 4 , 0 , 1 , 2 , 2 , 2 , 2 , 5 ,
              0 , 0 , 0 , 0 , 0 , 4 , 18, 4 , 12, 2 , 8 , 17, 6 , 2 , 5 , 0 , 10, 2 , 14, 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 1 , 2 , 8 , 16, 10, 2 , 3 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              2 , 2 , 2 , 2 , 2 , 5 , 0 , 6 , 5 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 17, 6 , 5 , 0 , 6 , 2 , 2 , 2 , 2 , 2 ,
              0 , 0 , 0 , 0 , 0 , 0 , 0 , 17, 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
              2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 6 , 2 , 2 , 2 , 2 , 2 , 5 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 18, 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 4 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 4 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 ,
              1 , 2 , 2 , 2 , 2 , 5 , 0 , 6 , 5 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 6 , 5 , 0 , 6 , 2 , 2 , 2 , 2 , 3 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 1 , 2 , 2 , 3 , 17, 10, 2 , 2 , 8 , 0 , 6 , 2 , 5 , 0 , 10, 2 , 2 , 8 , 0 , 1 , 2 , 2 , 3 , 0 , 4 ,
              4 , 0 , 6 , 2 , 3 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 1 , 2 , 5 , 0 , 4 ,
              4 , 0 , 0 , 0 , 4 , 4 , 0 , 1 , 3 , 0 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 0 , 1 , 3 , 0 , 4 , 4 , 0 , 0 , 0 , 4 ,
              12, 2 , 8 , 0 , 6 , 5 , 0 , 4 , 4 , 0 , 6 , 2 , 3 , 0 , 1 , 2 , 5 , 0 , 4 , 4 , 0 , 6 , 5 , 0 , 10, 2 , 14 ,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 4 , 0 , 0 , 0 , 4 , 0 , 4 , 0 , 0 , 0 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              4 , 0 , 10, 2 , 2 , 2 , 2 , 11, 11, 2 , 8 , 0 , 6 , 2 , 5 , 0 , 10, 2 , 11, 11, 2 , 2 , 2 , 2 , 8 , 0 , 4,
              4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 ,
              6 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 5
            };


    QString pathImage;
    for(int i = 0; i < MAP_TILES_WIDTH * MAP_TILES_HEIGHT; i++)
    {
        switch(mapArr[i])
        {
            case 0:
                pathImage = ":/Images/white.png";
                break;
            case 1:
                pathImage = ":/Images/wall1.png";
                break;
            case 2:
                pathImage = ":/Images/wall2.png";
                break;
            case 3:
                pathImage = ":/Images/wall3.png";
                break;
            case 4:
                pathImage = ":/Images/wall4.png";
                break;
            case 5:
                pathImage = ":/Images/wall5.png";
                break;
            case 6:
                pathImage = ":/Images/wall6.png";
                break;
            case 7:
                pathImage = ":/Images/wall7.png";
                break;
            case 8:
                pathImage = ":/Images/wall8.png";
                break;
            case 9:
                pathImage = ":/Images/wall9.png";
                break;
            case 10:
                pathImage = ":/Images/wall10.png";
                break;
            case 11:
                pathImage = ":/Images/wall11.png";
                break;
            case 12:
                pathImage = ":/Images/wall12.png";
                break;
            case 13:
                pathImage = ":/Images/wall13.png";
                break;
            case 14:
                pathImage = ":/Images/wall14.png";
                break;
            case 15:
                pathImage = ":/Images/wall15.png";
                break;
            case 16:
              pathImage = ":/Images/fence.png";
              break;
            case 17:
                pathImage = ":/Images/rosekane_0.png";
                break;
            case 18:
                pathImage = ":/Images/superDot.png";
                break;
        }

        int x = i % MAP_TILES_WIDTH;
        int y = i / MAP_TILES_WIDTH;
        Tile currTile(pathImage, x * TILE_WIDTH, y * TILE_WIDTH);
        currTile.setTileType(mapArr[i]);
        tileArr[i] = currTile;
        scene->addItem(currTile.getPixmapItem());
    }

    pacman = new Pacman(":/Images/pacmanRight.png", 20, 20);
    scene->addItem(pacman->getPixmapItem());

    pacman2 = new Pacman(":/Images/pacmanRight.png", 500, 500);
    scene->addItem(pacman2->getPixmapItem());

    ghostRed = new Ghost(":/Images/ghostRedRight.png", 100, 80);
    scene->addItem(ghostRed->getPixmapItem());

    ghostBlue = new Ghost(":/Images/ghostBlueRight.png", 200, 400);
    scene->addItem(ghostBlue->getPixmapItem());

    ghostYellow = new Ghost(":/Images/ghostYellowRight.png", 400, 80);
    scene->addItem(ghostYellow->getPixmapItem());

    ghostGreen = new Ghost(":/Images/ghostGreenRight.png", 400, 100);
    scene->addItem(ghostGreen->getPixmapItem());

    pacman->setSpeed(10);
    pacman2->setSpeed(10);
    ghostBlue->setSpeed(30);

    ui->label_game_level_num->setText(QString::number(1));
}

void gameWindow::startGame()
{
    gameLoopTimer = new QTimer(this);
    connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));

    gameLoopTimer->start(10);

}

void gameWindow::restart()
{
    tileArr[113].setTileType(17);
    tileArr[113].setPixmap(":/Images/rosekane_0.png");
    tileArr[115].setTileType(17);
    tileArr[115].setPixmap(":/Images/rosekane_0.png");
    tileArr[124].setTileType(17);
    tileArr[124].setPixmap(":/Images/rosekane_0.png");
    tileArr[227].setTileType(17);
    tileArr[227].setPixmap(":/Images/rosekane_0.png");
    tileArr[314].setTileType(17);
    tileArr[314].setPixmap(":/Images/rosekane_0.png");
    tileArr[331].setTileType(17);
    tileArr[331].setPixmap(":/Images/rosekane_0.png");
    tileArr[546].setTileType(17);
    tileArr[546].setPixmap(":/Images/rosekane_0.png");


    pacman->setLocation(20, 20);
    pacman2->setLocation(500, 500);
    ghostRed->setLocation(100, 80);
    ghostBlue->setLocation(200, 400);
    ghostYellow->setLocation(400, 80);
    ghostGreen->setLocation(400, 100);

}


gameWindow::~gameWindow()
{
    delete ui;
}


void gameWindow::keyPressEvent(QKeyEvent *event)
{
    if(connectionRole == SERVER_ROLE)
    {
        if(event->key() == Qt::Key_A)
        {
            pacman->setDirection(DIRECTION_LEFT);
        }
        else if(event->key() == Qt::Key_D)
        {
            pacman->setDirection(DIRECTION_RIGHT);
        }
        else if(event->key() == Qt::Key_W)
        {
            pacman->setDirection(DIRECTION_UP);
        }
        else if(event->key() == Qt::Key_S)
        {
            pacman->setDirection(DIRECTION_DOWN);
        }
    }
    else if(connectionRole == CLIENT_ROLE)
    {
        if(event->key() == Qt::Key_A)
        {
            pacman2->setDirection(DIRECTION_LEFT);
        }
        else if(event->key() == Qt::Key_D)
        {
            pacman2->setDirection(DIRECTION_RIGHT);
        }
        else if(event->key() == Qt::Key_W)
        {
            pacman2->setDirection(DIRECTION_UP);
        }
        else if(event->key() == Qt::Key_S)
        {
            pacman2->setDirection(DIRECTION_DOWN);
        }
    }
}

void gameWindow::rotateImage(Actor *act)
{
    if(act->getDirection() == DIRECTION_LEFT)
    {
        act->setPixmap(":/Images/pacmanLeft.png");
    }
    else if(act->getDirection() == DIRECTION_RIGHT)
    {
        act->setPixmap(":/Images/pacmanRight.png");
    }
    else if(act->getDirection() == DIRECTION_UP)
    {
        act->setPixmap(":/Images/pacmanUp.png");
    }
    else if(act->getDirection() == DIRECTION_DOWN)
    {
        act->setPixmap(":/Images/pacmanDown.png");
    }
}

int gameWindow::checkIfMoveIsPossible(Actor *act, directionType direction)
{
    int currentTile;
    int *found;
    switch(direction)
    {
        case DIRECTION_LEFT:
            currentTile = tileArr[act->getTileIndexLeft()].getTileType();
            break;
        case DIRECTION_RIGHT:
            currentTile = tileArr[act->getTileIndexRight()].getTileType();
            break;
        case DIRECTION_UP:
            currentTile = tileArr[act->getTileIndexUp()].getTileType();
            break;
        case DIRECTION_DOWN:
            currentTile = tileArr[act->getTileIndexDown()].getTileType();
            break;
    }
    found = std::find(std::begin(nonWalkableMapTiles), std::end(nonWalkableMapTiles), currentTile);
    if(found == std::end(nonWalkableMapTiles))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void gameWindow::setGhostDirection(Ghost *ghost)
{
    if(ghost->getYPos() == pacman->getYPos())
    {
        if(ghost->getXPos() > pacman->getXPos())
        {
            ghost->setDirection(DIRECTION_LEFT);
        }
        else
        {
            ghost->setDirection(DIRECTION_RIGHT);
        }
    }

    if(ghost->getYPos() == pacman2->getYPos())
    {
        if(ghost->getXPos() > pacman2->getXPos())
        {
            ghost->setDirection(DIRECTION_LEFT);
        }
        else
        {
            ghost->setDirection(DIRECTION_RIGHT);
        }
    }

    else if(ghost->getXPos() == pacman2->getXPos())
    {
        if(ghost->getYPos() > pacman2->getYPos())
        {
            ghost->setDirection(DIRECTION_UP);
        }
        else
        {
            ghost->setDirection(DIRECTION_DOWN);
        }
    }

    else if(ghost->getXPos() == pacman->getXPos())
    {
        if(ghost->getYPos() > pacman->getYPos())
        {
            ghost->setDirection(DIRECTION_UP);
        }
        else
        {
            ghost->setDirection(DIRECTION_DOWN);
        }
    }
}

void gameWindow::moveActor(Actor *actor)
{
    switch(actor->getDirection())
    {
        case DIRECTION_LEFT:
           if(checkIfMoveIsPossible(actor, DIRECTION_LEFT))
            {
                actor->moveLeft();
            }
            break;
        case DIRECTION_RIGHT:
            if(checkIfMoveIsPossible(actor, DIRECTION_RIGHT))
            {
                actor->moveRight();
            }
            break;
        case DIRECTION_UP:
            if(checkIfMoveIsPossible(actor, DIRECTION_UP))
            {
                actor->moveUp();
            }
            break;
        case DIRECTION_DOWN:
            if(checkIfMoveIsPossible(actor, DIRECTION_DOWN))
            {
                actor->moveDown();
            }
            break;
        case DONT_MOVE:
            break;
    }
}

template <typename T>
void gameWindow::checkDot(T *pac)
{
    if( (tileArr[pac->getCurrTile()].getTileType() == 17) && (pac->getLastTile() != pac->getCurrTile()) )
    {
        pac->setPoints(pac->getPoints() + 1);
    }
}

void gameWindow::checkSuperDot(Pacman *pac)
{
    if( (tileArr[pac->getCurrTile()].getTileType() == 18) && (pac->getLastTile() != pac->getCurrTile()) )
    {
        pac->setSpeed(pac->getSpeed() - 5);
    }
}

void gameWindow::checkLevelFinish()
{
    int endCounter = 0;
    for(int i = 0; i < MAP_TILES_WIDTH * MAP_TILES_HEIGHT; i++)
    {
        if(tileArr[i].getTileType() == 17)
        {
            endCounter ++;
        }
    }

    if(endCounter == 0)
    {
        ui->label_game_level_num->setText(QString::number(ui->label_game_level_num->text().toInt() + 1));
        endCounter == 0;
        restart();
    }
}

void gameWindow::updateTileGraphics(Pacman *pac)
{
    if(tileArr[pac->getCurrTile()].getTileType() == 17)
    {
        tileArr[pac->getCurrTile()].setTileType(0);
        tileArr[pac->getCurrTile()].setPixmap(":/Images/white.png");
    }

    if(tileArr[pac->getCurrTile()].getTileType() == 18)
    {
        tileArr[pac->getCurrTile()].setTileType(0);
        tileArr[pac->getCurrTile()].setPixmap(":/Images/white.png");
    }
}

clientwindow *gameWindow::getGameClient() const
{
    return gameClient;
}

void gameWindow::setGameClient(clientwindow *value)
{
    gameClient = value;
}

void gameWindow::sendGameDataToClient(QByteArray string)
{
    gameServer->sendData(string);
}

void gameWindow::sendGameDataToServer(QByteArray string)
{
    gameClient->sendData(string);
}

connectionRoleType gameWindow::getConnectionRole() const
{
    return connectionRole;
}

void gameWindow::setConnectionRole(const connectionRoleType &value)
{
    connectionRole = value;
}

serverWindow *gameWindow::getGameServer() const
{
    return gameServer;
}

void gameWindow::setGameServer(serverWindow *value)
{
    gameServer = value;
}

void gameWindow::checkIfDead(Pacman *pac)
{
    if( (pac->getCurrTile() == ghostRed->getCurrTile() ) ||
        (pac->getCurrTile() == ghostBlue->getCurrTile() ) ||
        (pac->getCurrTile() == ghostGreen->getCurrTile() ) ||
        (pac->getCurrTile() == ghostYellow->getCurrTile() ) )
    {
        pac->setNumOfLifes(pac->getNumOfLifes() - 1);
        pac->setLocation(20, 20);
    }
}

void gameWindow::PackDataServerToClient()
{
    QByteArray arr;
    arr.resize(28);

    quint16 pacmanxpos = static_cast<quint16>(pacman->getXPos());
    quint16 pacmanypos = static_cast<quint16>(pacman->getYPos());
    quint16 pacman2xpos = static_cast<quint16>(pacman2->getXPos());
    quint16 pacman2ypos = static_cast<quint16>(pacman2->getYPos());
    quint16 ghostRedxpos = static_cast<quint16>(ghostRed->getXPos());
    quint16 ghostRedypos = static_cast<quint16>(ghostRed->getYPos());
    quint16 ghostBluexpos = static_cast<quint16>(ghostBlue->getXPos());
    quint16 ghostBlueypos = static_cast<quint16>(ghostBlue->getYPos());
    quint16 ghostGreenxpos = static_cast<quint16>(ghostGreen->getXPos());
    quint16 ghostGreenypos = static_cast<quint16>(ghostGreen->getYPos());
    quint16 ghostYellowxpos = static_cast<quint16>(ghostYellow->getXPos());
    quint16 ghostYellowypos = static_cast<quint16>(ghostYellow->getYPos());

    arr[0] = pacman->getDirection();
    arr[1] = pacmanxpos >> 8;
    arr[2] = static_cast<quint8>(pacmanxpos);
    arr[3] = pacmanypos >> 8;
    arr[4] = static_cast<quint8>(pacmanypos);
    arr[5] = pacman2xpos >> 8;
    arr[6] = static_cast<quint8>(pacman2xpos);
    arr[7] = pacman2ypos >> 8;
    arr[8] = static_cast<quint8>(pacman2ypos);
    arr[9] = ghostRedxpos >> 8;
    arr[10] = static_cast<quint8>(ghostRedxpos);
    arr[11] = ghostRedypos >> 8;
    arr[12] = static_cast<quint8>(ghostRedypos);
    arr[13] = ghostBluexpos >> 8;
    arr[14] = static_cast<quint8>(ghostBluexpos);
    arr[15] = ghostBlueypos >> 8;
    arr[16] = static_cast<quint8>(ghostBlueypos);
    arr[17] = ghostGreenxpos >> 8;
    arr[18] = static_cast<quint8>(ghostGreenxpos);
    arr[19] = ghostGreenypos >> 8;
    arr[20] = static_cast<quint8>(ghostGreenypos);
    arr[21] = ghostYellowxpos >> 8;
    arr[22] = static_cast<quint8>(ghostYellowxpos);
    arr[23] = ghostYellowypos >> 8;
    arr[24] = static_cast<quint8>(ghostYellowypos);
    arr[25] = pacman->getNumOfLifes();
    arr[26] = pacman2->getNumOfLifes();
    arr[27] = pacman->getPoints();
    arr[28] = pacman2->getPoints();

    sendGameDataToClient(arr);
}

void gameWindow::UnpackDataServerToClient()
{
    QByteArray arr;
    arr.resize(28);

    arr = gameClient->getReceivedData();

    pacman->setDirection(static_cast<quint8>(arr[0]));

    quint16 recPacmanxPos = 0;
    recPacmanxPos |= static_cast<quint8>(arr[1]) << 8;
    recPacmanxPos |= static_cast<quint8>(arr[2]);
    pacman->setXPos(recPacmanxPos);

    quint16 recPacmanyPos = 0;
    recPacmanyPos |= static_cast<quint8>(arr[3]) << 8;
    recPacmanyPos |= static_cast<quint8>(arr[4]);
    pacman->setYPos(recPacmanyPos);

    quint16 recPacman2xPos = 0;
    recPacman2xPos |= static_cast<quint8>(arr[5]) << 8;
    recPacman2xPos |= static_cast<quint8>(arr[6]);
    pacman2->setXPos(recPacman2xPos);

    quint16 recPacman2yPos = 0;
    recPacman2yPos |= static_cast<quint8>(arr[7]) << 8;
    recPacman2yPos |= static_cast<quint8>(arr[8]);
    pacman2->setYPos(recPacman2yPos);

    quint16 ghostRedxPos = 0;
    ghostRedxPos |= static_cast<quint8>(arr[9]) << 8;
    ghostRedxPos |= static_cast<quint8>(arr[10]);
    ghostRed->setXPos(ghostRedxPos);

    quint16 ghostRedyPos = 0;
    ghostRedyPos |= static_cast<quint8>(arr[11]) << 8;
    ghostRedyPos |= static_cast<quint8>(arr[12]);
    ghostRed->setYPos(ghostRedyPos);

    quint16 ghostBluexPos = 0;
    ghostBluexPos |= static_cast<quint8>(arr[13]) << 8;
    ghostBluexPos |= static_cast<quint8>(arr[14]);
    ghostBlue->setXPos(ghostBluexPos);

    quint16 ghostBlueyPos = 0;
    ghostBlueyPos |= static_cast<quint8>(arr[15]) << 8;
    ghostBlueyPos |= static_cast<quint8>(arr[16]);
    ghostBlue->setYPos(ghostBlueyPos);

    quint16 ghostGreenxPos = 0;
    ghostGreenxPos |= static_cast<quint8>(arr[17]) << 8;
    ghostGreenxPos |= static_cast<quint8>(arr[18]);
    ghostGreen->setXPos(ghostGreenxPos);

    quint16 ghostGreenyPos = 0;
    ghostGreenyPos |= static_cast<quint8>(arr[19]) << 8;
    ghostGreenyPos |= static_cast<quint8>(arr[20]);
    ghostGreen->setYPos(ghostGreenyPos);

    quint16 ghostYellowxPos = 0;
    ghostYellowxPos |= static_cast<quint8>(arr[21]) << 8;
    ghostYellowxPos |= static_cast<quint8>(arr[22]);
    ghostYellow->setXPos(ghostYellowxPos);

    quint16 ghostYellowyPos = 0;
    ghostYellowyPos |= static_cast<quint8>(arr[23]) << 8;
    ghostYellowyPos |= static_cast<quint8>(arr[24]);
    ghostYellow->setYPos(ghostYellowyPos);

    pacman->setNumOfLifes(static_cast<quint8>(arr[25]));
    pacman2->setNumOfLifes(static_cast<quint8>(arr[26]));

    pacman->setPoints(static_cast<quint8>(arr[27]));
    pacman2->setPoints(static_cast<quint8>(arr[28]));
}

void gameWindow::PackDataClientToServer()
{
    QByteArray arr;
    arr.resize(1);

    arr[0] = pacman2->getDirection();
    sendGameDataToServer(arr);
}

void gameWindow::UnpackDataClientToServer()
{
    QByteArray arr;
    arr.resize(1);

    arr = gameServer->getReceivedData();
    pacman2->setDirection(static_cast<quint8>(arr[0]));
}

void gameWindow::gameLoop(void)
{
    if(connectionRole == CLIENT_ROLE)
    {
        UnpackDataServerToClient();
        PackDataClientToServer();
    }

    gameLoopCounterPacman++;
    gameLoopCounterPacman2++;
    gameLoopCounterGhost++;

    pacman->updateCurrTile();
    pacman2->updateCurrTile();
    ghostBlue->updateCurrTile();
    ghostRed->updateCurrTile();
    ghostGreen->updateCurrTile();
    ghostYellow->updateCurrTile();

    ui->label_lifes_num->setText(QString::number(pacman->getNumOfLifes()));
    ui->label_points->setText(QString::number(pacman->getPoints()));

    ui->label_lifes_num_2->setText(QString::number(pacman2->getNumOfLifes()));
    ui->label_points_2->setText(QString::number(pacman2->getPoints()));

    if(connectionRole == SERVER_ROLE)
    {
        checkIfDead(pacman);
        checkIfDead(pacman2);

        checkDot(pacman);
        checkDot(pacman2);

        checkSuperDot(pacman);
        checkSuperDot(pacman2);
    }

    updateTileGraphics(pacman);
    updateTileGraphics(pacman2);


    rotateImage(pacman);
    rotateImage(pacman2);

    if(gameLoopCounterPacman > pacman->getSpeed())
    {
        if(connectionRole == SERVER_ROLE)
        {
            moveActor(pacman);
        }
        pacman->setDirection(DONT_MOVE);
        pacman->updatePos();
        pacman->setLastTile(pacman->getCurrTile());
        gameLoopCounterPacman = 0;
    }

    if(gameLoopCounterPacman2 > pacman2->getSpeed())
    {
        if(connectionRole == SERVER_ROLE)
        {
            moveActor(pacman2);
        }
        pacman2->setDirection(DONT_MOVE);
        pacman2->updatePos();
        pacman2->setLastTile(pacman->getCurrTile());
        gameLoopCounterPacman2 = 0;
    }

    if(gameLoopCounterGhost > ghostBlue->getSpeed())
    {
        setGhostDirection(ghostRed);
        setGhostDirection(ghostBlue);
        setGhostDirection(ghostGreen);
        setGhostDirection(ghostYellow);

        if(connectionRole == SERVER_ROLE)
        {
            moveActor(ghostRed);
            moveActor(ghostBlue);
            moveActor(ghostGreen);
            moveActor(ghostYellow);
        }
        ghostRed->updatePos();
        ghostBlue->updatePos();
        ghostGreen->updatePos();
        ghostYellow->updatePos();
        gameLoopCounterGhost = 0;
    }

    checkLevelFinish();

    if(connectionRole == SERVER_ROLE)
    {
        UnpackDataClientToServer();
        PackDataServerToClient();
    }

    scene->update();
}


