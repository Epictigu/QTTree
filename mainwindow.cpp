#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include "renderarea.h"
#include "knotpos.h"
#include "calculateposition.h"
#include <QGridLayout>
#include <QComboBox>

MainWindow::MainWindow()
{
    scene = new RenderArea(deltaX, deltaY, this);

    penChanged();
    brushChanged();

    struct TreeNode* tree = NULL;
    tree = tree::TreeInsert(tree, 40, "Info zu Schluessel 40");
    tree = tree::TreeInsert(tree, 10, "Info zu Schluessel 10");
    tree = tree::TreeInsert(tree, 70, "Info zu Schluessel 70");
    tree = tree::TreeInsert(tree, 60, "Info zu Schluessel 60");
    tree = tree::TreeInsert(tree, 30, "Info zu Schluessel 30");
    tree = tree::TreeInsert(tree, 20, "Info zu Schluessel 20");
    tree = tree::TreeInsert(tree, 10, "Info zu Schluessel 10");

    knotpos *test0 = nullptr;
    test0 = calculateposition::positionen_eintragen(tree, deltaX, deltaY, 40, scene);
    scene->addKnot(test0);

    setWindowTitle(tr("QTTree"));

    setCentralWidget(scene->view);
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
