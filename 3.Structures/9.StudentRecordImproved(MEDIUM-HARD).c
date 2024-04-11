#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 50
#define flush fflush(stdin)

typedef enum {absent,present}availability;
typedef struct{
    char lName[16];
    char fName[24];
    char MI;
}Nametype;

typedef struct{
    Nametype name;
    int id;
    char course[8];
    int yearlvl;
    availability attendance;
}Studtype;

typedef struct{
    Studtype* stud;
    int count;
    int max;
}StudList;

void addstudent(StudList*);
void display(Studtype);
void displayblock(StudList);
void findElem(StudList);
void addstudent_many(StudList*);
void addstudent_pos(StudList*);
void sort_ascen(StudList*);
void sort_descen(StudList*);
void addstudent_sort(StudList*);
void display_samecourse(StudList);
void delete_samecourse(StudList*);
void deletestudent(StudList*);

int main(){
    StudList blockA;
    blockA.count = 0;
    blockA.max = MAX;
    blockA.stud = (Studtype*)malloc(sizeof(Studtype)*blockA.max);
    int option = 0;

    Studtype first[6] = {
                          {{"Detablan","Paul France",'M'}, 23100209, "BSCS",1,1},
                          {{"Cimafranca","Adrian",'O'}, 23100553,"BSIS", 1,1},
                          {{"Ancajas","Paul Winston",'T'}, 23102628,"BSIS", 1,1},
                          {{"Jakosalem","Carlos Miguel",'K'}, 23100571,"BSCS", 1,1},
                          {{"Ouano","Luis Andrei",'E'}, 23100371,"BSCS", 1,1},
                          {{"Tundag","Kenji",'D'}, 23100244,"BSIT", 1,1}
                         };
    int i;
    for(i=0;i<6;i++){
        blockA.stud[i] = first[i];
    }
    blockA.count = 6;                   
    while(1){
        system("cls");
        printf("\t\t\t\t\t\tBlock Section A\n");
        printf("\t=======================================================================================================\n");
        printf("\t\t\t\t      ==========Basic features==========\n");
        printf("\t\t\t\t      1. Add a student at the end of the list\n");
        printf("\t\t\t\t      2. Display Block\n");
        printf("\t\t\t\t      3. Find student in Block\n\n");
        printf("\t\t\t====================Bellow are advance features====================\n");
        printf("\t\t\t\t      4. Add multiple students\n");
        printf("\t\t\t\t      5. Add student at position\n");
        printf("\t\t\t\t      6. Sort students in ascending order\n");
        printf("\t\t\t\t      7. Sort students in descending order\n");
        printf("\t\t\t\t      8. Add student in sorted list\n");
        printf("\t\t\t\t      9. Display same Course\n");
        printf("\t\t\t\t      10.Delete same Course\n");
        printf("\t\t\t\t      11.Delete student\n");
        printf("\t\t\t\t      0.EXIT\n");
        printf("\t=======================================================================================================\n");
        printf("Enter your choice: ");
        flush;
        scanf("%d",&option);

        switch(option){
            case 1:
            addstudent(&blockA);
            break;

            case 2:
            displayblock(blockA);
            break;

            case 3:
            findElem(blockA);
            break;

            case 4:
            addstudent_many(&blockA);
            break;

            case 5:
            addstudent_pos(&blockA);
            break;

            case 6:
            sort_ascen(&blockA);
            break;

            case 7:
            sort_descen(&blockA);
            break;

            case 8:
            addstudent_sort(&blockA);
            break;

            case 9:
            display_samecourse(blockA);
            break;

            case 10:
            delete_samecourse(&blockA);
            break;

            case 11:
            deletestudent(&blockA);
            break;
            
            case 0:
            free(blockA.stud);
            exit(0);
        }
        option = 0;
    }
    return 0;
}

void getstudent(Studtype* info){
    printf("Input First name: ");
    flush;
    scanf(" %[^\n]",info->name.fName);
    printf("Input Middle name: ");
    flush;
    scanf(" %c",&info->name.MI);
    printf("Input Last name: ");
    flush;
    scanf(" %[^\n]",info->name.lName);
    printf("Input ID number: ");
    flush;
    scanf("%d",&info->id);
    printf("Input Course(BSIS,BSIT,BSCS): ");
    flush;
    scanf(" %s",&info->course);
    printf("Input Year level: ");
    flush;
    scanf(" %d",&info->yearlvl);
    printf("Input Student Attendance status(0 = Absent, 1 = Present): ");
    flush;
    scanf(" %d",&info->attendance);
}

void addstudent(StudList* A){
    if(A->count < A->max){
        system("cls");
        printf("==Note: This Function will only add 1 student in the block section==\n");
        getstudent(&A->stud[A->count++]);
        printf("Successfully add a student in block section\n");
    }else{
        printf("BLOCK IS FULL\n");
    }
    printf("press enter to go back option list");
    flush;
    getch();
}

void display(Studtype info){
    printf("\t\t%d\t",info.id);
    printf(" %s ",info.course);
    printf("%9d\t",info.yearlvl);
    printf(" \t %7s\t",(info.attendance)? "PRESENT":"ABSENT");
    printf(" %s,",info.name.lName);
    printf("%s ",info.name.fName);
    printf("%c.\n",info.name.MI);
}

void displayblock(StudList A){
    system("cls");
    printf("\n==This function display all student in a block section==\n\n");
    if(A.count != 0){
        int i;
        printf("\t\t\t\t\t\tBlock Section A\n");
        printf("\t=======================================================================================================\n");
        printf("\t\t   ID\t\tCourse    Yearlevel\tAttendance\t Name\n");
        printf("\t=======================================================================================================\n");
        for(i=0;i<A.count;i++){
            display(A.stud[i]);
        }
        printf("\t=======================================================================================================\n");
        printf("\n");
    }else{
        printf("Block section is empty\n");
    }
    printf("press enter to go back option list");
    flush;
    getch();
}

