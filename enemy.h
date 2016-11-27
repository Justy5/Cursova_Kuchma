#define ENEMY_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPolygon>
#include <QTimer>

#include <windows.h>


class Enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent = 0);
    ~Enemy();

signals:
    // Сигнал для передачи координат положения курсора мыши
    void signalTargetCoordinate(QPointF point);

public slots:

private:
    // Функция, в которой производится отслеживание положения мыши
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

