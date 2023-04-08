#include "header.h"


int isNumber(char s[])             // to check if entered info is a number
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (isdigit(s[i]) == 0 || i>9)
            return 0;
    if(i!=10){
        return 0;
    }
    return 1;
}



contactNode * create_contact(contactNode *p,char names[]){

    contactNode * temp=NULL;
    
    if (p==NULL){
        temp=(contactNode *)malloc(sizeof(contactNode));  //creates a node and initializes input
        strcpy(temp->name,names);
        printf("Enter the contact number:");
        scanf("%s",temp->number);

        while(isNumber(temp->number)==0){              //checks if the number is valid
            printf("Invalid contact number! Try again:");
            scanf("%s",temp->number);
        }

        temp->lchild=NULL;
        temp->rchild=NULL;
        p=temp;
    }

    else if(strcmp(names,p->name)==1){                      //recursive function to find the node and append new node
        p->rchild=(create_contact(p->rchild,names));
    }

    else if(strcmp(names,p->name)==-1){
        p->lchild=(create_contact(p->lchild,names));
    }

    else if(strcmp(names,p->name)==0){                      //if contact already exists then contact is not added
        printf("\n%s already exists!\n\n",p->name);
        return p;
    }
    if(temp==p){
        printf("\nContact created.\n\n");

    }

    return p;
}


contactNode * delete_contact(contactNode *root,char name[]){

    contactNode *ps,*s,*par,*p,*ch;
    p=root;
    par=NULL;
    while(p!=NULL){                         //searches for the node
        if(strcmp(name,p->name)==0){
            break;
        }
        par=p;
        if(strcmp(name,p->name)==1){
            p=p->rchild;
        }
        else{
            p=p->lchild;
        }
    }
    
    if(p==NULL){
        printf("\nContact does not exist.\n\n");
        return root;
    }
    
    //if node has both left and right child
    if(p->lchild!=NULL && p->rchild!=NULL){
        ps=p;
        s=p->rchild;
        while (s->lchild!=NULL){
            ps=s;
            s=s->lchild;
        }
        strcpy(p->name,s->name);
        strcpy(p->number,s->number);
        p=s;
        par=ps;
    }

    //if node has only one child or no child
    if(p->lchild!=NULL){
        ch=p->lchild;
    }
    else{
        ch=p->rchild;
    }

    if(par==NULL){
        root=ch;
    }
    else if(p==par->lchild){
        par->lchild=ch;
    }
    else if(p==par->rchild){
        par->rchild=ch;
    }
    free(p);
    printf("\nContact deleted.\n\n");
    return root;
}

void inorder_display(contactNode *p){              //recursive function to display tree in ascending order using inorder traversing
    if(p==NULL){
        return;
    }
    inorder_display(p->lchild);
    for(int i=0;i<10;i++){
        printf(" ");
    }
    printf("%s",p->name);
    for(int i=0;i<40-strlen(p->name)-strlen(p->number);i++){
        printf(" ");
    }
    printf("%s",p->number);
    printf("\n");
    inorder_display(p->rchild);
}

void contact_display(contactNode *p){       //Displaying the contacts in alphabetical order
    system("cls");
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    for(int i=0;i<(60-8)/2;i++)
        printf(" ");
    printf("CONTACTS");
    printf("\n");
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    if(p==NULL){
        for(int i=0;i<27;i++)
            printf(" ");
        printf("Empty!");
        printf("\n");
    }
    else
        inorder_display(p);
    for(int i=0;i<60;i++)
        printf("-");
    getch();
}

contactNode* searchTree(contactNode* root, char name[])
{
    // Base Cases: root is null or name is present at root
    if (root == NULL || strcmp(root->name , name)==0)
       return root;
    
    // name is greater than root's name
    if (strcmp(root->name , name)==-1)
       return searchTree(root->rchild, name);
 
    // name is smaller than root's name
    return searchTree(root->lchild, name);
}