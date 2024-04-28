#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define flush fflush(stdin)

typedef struct node{
    char elem;
    struct node* link;
}*LIST,celltype;

void display(LIST first);                               // Display List
void add_charFirst(LIST* first);                        // Add node(with data) at Fistndx
void add_charLast(LIST* first);                         // Add node(with data) at Lastndx   
void add_multipleCharFirst(LIST* first);                // Adds nodes(with data) starting at Fistndx 
void add_multipleCharLast(LIST* first);                 // Adds nodes(with data) starting at Lastndx
void add_charPos(LIST* first);                          // Adds node(with data) at nth ndx
void sortList_ascending(LIST first);                    // Sort List in ascending order (Selection Sort Method)
void sortList_descending(LIST first);                   // Sort List in descending order (Selection Sort Method)
void delete_char(LIST* first);                          // deletes a singe node;
void delete_charPos(LIST* first);                       // deletes a singe node at nth ndex;
void delete_sameChar(LIST* first);                      // deletes all occurences of a data in a List
void delete_all(LIST* first);                           // Housekeeping (Deallocating all nodes)

int main(){
    LIST first = NULL;
    int option = 0;

    while (1){
        printf("==========LINKED LIST==========\n");
        printf("1. Display list.\n");
        printf("2. Add a node at first.\n");
        printf("3. Add a node at last.\n");
        printf("4. Add multiple characters at first.\n");
        printf("5. Add multiple characters at last.\n");
        printf("6. Add a node in certain position.\n");
        printf("7. Sort list ascending order and display\n");
        printf("8. Sort list descending order and display\n");
        printf("9. Delete a character.\n");
        printf("10. Delete a character at a certain position.\n");
        printf("11.Delete the same characters.\n");
        printf("0. Exit.\n");
        printf("Enter you choice: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            display(first);
            break;

            case 2:
            add_charFirst(&first);
            break;

            case 3:
            add_charLast(&first);
            break;

            case 4:
            add_multipleCharFirst(&first);
            break;

            case 5:
            add_multipleCharLast(&first);
            break;

            case 6:
            add_charPos(&first);
            break;

            case 7:
            sortList_ascending(first);
            break;

            case 8:
            sortList_descending(first);
            break;

            case 9:
            delete_char(&first);
            break;

            case 10:
            delete_charPos(&first);
            break;

            case 11:
            delete_sameChar(&first);
            break;
            
            case 0:
            delete_all(&first);
            exit(0);
            break;
        }
        option = 0;
    }
    return 0;
}

void display(LIST first){                           // Display List
    LIST trav;
    if(first!=NULL){
        for(trav = first; trav!=NULL; trav = trav->link){
        printf("%c\n",trav->elem);
    }
    printf("\n\n");
    }else{
        printf("LIST IS EMPTY\n\n");
    }
}

void add_charFirst(LIST* first){                    // Add node(with data) at Firstndx 
    char elem;
    printf("Enter character you want to add: ");
    flush;
    scanf("%c",&elem);

    LIST temp = (LIST)malloc(sizeof(celltype));
    temp->elem = elem;
    temp->link= *first;
    *first = temp;
    printf("SUCCESSFULLY ADDED A NODE WITH VALUE AT FIRST\n\n");
}

void add_charLast(LIST* first){                     // Add node(with data) at Lastndx 
    char elem;
    printf("Enter character you want to add: ");
    flush;
    scanf("%c",&elem);

    LIST* trav;
    for(trav = first; (*trav)!= NULL; trav = &(*trav)->link){}
    LIST temp = (LIST)malloc(sizeof(celltype));
    temp->elem = elem;
    temp->link= *trav;
    *trav = temp;
    printf("SUCCESSFULLY ADDED A NODE WITH VALUE AT LAST\n\n");
}

void add_multipleCharFirst(LIST* first){            // Adds nodes(with data) starting at Firstndx
    int count=0;
    char elem;
    int i;
    printf("Enter the number of characters you want to add: ");
    flush;
    scanf("%d",&count);

    for(i=0;i<count;i++){
        printf("Enter Character %d: ",i+1);
        flush;
        scanf("%c",&elem);

        LIST temp = malloc(sizeof(celltype));
        temp->elem = elem;
        temp->link= *first;
        *first = temp;
    }
    printf("SUCCESSFULLY ADDED A MULTIPLE NODEs WITH VALUE AT FIRST \n\n");
}

