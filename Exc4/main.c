//
// Created by liperasz on 20/06/25.
//
#include "AVL-Tree.h"
#include <stdlib.h>
#include <stdio.h>

//-------------------------------
//main criado pelo chatGPT
//-------------------------------
int main() {
    AvlTree* tree = create_AVLTree();

    printf("Testando rotações na Árvore AVL:\n\n");

    // Caso 1: Rotação LL (inserção no lado esquerdo do lado esquerdo)
    printf("1. Testando rotação LL (inserindo 30, 20, 10):\n");
    insert_AVLTree(tree, 30);
    insert_AVLTree(tree, 20);
    insert_AVLTree(tree, 10);  // Deve disparar rotação LL
    inOrder_AVLTree(tree);
    printf("\n");

    free_AVLTree(tree);
    tree = create_AVLTree();

    // Caso 2: Rotação RR (inserção no lado direito do lado direito)
    printf("2. Testando rotação RR (inserindo 10, 20, 30):\n");
    insert_AVLTree(tree, 10);
    insert_AVLTree(tree, 20);
    insert_AVLTree(tree, 30);  // Deve disparar rotação RR
    inOrder_AVLTree(tree);
    printf("\n");

    free_AVLTree(tree);
    tree = create_AVLTree();

    // Caso 3: Rotação LR (inserção no lado direito do lado esquerdo)
    printf("3. Testando rotação LR (inserindo 30, 10, 20):\n");
    insert_AVLTree(tree, 30);
    insert_AVLTree(tree, 10);
    insert_AVLTree(tree, 20);  // Deve disparar rotação LR
    inOrder_AVLTree(tree);
    printf("\n");

    free_AVLTree(tree);
    tree = create_AVLTree();

    // Caso 4: Rotação RL (inserção no lado esquerdo do lado direito)
    printf("4. Testando rotação RL (inserindo 10, 30, 20):\n");
    insert_AVLTree(tree, 10);
    insert_AVLTree(tree, 30);
    insert_AVLTree(tree, 20);  // Deve disparar rotação RL
    inOrder_AVLTree(tree);

    free_AVLTree(tree);
    return 0;
}