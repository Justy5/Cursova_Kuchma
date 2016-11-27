#include "triangle.h"
#include <math.h>
#include <QDebug>
#include <QImage>
#include <QPainter>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Triangle::Triangle(QObject *parent) :  QObject(parent), QGraphicsItem()
{
    setRotation(0);
    gameTimer = new QTimer();

    spriteImage = new QPixmap(":/untitled");


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
    return QRectF(-28,-28,56,57);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPolygon polygon;
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->drawPixmap(-30,-30,*spriteImage);
    polygon << QPoint(0,-30) << QPoint(20,30) << QPoint(-20,30);
    painter->drawPolygon(polygon);
    qDebug()<<kx<<"  "<<ky;
   //-------------------------------------------------

    Q_UNUSED(option);
    Q_UNUSED(widget);
}



void Triangle::slotGameTimer()
{

    if(GetAsyncKeyState('A')){
        this->setX(this->x() - 2);
        setRotation(270);
        kx = this->x();
    }
    if(GetAsyncKeyState('D')){
        this->setX(this->x() + 2);
        setRotation(90);
        kx = this->x();
    }
    if(GetAsyncKeyState('W')){
        this->setY(this->y() - 2);
        setRotation(0);
        ky = this->y();
    }
    if(GetAsyncKeyState('S')){
        this->setY(this->y() + 2);
        setRotation(180);
        ky = this->y();
    }

    if(this->x() < -250){
        this->setX(-250);
         kx = this->x();// зліва
    }
    if(this->x() > 250){
        this->setX(250);
         kx = this->x();// справа
    }

    if(this->y() < -250){
        this->setY(-250);
         ky = this->y();// зверху
    }
    if(this->y() > 250){
        this->setY(250);
         ky = this->y();// знизу
    }


}
