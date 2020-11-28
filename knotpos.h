#ifndef KNOTPOS_H
#define KNOTPOS_H

#include <QColor>


class knotpos
{
public:
    knotpos(int x, int y, int size, int value);
    knotpos(int x, int y, int size, int value, knotpos *left, knotpos *right);
    int getX();
    int getY();
    int getSize();
    int getValue();

    knotpos *getLeft();
    knotpos *getRight();

    void setLeft(knotpos *k);
    void setRight(knotpos *k);

    void setSquare() {square = true;}
    void setColor(QColor *c) {color = c;}

    bool getSquare() {return square;}
    QColor *getColor() {return color;}
private:
    int x;
    int y;
    int size;
    int value;

    QColor *color = nullptr;
    bool square = false;

    knotpos *leftK;
    knotpos *rightK;
};

#endif
