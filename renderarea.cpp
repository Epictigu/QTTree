#include "renderarea.h"
#include <QPainter>
#include <string>

RenderArea::RenderArea(int deltaX, int deltaY, QWidget *parent) : QWidget(parent)
{
    antialiased = true;
    transformed = false;

    this->deltaX = deltaX;
    this->deltaY = deltaY;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

void RenderArea::addKnot(knotpos *knot){
    knotList.push_back(knot);
    if(knot->getX() + knot->getSize()*2 + deltaX > width())
        resize(knot->getX()+knot->getSize()*2 + deltaX, height());
    if(knot->getY() + knot->getSize()*2 + deltaY > height())
        resize(width(), knot->getY()+knot->getSize()*2 + deltaY);
    repaint();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if(antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

    for(list<knotpos*>::iterator it = knotList.begin(); it != knotList.end(); it++){
        if((*it)->getLeft() != nullptr)
            drawLine(new QPainter(this), (*it), (*it)->getLeft());

        if((*it)->getRight() != nullptr)
            drawLine(new QPainter(this), (*it), (*it)->getRight());
    }

    for(list<knotpos*>::iterator it = knotList.begin(); it != knotList.end(); it++){
        painter.save();

        QRect rect((*it)->getX(), (*it)->getY(), (*it)->getSize() * 2, (*it)->getSize() * 2);
        painter.drawEllipse(rect);

        QFont font = painter.font();
        font.setPointSize(font.pointSize() * 2);
        painter.setFont(font);
        painter.drawText((*it)->getSize() - QFontMetrics(painter.font()).size(Qt::TextSingleLine, QString::number((*it)->getValue())).width() / 2 + (*it)->getX(),
                         (*it)->getSize() + QFontMetrics(painter.font()).size(Qt::TextSingleLine, QString::number((*it)->getValue())).height() / 2 + (*it)->getY() - 4,
                         QString::number((*it)->getValue()));
        font.setPointSize(font.pointSize() / 2);

        painter.restore();
    }


    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    painter.end();
}

void RenderArea::drawLine(QPainter *painter, knotpos *pos1, knotpos *pos2){
    painter->setPen(pen);
    painter->setBrush(brush);
    if(antialiased)
        painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawLine(pos1->getX() + pos1->getSize(),
                     pos1->getY() + pos1->getSize(),
                     pos2->getX() + pos2->getSize(),
                     pos2->getY() + pos2->getSize());
    painter->end();
}


QSize RenderArea::sizeHint() const
{
    return QSize(width(), height());
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
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

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
