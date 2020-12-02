#ifndef CALCULATEPOSITION_H
#define CALCULATEPOSITION_H

#include "tree.h"
#include "knotpos.h"
#include "renderarea.h"
#include "showknot.h"

/**
 * @brief Klasse zum Berechnen der Positionen.
 */
class calculateposition
{
public:
    calculateposition();
    static knotpos *positionen_eintragen(struct TreeNode* tree,int delta_x, int delta_y, RenderArea* renderArea);
private:
    static knotpos *positionen_berechnen(struct TreeNode* tree, int *konstanten, int tiefe, int atm_x, RenderArea* renderArea);
    static int letzte_breite(knotpos* lead);
    static int dynamische_groesse(int tiefe, int size);
    static int dynamische_hoehe(int tiefe, int delta_y);
};

#endif // CALCULATEPOSITION_H
