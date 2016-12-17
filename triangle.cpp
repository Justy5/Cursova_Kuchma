#include "triangle.h"
#include <math.h>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QDebug>

static const double Pi = 3.14159265358979323846264338327950288419717;

Triangle::Triangle(QObject *parent) :  QObject(parent), QGraphicsItem()
{
    setRotation(0);
    gameTimer = new QTimer();
    posit = 3;
    spriteImage = new QPixmap(":/weapon");


    connect(gameTimer, &QTimer::timeout, this, &Triangle::slotGameTimer);
  //------------------------------------------------------------
    gameTimer->start(19);
    target = QPointF(0,0);
}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
    return QRectF(-28,-28,64,64);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->drawPixmap(-30,-30,*spriteImage);
   //-------------------------------------------------

    Q_UNUSED(option);
    Q_UNUSED(widget);
}



void Triangle::slotGameTimer()
{

    if(GetAsyncKeyState('W') && GetAsyncKeyState('A')){
        this->setY(this->y() - 3);
        this->setX(this->x() - 3);
        posit = 5;
    }
    else
    if(GetAsyncKeyState('W') && GetAsyncKeyState('D')){
        this->setY(this->y() - 3);
        this->setX(this->x() + 3);
        posit = 6;
    }
    else
    if(GetAsyncKeyState('S') && GetAsyncKeyState('A')){
        this->setY(this->y() + 3);
        this->setX(this->x() - 3);
        posit = 7;
    }
    else
    if(GetAsyncKeyState('S') && GetAsyncKeyState('D')){
        this->setY(this->y() + 3);
        this->setX(this->x() + 3);
        posit = 8;
    }
    else
//----------------------------------------------------------------
    if(GetAsyncKeyState('W')){
        this->setY(this->y() - 4);
        spriteImage = new QPixmap(":/weapon-up");
        posit = 1;
    }
    else
    if(GetAsyncKeyState('A')){
        this->setX(this->x() - 4);
        spriteImage = new QPixmap(":/weapon-left");
        posit = 2;
    }
    else
    if(GetAsyncKeyState('D')){
        this->setX(this->x() + 4);
        spriteImage = new QPixmap(":/weapon");
        posit = 3;
    }
    else
    if(GetAsyncKeyState('S')){
        this->setY(this->y() + 4);
        spriteImage = new QPixmap(":/weapon-down");
        posit = 4;
    }



    if(this->x() < -250){
        this->setX(-250);

    }

    if(this->x() > 247){
        this->setX(247);

    }

    if(this->y() < -185){
        this->setY(-185);

    }

    if(this->y() > 247){
        this->setY(247);

    }


}
