#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define flush fflush(stdin)
typedef struct{
    char fName[24],MI,lName[16];
}Nametype;
typedef struct{
    Nametype name;
    int id;
    char course[8];
    int yearlvl;
}Stud;
typedef struct node{
    Stud studrec;
    struct node* link;
}*LIST, List;

Stud getStud();
void display(List*);                               // Display List 
void add_First(List**);                            // Add node(with data) at Fistndx
void add_Last(List**);                             // Add node(with data) at Lastndx 
void add_multipleFirst(List**);                    // Adds nodes(with data) starting at Fistndx 
void add_multipleLast(List**);                     // Adds nodes(with data) starting at Lastndx
void add_Pos(List**);                              // Adds node(with data) at nth ndx
void sortList_ascending(List*);                    // Sort List in ascending order (Selection Sort Method)
void sortList_descending(List*);                   // Sort List in descending order (Selection Sort Method)             
void delete_studrec(List**);                       // deletes a singe node
void delete_Pos(List**);                           // deletes a singe node at nth ndex
void delete_same(List**);                          // deletes all occurences of a data in a List
void delete_all(List**);                           // Housekeeping (Deallocating all nodes)

int main(){
    List* head = NULL;
    int option = 0;

    while (1){
        printf("==========LINKED LIST==========\n");
        printf("1. Display list.\n");
        printf("2. Add a node at first.\n");
        printf("3. Add a node at last.\n");
        printf("4. Add multiple nodes at first.\n");
        printf("5. Add multiple nodes at last.\n");
        printf("6. Add a node in certain position.\n");
        printf("7. Sort list ascending order and display\n");
        printf("8. Sort list descending order and display\n");
        printf("9. Delete a node.\n");
        printf("10.Delete a node at a certain position.\n");
        printf("11.Delete the same Course.\n");
        printf("0. Exit.\n");
        printf("Enter you choice: ");
        scanf("%d",&option);

        switch(option){

            case 1:
            display(head);
            break;

            case 2:
            add_First(&head);
            break;

            case 3:
            add_Last(&head);
            break;

            case 4:
            add_multipleFirst(&head);
            break;

            case 5:
            add_multipleLast(&head);
            break;

            case 6:
            add_Pos(&head);
            break;

            case 7:
            sortList_ascending(head);
            break;

            case 8:
            sortList_descending(head);
            break;

            case 9:
            delete_studrec(&head);
            break;

            case 10:
            delete_Pos(&head);
            break;

            case 11:
            delete_same(&head);
            break;
            
            case 0:
            delete_all(&head);
            exit(0);
            break;
        }
        option = 0;
    }
    return 0;
}

Stud getStud(){
    Stud info;
    printf("Input LastName: ");
    flush;
    scanf("%[^\n]",info.name.lName);
    printf("Input FirstName: ");
    flush;
    scanf("%[^\n]",info.name.fName);
    printf("Input Middle Initial: ");
    flush;
    scanf("%c",&info.name.MI);
    printf("Input ID: ");
    flush;
    scanf("%d",&info.id);
    printf("Input Course: ");
    flush;
    scanf("%s",info.course);
    printf("Input Yearlevel: ");
    flush;
    scanf("%d",&info.yearlvl);

    return info;
}

void display(List* block){                                              // Display List 
    if(block != NULL){
        List* trav;
        for(trav = block; trav!=NULL; trav = trav->link){
            printf("ID: %d\t",trav->studrec.id);
            printf("Course & Yearlevel: %s %d\t",trav->studrec.course,trav->studrec.yearlvl);
            printf("Name: %s,",trav->studrec.name.lName);
            printf(" %s ",trav->studrec.name.fName);
            printf(".%c\n",trav->studrec.name.MI);
        }
        printf("\n\n");
    }else{
        printf("LIST IS EMPTY\n\n");
    }
    
}

void add_First(List** block){                                           // Add node(with data) at Fistndx
    List* temp = (List*)malloc(sizeof(List));
    temp->studrec = getStud();
    temp->link = *block;
    *block = temp;
    printf("SUCCESSFULLY ADDED A NODE WITH VALUE AT FIRST\n\n");
}

void add_Last(List** block){                                            // Add node(with data) at Lastndx 
    List** trav;
    for(trav = block; *trav != NULL; trav = &(*trav)->link){}
    List* temp = (List*)malloc(sizeof(List));
    temp->studrec = getStud();
    temp->link = *trav;
    *trav = temp;
    printf("SUCCESSFULLY ADDED A NODE WITH VALUE AT LAST\n\n");
}

