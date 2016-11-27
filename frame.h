#ifndef FRAME_H
#define FRAME_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsItem>
#include <QWidget>
#include <widget.h>

class Frame : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
     Frame(QWidget *parent = 0);
    ~Frame();
signals:

public slots:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
     QRectF boundingRect() const;
     QPixmap *lice;
};

#endif // FRAME_H
