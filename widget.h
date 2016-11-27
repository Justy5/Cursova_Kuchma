#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPaintEvent>
#include <QBrush>

#include <triangle.h>
#include <scena.h>
#include <ball.h>
#include <enemy.h>
#include <frame.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:


private:
    Ui::Widget *ui;
    CustomScene  *scene;
    Triangle *triangle;

};

#endif // WIDGET_H
