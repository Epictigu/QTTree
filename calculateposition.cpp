#include "calculateposition.h"
/*
//für reduzierung von Parametern
void calculatePosition::positionen_eintragen(struct TreeNode* tree,int delta_x, int delta_y, int size, ){
    int konstanten[3];
    int[0} = delta_x
    int[1] = delta_y
    int[2] = int size
    positionen_berechnen(tree, konstaten, 0, 1)
}
*/
knotpos* calculatePosition::positionen_berechnen(struct TreeNode* tree, int delta_x, int delta_y, int size, int atm_x, int tiefe){
    knotpos *PosRight = nullptr, *PosLeft =nullptr;

    //an die linkeste Position
    //falls es kein links mehr gibt bleibt Pos links nullptr
    TreeNode* halter = tree->left;
    if(halter->left != nullptr){                                                      //ist links ein Knoten?
        PosLeft = positionen_berechnen(halter, delta_x, delta_y, size, atm_x, tiefe +1); //rekursion
    }

    //Mitte befindet sich rechts neben allen linken unterknoten.
    if(PosLeft != nullptr) {atm_x = PosLeft->getX();}
    //die neuen Position ist Delta x entfernt von nächsten Punkt entfernt
    atm_x = atm_x + delta_x;

    //wird mit der rechten Seite fortgeführt
    halter = tree->right;                                                             // recht durchgehen
    if(halter->right != nullptr){                                                     //ist links ein Knoten?
        PosRight = positionen_berechnen(halter, delta_x, delta_y, size, atm_x, tiefe +1); //rekursion
    }
    knotpos *me = new knotpos(tiefe * 2 * delta_y,atm_x, size, tree->key, PosLeft, PosRight);

    if (PosRight != nullptr) return PosRight;
    else return me;                                                                       //ich gebe meinem Vater meine position
}
