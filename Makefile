CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SOURCES = $(wildcard src/*.c)
TARGET = build/student-record-system.exe

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	del /Q $(TARGET) 2>NUL

.PHONY: all clean
