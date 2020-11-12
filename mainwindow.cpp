#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include "renderarea.h"
#include <QGridLayout>
#include<QComboBox>

RenderArea *renderArea;

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

    setWindowTitle(tr("QTTree"));
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
