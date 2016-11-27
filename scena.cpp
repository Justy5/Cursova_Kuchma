#include "scena.h"
#include <QPainter>
#include <QPixmap>


CustomScene::CustomScene(QObject *parent) :
    QGraphicsScene()
{
    Q_UNUSED(parent);


}

CustomScene::~CustomScene()
{

}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalTargetCoordinate(event->scenePos());
}
