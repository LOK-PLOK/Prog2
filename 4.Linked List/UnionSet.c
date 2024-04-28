#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int elem;
    struct node* link;
}*SET, nodetype;

void CreateLinkedList(SET*,int*,int);           //Creates a linkedList from an Array and its size
SET unionset(SET,SET);                          //Creates a linkedList from 2 LinkedList
void display(SET);                              //Display Elements
void sort(SET);                                 //Sort Elements
void insertFirst(SET*,int);                     //Insert Element at First position(0)
void insertLast(int,SET*);                      //Insert Element at Last position(n)
void delete(SET*);                              //Housekeeping function (Deletes all dynamically allocated variables)

int main(){
    SET A = NULL;
    SET B = NULL;
    int arrA[]= {1,7,8,12,24};
    int arrB[]= {2,4,15,32};
    int sizeA = sizeof(arrA)/sizeof(arrA[0]);
    int sizeB = sizeof(arrB)/sizeof(arrB[0]);

    CreateLinkedList(&A,arrA,sizeA);
    CreateLinkedList(&B,arrB,sizeB);
    sort(A);
    sort(B);
    
    printf("SET A:\n");
    display(A);
    printf("\n\nSET B:\n");
    display(B);

    printf("\n\nSET C:\n");
    SET C = unionset(A,B);
    display(C);

    delete(&A);
    delete(&B);
    delete(&C);

    return 0;
}

void CreateLinkedList(SET* X,int* arr,int size){
    int i;
    for(i=0;i<size;i++){
        insertFirst(X,arr[i]);
    }
}

void display(SET X){
    SET trav;
    for(trav = X; trav!=NULL; trav = trav->link){
        if(trav->link != NULL){
            printf("[%d] --> ",trav->elem);
        }else{ 
            printf("[%d]",trav->elem);    
        }
    }
}

void insertFirst(SET* X,int val){
    SET temp = (SET)malloc(sizeof(nodetype));
    temp->elem = val;
    temp->link = *X;
    *X = temp;
}

void insertLast(int elem,SET *Y){
    SET* trav;
    for(trav = Y; *trav != NULL; trav = &(*trav)->link);
    *trav = (SET)malloc(sizeof(nodetype));
    (*trav)->elem = elem;
    (*trav)->link = NULL;
}

void sort(SET X){
    SET i,j;
    for(i = X; i!= NULL;i=i->link){
        SET min = i;
        for(j = i->link; j!=NULL; j=j->link){
            if(j->elem < min -> elem){
                min = j;
            }
        }
        int temp = i->elem;
        i->elem = min->elem;
        min->elem = temp;
    }
}

SET unionset(SET A,SET B){
    SET C = NULL;
    SET aptr = A, bptr = B;
    SET *cptr = &C;

    while(aptr != NULL || bptr != NULL){
        if(aptr != NULL && bptr != NULL){
            if (aptr->elem < bptr->elem){//----------------
                insertLast(aptr->elem, cptr);//           |---------> Will check if the element in NODE A is less than the element in NODE B,
                aptr = aptr->link;//                      |---------> element in NODE B, INSERT ,then move the ptr of A to the next Node
            //---------------------------------------------

            }else if (aptr->elem > bptr->elem){//----------
                insertLast(bptr->elem, cptr);//           |---------> Will check if the element in NODE B is less than the
                bptr = bptr->link;//                      |---------> element in NODE A, INSERT , then move the ptr of B to the next Node
            //---------------------------------------------

            }else{
                insertLast(aptr->elem, cptr);//------------
                aptr = aptr->link;//                      |---------> Will check if both elements in NODE A and NODE B are eqaul,  
                bptr = bptr->link;//                      |---------> INSERT either NODE A or B, then move both ptrs to the next Node
            }//--------------------------------------------

        }else{

            while(aptr != NULL){//-------------------------
                insertLast(aptr->elem, cptr);//           |
                aptr = aptr->link;//                      |
            }//                                           |
             //                                           |---------> Will continue if one of the SET reaches the end and the other has not
            while(bptr != NULL){//                        |
                insertLast(bptr->elem, cptr);//           |
                bptr = bptr->link;//                      |
            }//--------------------------------------------
        }
    }

    return C;
}


void delete(SET* X){
    while(*X != NULL){
        SET temp = *X;
        *X = (*X)->link;
        free(temp);
    }
}