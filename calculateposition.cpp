#include "calculateposition.h"

//für reduzierung von Parametern
knotpos* calculateposition::positionen_eintragen(struct TreeNode* tree,int delta_x, int delta_y, int size, RenderArea* renderArea){
    int konstanten[3] {0};
    konstanten[0] = delta_x;
    konstanten[1] = delta_y;
    konstanten[2] = size;
    knotpos* start =nullptr;
    start = positionen_berechnen(tree, konstanten, 0, 1, renderArea);
    renderArea->addKnot(start);
    return start;
}

knotpos* calculateposition::positionen_berechnen(struct TreeNode* tree, int *konstanten, int atm, int tiefe, RenderArea* renderArea){

    knotpos *PosRight = nullptr, *PosLeft = nullptr;

    //an die linkeste Position
    //falls es kein links mehr gibt bleibt Pos links nullptr
    TreeNode* halter = tree->left;
    if(halter != nullptr){
        PosLeft = positionen_berechnen(halter, konstanten, atm,  tiefe +1, renderArea);
    }

    //Mitte befindet sich rechts neben allen linken unterknoten.
    if(PosLeft != nullptr) {atm = letzte_breite(PosLeft);}

    //die neuen Position ist Delta x entfernt von nächsten Punkt entfernt
    atm += konstanten[0];

    //wird mit der rechten Seite fortgeführt
    halter = tree->right;
    if(halter != nullptr){
       PosRight = positionen_berechnen(halter, konstanten, atm, tiefe +1, renderArea);
    }
    knotpos *me = new knotpos(atm, tiefe * konstanten[1], konstanten[2], tree->key, PosLeft, PosRight);
    renderArea->addKnot(me);


    return me;                                                                                          //ich gebe meinem Vater meine position
}

//finde den Punkt der auf der x- Achse am nächsten ist
int calculateposition::letzte_breite(knotpos* lead){
    int zaehler = lead->getX();
    if(lead->getRight() != nullptr){
        zaehler = letzte_breite(lead->getRight());
    }
    else return zaehler;

    return zaehler;
}
