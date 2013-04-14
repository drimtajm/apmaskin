SHELL=/bin/bash
CC = g++
RM = rm -rf
MKDIR_P = mkdir -vp
BUILD_OUTPUT_DIR = build
OBJ_DIR = $(BUILD_OUTPUT_DIR)/obj
BIN_DIR = $(BUILD_OUTPUT_DIR)/bin
SRC_DIR = src
MV = mv -v

APPLICATION = HelloRaspberry

VPATH = $(OBJ_DIR):$(BIN_DIR):$(SRC_DIR)


# Intended variants:
# 'VARIANT_DEBUG'             - With debug prints    ARM
# 'VARIANT_RELEASE'           - Without prints       ARM
# 'VARIANT_UNIT_TESTS'        - Unit tests           x86
# 'VARIANT_INTEGRATION_TESTS' - Integration tests    x86
#
# TODO Make variant(s) for ARM - Currently only x86 variants
# TODO Make the build output of different variants go into different directories

ifdef VARIANT_DEBUG
CFLAGS=-DVARIANT_DEBUG
else
CFLAGS=
endif

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
	$(RM) $(APPLICATION) $(BUILD_OUTPUT_DIR)

$(BUILD_OUTPUT_DIR) :
	$(MKDIR_P) $@

$(OBJ_DIR) :
	$(MKDIR_P) $@

$(BIN_DIR) :
	$(MKDIR_P) $@
