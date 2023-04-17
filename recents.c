#include "header.h"

recentNode* updateRecents(recentNode* head,contactNode* p){     //updates recents based on call
    recentNode *q=head,*par=NULL;
    while(q!=NULL){
        if(strcmp(q->name,p->name)==0)
            break;
        par=q;
        q=q->next;
    }
    if(q!=NULL){
        if(q==head){
            head=q->next;
            free(q);
        }
        else{
            recentNode* temp=q;
            par->next=q->next;
            free(temp);
        }    
    }
    recentNode* temp=(recentNode*)malloc(sizeof(recentNode));
    strcpy(temp->name,p->name);
    strcpy(temp->number,p->number);
    temp->next=head;
    head=temp;
    return head;
}


void displayRecents(recentNode *head){      //displays the recents page
    system("cls");
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    for(int i=0;i<(60-7)/2;i++)
        printf(" ");
    printf("RECENTS");
    printf("\n");
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    if (head==NULL){
        for(int i=0;i<27;i++)
            printf(" ");
        printf("EMPTY!\n");
    }
    recentNode* p=head;
    while(p!=NULL){
        for(int i=0;i<10;i++){
        printf(" ");
        }
        printf("%s",p->name);
        for(int i=0;i<40-strlen(p->name)-strlen(p->number);i++){
        printf(" ");
        }
        printf("%s",p->number);
        printf("\n");
        p=p->next;
    }
    for(int i=0;i<60;i++)
        printf("-");
    getch();
}