//
// Created by liperasz on 21/06/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "AVL-Tree.h"

//-------------------------------
//Main criado pelo chatGPT
//-------------------------------
int main() {

    AvlTree* tree = create_AVLTree();

    // Inserindo elementos na árvore AVL
    insert_AVLTree(tree, 10);
    insert_AVLTree(tree, 20);
    insert_AVLTree(tree, 30);
    insert_AVLTree(tree, 40);
    insert_AVLTree(tree, 50);
    insert_AVLTree(tree, 25); // Inserção que pode causar rotações

    printf("Árvore AVL após inserções:\n");
    inOrder_AVLTree(tree); // Mostra os elementos em ordem

    // Verificando se a árvore é uma AVL válida
    if (verifyAVLTree(tree)) {
        printf("\nA árvore é uma AVL válida.\n");
    } else {
        printf("\nA árvore NÃO é uma AVL válida.\n");
    }

    // Removendo um elemento e verificando novamente
    remove_AVLTree(tree, 30);
    printf("\nÁrvore AVL após remoção do 30:\n");
    inOrder_AVLTree(tree);

    if (verifyAVLTree(tree)) {
        printf("\nA árvore ainda é uma AVL válida após remoção.\n");
    } else {
        printf("\nA árvore deixou de ser uma AVL válida após remoção.\n");
    }

    free_AVLTree(tree); // Libera a memória alocada para a árvore

    return 0;

}