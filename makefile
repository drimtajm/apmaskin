SHELL=/bin/bash
CC = g++
MKDIR = mkdir -pv
RM = rm -rf
CFLAGS = -Wall
ARFLAGS = rv
DEBUG_BUILD_OUTPUT_DIR = debug
RELEASE_BUILD_OUTPUT_DIR = release
UNIT_TEST_BUILD_OUTPUT_DIR = unit_test
TEST_SUITE_SUFFIX = _tests

ifeq ($(VARIANT), DEBUG)
  CFLAGS += -DVARIANT_DEBUG
  BUILD_OUTPUT_DIR = $(DEBUG_BUILD_OUTPUT_DIR)
endif
ifeq ($(VARIANT), RELEASE)
  BUILD_OUTPUT_DIR = $(RELEASE_BUILD_OUTPUT_DIR)
endif
ifeq ($(VARIANT), UNIT_TEST)
  BUILD_OUTPUT_DIR = $(UNIT_TEST_BUILD_OUTPUT_DIR)
endif

SRC_DIR = src
OBJ_DIR = $(BUILD_OUTPUT_DIR)/obj

DEPS_DIR = $(BUILD_OUTPUT_DIR)/deps

LIB_DIR = $(BUILD_OUTPUT_DIR)/lib
PROD_LIB = $(LIB_DIR)/prod.a

BIN_DIR  = $(BUILD_OUTPUT_DIR)/bin

GTEST_DIR = gtest

MAIN_APPLICATION   = $(BIN_DIR)/HelloRaspberry
UNIT_TEST_BINARIES =
GENERAL_TARGET_DEPENDENCIES = $(BUILD_OUTPUT_DIR) $(BIN_DIR) $(OBJ_DIR) $(LIB_DIR) $(PROD_LIB)

# 'PROD_OBJ' lists object files from product sourcefiles
# Contents of this variable will be initially empty and then added to by module makefiles
PROD_OBJ =
DEPS     =

# Must be before module makefiles
ifeq ($(VARIANT), UNIT_TEST)
include $(GTEST_DIR)/gtest.mk
endif

include $(SRC_DIR)/hello/hello.mk
include $(SRC_DIR)/led/led.mk
include $(SRC_DIR)/motor/motor.mk

ifeq ($(VARIANT), UNIT_TEST)
include $(GTEST_DIR)/all_unit_tests_command.mk
endif

# Include dependency files, if they exist, unless we're cleaning
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

.PHONY : all clean
all : $(VARIANT)
	@echo Done building variant $(VARIANT)
	@echo ' '

clean :
	@echo Cleaning everything
	$(RM) $(DEBUG_BUILD_OUTPUT_DIR) $(RELEASE_BUILD_OUTPUT_DIR) $(UNIT_TEST_BUILD_OUTPUT_DIR)
	@echo ' '

$(OBJ_DIR)/%.o : %.cpp
	@echo 'Compiling "$<" because of "$?"'
	$(CC) $(CFLAGS) -c $< -o $@
	@echo ' '

$(DEPS_DIR)/%.d : %.cpp
	@echo 'Generating deps for "$<" because of "$?"'
	@set -e; rm -f $@; \
	$(MKDIR) $(DEPS_DIR)
	$(CC) -MM $(CFLAGS) $< > $@.tmp; \
	sed 's,\($*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@ : ,g' < $@.tmp > $@; \
	rm -f $@.tmp
	@echo ' '

$(MAIN_APPLICATION) : $(BIN_DIR) $(PROD_LIB) $(MAIN_OBJ)
	@echo 'Linking $@'
	$(CC) -o $@ $(MAIN_OBJ) $(PROD_LIB)
	@echo ' '

$(PROD_LIB) : $(PROD_OBJ)
	@echo 'Archiving product object files into "$@"'
	$(AR) $(ARFLAGS) $@ $(PROD_OBJ)
	@echo ' '

$(OBJ_DIR) :
	@$(MKDIR) $@
	@echo ' '

$(DEPS_DIR) :
	@$(MKDIR) $@
	@echo ' '
	
$(LIB_DIR) :
	@$(MKDIR) $@
	@echo ' '

$(BIN_DIR) :
	@$(MKDIR) $@
	@echo ' '

$(BUILD_OUTPUT_DIR) :
	@$(MKDIR) $@
	@echo ' '

DEBUG : $(GENERAL_TARGET_DEPENDENCIES) $(MAIN_APPLICATION)

RELEASE : $(GENERAL_TARGET_DEPENDENCIES) $(MAIN_APPLICATION)

UNIT_TEST : $(GENERAL_TARGET_DEPENDENCIES) $(UNIT_TEST_BINARIES)
	$(ALL_UNIT_TESTS_COMMAND)
