#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
#define MAX 8
#define flush fflush(stdin)

typedef struct {
    char fname[24], mi, lname[16];
} Nametype;

typedef struct {
    Nametype name;
    unsigned int id;
    char course[8];
    int yearlvl;
} Studtype;

typedef struct {
    int count;
    Studtype stud[SIZE];
} Studlist;

Studlist initializeList();
void getStudent(Studtype *);
void displayStudent(Studtype);
void displayList(Studlist);
void findElem(Studlist);
void populateList(Studlist *);
void addStudent(Studlist *);
void insertFirst(Studlist *);
void deleteStudent(Studlist *);
void sortList(Studlist *);
void displayCourse(Studlist);
void insertSorted(Studlist*);

int main() {
    Studlist List = initializeList();
    populateList(&List);
    int option = 0;

    while (1) {
        system("cls");
        printf("What to do with the DATA?\n");
        printf("1. DISPLAY student record.\n");
        printf("2. FIND student using ID inputted by user.\n");
        printf("3. ADD student/s to the student record.\n");
        printf("4. ADD student and INSERT at first index of student record.\n");
        printf("5. DELETE a student from the list using ID.\n");  
        printf("6. SORT student ID in ascending order.\n");
        printf("7. Display all the student records within a SPECIFIED COURSE.\n");
        printf("8. EXIT.\n\n");
        printf("Current Students recorded: %d\n", List.count);

        while (option <= 0 || option > MAX) {
            printf("Enter option number: ");
            scanf("%d", &option);
        }

        switch (option) {
            case 1:
                displayList(List);
                break;
                
            case 2:
                findElem(List);
                break;

            case 3:
                addStudent(&List);
                break;

            case 4:
                insertFirst(&List);
                break;

            case 5:
                deleteStudent(&List);
                break;

            case 6:
                sortList(&List);
                break;

            case 7:
                displayCourse(List);
                break;

            case 8:
                insertSorted(&List);
                break;
            
            case 9:
                exit(0);
        }
        option = 0;
    }

    return 0;
}

Studlist initializeList() {
    Studlist List = {.count = 0};
    return List;
}

void getStudent(Studtype *Info) {
    printf("\nEnter Student ID: ");
    flush;
    scanf("%u", &Info->id);
    printf("Enter First Name: ");
    flush;
    scanf("%[^\n]s", Info->name.fname);
    printf("Enter Middle Initial: ");
    flush;
    scanf("%c", &Info->name.mi); 
    printf("Enter Last Name: ");
    flush;
    scanf("%[^\n]s", Info->name.lname);
    printf("Enter Course: ");
    flush;
    scanf("%s", Info->course);
    printf("Enter YearLevel: ");
    flush;
    scanf("%d", &Info->yearlvl);
}

void populateList(Studlist *List) {
    int n;
    printf("Enter Number of Students: ");
    scanf("%d", &n);
    int i;
    if (List->count < SIZE) {
        for (i = 0; i < n; i++) {
            printf("Enter Student[%d]: ", i + 1);
            getStudent(&List->stud[List->count]);
            List->count++;
        }
    } else {
        printf("LIST FULL.");
    }
}

void displayStudent(Studtype Info) {
    printf("ID: %u,\tName: %s %c. %s\t%s %d\n", Info.id, Info.name.fname, Info.name.mi, Info.name.lname, Info.course, Info.yearlvl);
}

void displayList(Studlist List) {
    system("cls");
    int x;
    for (x = 0; x < List.count; x++) {
        displayStudent(List.stud[x]);
    }
    printf("\n\nPress ENTER to go back to the main menu.");
    getch();
}

void findElem(Studlist List) {
    system("cls");
    int n;
    printf("--ID number you are looking for--\n");
    printf("ID: ");
    flush;
    scanf("%d", &n);
    int x;
    for (x = 0; x < List.count && List.stud[x].id != n; x++) {}
    if (x < List.count) {
        printf("ID FOUND\n");
        displayStudent(List.stud[x]);
    } else {
        printf("ID NOT FOUND\n");
    }
    printf("\n\nPress ENTER to go back to the main menu.");
    getch();
}

void addStudent(Studlist *List) {
    system("cls");
    if (List->count < SIZE) {
        printf("Enter Student[%d]: ", List->count + 1);
        getStudent(&List->stud[List->count]);
        List->count++;
    } else {
        printf("LIST IS FULL.\n");
    }
    printf("\n\nPress ENTER to go back to the main menu.");
    getch();
}

void insertFirst(Studlist *List) {
    system("cls");
    int x;
    if (List->count < SIZE) {
        for (x = List->count; x > 0; x--) {
            List->stud[x] = List->stud[x - 1];
        }
        getStudent(&List->stud[0]);
        List->count++;
    } else {
        printf("LIST IS FULL\n");
    }
    printf("\n\nPress ENTER to go back to the main menu.");
    getch();
}

void deleteStudent(Studlist *List) {
    system("cls");
    int id;
    printf("Enter ID you want to DELETE: ");
    scanf("%d", &id);
    int x;
    for (x = 0; x < List->count && List->stud[x].id != id; x++) {}
    if (x < List->count) {
        int y;
        for (y = x + 1; y < List->count; y++) {
            List->stud[y - 1] = List->stud[y];
        }
        List->count--;
    } else {
        printf("ID NOT FOUND\n");
    }
    printf("\n\nPress ENTER to go back to the main menu.");
    getch();
}

void sortList(Studlist *List) {
    system("cls");
    printf("THIS WILL SORT THE LIST");
    int x, y;
    for (x = 0; x < List->count - 1; x++) {
        int min = x;
        for (y = x + 1; y < List->count; y++) {
            if (List->stud[y].id < List->stud[min].id) {
                min = y;
            }
        }
        Studtype temp = List->stud[x];
        List->stud[x] = List->stud[min];
        List->stud[min] = temp;
    }
    
    printf("\n\nPress ENTER to go back to the main menu.");
    getch();
}

void displayCourse(Studlist List) {
    system("cls");
    char c[8];
    printf("THIS WILL DISPLAY THE COURSE YOU INPUTTED\n");
    printf("Enter Course: ");
    scanf("%s", c);
    int x;
    for (x = 0; x < List.count; x++) {
        if (strcmp(List.stud[x].course, c) == 0) {
            displayStudent(List.stud[x]);
        }
    }
    printf("\n\nPress ENTER to go back to the main menu.");
    getch();
}
 void insertSorted(Studlist* List){
    addStudent(&List);
    sortList(List);
}