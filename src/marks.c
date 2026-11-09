#include <stdio.h>
#include "marks.h"

void enterMarks(Student students[], int count)
{
    int id;
    int i;
    float marks;
    int ch;

    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }

    printf("Enter Student ID: ");
    if (scanf("%d", &id) != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
        printf("Invalid student ID.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter marks (0-100): ");
            if (scanf("%f", &marks) != 1)
            {
                while ((ch = getchar()) != '\n' && ch != EOF)
                {
                }
                printf("Invalid marks.\n");
                return;
            }

            if (marks < 0 || marks > 100)
            {
                printf("Marks must be between 0 and 100.\n");
                return;
            }

            students[i].marks = marks;
            printf("Marks updated successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}
