SHELL=/bin/bash
CC = arm-linux-gnueabi-g++
RM = rm -rf
MKDIR_P = mkdir -vp
SRC_DIR = src
DEBUG_BUILD_OUTPUT_DIR = debug
RELEASE_BUILD_OUTPUT_DIR = release
MV = mv -v

APPLICATION = HelloRaspberry



# Intended variants:
# 'VARIANT_DEBUG'             - With debug prints    ARM
# 'VARIANT_RELEASE'           - Without prints       ARM
# 'VARIANT_UNIT_TESTS'        - Unit tests           x86
# 'VARIANT_INTEGRATION_TESTS' - Integration tests    x86

ifdef VARIANT_DEBUG
CFLAGS=-DVARIANT_DEBUG
BUILD_OUTPUT_DIR = $(DEBUG_BUILD_OUTPUT_DIR)
else
CFLAGS=
BUILD_OUTPUT_DIR = $(RELEASE_BUILD_OUTPUT_DIR)
endif

OBJ_DIR = $(BUILD_OUTPUT_DIR)/obj
BIN_DIR = $(BUILD_OUTPUT_DIR)/bin

# Add 'BIN_DIR' to 'VPATH' for ability to find 'APPLICATION'
# Also add 'SRC_DIR' because empirically I discovered that
# 'VPATH' requires that 'SRC_DIR' itself is added as well as
# any of its subdirs. Adding just the subdirs alone won't do.
VPATH = $(BIN_DIR):$(SRC_DIR)

# Initialize 'OBJS' and then let the modules add to it
OBJS = 

# Add modules
include $(SRC_DIR)/hello/hello.mk

all: $(APPLICATION)

$(APPLICATION): $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(BIN_DIR) $(OBJS)
	@echo 'Linking $@'
	$(CC)  -o $(APPLICATION) $(OBJ_DIR)/*.o
	@$(MV) $(APPLICATION) $(BIN_DIR)/
	@touch $(BIN_DIR)/$(APPLICATION)  # ...otherwise $(BIN_DIR) will be younger than $(APPLICATION)

.PRECIOUS: $(OBJ_DIR)/HelloRaspberry.d
	
$(OBJ_DIR)/%.d: %.cpp
	@echo 'Generating deps for "$<" because of "$?"'
	@set -e; rm -f $@; \
	$(MKDIR_P) $(OBJ_DIR)
	$(CC) -MM $(CPPFLAGS) $< > $@.tmp; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@; \
	rm -f $@.tmp
#	$(MV) $@ $(OBJ_DIR)/  ### If not using $(OBJ_DIR) prefix for %.d and $(OBJ_DIR) in 'VPATH' - Does not work.
	
ifneq ($(MAKECMDGOALS),clean)
-include $(OBJ_DIR)/HelloRaspberry.d
endif

$(OBJ_DIR)/%.o : %.cpp $(OBJ_DIR)/%.d
	@echo 'Compiling "$<" because of "$?"'
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(APPLICATION) $(DEBUG_BUILD_OUTPUT_DIR) $(RELEASE_BUILD_OUTPUT_DIR)

$(BUILD_OUTPUT_DIR) :
	$(MKDIR_P) $@

$(OBJ_DIR) :
	$(MKDIR_P) $@

$(BIN_DIR) :
	$(MKDIR_P) $@
