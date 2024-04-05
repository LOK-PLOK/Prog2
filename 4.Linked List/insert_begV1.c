#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    int data;
    struct cell* link;
}celltype,*LIST;

LIST add_beg(LIST head,int d){
    LIST ptr = malloc(sizeof(celltype));
    ptr->data = d;
    ptr->link=NULL;
    
    ptr->link=head;
    head = ptr;
    return head;
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
    
    head = add_beg(head,data);
    ptr = head;
    while(ptr!= NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}