void add_multipleCharLast(LIST* first){             // Adds nodes(with data) starting at Lastndx
    int count=0;
    char elem;
    int i;
    printf("Enter the number of characters you want to add: ");
    flush;
    scanf("%d",&count);

    LIST* trav;
    for(i=0;i<count;i++){
        printf("Enter Character %d: ",i+1);
        flush;
        scanf("%c",&elem);

        for(trav = first; (*trav)!= NULL; trav = &(*trav)->link){}
        LIST temp = malloc(sizeof(celltype));
        temp->elem = elem;
        temp->link= *trav;
        *trav = temp;
    }
    printf("SUCCESSFULLY ADDED A MULTIPLE NODEs WITH VALUE AT LAST \n\n");
}

void add_charPos(LIST* first){                      // Adds node(with data) at nth ndx
    char elem;
    int i,pos;
    printf("Enter character you want to add: ");
    flush;
    scanf("%c",&elem);

    printf("Enter position: ");
    flush;
    scanf("%d",&pos);

    LIST *trav,temp;
    for(trav = first,i=0; i != pos && (*trav)!= NULL; i++, trav= &(*trav)->link){}
    if(i == pos){  
        temp = (LIST)malloc(sizeof(celltype));
        temp->elem = elem;
        temp->link= *trav;
        *trav = temp;
        printf("SUCCESSFULLY ADDED A NODE WITH VALUE AT NTH POSITION\n\n");                   //corrected conditions in forloop and if statement
    }else{
        printf("POSITION OR NO.NODES EXCEEDS LIST\n\n");
    }
}

void sortList_ascending(LIST first){                // Sort List in ascending order (Selection Sort Method)
    LIST i,j;
    for(LIST i = first; i!=NULL ; i = i->link){
        LIST min = i;
        for(j=i->link;j!=NULL;j= j->link){
            if(j->elem < min->elem){
                min = j;
            }
        }
        char temp = i->elem;
        i->elem = min->elem;
        min->elem = temp;
    }
    display(first);
}

void sortList_descending(LIST first){               // Sort List in descending order (Selection Sort Method)
    LIST i,j;
    for(LIST i = first; i!=NULL ; i = i->link){
        LIST min = i;
        for(j=i->link;j!=NULL;j= j->link){
            if(j->elem > min->elem){
                min = j;
            }
        }
        char temp = i->elem;
        i->elem = min->elem;
        min->elem = temp;
    }
    display(first);
}

void delete_char(LIST* first){                      // deletes a singe node;
    char elem;
    printf("Enter character you want to delete: ");
    flush;
    scanf("%c",&elem);

    LIST* trav;
    for(trav = first; (*trav)!= NULL&& (*trav)->elem != elem;trav = &(*trav)->link){}
    if(*trav != NULL){
        LIST temp = *trav;
        *trav = (*trav)->link;
        free(temp);
        printf("SUCCESFULLY DELETED A NODE\n\n");
        display(*first);
    }else{
        printf("CHARACTER NOT IN LIST\n\n");
    }
}

void delete_charPos(LIST* first){                   // deletes a singe node at nth ndex;
    int i,pos;
    printf("Enter position: ");
    flush;
    scanf("%d",&pos);

    LIST *trav,temp;
    for(trav = first,i=0; i != pos && (*trav)!= NULL; i++, trav= &(*trav)->link){}
    if(i == pos){ 
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
        printf("SUCCESFULLY DELETED A NODE AT NTH POSTION\n\n");                                 //corrected conditions in forloop and if statement
    }else{
        printf("POSITION EXCEEDS LIST\n\n");
    }
}

void delete_sameChar(LIST* first){                  // deletes all occurences of a data in a List
    char elem;
    printf("Enter character(No.occurance) you want to delete: ");
    flush;
    scanf("%c",&elem);

    LIST* trav = first;
    while ((*trav)!=NULL)
    {
        if((*trav)->elem == elem){
            LIST temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }else{
            trav = &(*trav)->link;
        }
    }
    
    printf("SUCCESFULLY DELETED NODEs WITH DATA OF SAME OCCURENCES\n\n");
}

void delete_all(LIST* first){                       // Housekeeping function to delete all Nodes in List
    LIST* trav;
    while(*first != NULL){
        LIST temp = *first;
        *first = (*first)->link;
        free(temp);
    }
    printf("SUCCESSFULLY EMPTIED THE LIST\n\n");
}