#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define flush fflush(stdin)

typedef enum {YES,NO}bool;

typedef char string[100];

typedef struct{
    string title;
    string author;
    string genre;
    bool available;
}book;

typedef struct{
    book library[MAX];
    int count;
}record;

void initialize(record*);
void addbook_details(book*);
void addbook(record*);
void display(record);
void borrow_book(record*);
void return_book(record*);

int main(){
    record first;
    initialize(&first);

    int option = 0;
    while(1){
        printf("Library Management System\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Borrow a book\n");
        printf("4. Return a book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        flush;
        scanf("%d",&option);

        switch(option){
            case 1:
            addbook(&first);
            break;

            case 2:
            display(first);
            break;

            case 3:
            borrow_book(&first);
            break;

            case 4:
            return_book(&first);
            break;

            case 5:
            exit(0);
        }
        option = 0;
    }
}

void initialize(record* N){
    N->count = 0;
}

void addbook_details(book* N){
    printf("Enter book title: ");
    flush;
    scanf("%[^\n]s",N->title);
    printf("Enter book author: ");
    flush;
    scanf("%[^\n]s",N->author);
    printf("Enter book genre: ");
    flush;
    scanf("%[^\n]s",N->genre);
    N->available = YES;
    flush;
}

void addbook(record* N){
    int add;
    printf("How many books?: ");
    scanf("%d",&add);
    
    int i;
    if(N->count < MAX){
        for(i=0;i<add;i++){
            printf("Enter Book[%d] details:\n",i+1);
            addbook_details(&N->library[i]);
            N->count++;
        }
        printf("Book(s) added successfully\n\n");
    }else{
        printf("No space\n");
    }
}

void display(record N){
    int i;
    if(N.count!=0){
        for(i=0;i<N.count;i++){
            printf("%d. Title: %s, Author: %s, Genre: %s, Available: ",i+1,N.library[i].title,N.library[i].author,N.library[i].genre);
            printf("%s",(N.library[i].available == YES)? "YES\n":"NO\n");
        }
        printf("\n\n");
    }else{
        printf("Library is empty\n\n");
    }
    
}

void borrow_book(record* N){
    printf("Library books: ");
    int i;
    int index;
    if(N->count!=0){
        printf("\n");
        for(i=0;i<N->count;i++){
            printf("%d. Title: %s, Author: %s, Genre: %s, Available: ",i+1,N->library[i].title,N->library[i].author,N->library[i].genre);
            printf("%s",(N->library[i].available == YES)? "YES\n":"NO\n");
        }
        printf("Enter the index of the book you want to borrow: ");
        scanf("%d",&index);

        index--;
        if(N->library[index].available == YES){
            printf("You have successfully borrowed the book.\n\n");
            N->library[index].available = NO;
        }else{
            printf("Book currently in someone elses' possesion\n\n");
        }
    }else{
        printf("empty\n\n");
    }

}

void return_book(record* N){
     printf("Library books: ");
    int i;
    int index;
    if(N->count!=0){
        printf("\n");
        for(i=0;i<N->count;i++){
            printf("%d. Title: %s, Author: %s, Genre: %s, Available: ",i+1,N->library[i].title,N->library[i].author,N->library[i].genre);
            printf("%s",(N->library[i].available == YES)? "YES\n":"NO\n");
        }
        printf("Enter the index of the book you want to borrow: ");
        scanf("%d",&index);

        index--;
        if(N->library[index].available == NO){
            printf("You have successfully returned the book.\n\n");
            N->library[index].available = YES;
        }else{
            printf("You have not borrowed this book\n\n");
        }
    }else{
        printf("empty\n\n");
    }
}