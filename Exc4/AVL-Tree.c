//
// Created by liperasz on 20/06/25.
//

#include "AVL-Tree.h"
#include <stdlib.h>
#include <stdio.h>

AvlTree* create_AVLTree() {

    AvlTree* tree = (AvlTree*) malloc(sizeof(AvlTree));
    if (tree != NULL) {
        *tree = NULL;
    }
    return tree;

}

void freeElement_AVLTree(Element *element) {

    if (element == NULL) {
        return;
    }
    freeElement_AVLTree(element->left);
    freeElement_AVLTree(element->right);
    free(element);
    element = NULL;
}

void free_AVLTree(AvlTree *tree) {

    if (tree == NULL) {
        return;
    }
    freeElement_AVLTree(*tree);
    free(tree);
}

int insert_AVLTree(AvlTree *tree, int data) {

    if (*tree == NULL) {
        Element *newElement = (Element *) malloc(sizeof(Element));
        if (newElement == NULL) {
            return 0;
        }

        newElement->data = data;
        newElement->height = 0;
        newElement->left = NULL;
        newElement->right = NULL;
        *tree = newElement;
    }

    if (data < (*tree)->data) {
        if (insert_AVLTree(&(*tree)->left, data)) {
            if (balance_Element(*tree) >= 2) {
                if (data < (*tree)->left->data) {
                    rotateLL_AVLTree(tree);
                }
                else {
                    rotateLR_AVLTree(tree);
                }
            }
        }
    }

    else if (data > (*tree)->data) {
        if (insert_AVLTree(&(*tree)->right, data)) {
            if (balance_Element(*tree) >= 2) {
                if (data > (*tree)->right->data) {
                    rotateRR_AVLTree(tree);
                }
                else {
                    rotateRL_AVLTree(tree);
                }
            }
        }
    }

    else {
        return 0;
    }

    (*tree)->height = bigger(height_Element((*tree)->left), height_Element((*tree)->right)) + 1;

    return 1;
}


int remove_AVLTree(AvlTree *tree, int data) {

    if (is_Empty_AVLTree(tree)) {
        return 0;
    }

    if (data < (*tree)->data) {
        if (remove_AVLTree(&(*tree)->left, data)) {
            if (balance_Element(*tree) >= 2) {
                if (height_Element((*tree)->right->left) <= height_Element((*tree)->right->right)) {
                    rotateRR_AVLTree(tree);
                }
                else {
                    rotateRL_AVLTree(tree);
                }
            }
        }
    }

    if (data > (*tree)->data) {
        if (remove_AVLTree(&(*tree)->right, data)) {
            if (balance_Element(*tree) >= 2) {
                if (height_Element((*tree)->left->right) <= height_Element((*tree)->left->left)) {
                    rotateLL_AVLTree(tree);
                }
                else {
                    rotateLR_AVLTree(tree);
                }
            }
        }
    }

    if ((*tree)->data == data) {

        if(((*tree)->left == NULL || (*tree)->right == NULL)) {

            Element *oldElement = (*tree);
            if((*tree)->left != NULL) {
                *tree = (*tree)->left;
            }
            else {
                *tree = (*tree)->right;
            }
            free(oldElement);

        } else {

            Element *element = findSmaller_AVLTree((*tree)->right);
            (*tree)->data = element->data;
            remove_AVLTree(&(*tree)->right, (*tree)->data);
            if(balance_Element(*tree) >= 2){
                if(height_Element((*tree)->left->right) <= height_Element((*tree)->left->left))
                    rotateLL_AVLTree(tree);
                else
                    rotateLR_AVLTree(tree);
            }
        }
        if (*tree != NULL)
            (*tree)->height = bigger(height_Element((*tree)->left),height_Element((*tree)->right)) + 1;
        return 1;
    }

}

Element* findSmaller_AVLTree(Element *element) {

    Element *element1 = element;
    Element *element2 = element->left;

    while (element2 != NULL) {
        element1 = element2;
        element2 = element2->left;
    }

    return element1;

}

void rotateLL_AVLTree(AvlTree *tree) {

    Element *element = (*tree)->left;
    (*tree)->left = element->right;
    element->right = *tree;
    (*tree)->height = bigger(height_Element((*tree)->left), height_Element((*tree)->right)) + 1;
    element->height = bigger(height_Element(element->left), (*tree)->height) + 1;
    *tree = element;
}

//É o espelho da função LL, sem segredo.
void rotateRR_AVLTree(AvlTree *tree) {

    Element *element = (*tree)->right;
    (*tree)->right = element->left;
    element->left = *tree;
    (*tree)->height = bigger(height_Element((*tree)->left), height_Element((*tree)->right)) + 1;
    element->height = bigger(height_Element(element->right), (*tree)->height) + 1;
    *tree = element;

}


void rotateLR_AVLTree(AvlTree *tree) {

    rotateRR_AVLTree(&(*tree)->left);
    rotateLL_AVLTree(tree);

}

void rotateRL_AVLTree(AvlTree *tree) {

    rotateLL_AVLTree(&(*tree)->right);
    rotateRR_AVLTree(tree);

}

int is_Empty_AVLTree(AvlTree *tree) {

    if (tree == NULL || *tree == NULL) {
        return 1;
    }
    return 0;
}

int height_AVLTree(AvlTree *tree) {

    if (is_Empty_AVLTree(tree)) {
        return 0;
    }

    int left_height = height_AVLTree(&(*tree)->left);
    int right_height = height_AVLTree(&(*tree)->right);

    if (left_height > right_height) {
        return left_height + 1;
    }
    return right_height + 1;
}

int quantityElements_AVLTree(AvlTree *tree) {

    if (is_Empty_AVLTree(tree)) {
        return 0;
    }
    return quantityElements_AVLTree(&(*tree)->left) + quantityElements_AVLTree(&(*tree)->right) + 1;
}

int consult_AVLTree(AvlTree *tree, int data) {

    if (is_Empty_AVLTree(tree)) {
        return 0;
    }
    Element *element = *tree;

    while (element != NULL) {

        if (data < element->data) {
            return 1;
        }
        if (data > element->data) {
            element = element->right;
        }
        else {
            element = element->left;
        }
    }
    return 0;
}

void preOrder_AVLTree(AvlTree *tree) {

    if (tree == NULL) {
        return;
    }
    if (*tree != NULL) {

        printf("Elemento: %d. Altura: %d.\n", (*tree)->data, (*tree)->height);
        preOrder_AVLTree(&(*tree)->left);
        preOrder_AVLTree(&(*tree)->right);

    }
}

void inOrder_AVLTree(AvlTree *tree) {

    if (tree == NULL) {
        return;
    }
    if (*tree != NULL) {

        inOrder_AVLTree(&(*tree)->left);
        printf("Elemento: %d. Altura: %d. Fator Balanceamento: %d.\n", (*tree)->data, (*tree)->height, balance_Element(*tree));
        inOrder_AVLTree(&(*tree)->right);

    }
}

void postOrder_AVLTree(AvlTree *tree) {

    if (tree == NULL) {
        return;
    }
    if (*tree != NULL) {
        postOrder_AVLTree(&(*tree)->left);
        postOrder_AVLTree(&(*tree)->right);
        printf("Elemento: %d. Altura: %d.\n", (*tree)->data, (*tree)->height);
    }
}

int height_Element(Element *element) {

    if (element == NULL) {
        return -1;
    }
    return element->height;
}

int balance_Element(Element *element) {
    return labs(height_Element(element->left) - height_Element(element->right));
}

int bigger(int x, int y) {

    if (x > y) {
        return x;
    }
    return y;
}