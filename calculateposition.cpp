#include "calculateposition.h"

//dynamisch mit Übergabewert, rekursiv
void calculatePosition::positionen_eintragen(struct TreeNode* tree){
    positionen_y(tree, 5, 1);
    positionen_x(tree, 5, 1);
}

//tiefe sollte an null starten 1
int calculatePosition::positionen_y(struct TreeNode* tree, int delta_y, int tiefe){
    if(tree->left != nullptr){
        positionen_y(tree->left, delta_y, tiefe + 1);
    }
    if(tree->right != nullptr){
        positionen_y(tree->right, delta_y, tiefe + 1);
    }
    // rueckgabe der y koordinate mit funktion
    knotpos posX = new knotpos(int x, int y, int size, int value, knotpos *left, knotpos *right);
    return tiefe * 2 * delta_y;
}

// atm sollte an 0 starten
int calculatePosition::positionen_x(struct TreeNode* tree, int delta_x, int atm){
    TreeNode* halter = tree->left;                                    //erst links durchgehen
    if(halter->left != nullptr){
        atm = positionen_x(halter, delta_x, atm);                    //gib positionen des letzten zurück
    }
    // rueckgabe der x koordinate mit funktion
    int xkoordinate = atm = 2*delta_x + atm;                            // ich muss zwischen links und recht liegen
    halter = tree->right;                                            // recht durchgehen
    if(halter->right != nullptr){
        positionen_x(halter, delta_x, atm);
        atm = (halter->xkoordinate)+ 2*delta_x;
    }
    return atm;                                                        //ich gebe meinem Vater meine position
}
