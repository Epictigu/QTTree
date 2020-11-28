#include "showknot.h"
#include "tree.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    struct TreeNode* tree = NULL;
    srand (time(NULL));
    for (int i = 0; i < 10; i++) {
        int random = rand() % 100;
        tree = tree::TreeInsert(tree, random, "Info zu Schluessel " + std::to_string(random));
    }

    ShowKnot::display(tree);
    return a.exec();
}
