#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"
#include "input.h"

Student studentCreate(char *name, char *number, int grade) {
    Student student;

    strcpy(student.name, name);
    strcpy(student.number, number);
    student.grade = grade;

    return student;
}

int loadStudents(Student arr[], int howMany) {

    FILE* stream = fopen("students.csv", "r");

    int count = 0;
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        if(count == howMany) break;

        char* tmp = strdup(line);
        
        char** tokens = splitString(tmp, 3, ";");
        
        int grade = atoi(tokens[2]);
        arr[count++] = studentCreate(tokens[0], tokens[1], grade);

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return count;
}

//Ponteiros e tipos compostos - 1

void studentPrint(PtStudent s) {
   printf("%-15s | %-30s | %d \n", s->number, s->name, s->grade);
}

//Ponteiros e tipos compostos - 2

 bool studentSame(PtStudent s1, PtStudent s2){
    return (s1 == s2);
 }

 //Ponteiros e tipos compostos - 3

 bool studentEquals(PtStudent s1, PtStudent s2){
    if(strcmp(s1->name, s2->name) == 0 && strcmp(s1->name, s2->number) == 0 && s1->grade == s2->grade) return true;
 
    return false;
 }