#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define flush fflush(stdin)


typedef char string[50];

typedef struct{
    string Lname;
    string Fname;
    char MI;
}Nametype;

typedef struct{
    Nametype name;
    int id;
    string course;
    int yearlvl;
}studType;

typedef struct{
    studType stud[MAX];
    int count;
}studList;

studList initialize();
void populateList(studList*);
void addStud(studType*);
void displayStudent(studType);
void displayList(studList);
void displayCourse(studList);
void findElem(studList);
void deleteStudet(studList*); 
void sortList(studList*);
void addStudent(studList*);
void addStudent_First(studList*);
void addStudent_inSort(studList*);

int main(){
    // studList first = initialize();
    // populateList(&first);
    studType firsts[6] = {
                          {{"Detablan","Paul France",'M'}, 23100209, "BSCS",1},
                          {{"Cimafranca","Adrian",'O'}, 23100553,"BSIS", 1},
                          {{"Ancajas","Paul Winston",'T'}, 23102628,"BSIS", 1},
                          {{"Jakosalem","Carlos Miguel",'K'}, 23100571,"BSCS", 1},
                          {{"Ouano","Luis Andrei",'E'}, 23100371,"BSCS", 1},
                          {{"Tundag","Kenji",'D'}, 23100244,"BSIT", 1}
                         };
    studList second = {{firsts[0],firsts[1],firsts[2],firsts[3],firsts[4],firsts[5]},6};

    int option = 0;
    while(1){
        printf("1. Display Record.\n");
        printf("2. Display Record of same Course.\n");
        printf("3. Find Student by ID.\n");
        printf("4. Delete Student by ID in Record.\n");
        printf("5. Sort Record.\n");
        printf("6. Add Student.\n");
        printf("7. Add Student at First index.\n");
        printf("8. Add Student in Sorted List.\n");
        printf("Enter option number: ");
        flush;
        scanf("%d",&option);

        switch(option){
            case 1:
            displayList(second);
            break;

            case 2:
            displayCourse(second);
            break;

            case 3:
            findElem(second);
            break;

            case 4:
            deleteStudet(&second);
            break;

            case 5:
            sortList(&second);
            break;

            case 6:
            addStudent(&second);
            break;

            case 7:
            addStudent_First(&second);
            break;

            case 8:
            addStudent_inSort(&second);
            break;

            case 9:
            exit(0);
        }
        option = 0;
    }
}

studList initialize(){
    studList f = {.count = 0};
    return f;
}

void getStudent(studType* info){
    printf("Student's last name: ");
    flush;
    scanf("%[^\n]s",info->name.Lname);
    printf("Student's first name: ");
    flush;
    scanf("%[^\n]s",info->name.Fname);
    printf("Student's middle name: ");
    flush;
    scanf("%c",&info->name.MI);
    printf("Student's ID: ");
    flush;
    scanf("%d",&info->id);
    printf("Student's course: ");
    flush;
    scanf("%s",info->course);
    printf("Student's yearlevel: ");
    flush;
    scanf("%d",&info->yearlvl);
}

void populateList(studList* LIST){
    int add;
    printf("Input number of STUDENTS: ");
    scanf("%d",&add);

    int i;
    if(LIST->count < MAX){
        for(i=0;i<add;i++){
            printf("===Enter student%d details===\n",i+1);
            getStudent(&LIST->stud[i]);
            LIST->count++;
        }
        printf("\n");     
    }else{
        printf("NO SPACE AVAILABLE\n\n");
    }
}

void displayStudent(studType info){
    printf("ID Number: %d\tCourse: %s Yr.%d\tName: %s,%s %c.\n",info.id,info.course,info.yearlvl,info.name.Lname,info.name.Fname,info.name.MI);
}

void displayList(studList List){
    int i;
    for(i=0;i<List.count;i++){
        printf("%d. ",i+1);
        displayStudent(List.stud[i]);
    }
    printf("\n");
}

void displayCourse(studList List){
    string Course;
    printf("Enter Course: ");
    scanf("%s",Course);

    int i;
    printf("\n");
    for(i=0;i<List.count;i++){
        if(strcmpi(List.stud[i].course,Course) == 0){
            displayStudent(List.stud[i]);
        }
    }
    printf("\n");
}

void findElem(studList List){
    int ID;
    printf("Enter Student Id: ");
    scanf("%d",&ID);

    int i;
    for(i=0;i<List.count&&List.stud[i].id != ID;i++){}
    if(i<List.count){
        printf("\n");
        displayStudent(List.stud[i]);
        printf("\n");
    }else{
        printf("ID NOT IN RECORD.\n\n");
    }
}

void deleteStudet(studList* List){
    int ID;
    printf("Enter Student Id: ");
    scanf("%d",&ID);

    int i;
    int x;
    for(i=0;i<List->count&&List->stud[i].id != ID;i++){}
    if(i<List->count){
       for(x=i;x<List->count-1;x++){
        List->stud[x] = List->stud[x+1];
       }
       List->count--;
       printf("STUDENT SUCCESSFULLY REMOVED\n\n");
    }else{
        printf("ID NOT IN RECORD.\n\n");
    }
} 

void sortList(studList* List){
    int i,j;

    for(i=0;i<List->count-1;i++){
        int min = i;
        for(j=i+1;j<List->count;j++){
            if(List->stud[j].id < List->stud[min].id){
                min = j;
            }
        }
        studType temp = List->stud[i];
        List->stud[i] = List->stud[min];
        List->stud[min] = temp;
    }
    for(i=0;i<List->count;i++){
        printf("%d. ",i+1);
        displayStudent(List->stud[i]);
    }
    printf("\n");
}

void addStudent(studList* List){
    printf("Student Details: \n");
    if(List->count < MAX){
        getStudent(&List->stud[List->count]);
        List->count++;
        printf("STUDENT SUCCESSFULLY ADDED.\n\n");     
    }else{
        printf("NO SPACE AVAILABLE\n\n");
    }
}

void addStudent_First(studList* List){
    int x;
    if(List->count < MAX){
        for(x=List->count;x>0;x--){
            List->stud[x] = List->stud[x-1];
        }
        getStudent(&List->stud[0]);
        List->count++;
        printf("STUDENT SUCCESSFULLY ADDED.\n\n");
    }else{
        printf("NO SPACE AVAILABLE\n\n");
    }
}

void addStudent_inSort(studList* List){
    addStudent(List);
    sortList(List);
}