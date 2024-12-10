# Source files for the project
TASK1_SRC := mmu.c util.c list.c

# Header files (for tracking dependencies)
HEADERS := list.h util.h

# Executable output name
EXE := mmu

# Compiler and flags
CC := gcc
CFLAGS := -Wall -std=c99 -std=gnu99 -Werror -pedantic -g

# Default target to build the executable
all: $(EXE)

# Rule to build the executable
$(EXE): $(TASK1_SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(TASK1_SRC) -o $(EXE)

# Clean target to remove the executable
clean:
	rm -f $(EXE)
