#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QPen>
#include <QWidget>
#include <list>
#include "knotpos.h"

using namespace std;

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);
    void addKnot(knotpos *knot);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawLine(QPainter *painter, knotpos *pos1, knotpos *pos2);

    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
    list<knotpos*> knotList;

};

#endif
