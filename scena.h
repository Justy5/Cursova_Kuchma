#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CustomScene(QObject *parent = 0);
    ~CustomScene();

signals:

    void signalTargetCoordinate(QPointF point);

public slots:

private:

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMSCENE_H