void add_multipleFirst(List** block){                                   // Adds nodes(with data) starting at Fistndx 
    int count;
    int i;
    printf("Enter number of students you want to add: ");
    flush;
    scanf("%d",&count);

    for(i=0;i<count;i++){
        printf("\nStudent Details[%d]\n",i+1);
        List*temp = (List*)malloc(sizeof(List));
        temp->studrec = getStud();
        temp->link = *block;
        *block = temp;
    }
    printf("SUCCESSFULLY ADDED A MULTIPLE NODEs WITH VALUE AT FIRST \n\n");
}

void add_multipleLast(List** block){                                    // Adds nodes(with data) starting at Lastndx
    int count;
    int i;
    printf("Enter number of students you want to add: ");
    flush;
    scanf("%d",&count);
    List** trav;
    for(i=0;i<count;i++){
        printf("\nStudent Details[%d]\n",i+1);
        for(trav=block; *trav!=NULL ; trav = &(*trav)->link){}
        List* temp = (List*)malloc(sizeof(List));
        temp->studrec = getStud();
        temp->link = *trav;
        *trav = temp;
    }
    printf("SUCCESSFULLY ADDED A MULTIPLE NODEs WITH VALUE AT LAST \n\n");
}

void add_Pos(List** block){                                             // Adds node(with data) at nth ndx
    int i,pos;
    printf("Enter position: ");
    flush;
    scanf("%d",&pos);

    List**trav,*temp;
    for(trav=block,i=0; *trav!=NULL && i!=pos; trav = &(*trav)->link,i++){}
    if(i==pos){
        printf("\n==Student Details==\n");
        temp = (List*)malloc(sizeof(List));
        temp->studrec = getStud();
        temp->link = *trav;
        *trav = temp;
        printf("SUCCESSFULLY ADDED A NODE WITH VALUE AT NTH POSITION\n\n");
    }else{
        printf("POSITION OR NO.NODES EXCEEDS LIST\n\n");
    }
}

void sortList_ascending(List* block){                                    // Sort List in ascending order (Selection Sort Method)
    List* i,*j;
    for(i=block; i!=NULL;i=i->link){
        List* min = i;
        for(j=i->link; j!=NULL; j = j->link){
            if(strcmp(j->studrec.name.lName,min->studrec.name.lName) < 0){
                min = j;
            }
        }
        Stud temp = i->studrec;
        i->studrec = min->studrec;
        min->studrec = temp;
    }
    display(block);
}

void sortList_descending(List* block){                                    // Sort List in descending order (Selection Sort Method) 
     List* i,*j;
    for(i=block; i!=NULL;i=i->link){
        List* min = i;
        for(j=i->link; j!=NULL; j = j->link){
            if(strcmp(j->studrec.name.lName,min->studrec.name.lName) > 0){
                min = j;
            }
        }
        Stud temp = i->studrec;
        i->studrec = min->studrec;
        min->studrec = temp;
    }
    display(block);
}

void delete_studrec(List** block){                                        // deletes a singe node                               
    char lName[16];
    printf("Enter Lastname to delete from the list: ");
    flush;
    scanf("%s",lName);

    List** trav;
    for(trav = block;*trav!=NULL && strcmp((*trav)->studrec.name.lName,lName) != 0; trav = &(*trav)->link){}
    if(*trav != NULL){
        List* temp = *trav;
        *trav = (*trav)->link;
        free(temp);
        printf("SUCCESFULLY DELETED A NODE\n\n");
        display(*block);
    }else{
        printf("STUDENT NOT IN LIST\n\n");
    }
}

void delete_Pos(List** block){                                            // deletes a singe node at nth ndex
    int i,pos;
    printf("Enter position: ");
    flush;
    scanf("%d",&pos);

    List**trav,*temp;
    for(trav = block,i=0;*trav != NULL && i!=pos; i++,trav=&(*trav)->link){}
    if(i == pos){
        List* temp = *trav;
        *trav = (*trav)->link;
        free(temp);
        printf("SUCCESFULLY DELETED A NODE AT NTH POSTION\n\n");
    }else{
        printf("POSITION OR NO.NODES EXCEEDS LIST\n\n");
    }
}

void delete_same(List** block){                                           // deletes all occurences of a data in a List
    char course[8];
    printf("Enter course you want to delete: ");
    flush;
    scanf("%s",course);

    List** trav = block;
    while(*trav != NULL){
        if(strcmp((*trav)->studrec.course,course) == 0){
            List* temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }else{
            trav = &(*trav)->link;
        }
    }
    printf("SUCCESFULLY DELETED NODEs WITH DATA OF SAME OCCURENCES\n\n");
}

void delete_all(List** block){                                             // Housekeeping (Deallocating all nodes)
    while(*block != NULL){
        List* temp = *block;
        *block = (*block)->link;
        free(temp);
    }
    printf("SUCCESSFULLY EMPTIED THE LIST\n\n");
}