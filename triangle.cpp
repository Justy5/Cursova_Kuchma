#include "triangle.h"
#include <math.h>
#include <QDebug>
#include <QImage>
#include <QPainter>

static const double Pi = 3.14159265358979323846264338327950288419717;

Triangle::Triangle(QObject *parent) :  QObject(parent), QGraphicsItem()
{
    setRotation(0);
    gameTimer = new QTimer();

    spriteImage = new QPixmap(":/weapon");


    connect(gameTimer, &QTimer::timeout, this, &Triangle::slotGameTimer);
  //------------------------------------------------------------
    gameTimer->start(10);
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
    qDebug()<<kx<<"  "<<ky;
   //-------------------------------------------------

    Q_UNUSED(option);
    Q_UNUSED(widget);
}



void Triangle::slotGameTimer()
{
    if(GetAsyncKeyState('W')){
        this->setY(this->y() - 2);
        spriteImage = new QPixmap(":/weapon-up");
    }
    if(GetAsyncKeyState('A')){
        this->setX(this->x() - 2);
        spriteImage = new QPixmap(":/weapon-left");

    }
    if(GetAsyncKeyState('D')){
        this->setX(this->x() + 2);
        spriteImage = new QPixmap(":/weapon");

    }
    if(GetAsyncKeyState('S')){
        this->setY(this->y() + 2);
        spriteImage = new QPixmap(":/weapon-down");
    }

    if(this->x() < -250){
        this->setX(-250);
         kx = this->x();// зліва
    }
    if(this->x() > 247){
        this->setX(247);
         kx = this->x();// справа
    }

    if(this->y() < -185){
        this->setY(-185);
         ky = this->y();// зверху
    }
    if(this->y() > 247){
        this->setY(247);
         ky = this->y();// знизу
    }


}
