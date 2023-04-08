#include "header.h"


int main(){
    contactNode *contactRoot=NULL;
    recentNode *recentHead=NULL;
    struct Nodes frequent[15];
    int option,count=0;
    char name[20];
    while(1){
        system("cls");                      //menu display
        
        for(int i=0;i<30;i++)
            printf("-");
        printf("\n");
        for(int i=0;i<13;i++)
            printf(" ");
        printf("MENU\n");
        for(int i=0;i<30;i++)
            printf("-");
        printf("\n");
        
        /*displaying the options*/
        printf("1.Create a new contact.\n2.Delete a contact.\n3.Display Contacts.\n4.Display Recents\n5.Display Frequents.\n6.Call a Contact.\n7.Exit.\n");
        for(int i=0;i<30;i++)
            printf("-");
        printf("\n");
        
        printf("Enter your choice:\n>");
        scanf("%d",&option);
        printf("\n");
        
        switch(option){
            
            case 1:printf("Enter the name of the contact to be created:");      //create new contact
                    scanf("%s",&name);
                    contactRoot=create_contact(contactRoot,name);
                    getch();
                    break;
            
            case 2:if (contactRoot==NULL){                                          //delete contact
                        printf("\nContacts is Empty!\n\n");
                        break;
                    }
                    printf("Enter the name of the contact to be deleted:");
                    scanf("%s",&name);
                    contactRoot=delete_contact(contactRoot,name);
                    getch();
                    break;
            
            case 3:contact_display(contactRoot);                                    //display contacts
                    break;
            
            case 4:displayRecents(recentHead);                                      //display recents
                    break;
            
            case 5:displayFrequents(frequent,&count);                               //display frequents
                    break;

            case 6:printf("Enter a Contact name to call:");                         //call a contact
                    scanf("%s",name);
                    contactNode* p=searchTree(contactRoot,name);
                    if(p==NULL){
                        printf("Contact does not exist.");
                        getch();
                        break;
                    }
                    else{
                        updatefrequents(&count,p,frequent);
                        recentHead=updateRecents(recentHead,p);

                        printf("Call connected to %s.",p->name);
                        getch();
                        break;
                    }
            
            case 7:printf("Terminating...");    // to exit the program
                    exit(0);
                    break;
            
            default:printf("Retry Please.\n\n");        //if a wrong option is chosen
                    getch();
                    break;
        }
    }
    return 0;
}