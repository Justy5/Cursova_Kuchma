#include "ball.h"
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <QDebug>
#include <Windows.h>

Ball::Ball(Triangle *triangle)
{

    kx = triangle->x();
    ky = triangle->y();
    ballTimer = new QTimer();
    ballImage = new QPixmap(":/sphere");
    positTriangle = triangle->getPosit();
    connect(ballTimer,&QTimer::timeout,this,&Ball::slotBallTimer);
    ballTimer->start(0);
}


QRectF Ball::boundingRect() const
{
    return QRectF(-1000,-1000,2000,2000);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->setCompositionMode(QPainter::CompositionMode_Source);
    painter->drawPixmap(0,0,*ballImage);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ball::slotBallTimer()
{
            if(positTriangle==5)
            {
                this->setY(this->y() - 2);
                this->setX(this->x() - 2);
            }
            else
            {
                if(positTriangle==6)
                {
                    this->setY(this->y() - 2);
                    this->setX(this->x() + 2);
                }
                else
                {
                    if(positTriangle==7)
                    {
                        this->setY(this->y() + 2);
                        this->setX(this->x() - 2);
                    }
                    else
                    {
                        if(positTriangle==8)
                        {
                            this->setY(this->y() + 2);
                            this->setX(this->x() + 2);
                        }
                        else
                        {
    //-------------------------------------------------------------------
                            if(positTriangle==1)
                            {
                                this->setY(this->y()-4);
                            }
                            else
                            {
                                if(positTriangle==2)
                                {
                                    this->setX(this->x()-4);
                                }
                                else
                                {
                                    if(positTriangle==3)
                                    {
                                        this->setX(this->x()+4);
                                    }
                                    else
                                    {
                                        if(positTriangle==4)
                                        {
                                            this->setY(this->y()+4);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            qDebug()<<"X = "<<this->x();
            qDebug()<<"Y = "<<this->y();
            if(this->x()<-250 || this->x()>250 || this->y()<-250 || this->y()>250)
                this->~Ball();

}
