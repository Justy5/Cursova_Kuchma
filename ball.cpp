#include "ball.h"
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <QDebug>
#include <Windows.h>

Ball::Ball(Triangle *parent)
{
    kx = parent->x();
    ky = parent->y();
    ballTimer = new QTimer();
    ballImage = new QPixmap(":/sphere");
    positTriangle = parent->getPosit();
    connect(ballTimer,&QTimer::timeout,this,&Ball::slotBallTimer);
    ballTimer->start(0);
}

Ball::~Ball()
{
    delete this;
}

QRectF Ball::boundingRect() const
{
    return QRectF(-520,-520,520,520);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->setCompositionMode(QPainter::CompositionMode_Source);
    painter->drawPixmap(kx,ky,*ballImage);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ball::slotBallTimer()
{
            if(positTriangle==5)
            {
                this->setY(this->y() - 1);
                this->setX(this->x() - 1);
            }
            else
            {
                if(positTriangle==6)
                {
                    this->setY(this->y() - 1);
                    this->setX(this->x() + 1);
                }
                else
                {
                    if(positTriangle==7)
                    {
                        this->setY(this->y() + 1);
                        this->setX(this->x() - 1);
                    }
                    else
                    {
                        if(positTriangle==8)
                        {
                            this->setY(this->y() + 1);
                            this->setX(this->x() + 1);
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
}
