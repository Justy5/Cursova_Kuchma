#include "frame.h"

Frame::Frame(QWidget *parent) : QObject(parent), QGraphicsItem()
{
     lice = new QPixmap(":/scena_pikcha");
     Q_UNUSED(parent);
}

Frame::~Frame()
{

}

QRectF Frame::boundingRect() const
{
    return QRectF(-260,-260,520,520);
}

void Frame::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter->drawPixmap(-280, -280, *lice);

     Q_UNUSED(option);
     Q_UNUSED(widget);

}
