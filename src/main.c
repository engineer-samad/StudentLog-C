#include <stdio.h>
#include <student.h>
#include <marks.h>
#include <result.h>
#include <attendance.h>
#include <report.h>
#include <fileio.h>
#include <auth.h>

// Helper function to read input safely and flush standard input buffer
static int getChoice(void)
{
    int choice, status;
    status = scanf("%d", &choice);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (status != 1)
    {
        return -1; // Return error sentinel for invalid input
    }
    return choice;
}

int main(void)
{
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    if (adminLogin() == 0)
    {
        printf("Authentication failed. Exiting...\n");
        return 0;
    }

    loadRecords(students, &count);

    do
    {
        printf("\n====================================\n");
        printf(" UNIVERSITY STUDENT RECORD SYSTEM\n");
        printf("====================================\n");

        printf("1.  Add Student\n");
        printf("2.  Display Students\n");
        printf("3.  Search Student\n");
        printf("4.  Update Student\n");
        printf("5.  Delete Student\n");
        printf("6.  Enter Marks\n");
        printf("7.  View Result\n");
        printf("8.  Enter Attendance\n");
        printf("9.  Attendance Report\n");
        printf("10. Merit List\n");
        printf("11. Class Statistics\n");
        printf("12. Student Transcript\n");
        printf("13. Save Records\n");
        printf("14. Create Backup\n");
        printf("15. Export CSV\n");
        printf("0.  Exit\n");

        printf("\nEnter your choice: ");
        choice = getChoice();

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                saveRecords(students, count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                saveRecords(students, count);
                break;

            case 5:
                deleteStudent(students, &count);
                saveRecords(students, count);
                break;

            case 6:
                enterMarks(students, count);
                saveRecords(students, count);
                break;

            case 7:
                showResult(students, count);
                break;

            case 8:
                markAttendance(students, count);
                saveRecords(students, count);
                break;

            case 9:
                attendanceReport(students, count);
                break;

            case 10:
                showMeritList(students, count);
                break;

            case 11:
                showStatistics(students, count);
                break;

            case 12:
                showTranscript(students, count);
                break;

            case 13:
                saveRecords(students, count);
                printf("Records saved successfully.\n");
                break;

            case 14:
                backupRecords(students, count);
                break;

            case 15:
                exportCSV(students, count);
                break;

            case 0:
                saveRecords(students, count);
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option number.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}