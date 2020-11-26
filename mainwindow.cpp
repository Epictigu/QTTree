#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include "renderarea.h"
#include "knotpos.h"
#include "calculateposition.h"
#include <QGridLayout>
#include <QComboBox>
#include <QScreen>

MainWindow::MainWindow()
{
    scene = new RenderArea(deltaX, deltaY, this);

    penChanged();
    brushChanged();

    struct TreeNode* tree = NULL;
    srand (time(NULL));
    for (int i = 0; i < 100; i++) {
        int random = rand() % 1000;
        tree = tree::TreeInsert(tree, random, "Info zu Schluessel " + std::to_string(random));
    }

    knotpos *test0 = nullptr;
    test0 = calculateposition::positionen_eintragen(tree, deltaX, deltaY, 40, scene);
    scene->addKnot(test0);

    setWindowTitle(tr("QTTree"));

    setCentralWidget(scene->view);

    QRectF qrf = scene->sceneRect();
    QSize rec = qApp->screens()[0]->size();

    int x = rec.width() - qrf.width(); if(x != 0) x /= 2;
    int y = rec.height() - qrf.height(); if(y != 0) y /= 2;
    move(x, y);
}

RenderArea* MainWindow::getRenderArea(){
    return scene;
}

void MainWindow::penChanged()
{
    Qt::PenStyle style = Qt::PenStyle(Qt::SolidLine);
    Qt::PenCapStyle cap = Qt::PenCapStyle(Qt::FlatCap);
    Qt::PenJoinStyle join = Qt::PenJoinStyle(Qt::MiterJoin);
    scene->setPen(QPen(Qt::black, 2, style, cap, join));
}

void MainWindow::brushChanged()
{
   Qt::BrushStyle style = Qt::BrushStyle(Qt::SolidPattern);
   scene->setBrush(QBrush(Qt::gray, style));
}
