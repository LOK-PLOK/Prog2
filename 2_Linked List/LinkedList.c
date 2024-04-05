#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define flush fflush(stdin)

typedef struct node{
    char elem;
    struct node* link;
}*LIST,celltype;

void add_char(LIST*);               // add 1 element with character/data
void add_multipleChar(LIST*);       // add multiple elements with characters/datas
void display(LIST);                 // display all element's data
void delete_char(LIST*);            // delete an element of the first occurence of character/data
void delete_sameChar(LIST*);        // delete all elements with the same character/data
void delete_all(LIST*);             // delete all elements in the program

int main(){
    LIST L = NULL;
    int option = 0;

    while(1){
        printf("==========LINKED LIST==========\n");
        printf("1. Add a character.\n");
        printf("2. Add multiple characters.\n");
        printf("3. Display list.\n");
        printf("4. Delete a character.\n");
        printf("5. Delete the same characters.\n");
        printf("6. Exit.\n");
        printf("Enter you choice: ");
        scanf("%d",&option);

        switch(option){
            case 1:
            add_char(&L);
            break;

            case 2:
            add_multipleChar(&L);
            break;

            case 3:
            display(L);
            break;

            case 4:
            delete_char(&L);
            break;

            case 5:
            delete_sameChar(&L);
            break;

            case 6:
            delete_all(&L);
            exit(0);
            break;
        }
        option = 0;
    }
    return 0;
}

void add_char(LIST* first){
    char elem;
    printf("Enter character you want to add: ");
    flush;
    scanf("%c",&elem);

    LIST temp = (LIST)malloc(sizeof(celltype)); // allocating temp of type LIST;
    temp->elem = elem;                          // assigning character in temp;
    temp->link = *first;                        // connect templink to where first is pointing;
    *first = temp;                              // connects first to where temp is pointing
    printf("SUCCESSFULY ADDED CHARACTER\n\n");
}

void add_multipleChar(LIST* first){
    int add;
    printf("How many characters to add?: ");
    flush;
    scanf("%d",&add);

    int i;
    char elem;
    for(i=0;i<add;i++){
        printf("Enter character you want to add: ");
        flush;
        scanf("%c",&elem);

        LIST temp = (LIST)malloc(sizeof(celltype));
        temp->elem = elem;
        temp->link = *first;
        *first = temp;
    }
    printf("SUCCESSFULY ADDED CHARACTERs\n\n");
}

void display(LIST first){
    LIST trav;
    if(first!= NULL){
        for(trav = first; trav!=NULL;trav=trav->link){
        printf("%c\n",trav->elem);
        }
    printf("\n\n");
    }else{
        printf("LIST IS EMPTY\n\n");
    }
}

void delete_char(LIST* first){
    char elem;
    printf("Enter character you want to delete: ");
    flush;
    scanf("%c",&elem);
    LIST* trav;
    for(trav = first; (*trav)!=NULL && (*trav)->elem != elem; trav=&(*trav)->link){} // finds first occurence of character that is to be deleted;
    if(*trav != NULL){  // when character is found;
        LIST temp = (*trav); // temporary pointer that points to an element
        (*trav) = (*trav)->link;// links to the element after the temporary pointer is pointing at;
        free(temp);// deallocate element that temporary pointer is pointing at;
        printf("SUCCESSFULLY DELETED CHARACTER\n\n");
    }else{
        printf("CHARACTER NOT IN LIST\n\n");
    }
}

void delete_sameChar(LIST* first){
    if(*first != NULL){
        char elem;
        printf("Enter character you want to delete in LIST: ");
        flush;
        scanf("%c",&elem);

        LIST* trav = first;
        while(*trav != NULL){
            if((*trav)->elem == elem){
                LIST temp = *trav;
                *trav = (*trav)->link;
                free(temp);
            }else{
                trav = &(*trav)->link;
            }
        }
        printf("SUCCESSFULLY REMOVED SAME CHARACTERS\n\n");
    }else{
        printf("LIST CURRENTLY EMPTY\n\n");
    }
    
}

void delete_all(LIST* first){
    LIST* trav;                         // delete all elements in program
    while(*first != NULL){
        LIST temp = *first;
        *first = (*first)->link;
        free(temp);
    }
    printf("SUCCESSFULLY EMPTIED THE LIST.\n\n");
}