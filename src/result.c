#include <stdio.h>
#include "result.h"

char calculateGrade(float marks)
{
    if (marks >= 85)
        return 'A';

    else if (marks >= 70)
        return 'B';

    else if (marks >= 60)
        return 'C';

    else if (marks >= 50)
        return 'D';

    else
        return 'F';
}

float calculateGPA(float marks)
{
    if (marks >= 85)
        return 4.0;

    else if (marks >= 80)
        return 3.7;

    else if (marks >= 75)
        return 3.3;

    else if (marks >= 70)
        return 3.0;

    else if (marks >= 65)
        return 2.7;

    else if (marks >= 60)
        return 2.3;

    else if (marks >= 55)
        return 2.0;

    else if (marks >= 50)
        return 1.0;

    else
        return 0.0;
}

void showResult(Student students[], int count)
{
    int id, i;

    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("\n----- STUDENT RESULT -----\n");

            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);

            printf("Grade: %c\n",
                   calculateGrade(students[i].marks));

            printf("GPA: %.2f\n",
                   calculateGPA(students[i].marks));

            if (students[i].marks >= 50)
                printf("Status: PASS\n");
            else
                printf("Status: FAIL\n");

            return;
        }
    }

    printf("Student not found!\n");
}

// first define the course name of 5 subjects for every semester hardcoded in the program. Then, the program should ask for the student id and semester. After that, the program should display the course names of that semester and ask for the marks of each subject. The program should then calculate the total marks and average marks of the student and display it along with the grade and GPA. The program should also check if the student has passed or failed based on the average marks. If the average marks is greater than or equal to 50, then the student has passed, else the student has failed. The program should also ask if the user wants to enter another student's marks or not. If yes, repeat the process, else exit the program.
