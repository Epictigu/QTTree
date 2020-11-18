#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include "renderarea.h"
#include "knotpos.h"
#include <QGridLayout>
#include<QComboBox>

MainWindow::MainWindow()
{
    renderArea = new RenderArea;



    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);
    setLayout(mainLayout);

    penChanged();
    brushChanged();

    knotpos *test2 = new knotpos(210, 170, 40, 7);
    knotpos *test3 = new knotpos(310, 170, 40, 212);
    knotpos *test1 = new knotpos(260, 20, 40, 42, test2, test3);


    renderArea->addKnot(test2);
    renderArea->addKnot(test3);
    renderArea->addKnot(test1);

    setWindowTitle(tr("QTTree"));
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
