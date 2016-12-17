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
    int getPosit(){ return posit; }
    int triangleX(){ return this->x(); }
    int triangleY(){ return this->y(); }
    ~Triangle();
protected:
        QPixmap *spriteImage;
signals:
    void signalTargetCoordinate();
public slots:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QRectF boundingRect() const;


private slots:
    void slotGameTimer();

private:
    QTimer *gameTimer;
    QPointF target; 
    QPicture *Images;

    int posit;
    int rotation;
};

#endif // TRIANGLE_H