void findElem(StudList A){
    system("cls");
    printf("==Note: This function will find A student in the list by using student ID==\n");
    int id;
    printf("Enter student ID: ");
    scanf("%d",&id);
    int i;
    for(i=0;i<A.count && A.stud[i].id != id;i++);
    if(i<A.count){
        printf("\n\t\t\t\t\t\tBlock Section A\n");
        printf("\t=======================================================================================================\n");
        printf("\t\t   ID\t\tCourse    Yearlevel\tAttendance\t Name\n");
        display(A.stud[i]);
        printf("\t=======================================================================================================\n");
        printf("\n");
    }else{
        printf("ID not found in list\n\n");
    }
    printf("press enter to go back option list");
    flush;
    getch();
}

void addstudent_many(StudList* A){
    system("cls");
    int count;
    printf("==Note: This Function will add Multiple Students at the current last index of the List\n");
    printf("Enter the number of students you want to add: ");
    flush;
    scanf("%d",&count);

    if(A->count + count < A->max){
        int i;
        for(i=0;i<count;i++){
            printf("===Student [%d]===\n",A->count+i);
            getstudent(&A->stud[A->count+i]);
            printf("\n");
        }
        A->count+=count;
        flush;
        printf("Successfully added students\n\n");
    }else{
        printf("The amount will go beyond the max capacity\n");
    }
    printf("press enter to go back option list\n");
    flush;
    getch();
}

void addstudent_pos(StudList* A){
    system("cls");
    printf("==Note: This function will add a student and insert it on a position inputted by the user==\n");
    int pos;
    printf("Enter Position (0 - %d): ",A->count-1);
    flush;
    scanf("%d",&pos);

    if(A->count+pos < A->max){
        int i,x;
        for(i=0;i<A->count && i != pos;i++);
        for(x=A->count;x>=i;x--){
            A->stud[x] = A->stud[x-1];
        }
        getstudent(&A->stud[pos]);
        A->count++;
        flush;
        printf("Successfully added students\n\n");
    }else{
        printf("The amount will go beyond the max capacity\n");
    }
    printf("press enter to go back option list\n");
    flush;
    getch();
}

void sort_ascen(StudList* A){
    int i,j;
    for(i=0;i<A->count;i++){
        int min = i;
        for(j=i+1;j<A->count;j++){
            if(strcmp(A->stud[j].name.lName,A->stud[min].name.lName) < 0){
                min = j;
            }
        }
        Studtype temp = A->stud[i];    
        A->stud[i] = A->stud[min];
        A->stud[min] = temp;
    }
    displayblock(*A);
}

void sort_descen(StudList* A){
    int i,j;
    for(i=0;i<A->count;i++){
        int min = i;
        for(j=i+1;j<A->count;j++){
            if(strcmp(A->stud[j].name.lName,A->stud[min].name.lName) > 0){
                min = j;
            }
        }
        Studtype temp = A->stud[i];    
        A->stud[i] = A->stud[min];
        A->stud[min] = temp;
    }
    displayblock(*A);
}

void addstudent_sort(StudList* A){
    system("cls");
    printf("==Note: This function will add a student and then sort the list\n");
    addstudent(A);
    printf("Check if the student you add is in its proper location\n\n");
    sort_ascen(A);
}

void display_samecourse(StudList A){
    system("cls");
    printf("==Note: This function will display students in the block section with the same courses\n");
    char course[8];
    printf("Enter the course you want to display: ");
    flush;
    scanf("%s",course);
    int i;
    printf("\t\t\t\t\t\tBlock Section A\n");
    printf("\t=======================================================================================================\n");
    printf("\t\t   ID\t\tCourse    Yearlevel\tAttendance\t Name\n");
    printf("\t=======================================================================================================\n");
    for(i=0;i<A.count;i++){
        if(strcmp(A.stud[i].course,course) == 0){
            display(A.stud[i]);
        }
    }
    printf("\t=======================================================================================================\n");
    printf("\n");
    printf("press enter to go back option list\n");
    flush;
    getch();
}

void delete_samecourse(StudList* A){
    system("cls");
    printf("==Note This function will delete students in the block section with the same course\n");
    char course[8];
    printf("Enter the course you want to delete: ");
    flush;
    scanf("%s",course);
    int i=0,j;
    printf("\t\t\t\t\t\tBlock Section A\n");
    printf("\t=======================================================================================================\n");
    printf("\t\t   ID\t\tCourse    Yearlevel\tAttendance\t Name\n");
    printf("\t=======================================================================================================\n");
    while(i < A->count){
        if(strcmp(A->stud[i].course,course) == 0){
            for(j=i+1;j<A->count;j++){
                A->stud[j-1] = A->stud[j];
            }
            A->count--;
        }else{
            display(A->stud[i]);
            i++;
        }
    }
    printf("\t=======================================================================================================\n");

    printf("press enter to go back option list\n");
    flush;
    getch();
}

void deletestudent(StudList* A){
    system("cls");
    printf("==Note this function will delete a single student base on the user input==\n");
    int id;
    printf("Enter student ID for deletion: ");
    flush;
    scanf("%d",&id);
    int i;
    for(i=0;i<A->count && A->stud[i].id != id;i++);
    if(i < A->count){
        int x;
        for(x = i+1;x<A->count;x++){
            A->stud[x-1] = A->stud[x];
        }
        A->count--;
    }else{
        printf("ID not found in list\n\n");
    }
    displayblock(*A);
}