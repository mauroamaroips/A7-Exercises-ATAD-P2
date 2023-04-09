#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"
#include "input.h"

int main() {
   
    Student students[200];

    int n = loadStudents(students, 60);

    //Ponteiros e tipos compostos - 1

    for(int i=0; i < n; i++) {
        //printf("Student[%2d]: %s \n", i, students[i].name);
        studentPrint(&students[i]);
    }

    //Ponteiros e tipos compostos - 2

    Student student1 = {"Shelby Newton", "5047531556", 6};

    printf("\nComparing students stored at different locations: \n");
    studentPrint(&students[0]);
    studentPrint(&student1);

    bool same = studentSame(&students[0], &student1);
    bool equals = studentSame(&students[1], &students[1]);

    printf("\nAre they the same student? %s \n", (same ? "Yes" : "No"));
    printf("\nAre they the same student? %s \n", (equals ? "Yes" : "No"));


    //Ponteiros e tipos compostos - 2

    return EXIT_SUCCESS;
}
