#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define flush fflush(stdin)

typedef char string[20];

//data structure
typedef struct{
    int month,day,year;
}Date;

//complete name structure
typedef struct name{
    string fname,mname,lname;
}Name;

//Student information structure
typedef struct stud{
    string id;
    Name stud_name;
    int age;
    bool gender; // false = female, true = male
    Date birth_date;
}StudInfo;

//List of student structure
typedef struct{
    StudInfo* class; // dynamically allocated array
    int ctr; // current number of student in list
    int max; // maximum number of student in the list
}ClassList, *ClassListPtr;

void display(StudInfo);
void displayList(ClassList, ClassListPtr);
void findElem(ClassList,ClassListPtr);
void deleteStudet(ClassList*,ClassListPtr);
void swap(StudInfo*,StudInfo*);
void sortList(ClassList*,ClassListPtr);
void getstudent(StudInfo*);
void addStudentboth(ClassList*,ClassListPtr);
void addStudent_First(ClassList*,ClassListPtr);
void addStudent_inSort(ClassList*,ClassListPtr);

int main(){
    ClassList CS;
    ClassListPtr IT;

    CS.ctr = 0;
    CS.max = 10;
    CS.class = (StudInfo*)malloc(sizeof(StudInfo)*CS.max);
    IT = (ClassListPtr)malloc(sizeof(ClassList));
    IT->ctr = 0;
    IT->max = 10;
    IT->class = (StudInfo*)malloc(sizeof(StudInfo)*IT->max);
    int option = 0;
    ClassList Same_year;

    while(1){
        printf("===Class List of Computer Science and Information Technology===\n");
        printf("1. Display List.\n");
        printf("2. Find Student by ID.\n");
        printf("3. Delete Student by name.\n");
        printf("4. Sort List.\n");
        printf("5. Add student in CS and IT(same student).\n");
        printf("6. Add student at first index(same student).\n");
        printf("7. Add student in sorted List.\n");
        printf("0. Exit\n");
        printf("Enter option number: ");
        scanf("%d",&option);

        switch(option){
            case 1:
            displayList(CS,IT);
            break;

            case 2:
            findElem(CS,IT);
            break;

            case 3:
            deleteStudet(&CS,IT);
            break;

            case 4:
            sortList(&CS,IT);
            break;

            case 5:
            addStudentboth(&CS,IT);
            break;

            case 6:
            addStudent_First(&CS,IT);
            break;

            case 7:
            addStudent_inSort(&CS,IT);
            break;

            case 0:
            free(CS.class);
            free(IT->class);
            free(IT);
            free(Same_year.class);
            exit(0);
            break;
        }
        option = 0;
    }
    return 0;
}

void display(StudInfo prog){
    printf("ID: %s\t",prog.id);
    printf("AGE: %d\t",prog.age);
    printf("GENDER: %s\t",(prog.gender == true)? "Male":"Female");
    printf("Birth Date: %d/%d/%d\t",prog.birth_date.month,prog.birth_date.day,prog.birth_date.year);
    printf("NAME: %s, %s %c.\t\n",prog.stud_name.lname,prog.stud_name.fname,prog.stud_name.mname[0]);
}

void displayList(ClassList CS, ClassListPtr IT){
    if(CS.ctr!= 0 || IT->ctr != 0){
        int i;
        printf("\n======CLASSLIST CS======\n");
        for(i=0;i<CS.ctr;i++){
            display(CS.class[i]);
        }printf("\n\n");

        printf("======CLASSLIST IT======\n");
        for(i=0;i<IT->ctr;i++){
            display(IT->class[i]);
        }printf("\n\n");
    }else{
        printf("CLASSLIST IS EMPTY\n\n");
    }
}

void findElem(ClassList CS,ClassListPtr IT){
    string id;
    printf("Enter ID: ");
    scanf(" %s",id);

    int i,j;
    for(i=0;i<CS.ctr&& strcmp(CS.class[i].id,id)!= 0;i++){}
    for(j=0;j<CS.ctr&& strcmp(IT->class[j].id,id)!= 0;j++){}
    if(i<CS.ctr &&i<IT->ctr){
        printf("\n======CLASSLIST CS======\n");
        display(CS.class[i]);
        printf("\n\n");
        printf("======CLASSLIST IT======\n");
        display(IT->class[i]);
        printf("\n\n");
    }else{
        printf("STUDENT NOT IN LIST\n\n");
    }
}

