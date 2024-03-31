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
}ClassList;

void getstudent(StudInfo*);           //Get student information
void displayList(ClassList);          //Display student information
void findElem(ClassList);             //Find student by ID and Display
void deleteStudet(ClassList*);        //delete student in List
void sortList(ClassList*);            //Sort the list(selection sort)
void addStudent(ClassList*);          //addstudent at last index
void addStudent_First(ClassList*);    //addstudent at first index
void addStudent_inSort(ClassList*);   //addstudent at correct index in sorted list
ClassList same_birthyear(ClassList);  //inialization function for student with same year
void displayList_sameyear(ClassList);


int main(){
    ClassList CS;
    CS.max = 10;
    CS.ctr = 0;
    CS.class = (StudInfo*)malloc(sizeof(StudInfo)*CS.max);
    int option = 0;
    ClassList Same_year;

    while(1){
        printf("===Class List of Computer Science===\n");
        printf("1. Display List.\n");
        printf("2. Display List with same year.\n");
        printf("3. Find Student by ID.\n");
        printf("4. Delete Student by name.\n");
        printf("5. Sort List.\n");
        printf("6. Add student.\n");
        printf("7. Add student at first index.\n");
        printf("8. Add student in sorted List.\n");
        printf("0. Exit\n");
        printf("Enter option number: ");
        scanf("%d",&option);

        switch(option){
            case 1:
            displayList(CS);
            break;

            case 2:
            Same_year = same_birthyear(CS);
            displayList_sameyear(Same_year);
            break;

            case 3:
            findElem(CS);
            break;

            case 4:
            deleteStudet(&CS);
            break;

            case 5:
            sortList(&CS);
            break;

            case 6:
            addStudent(&CS);
            break;

            case 7:
            addStudent_First(&CS);
            break;

            case 8:
            addStudent_inSort(&CS);
            break;

            case 0:
            free(CS.class);
            free(Same_year.class);
            exit(0);
            break;
        }
        option = 0;
    }

}

void getstudent(StudInfo*first){
    printf("Enter student ID: ");
    flush;
    scanf("%s",first->id);
    printf("Enter Last Name: ");
    flush;
    scanf("%[^\n]s",first->stud_name.lname);
    printf("Enter First Name: ");
    flush;
    scanf("%[^\n]s",first->stud_name.fname);
    printf("Enter Middle Name: ");
    flush;
    scanf("%s",first->stud_name.mname);
    printf("Enter Age: ");
    flush;
    scanf("%d",&first->age);
    printf("Enter gender(1=M,0=FM): ");
    flush;
    scanf("%d",&first->gender);
    printf("Enter Month of Bday: ");
    flush;
    scanf("%d",&first->birth_date.month);
    printf("Enter Day of Bday: ");
    flush;
    scanf("%d",&first->birth_date.day);
    printf("Enter Year of Bday: ");
    flush;
    scanf("%d",&first->birth_date.year);
}

void addStudent(ClassList*first){
    if(first->ctr < first->max){
        printf("===STUDENT %d===\n",first->ctr+1);
        getstudent(&first->class[first->ctr]);
        first->ctr++;
        printf("SUCCESSFULLY ADDED A STUDENT\n\n");
    }else{
        printf("NO MORE AVAILABLE SPACE.\n\n");
    }
}

void findElem(ClassList first){
    string id;
    printf("Enter Student ID: ");
    scanf("%s",id);
    int i;
    for(i=0;i<first.ctr&&strcmpi(first.class[i].id,id) != 0;i++){}
    if(i<first.ctr){
        printf("ID: %s\tBirthdate: %d/%d/%d\tAge: %d\t\tGender: ",first.class[i].id,first.class[i].birth_date.month,
        first.class[i].birth_date.day,first.class[i].birth_date.year,first.class[i].age);
        printf("%s\t",(first.class[i].gender)? "Male":"Female");
        printf("Name: %s,%s.%c\n",first.class[i].stud_name.lname,first.class[i].stud_name.fname,first.class[i].stud_name.mname[0]);
        printf("\n\n");
    }else{
        printf("NOT IN CLASSLIST\n\n");
    }
}

