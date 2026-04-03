#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LINK LIST
typedef struct Linklist
{
    char list_category[50];
    char list_Maincategory[50];
    char sub_category[50];
    int ratings;
    struct Linklist *next;
} Lkl;

// SUB TREE
typedef struct Node
{
    char category[50];
    int countAciiSubTree;
    struct Node *right, *left;
    Lkl *list;
    
} Node;

// MAIN TREE
typedef struct Maintree
{
    char Maincategory[50];
    int countAciiMainTree;
    Node *root;
    struct Maintree *left, *right;

} Maintree;

// FUNCTION DECLARATIONS
Lkl *createList(Lkl *head, char listMainCat[50], char c[30]);
Node *create(Node *root, char listMainCat[50]);
Maintree *createMainTree(Maintree *rootNode);

Maintree *search_category(char category_choice[50], Maintree *mainRoot);
Node *search_subCategory(char category_sub[50], Maintree *mainRoot);
int search_list(char category_last[50], Node *key_sub);

void displayList();
int adminPass(char pass[50]);

#endif