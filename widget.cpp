#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <iostream>
#include <QDebug>
#include <QPainter>


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    //параметри вікна
    this->resize(720,600);
    this->setFixedSize(720,600);

    ui->setupUi(this);
    scene   = new CustomScene();    // Ініцілізуємо сцену

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по горизонтали

    scene->setSceneRect(-250,-250,500,500);   // розмір сцени

    scene->addLine(-270,-270, 270,-270, QPen(Qt::black));
    scene->addLine(-270, 270, 270, 270, QPen(Qt::black));
    scene->addLine(-270,-270,-270, 270, QPen(Qt::black));
    scene->addLine( 270,-270, 270, 270, QPen(Qt::black));
//------------------------------------------------------



//------------------------------------------------------
    Frame *frame;
    triangle = new Triangle();
    triangle->setPos(0,0);
    frame = new Frame();
    scene->addItem(frame);
    scene->addItem(triangle);
    WidballTimer = new QTimer();

    connect(WidballTimer, &QTimer::timeout, this, &Widget::slotBall);

    WidballTimer->start(500);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotBall()
{
    if(GetAsyncKeyState(VK_SPACE))
    {
            ball = new Ball(triangle);
            ball->setPos(triangle->x(),triangle->y());
            scene->addItem(ball);
     }

}

