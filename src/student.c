#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Student limit reached!\n");
        return;
    }

    int id, i;

    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (students[i].id == id)
        {
            printf("Student ID already exists!\n");
            return;
        }
    }

    students[*count].id = id;

    printf("Enter Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", students[*count].department);

    printf("Enter Semester: ");
    scanf("%d", &students[*count].semester);

    students[*count].marks = 0;
    students[*count].totalClasses = 0;
    students[*count].attendedClasses = 0;

    (*count)++;

    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nID: %d", students[i].id);
        printf("\nName: %s", students[i].name);
        printf("\nDepartment: %s", students[i].department);
        printf("\nSemester: %d\n", students[i].semester);
    }
}

void searchStudent(Student students[], int count)
{
    int id, i;

    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("\nStudent Found!");
            printf("\nName: %s", students[i].name);
            printf("\nDepartment: %s", students[i].department);
            printf("\nSemester: %d\n", students[i].semester);
            return;
        }
    }

    printf("Student not found.\n");
}

void updateStudent(Student students[], int count)
{
    int id, i;

    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Department: ");
            scanf(" %[^\n]", students[i].department);

            printf("Enter New Semester: ");
            scanf("%d", &students[i].semester);

            printf("Student updated successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void deleteStudent(Student students[], int *count)
{
    int id, i, j;

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++)
    {
        if (students[i].id == id)
        {
            for (j = i; j < *count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("Student deleted successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}

// Edge case handling for adding student, student name and department must be string and should not be empty, student id should be assign automatically by the system, the system must generate a unique id for each student, the id should be incremented by 1 for each new student added. The system should also check if the student name and department are not empty before adding the student. If they are empty, the system should prompt the user to enter valid values. the semester should be valid positive number in range between 1-8
// once the student is addedd its id should be displayed to the user. along with student added successfully message. 
// after that the system should ask for another student to be added or not. If yes, repeat the process, else exit the program.
