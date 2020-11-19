#include "knotpos.h"

knotpos::knotpos(int x, int y, int size, int value)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->value = value;

    this->leftK = nullptr;
    this->rightK = nullptr;
}

knotpos::knotpos(int x, int y, int size, int value, knotpos *left, knotpos *right)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->value = value;

    this->leftK = left;
    this->rightK = right;
}

int knotpos::getX(){
    return x;
}

int knotpos::getY(){
    return y;
}

int knotpos::getSize(){
    return size;
}

int knotpos::getValue(){
    return value;
}

knotpos* knotpos::getLeft(){
    return leftK;
}

knotpos* knotpos::getRight(){
    return rightK;
}

void knotpos::setLeft(knotpos *k){
    leftK = k;
}

void knotpos::setRight(knotpos *k){
    rightK = k;
}
