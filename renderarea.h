#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPen>
#include <QWidget>
#include <list>
#include "knotpos.h"
#include <QGraphicsView>

using namespace std;

class RenderArea : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit RenderArea(int deltaX, int deltaY, QWidget *parent = nullptr);

    QSize sizeHint() const;
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void addKnot(knotpos *knot);

    QGraphicsView *view;

protected:
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

private:
    void drawLine(knotpos *pos1, knotpos *pos2);

    QPen pen;
    QBrush brush;

    int deltaX;
    int deltaY;
};

#endif
