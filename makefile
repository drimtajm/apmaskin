MKDIR=mkdir -pv
RM=rm -rf
DEBUG_BUILD_OUTPUT_DIR=debug
RELEASE_BUILD_OUTPUT_DIR=release
UNIT_TEST_BUILD_OUTPUT_DIR=unit_test

ifeq ($(VARIANT), DEBUG)
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

# 'PROD_OBJ' lists object files from product sourcefiles
# Contents of this variable will be initially empty and then added to by module makefiles
PROD_OBJ =
DEPS =

include $(SRC_DIR)/foo/foo.mk

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

$(DEPS_DIR)/%.d: %.cpp
	@echo 'Generating deps for "$<" because of "$?"'
	@set -e; rm -f $@; \
	$(MKDIR) $(DEPS_DIR)
	$(CC) -MM $(CFLAGS) $< > $@.tmp; \
	sed 's,\($*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@ : ,g' < $@.tmp > $@; \
	rm -f $@.tmp
	@echo ' '

$(PROD_LIB) : $(BUILD_OUTPUT_DIR) $(PROD_LIB_DIR) $(PROD_OBJ)
	touch $@

$(OBJ_DIR) :
	@$(MKDIR) $@

$(DEPS_DIR) :
	@$(MKDIR) $@
	
$(PROD_LIB_DIR) :
	@$(MKDIR) $@

$(BUILD_OUTPUT_DIR) :
	@$(MKDIR) $@

DEBUG : $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(PROD_LIB)
	@echo Nothing specified for variant DEBUG

RELEASE : $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(PROD_LIB)
	@echo Nothing specified for variant RELEASE
	
UNIT_TEST : $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(PROD_LIB)
	@echo Nothing specified for variant UNIT_TEST
