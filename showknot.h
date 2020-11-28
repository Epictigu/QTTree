#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ShowKnot; }
QT_END_NAMESPACE

class ShowKnot : public QMainWindow
{
    Q_OBJECT

public:
    ShowKnot(struct TreeNode* tree);
    RenderArea* getRenderArea();

    static ShowKnot* display(struct TreeNode* tree);

private:
    void penChanged();
    void brushChanged();

    int deltaX = 100;
    int deltaY = 150;

    RenderArea *scene;

};

#endif // MAINWINDOW_H
