#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct
{
    int id;
    char name[50];
    char department[40];
    int semester;
    float marks;
    int totalClasses;
    int attendedClasses;

} Student;

void addStudent(Student students[], int *count);

void displayStudents(Student students[], int count);

void searchStudent(Student students[], int count);

void updateStudent(Student students[], int count);

void deleteStudent(Student students[], int *count);

#endif