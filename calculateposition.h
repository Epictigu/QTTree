#ifndef CALCULATEPOSITION_H
#define CALCULATEPOSITION_H

#include "tree.h"
#include "knotpos.h"

class calculatePosition
{
public:
    calculatePosition();
    void positionen_eintragen(struct TreeNode* tree);
    knotpos* positionen_berechnen(struct TreeNode* tree, int delta_x, int delta_y, int size, int atm_x, int tiefe);
};

#endif // CALCULATEPOSITION_H
