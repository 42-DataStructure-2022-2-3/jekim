#include "../includes/treeTester.h"

void testfield(void) {

    BSTNode rootNode;

    rootNode.data = 30;
    BinSearchTree *tree = makeBinSearchTree(rootNode);

    BSTNode *element = makeBSTNode(20);
    insert_loop(tree, *element);
    element->data = 40;
    insert_loop(tree, *element);
     element->data = 10;
    insert_loop(tree, *element);
     element->data = 24;
    insert_loop(tree, *element);
     element->data = 34;
    insert_loop(tree, *element);
     element->data = 46;
    insert_loop(tree, *element);
     element->data = 6;
    insert_loop(tree, *element);
     element->data = 14;
    insert_loop(tree, *element);
      element->data = 22;
    insert_loop(tree, *element);

    deleteBSTNode(tree, 24);
    deleteBSTNode(tree, 30);

    printTreeData_InOrder(tree->pRootNode);
}

int main(void) {
    testfield();
    return 0;
}
