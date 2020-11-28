#include "renderarea.h"
#include <QPainter>
#include <string>
#include <QTimeLine>
#include <QGraphicsSceneWheelEvent>
#include <windows.h>
#include <QGraphicsLineItem>
#include <QStyleOptionGraphicsItem>
#include <QApplication>
#include <QDesktopWidget>

int zFont = 2000;
int zCircle = 1000;
int zLine = 0;

RenderArea::RenderArea(int deltaX, int deltaY, QWidget *parent) : QGraphicsScene(parent)
{
    this->deltaX = deltaX;
    this->deltaY = deltaY;

    setSceneRect(0, 0, 200, 200);

    view = new QGraphicsView(this);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setRenderHint(QPainter::Antialiasing);
}

void RenderArea::wheelEvent(QGraphicsSceneWheelEvent *event){
    if(GetKeyState(VK_CONTROL) < 0){
        view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        static const double scaleFactor = 1.1;
        static double currentScale = 1.0;  // stores the current scale value.
        static const double scaleMin = .1; // defines the min scale limit.
        static const double scaleMax = 2.0;

        if(event->delta() > 0 && currentScale < scaleMax) {
            view->scale(scaleFactor, scaleFactor);
            currentScale *= scaleFactor;
        } else if (event->delta() < 0 && currentScale > scaleMin) {
            view->scale(1 / scaleFactor, 1 / scaleFactor);
            currentScale /= scaleFactor;
        }
    }
}

void RenderArea::addKnot(knotpos *knot){
    QBrush bC(brush);
    if(knot->getColor() != nullptr)
        bC.setColor((*knot->getColor()));
    else
        bC = brush;

    QAbstractGraphicsShapeItem *qE = nullptr;
    if(knot->getSquare())
        qE = addRect(knot->getX(),knot->getY(),knot->getSize()*2,knot->getSize()*2, pen, bC);
    else
        qE = addEllipse(knot->getX(),knot->getY(),knot->getSize()*2,knot->getSize()*2, pen, bC);
    qE->setZValue(zCircle++);

    QFont f("Calibri");
    f.setWeight(QFont::Bold);
    f.setPointSize(18);

    QGraphicsTextItem *text = addText(QString::number(knot->getValue()), f);
    text->setPos(knot->getSize() - QFontMetrics(f).size(Qt::TextSingleLine, QString::number(knot->getValue())).width() / 2 + knot->getX() - 4,
                 knot->getSize() - QFontMetrics(f).size(Qt::TextSingleLine, QString::number(knot->getValue())).height() / 2 + knot->getY() - 4);
    text->setZValue(zFont++);

    if(knot->getLeft() != nullptr)
        drawLine(knot, knot->getLeft());
    if(knot->getRight() != nullptr)
        drawLine(knot, knot->getRight());

    if(knot->getX() + knot->getSize()*2 + deltaX > width())
        setSceneRect(0, 0, knot->getX()+knot->getSize()*2 + deltaX, height());
    if(knot->getY() + knot->getSize()*2 + deltaY > height())
        setSceneRect(0, 0, width(), knot->getY()+knot->getSize()*2 + deltaY);
    update();
}


void RenderArea::drawLine(knotpos *pos1, knotpos *pos2){
    QGraphicsLineItem *qL = addLine(pos1->getX() + pos1->getSize(),
                     pos1->getY() + pos1->getSize(),
                     pos2->getX() + pos2->getSize(),
                     pos2->getY() + pos2->getSize());
    qL->setZValue(zLine++);
}


QSize RenderArea::sizeHint() const
{
    return QSize(width(), height());
}


void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