void getstudent(StudInfo* info){
    printf("Enter student ID: ");
    scanf(" %s",info->id);
    printf("Enter Last Name: ");
    scanf(" %[^\n]s",info->stud_name.lname);
    printf("Enter First Name: ");
    scanf(" %[^\n]s",info->stud_name.fname);
    printf("Enter Middle Name: ");
    scanf(" %s",info->stud_name.mname);
    printf("Enter Age: ");
    scanf("%d",&info->age);
    printf("Enter gender(1=M,0=FM): ");
    scanf("%d",&info->gender);
    printf("Enter Month of Bday: ");
    scanf("%d",&info->birth_date.month);
    printf("Enter Day of Bday: ");
    scanf("%d",&info->birth_date.day);
    printf("Enter Year of Bday: ");
    scanf("%d",&info->birth_date.year);
}


void addStudentboth(ClassList* CS,ClassListPtr IT){
    if(CS->ctr < CS->max ){
        printf("===STUDENT %d===\n",CS->ctr+1);
        getstudent(&CS->class[CS->ctr]);
        IT->class[IT->ctr++] = CS->class[CS->ctr++];
        printf("SUCCESFULLY ADDED STUDENT IN CS AND IT\n\n");
    }else{
        printf("NO SPACE\n\n");
    }
}

void addStudent_First(ClassList* CS,ClassListPtr IT){
    if(CS->ctr < CS->max ){
        int i;
        for(i=CS->ctr;i>0;i--){
            CS->class[i] = CS->class[i-1];
            IT->class[i] = IT->class[i-1];
        }
        getstudent(&CS->class[0]);
        IT->class[0] = CS->class[0];
        CS->ctr++;IT->ctr++;
        printf("SUCCESFULLY ADDED STUDENT IN CS AND IT\n\n");
    }else{
        printf("NO SPACE\n\n");
    }
}


void deleteStudet(ClassList* CS,ClassListPtr IT){
    string id;
    printf("Enter ID: ");
    scanf(" %s",id);

    int i,j,x,y;
    for(i=0;i<CS->ctr&& strcmp(CS->class[i].id,id)!= 0;i++){}
    for(j=0;j<IT->ctr&& strcmp(IT->class[j].id,id)!= 0;j++){}
    if(i<CS->ctr &&i<IT->ctr){
        for(x=i+1,y=j+1;x<CS->ctr,y<IT->ctr;x++,y++){
            CS->class[x-1] = CS->class[x];
            IT->class[y-1] = IT->class[y];
        }
        CS->ctr--;IT->ctr--;
        printf("SUCCESSFULLY DELETED STUDENT\n\n");
        displayList(*CS,IT);
    }else{
        printf("STUDENT NOT IN LIST\n\n");
    }
}

void swap(StudInfo* info1, StudInfo* info2){
    StudInfo temp = *info1;
    *info1 = *info2;
    *info2 = temp;
}

void sortList(ClassList* CS, ClassListPtr IT) {
    int i, j, x, y;
    for (i = 0, x = 0; i < CS->ctr && x < IT->ctr; i++, x++) {
        int min = i;
        int low = x;
        for (j = i + 1, y = x + 1; j < CS->ctr && y < IT->ctr; j++, y++) {
            if (strcmp(CS->class[j].id, CS->class[min].id) < 0) {
                min = j;
            }
            if (strcmp(IT->class[y].id, IT->class[low].id) < 0) {
                low = y;
            }
        }
        swap(&CS->class[i], &CS->class[min]);
        swap(&IT->class[x], &IT->class[low]);
    }
    displayList(*CS, IT);
}

void addStudent_inSort(ClassList* CS,ClassListPtr IT){
    addStudentboth(CS,IT);
    sortList(CS,IT)
}
