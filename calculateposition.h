#ifndef CALCULATEPOSITION_H
#define CALCULATEPOSITION_H

#include "tree.h"
#include "knotpos.h"

class calculatePosition
{
public:
    calculatePosition();
    void positionen_eintragen(struct TreeNode* tree);
    int positionen_y(struct TreeNode* tree, int delta_y, int tiefe);
    int positionen_x(struct TreeNode* tree, int delta_x, int atm);
};

#endif // CALCULATEPOSITION_H
