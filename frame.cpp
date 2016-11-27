#include "frame.h"

Frame::Frame(QWidget *parent) : QObject(parent), QGraphicsItem()
{
     lice = new QPixmap(":/lice.jpg");
     Q_UNUSED(parent);
}

Frame::~Frame()
{

}

QRectF Frame::boundingRect() const
{
    return QRectF(-50,-50,500,500);
}

void Frame::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter->drawPixmap(-50, -50, *lice);

     Q_UNUSED(option);
     Q_UNUSED(widget);

}
