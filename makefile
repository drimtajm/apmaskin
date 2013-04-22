SHELL=/bin/bash
CC = arm-linux-gnueabi-g++
RM = rm -rf
MKDIR_P = mkdir -vp
MV = mv -v
SRC_DIR = src
DEBUG_BUILD_OUTPUT_DIR = debug
RELEASE_BUILD_OUTPUT_DIR = release
UNIT_TEST_BUILD_OUTPUT_DIR = unit_tests
GTEST_DIR = gtest

APPLICATION = HelloRaspberry
CFLAGS = -Wall

# Variant-specific settings
#-----------------------------
# Intended variants:
# 'VARIANT_DEBUG'             - With debug prints    ARM
# 'VARIANT_RELEASE'           - Without prints       ARM
# 'VARIANT_UNIT_TESTS'        - Unit tests           x86
# 'VARIANT_INTEGRATION_TESTS' - Integration tests    x86
ifeq ($(VARIANT), debug)
CFLAGS += -DVARIANT_DEBUG
BUILD_OUTPUT_DIR = $(DEBUG_BUILD_OUTPUT_DIR)
endif
ifeq ($(VARIANT), release)
BUILD_OUTPUT_DIR = $(RELEASE_BUILD_OUTPUT_DIR)
endif
ifeq ($(VARIANT), unit_tests)
CC = g++
BUILD_OUTPUT_DIR = $(UNIT_TEST_BUILD_OUTPUT_DIR)
endif

# Name the sub-directories of the build output directory
OBJ_DIR  = $(BUILD_OUTPUT_DIR)/obj
DEPS_DIR = $(BUILD_OUTPUT_DIR)/deps
BIN_DIR  = $(BUILD_OUTPUT_DIR)/bin

# Add 'SRC_DIR' because empirically I discovered that
# 'VPATH' requires that 'SRC_DIR' itself is added as well as
# any of its subdirs. Adding just the subdirs alone won't do.
VPATH = $(OBJ_DIR):$(BIN_DIR):$(SRC_DIR)

# Initialize 'OBJS' and 'DEPS' and then let the modules add to them
OBJS = 
DEPS =

# Include module makefiles
include $(SRC_DIR)/hello/hello.mk
include $(SRC_DIR)/led/led.mk
include $(SRC_DIR)/motor/motor.mk

# Unit test makefile must be included after module makefiles or
# unit test object files will be left out
include $(GTEST_DIR)/gtest.mk

# Include dependency files, if they exist, unless we're cleaning
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

# Unit test builds shall not link the application
ifneq ($(VARIANT), unit_tests)
all : $(APPLICATION)
endif

$(APPLICATION): $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(BIN_DIR) $(OBJS)
	@echo 'Linking $@'
	$(CC)  -o $(APPLICATION) $(OBJ_DIR)/*.o
	@$(MV) $(APPLICATION) $(BIN_DIR)/
	@touch $(BIN_DIR)/$(APPLICATION)  # ...otherwise $(BIN_DIR) will be younger than $(APPLICATION)
	@echo ' '

# General rule for dependency file generation
$(DEPS_DIR)/%.d: %.cpp
	@echo 'Generating deps for "$<" because of "$?"'
	@set -e; rm -f $@; \
	$(MKDIR_P) $(DEPS_DIR)
	$(CC) -MM $(CFLAGS) $< > $@.tmp; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@; \
	rm -f $@.tmp
	@echo ' '

# Genreral rule for object file generation (compilation)
%.o : %.cpp
	@echo 'Compiling "$<" because of "$?"'
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@
	@echo ' '

# Rules for build output directory and its sub-directories
$(BUILD_OUTPUT_DIR) :
	$(MKDIR_P) $@
	@echo ' '

$(OBJ_DIR) :
	$(MKDIR_P) $@
	@echo ' '

$(DEPS_DIR) :
	$(MKDIR_P) $@
	@echo ' '

$(BIN_DIR) :
	$(MKDIR_P) $@
	@echo ' '

clean:
	$(RM) $(DEBUG_BUILD_OUTPUT_DIR) $(RELEASE_BUILD_OUTPUT_DIR) $(UNIT_TEST_BUILD_OUTPUT_DIR)
