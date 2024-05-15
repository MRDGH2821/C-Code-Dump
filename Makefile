# Set the source directory
SRC_DIR := src

# Set the output directory
OUT_DIR := out`

# Find all .c files recursively in the source directory
SRCS := $(shell find $(SRC_DIR) -name '*.c')

# Generate the corresponding .o file names
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/%.o,$(SRCS))

# Set the compiler and compiler flags
CC := gcc
CFLAGS :=

# Default target
all: $(OBJS)

# Rule to compile .c files to .o files
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean