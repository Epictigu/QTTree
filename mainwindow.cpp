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
    renderArea = new RenderArea(deltaX, deltaY);



    QGridLayout *mainLayout = new QGridLayout;

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
    test0 = calculateposition::positionen_eintragen(tree, deltaX, deltaY, 40, renderArea);
    renderArea->addKnot(test0);
    /*
    knotpos *test2 = new knotpos(210, 170, 40, 7);
    knotpos *test3 = new knotpos(310, 170, 40, 212);
    knotpos *test1 = new knotpos(260, 20, 40, 42, test2, test3);


    renderArea->addKnot(test2);
    renderArea->addKnot(test3);
    renderArea->addKnot(test1);
    */
    setWindowTitle(tr("QTTree"));

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 0, 0);
    setLayout(mainLayout);
}

RenderArea* MainWindow::getRenderArea(){
    return renderArea;
}

void MainWindow::penChanged()
{
    Qt::PenStyle style = Qt::PenStyle(Qt::SolidLine);
    Qt::PenCapStyle cap = Qt::PenCapStyle(Qt::FlatCap);
    Qt::PenJoinStyle join = Qt::PenJoinStyle(Qt::MiterJoin);
    renderArea->setPen(QPen(Qt::black, 2, style, cap, join));
}

void MainWindow::brushChanged()
{
   Qt::BrushStyle style = Qt::BrushStyle(Qt::SolidPattern);
   renderArea->setBrush(QBrush(Qt::gray, style));
}
