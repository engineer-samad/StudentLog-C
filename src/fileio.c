#include <stdio.h>
#include "fileio.h"

void saveRecords(Student students[], int count)
{
    FILE *fp;

    fp = fopen("data/students.dat", "wb");

    if (fp == NULL)
    {
        printf("File could not be opened!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);

    fwrite(students, sizeof(Student), count, fp);

    fclose(fp);

    printf("Records saved successfully!\n");
}

void loadRecords(Student students[], int *count)
{
    FILE *fp;

    fp = fopen("data/students.dat", "rb");

    if (fp == NULL)
    {
        *count = 0;
        return;
    }

    if (fread(count, sizeof(int), 1, fp) != 1)
    {
        *count = 0;
        fclose(fp);
        return;
    }

    if (*count < 0 || *count > MAX_STUDENTS)
    {
        *count = 0;
        fclose(fp);
        return;
    }

    if (fread(students, sizeof(Student), *count, fp) !=
        (size_t)*count)
    {
        *count = 0;
    }

    fclose(fp);
}

void backupRecords(Student students[], int count)
{
    FILE *fp;

    fp = fopen("data/students_backup.dat", "wb");

    if (fp == NULL)
    {
        printf("Backup failed!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);

    fwrite(students, sizeof(Student), count, fp);

    fclose(fp);

    printf("Backup created successfully!\n");
}

void exportCSV(Student students[], int count)
{
    FILE *fp;
    int i;

    fp = fopen("data/students.csv", "w");

    if (fp == NULL)
    {
        printf("CSV file could not be created!\n");
        return;
    }

    fprintf(fp, "ID,Name,Department,Semester,Marks\n");

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%s,%d,%.2f\n",
                students[i].id,
                students[i].name,
                students[i].department,
                students[i].semester,
                students[i].marks);
    }

    fclose(fp);

    printf("CSV file created successfully!\n");
}


// the program must store the data in a binary file automatically. for example is a new student is added the student record be saved automatically, if i terminate the program and restart it again the data should be loaded automatically from the binary file. The program should also export the data to a CSV file automatically after every 10 records are added. The CSV file should be named as "students.csv".
// data of the student must be saved in consistent order, like in dbs, student attendance data, marks data, and student personal data should be saved in the same order as they are added. 
// for exporting data as csv their should be options: 1. students list 2. students attendance report 3. students marks report. The user should be able to select which report to export as csv. The csv file should be named as "students_list.csv", "students_attendance_report.csv", "students_marks_report.csv", "students_transcript_report.csv" respectively.
