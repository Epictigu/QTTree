#ifndef KNOTPOS_H
#define KNOTPOS_H


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
private:
    int x;
    int y;
    int size;
    int value;

    knotpos *leftK;
    knotpos *rightK;
};

#endif
