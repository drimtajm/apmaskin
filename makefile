SHELL=/bin/bash
CC = g++
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
#
# TODO Make variant(s) for ARM - Currently only x86 variants

ifdef VARIANT_DEBUG
CFLAGS=-DVARIANT_DEBUG
BUILD_OUTPUT_DIR = $(DEBUG_BUILD_OUTPUT_DIR)
else
CFLAGS=
BUILD_OUTPUT_DIR = $(RELEASE_BUILD_OUTPUT_DIR)
endif

OBJ_DIR = $(BUILD_OUTPUT_DIR)/obj
BIN_DIR = $(BUILD_OUTPUT_DIR)/bin

VPATH = $(OBJ_DIR):$(BIN_DIR):$(SRC_DIR)

OBJS = 
OBJS += HelloRaspberry.o

all: $(APPLICATION)

$(APPLICATION): $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(BIN_DIR) $(OBJS)
	@echo 'Linking $@'
	$(CC)  -o $(APPLICATION) $(OBJ_DIR)/*.o
	@$(MV) $(APPLICATION) $(BIN_DIR)/
	@touch $(BIN_DIR)/$(APPLICATION)  # ...otherwise $(BIN_DIR) will be younger than $(APPLICATION)

# TODO Dependencies to header files will need to be handled more generally when we come up with more files 
%.o : %.cpp variant.h 
	@echo 'Compiling $<'
	$(CC) $(CFLAGS) -c $<
	@$(MV) $@ $(OBJ_DIR)/

clean:
	$(RM) $(APPLICATION) $(DEBUG_BUILD_OUTPUT_DIR) $(RELEASE_BUILD_OUTPUT_DIR)

$(BUILD_OUTPUT_DIR) :
	$(MKDIR_P) $@

$(OBJ_DIR) :
	$(MKDIR_P) $@

$(BIN_DIR) :
	$(MKDIR_P) $@
