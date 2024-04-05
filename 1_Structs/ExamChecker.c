#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
#define flush fflush(stdin)

typedef struct {
    char firstName[50];
    char lastName[50];
    char middleInitial;
} Name;

typedef struct {
    Name studentName;
    int idNum;
    int studentGrades[3];
} StudentDetail;

typedef struct {
    StudentDetail student[MAX];
    int count;
} ClassRecord;

typedef struct {
    ClassRecord classList;
    ClassRecord examRetake[3]; 
} ClassResult;


void populate(ClassRecord *record, int classCount);
StudentDetail addStudent(char *fName, char *lName, char mi, int idNum, int grades[3]);
void checkExams(ClassResult *results);

int main() {
	int i;
	int x;
    int classCount;

    ClassResult results;
    results.classList.count = 0;

    results.examRetake[0].count = 0;  
    results.examRetake[1].count = 0;
    results.examRetake[2].count = 0;
    

    printf("Input Number of Students in Class: ");
    scanf("%d", &classCount);

    if (classCount <= 0 || classCount > MAX) {
        printf("Maximum Number of Students per Class is only %d", MAX);
        return 1; 
    }

    populate(&results.classList, classCount);
    checkExams(&results);

    
    for (i = 0; i < 3; i++) {
        printf("Retakers Needed for Exam %d:", i + 1);
        if (results.examRetake[i].count == 0) {
            printf("No Retakers for Exam %d\n\n", i + 1);
        } else if (results.examRetake[i].count == classCount) {
            printf("All Students Have to Retake Exam %d\n\n", i + 1);
        } else {
            for (x = 0; x < results.examRetake[i].count; x++) {
                printf("%s ", results.examRetake[i].student[x].studentName.firstName);
            }
            printf("\n\n");
        }
    }

    return 0;
}

void populate(ClassRecord *record, int classCount) {
    int i, x;
    char fName[50], lName[50];
    char MI;
    int idNum, grades[3];

    for (i = 0; i < classCount; i++) {
        printf("=== STUDENT %d ===\n\n", i + 1);

        printf("Input First Name: ");
        flush;
        scanf("%s", fName);
        printf("Input Last Name: ");
        flush;
        scanf("%s", lName); 
        printf("Input Middle Initial: ");
        flush;
        scanf("%c", &MI);
        printf("Input ID Number: ");
        flush;
        scanf("%d", &idNum);

        for (x = 0; x < 3; x++) {
            printf("Input Exam Score %d: ", x + 1);
            flush;
            scanf("%d", grades + x);
        }

        record->student[i] = addStudent(fName, lName, MI, idNum, grades);
        record->count++;
    }
}

StudentDetail addStudent(char *fName, char *lName, char mi, int idNum, int grades[3]) {
    int i;
    StudentDetail details;

    details.studentName.middleInitial = mi;
    strcpy(details.studentName.firstName, fName);
    strcpy(details.studentName.lastName, lName);

    details.idNum = idNum;
    for (i = 0; i < 3; i++) {
    details.studentGrades[i] = grades[i];
}

return details;
}

void checkExams(ClassResult *results) {
    int i, j;
    for (i = 0; i < results->classList.count; i++) { 
        for (j = 0; j < 3; j++) { 
            if (results->classList.student[i].studentGrades[j] < 60) {
                results->examRetake[j].student[results->examRetake[j].count] = results->classList.student[i];
                results->examRetake[j].count++;
            }
        }
    }
}
