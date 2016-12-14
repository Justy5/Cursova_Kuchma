#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPaintEvent>
#include <QBrush>
#include <QEventLoop>
#include <conio.h>
#include <QThread>

#include <triangle.h>
#include <scena.h>
#include <frame.h>
#include <ball.h>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
public slots:

private slots:
    void slotBall();
private:
    Ui::Widget *ui;
    CustomScene  *scene;
    Triangle *triangle;
    Ball *ball;
    QTimer *WidballTimer;
};



#endif // WIDGET_H




