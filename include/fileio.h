#ifndef FILEIO_H
#define FILEIO_H

#include "student.h"

void saveRecords(Student students[], int count);

void loadRecords(Student students[], int *count);

void backupRecords(Student students[], int count);

void exportCSV(Student students[], int count);

#endif