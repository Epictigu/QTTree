#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree::TreePrint(tree::TreeExample1());
}

MainWindow::~MainWindow()
{
    delete ui;
}

