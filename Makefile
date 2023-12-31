C := gcc
CFLAGS := -Wall -Wextra -pedantic -g -std=gnu89
LDFLAGS :=

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
BIN_DIR := $(BUILD_DIR)/bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)
TARGET := mipsify


.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ -o $@

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -MMD -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) mipsify

put:
	sudo cp mipsify /usr/bin
# Add a phony target to force rebuilding 'mipsify'
force: clean all
install: all put clean
