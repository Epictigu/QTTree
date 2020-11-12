#include "renderarea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{

    antialiased = true;
    transformed = false;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    QRect rect(10, 10, 80, 80);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if(antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

    for(int x = 0; x < width(); x+=100){
        for(int y = 0; y < height(); y+=100){
            painter.save();
            painter.translate(x, y);

            if(transformed){
                painter.translate(50, 50);
                painter.rotate(60.0);
                painter.scale(0.6, 0.9);
                painter.translate(-50, -50);
            }

            painter.drawLine(50, 50, 50, 150);
            painter.drawLine(50, 50, 150, 50);
            painter.drawEllipse(rect);
            QFont font = painter.font();
            font.setPointSize(font.pointSize() * 2);
            painter.setFont(font);
            painter.drawText(QFontMetrics(painter.font()).size(Qt::TextSingleLine, "219").width(), 57, "219");

            painter.restore();
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}


QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
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
