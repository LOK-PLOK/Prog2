#include <stdio.h>
#include <stdlib.h>

//structure of data
typedef struct cell{
    int data;
    struct cell* link;
}celltype,*LIST;

void add_beg(LIST* head,int d){
    LIST ptr = malloc(sizeof(celltype));//dynamically allocated 
    ptr->data = d; //initialize value
    ptr->link=NULL;
    
    ptr->link= *head; //point to where head is pointing at
    *head = ptr; // head pointing at where ptr is pointing
}

void delete_elem(LIST* A, int elem){
    LIST* trav;
    for(trav = A; trav!=NULL&&(*trav)->data!=elem;trav = &(*trav)->link){} //Loop that find the element we are looking for
    if((*trav)!=NULL){ // if trav == NULL, it means that the element is not in list,otherwise element is in the list
        LIST temp = (*trav); // temporary variable that holds the value of trav
        (*trav) = (*trav)->link; // changing the pointer of trav to the link trav is poiting at
        free(temp);// deleting the element
    }
}

void delete(LIST* A){
    while (*A != NULL) {
        LIST temp = *A;
        *A = (*A)->link;    //delete all function
        free(temp);
    }
}

int main(){
    LIST head = malloc(sizeof(celltype));
    head->data = 45;
    head->link = NULL;
    
    LIST ptr = malloc(sizeof(celltype));
    ptr->data = 98;
    ptr->link = NULL;
    
    head->link = ptr;
    
    int data = 3;
    
    add_beg(&head,data);
    
    for(ptr = head; ptr!=NULL;ptr = ptr->link){
        printf("%d ",ptr->data);
    }
    printf("\n");
    delete(&head);
    
    if(head == NULL){
        printf("Successfully delete Linked List");
    }else{
        for(ptr = head; ptr!=NULL;ptr = ptr->link){
        printf("%d ",ptr->data);
        }
    }

    return 0;
}