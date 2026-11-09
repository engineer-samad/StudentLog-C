#include <stdio.h>
#include "attendance.h"

void markAttendance(Student students[], int count)
{
    int id, i;

    printf("Enter Student ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter Total Classes: ");
            scanf("%d", &students[i].totalClasses);

            printf("Enter Attended Classes: ");
            scanf("%d", &students[i].attendedClasses);

            if (students[i].totalClasses <= 0 ||
                students[i].attendedClasses < 0 ||
                students[i].attendedClasses >
                students[i].totalClasses)
            {
                printf("Invalid attendance!\n");

                students[i].totalClasses = 0;
                students[i].attendedClasses = 0;

                return;
            }

            printf("Attendance saved successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void attendanceReport(Student students[], int count)
{
    int i;
    float percentage;

    printf("\n----- ATTENDANCE REPORT -----\n");

    for (i = 0; i < count; i++)
    {
        printf("\nID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);

        if (students[i].totalClasses == 0)
        {
            printf("Attendance not entered.\n");
        }
        else
        {
            percentage =
                (float)students[i].attendedClasses /
                students[i].totalClasses * 100;

            printf("Attendance: %.2f%%\n", percentage);

            if (percentage < 75)
                printf("Attendance Shortage!\n");
            else
                printf("Attendance Satisfactory.\n");
        }
    }
}

// monthly attendance --> each month have either 30 or 31 days, so we can take 30 days as a month and 12 months in a year. So total classes in a year = 30 * 12 = 360 classes.
// Enter student id, total classes, attended classes, and then calculate the attendance percentage. If the percentage is less than 75%, print "Attendance Shortage!", else print "Attendance Satisfactory."
// After that the program should ask again if the user wants to enter another student's attendance or not. If yes, repeat the process, else exit the program.
