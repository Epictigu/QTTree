#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

    RenderArea* getRenderArea();

private:
    void penChanged();
    void brushChanged();

    RenderArea *renderArea;

};
#endif // MAINWINDOW_H
