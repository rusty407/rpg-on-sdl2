# OBJS specifies which files to compile
OBJS = main.o 

# CC specifies the compiler
CC = g++

# COMPILER_FLAGS specifies compilation options
# -w suppresses warnings, pkg-config provides SDL2 include paths
COMPILER_FLAGS = -w $(shell pkg-config --cflags sdl2)

# LINKER_FLAGS specifies libraries to link
LINKER_FLAGS = $(shell pkg-config --libs sdl2)

# OBJ_NAME specifies the name of the executable
OBJ_NAME = output 

# Default target to build the executable
all: $(OBJ_NAME)

# Link object files to create the executable
$(OBJ_NAME): $(OBJS)
	$(CC) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(COMPILER_FLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(OBJ_NAME)

# Placeholder for install (no system-wide install needed)
install:
	@echo "No system-wide install needed for this example"

# Phony targets
.PHONY: all clean install