void deleteStudet(ClassList* first){
    string lname;
    printf("Enter student Last Name to delete student: ");
    flush;
    scanf("%s",lname);
    int i,j;
    for(i=0;i<first->ctr&& strcmpi(first->class[i].stud_name.lname,lname) != 0;i++){}
    if(i<first->ctr){
        for(j=i+1; j<first->ctr;j++){
                first->class[j-1] = first->class[j];
        }
        first->ctr--;
        printf("STUDENT SUCCESSFULLY DELETED\n\n");
    }else{
        printf("STUDENT NOT IN LIST\n\n");
    }
}

void displayList(ClassList first){
    int i;
    printf("===STUDENTS===\n");
    if(first.ctr !=0){
        for(i=0;i<first.ctr;i++){
            printf("ID: %s\tBirthdate: %d/%d/%d\tAge: %d\t\tGender: ",first.class[i].id,first.class[i].birth_date.month,
            first.class[i].birth_date.day,first.class[i].birth_date.year,first.class[i].age);
            printf("%s\t",(first.class[i].gender)? "Male":"Female");
            printf("Name: %s,%s.%c\n",first.class[i].stud_name.lname,first.class[i].stud_name.fname,first.class[i].stud_name.mname[0]);
        }
        printf("\n\n");
    }else{
        printf("LIST IS EMPTY\n\n");
    }
}

void sortList(ClassList* first){
    int i,j;
    for(i=0;i<first->ctr-1;i++){
        int min = i;
        for(j=i+1;j<first->ctr;j++){
            if(strcmpi(first->class[j].stud_name.lname,first->class[min].stud_name.lname) < 0){
                min = j;
            }
        }
        StudInfo temp = first->class[i];
        first->class[i] = first->class[min];
        first->class[min] = temp;
    }
    displayList(*first);
}

void addStudent_First(ClassList* first){
   if(first->ctr < first->max){
        int i;
        for(i=first->ctr;i>0;i--){
            first->class[i] =first->class[i-1];
        }
        getstudent(&first->class[0]);
        first->ctr++;
        printf("\n\n");
   }else{
        printf("NO MORE AVAILABLE SPACE.\n\n");
   }
}

/*Create a function that
adds a new student in 
the classlist collection.
adds the student based
on the lastname in ascending 
order.*/

void addStudent_inSort(ClassList* first){
    addStudent(first);
    int i,j;
    for(i=0;i<first->ctr-1;i++){
        int min = i;
        for(j=i+1;j<first->ctr;j++){
            if(strcmpi(first->class[j].stud_name.lname,first->class[min].stud_name.lname) < 0){
                min = j;
            }
        }
        StudInfo temp = first->class[i];
        first->class[i] = first->class[min];
        first->class[min] = temp;
    }
    printf("\n\n");
}

/*Create a function that would 
return all students name
that is born on a specified
birth year. use the concept
of adding a sentinel value 
using empty string as values.*/

ClassList same_birthyear(ClassList first){
    int year;
    printf("Enter Year: ");
    flush;
    scanf("%d",&year);

    ClassList second;
    second.ctr = 0;
    second.max = 10;
    
    int i,y = 0,count = 0;
    for(i=0;i<first.ctr;i++){
        if(first.class[i].birth_date.year == year){
            count++;
        }
    }
    second.ctr = count;
    second.class = (StudInfo*)malloc(sizeof(StudInfo)*count+1);
    for(i=0;i<first.ctr;i++){
        if(first.class[i].birth_date.year == year){
            second.class[y] = first.class[i];
            y++;
        }
    }
    strcpy(first.class[y].stud_name.lname," ");

    return second;
}

void displayList_sameyear(ClassList first){
    int i;
    printf("===STUDENTS===\n");
    if(first.ctr !=0){
        for(i=0;strcmp(first.class[i].stud_name.lname, " ") != 0;i++){
            printf("ID: %s\tBirthdate: %d/%d/%d\tAge: %d\t\tGender: ",first.class[i].id,first.class[i].birth_date.month,
            first.class[i].birth_date.day,first.class[i].birth_date.year,first.class[i].age);
            printf("%s\t",(first.class[i].gender)? "Male":"Female");
            printf("Name: %s,%s.%c\n",first.class[i].stud_name.lname,first.class[i].stud_name.fname,first.class[i].stud_name.mname[0]);
        }
        printf("\n\n");
    }else{
        printf("LIST IS EMPTY\n\n");
    }
}
