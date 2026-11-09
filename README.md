# Student Record System

A C-based student management application for handling academic records in a university or college environment. The system provides a menu-driven interface for managing student details, marks, attendance, results, reports, backups, and exports.

## Features

- Add, display, search, update, and delete student records
- Store and manage student academic information
- Enter and update marks per student
- Track class attendance and calculate attendance percentages
- View student results and merit list
- Generate class statistics and transcripts
- Create backups and export student data to CSV
- Secure admin login before using the system

## Project Structure

- `src/` – source code for the application modules
- `include/` – header files for declarations and shared structures
- `data/` – runtime records, backups, and export files
- `docs/` – documentation and design assets such as screenshots and reports
- `build/` – compiled executable output
- `Makefile` – build configuration for compiling the project

## Build Instructions

Make sure GCC and GNU Make are installed, then run:

```sh
make
```

This will build the executable at:

```sh
build/student-record-system.exe
```

## Run the Program

From the project root, execute:

```sh
./build/student-record-system.exe
```

On first launch, the system prompts for an admin login.

Default credentials:

- Username: `admin`
- Password: `1234`

## Notes

- The project is implemented in plain C and designed as a command-line application.
- Student records, backups, and exported files are stored under the `data` directory.
- The system is intended for academic record management and reporting workflows.
