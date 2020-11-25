#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    RenderArea* getRenderArea();

private:
    void penChanged();
    void brushChanged();

    int deltaX = 100;
    int deltaY = 150;

    RenderArea *scene;

};
#endif // MAINWINDOW_H
