#include "header.h"

void swap(struct Nodes* xp, struct Nodes* yp)       // swaps the nodes for bubblesort
{
    struct Nodes temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(struct Nodes arr[], int n)          //used to sort the frequents array according to priority
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].priority < arr[j + 1].priority)
                swap(&arr[j], &arr[j + 1]);
}

void updatefrequents(int *count,contactNode* p,struct Nodes* frequent){     // updated frequents page
    int flag=1;
    for(int i=0;i<(*count);i++){
        if(strcmp(p->name,frequent[i].name)==0){
            frequent[i].priority+=1;
            flag=0;
            break;
        }
    }
    if(flag){
        strcpy(frequent[(*count)].name,p->name);
        strcpy(frequent[(*count)].number,p->number);
        frequent[(*count)].priority=1;
        (*count)++;
    }
    else{
        bubbleSort(frequent,(*count));
    }

}

void displayFrequents(struct Nodes frequent[],int *count){      //displays the frequents page
    system("cls");
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    for(int i=0;i<(60-9)/2;i++)
        printf(" ");
    printf("FREQUENTS");
    printf("\n");
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    if((*count)==0){
        for(int i=0;i<27;i++)
            printf(" ");
        printf("Empty!");
        printf("\n");
    }
    else{
        for(int i=0;i<(*count);i++){
            for(int j=0;j<10;j++){
                printf(" ");
            }
            printf("%s",frequent[i].name);
            for(int j=0;j<40-strlen(frequent[i].name)-strlen(frequent[i].number);j++){
                printf(" ");
            }
            printf("%s",frequent[i].number);
            printf("\n");
        }
    }
    for(int i=0;i<60;i++)
        printf("-");
    getch();
}