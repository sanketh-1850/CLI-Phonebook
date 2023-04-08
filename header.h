#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct Node{                //structures of the binary search trees
    char name[20];
    char number[10];
    struct Node *lchild;
    struct Node *rchild;
}contactNode;

struct Nodes{               //structure for frequents array element
    int priority;
    char name[20];
    char number[10];
};

typedef struct node{
    char name[20];
    char number[10];
    struct node *next;
}recentNode;



contactNode * create_contact();         //functions for contacts

contactNode * delete_contact();

contactNode* searchTree();

void inorder_display();

void contact_display();




void updatefrequents();         //functions for frequents

void bubblesort();

void swap();

void displayFrequents();




recentNode* updateRecents();          //functions for recents

void displayRecents();

#endif
