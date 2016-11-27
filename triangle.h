#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPolygon>
#include <QTimer>
#include <QBrush>
#include <QPixmap>
#include <QPicture>


#include <windows.h>

class Triangle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Triangle(QObject *parent = 0);
    QPixmap* getSpriteImage(){ return spriteImage; }
    ~Triangle();

signals:
    void signalTargetCoordinate();
public slots:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QRectF boundingRect() const;
    int kx,ky;

private slots:
    void slotGameTimer();

private:
    QTimer *gameTimer;
    QPointF target;
    QPixmap *spriteImage;
    QPicture *Images;

    int rotation;
};

#endif // TRIANGLE_H
