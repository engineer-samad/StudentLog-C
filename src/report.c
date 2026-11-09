#include <stdio.h>
#include "report.h"
#include "result.h"

void showMeritList(Student students[], int count)
{
    Student copy[MAX_STUDENTS];
    Student temp;

    int i, j;

    if (count == 0)
    {
        printf("No records available!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        copy[i] = students[i];
    }

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (copy[j].marks < copy[j + 1].marks)
            {
                temp = copy[j];
                copy[j] = copy[j + 1];
                copy[j + 1] = temp;
            }
        }
    }

    printf("\n----- MERIT LIST -----\n");

    for (i = 0; i < count; i++)
    {
        printf("%d. %s - %.2f Marks\n",
               i + 1, copy[i].name, copy[i].marks);
    }
}

void showStatistics(Student students[], int count)
{
    int i, pass = 0, fail = 0;
    float total = 0;

    if (count == 0)
    {
        printf("No records available!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        total = total + students[i].marks;

        if (students[i].marks >= 50)
            pass++;
        else
            fail++;
    }

    printf("\n----- CLASS STATISTICS -----\n");

    printf("Total Students: %d\n", count);
    printf("Passed Students: %d\n", pass);
    printf("Failed Students: %d\n", fail);
    printf("Average Marks: %.2f\n", total / count);
}

void showTranscript(Student students[], int count)
{
    int id, i;

    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("\n----- STUDENT TRANSCRIPT -----\n");

            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Semester: %d\n", students[i].semester);
            printf("Marks: %.2f\n", students[i].marks);

            printf("Grade: %c\n",
                   calculateGrade(students[i].marks));

            printf("GPA: %.2f\n",
                   calculateGPA(students[i].marks));

            return;
        }
    }

    printf("Student not found!\n");
}