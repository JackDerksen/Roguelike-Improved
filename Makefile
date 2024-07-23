CC := g++
CFLAGS := -Isrc -std=c++11 -Wall
LDFLAGS := -lncurses
BINDIR := bin
OBJDIR := obj
SRCDIR := src
TARGET := Roguelike

# Use wildcard function to compile all .cpp files in the src directory
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
# Convert the *.cpp filenames to *.o to give a list of object files to build
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

.PHONY: all test clean

# Default target
all: $(BINDIR)/$(TARGET)

# Link the program
$(BINDIR)/$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Compile all .cpp to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# I should change this later to call a debugger
test: CFLAGS += -DTESTING
test: $(BINDIR)/$(TARGET)

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/* src/test

run: all
	./$(BINDIR)/$(TARGET)

