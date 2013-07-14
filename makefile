SHELL=/bin/bash
CC = g++
MKDIR = mkdir -pv
RM = rm -rf
#CFLAGS = -Wall
ARFLAGS = rv
DEBUG_BUILD_OUTPUT_DIR = debug
RELEASE_BUILD_OUTPUT_DIR = release
UNIT_TEST_BUILD_OUTPUT_DIR = unit_test

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

PROD_LIB_DIR = $(BUILD_OUTPUT_DIR)/lib
PROD_LIB = $(PROD_LIB_DIR)/prod.a

BIN_DIR  = $(BUILD_OUTPUT_DIR)/bin

MAIN_APPLICATION = $(BIN_DIR)/HelloRaspberry

# 'PROD_OBJ' lists object files from product sourcefiles
# Contents of this variable will be initially empty and then added to by module makefiles
PROD_OBJ =
DEPS =

include $(SRC_DIR)/hello/hello.mk
#include $(SRC_DIR)/foo/foo.mk

# Include dependency files, if they exist, unless we're cleaning
ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

.PHONY : all clean
all : $(VARIANT)
	@echo Done building variant $(VARIANT)

clean :
	@echo Cleaning everything
	$(RM) $(DEBUG_BUILD_OUTPUT_DIR) $(RELEASE_BUILD_OUTPUT_DIR) $(UNIT_TEST_BUILD_OUTPUT_DIR)

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

$(MAIN_APPLICATION) : $(BIN_DIR) $(PROD_LIB)
	@echo 'Linking $@'
	$(CC) -o $@ $(PROD_LIB)

$(PROD_LIB) : $(PROD_LIB_DIR) $(PROD_OBJ)
	@echo 'Archiving product object files into "$@"'
	$(AR) $(ARFLAGS) $@ $(PROD_OBJ)
	@echo ' '

$(OBJ_DIR) :
	@$(MKDIR) $@

$(DEPS_DIR) :
	@$(MKDIR) $@
	
$(PROD_LIB_DIR) :
	@$(MKDIR) $@

$(BIN_DIR) :
	@$(MKDIR) $@

$(BUILD_OUTPUT_DIR) :
	@$(MKDIR) $@

DEBUG : $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(PROD_LIB) $(MAIN_APPLICATION)

RELEASE : $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(PROD_LIB) $(MAIN_APPLICATION)
	
UNIT_TEST : $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(PROD_LIB)
	@echo Nothing specified for variant UNIT_TEST
