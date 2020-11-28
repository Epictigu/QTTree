#include "showknot.h"
#include "tree.h"
#include "renderarea.h"
#include "knotpos.h"
#include "calculateposition.h"
#include <QGridLayout>
#include <QComboBox>
#include <QScreen>
#include <QApplication>
#include <iostream>

ShowKnot::ShowKnot(struct TreeNode* tree)
{
    scene = new RenderArea(deltaX, deltaY, this);

    penChanged();
    brushChanged();

    knotpos *test0 = nullptr;
    test0 = calculateposition::positionen_eintragen(tree, deltaX, deltaY, 40, scene);
    test0->setSquare();
    test0->setColor(new QColor(Qt::yellow));
    scene->addKnot(test0);

    setWindowTitle(tr("QTTree"));

    setCentralWidget(scene->view);

    QRectF qrf = scene->sceneRect();
    QSize rec = qApp->screens()[0]->size();

    int width = qrf.width(); if(width > rec.width()) width = rec.width();
    int height = qrf.width(); if(height > rec.height() - QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight))  height = rec.height() - QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight);
    resize(width, height);
    setMinimumSize(width / 4, height / 4);

    int x = rec.width() - width; if(x != 0) x /= 2; if(x < 0) x = 0;
    int y = rec.height() - height; if(y != 0) y /= 2; if(y < 0) y = 0;
    move(x, y);
}

RenderArea* ShowKnot::getRenderArea(){
    return scene;
}

void ShowKnot::penChanged()
{
    Qt::PenStyle style = Qt::PenStyle(Qt::SolidLine);
    Qt::PenCapStyle cap = Qt::PenCapStyle(Qt::FlatCap);
    Qt::PenJoinStyle join = Qt::PenJoinStyle(Qt::MiterJoin);
    scene->setPen(QPen(Qt::black, 2, style, cap, join));
}

void ShowKnot::brushChanged()
{
   Qt::BrushStyle style = Qt::BrushStyle(Qt::SolidPattern);
   scene->setBrush(QBrush(Qt::gray, style));
}

ShowKnot* ShowKnot::display(struct TreeNode* tree){
    ShowKnot* s = new ShowKnot(tree);
    s->show();
    return s;
};
