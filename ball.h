#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <iostream>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPolygon>
#include <QTimer>
#include <QBrush>
#include <QPixmap>
#include <QPicture>
#include <triangle.h>

class Ball : public Triangle
{
    Q_OBJECT
public:
    Ball(Triangle *parent);
    ~Ball();
public slots:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:
    void collisionDetected();///----------------
private slots:
    void slotBallTimer();

private:
    QRectF boundingRect() const;

    QTimer *ballTimer;
    QPointF target;
    QPixmap *ballImage;
    int positTriangle;
};

#endif // BALL_H
