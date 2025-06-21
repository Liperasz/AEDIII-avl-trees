//
// Created by liperasz on 21/06/25.
//

#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct element {

    int data;
    int height;
    struct element* left;
    struct element* right;

} Element;

typedef Element *AvlTree;

AvlTree* create_AVLTree();
void freeElement_AVLTree(Element *element);
void free_AVLTree(AvlTree *tree);
int insert_AVLTree(AvlTree *tree, int data);
int remove_AVLTree(AvlTree *tree, int data);
Element* findSmaller_AVLTree(Element *element);
void rotateLL_AVLTree(AvlTree *tree);
void rotateRR_AVLTree(AvlTree *tree);
void rotateLR_AVLTree(AvlTree *tree);
void rotateRL_AVLTree(AvlTree *tree);
int is_Empty_AVLTree(AvlTree *tree);
int height_AVLTree(AvlTree *tree);
int quantityElements_AVLTree(AvlTree *tree);
int consult_AVLTree(AvlTree *tree, int data);
void preOrder_AVLTree(AvlTree *tree);
void inOrder_AVLTree(AvlTree *tree);
void postOrder_AVLTree(AvlTree *tree);
int height_Element(Element *element);
int balance_Element(Element *element);
int bigger(int x, int y);
int verifyAVLTree(AvlTree *tree);

AvlTree* transform_AVLTree(AvlTree *tree);
int inserting_AVLTree(AvlTree *normaltree, AvlTree *avltree);

#endif //AVL_TREE_H
