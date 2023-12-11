CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=gnu89
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

TEST_DIR := tests
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_BINS := $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%_test, $(TEST_SRCS))

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ -o $@

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -MMD -c $< -o $@

test: $(TEST_BINS)
	@for test_bin in $(TEST_BINS); do \
		echo "Running $$test_bin"; \
		$$test_bin; \
	done

$(BIN_DIR)/%_test: $(TEST_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $< $(filter-out $(TARGET), $(OBJS)) -o $@

clean:
	$(RM) -r $(BUILD_DIR)

# Add a phony target to force rebuilding 'mipsify'
force: clean all

