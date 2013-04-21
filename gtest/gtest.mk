ifeq ($(VARIANT), unit_tests)
TESTS   = apmaskin_unit_tests
AR      = ar
ARFLAGS = rv

CFLAGS += -I$(GTEST_DIR) -I$(GTEST_DIR)/include -I$(GTEST_DIR)/include/gtest -I$(GTEST_DIR)/include/gtest/internal

all : $(BUILD_OUTPUT_DIR) $(OBJ_DIR) $(BIN_DIR) $(TESTS)
	@echo 'Running unit test suite "$(TESTS)"...'
	$(BIN_DIR)/$(TESTS)

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
                
# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

$(OBJ_DIR)/gtest-all.o : $(GTEST_SRCS_)
	$(MKDIR_P) $(OBJ_DIR)
	@echo 'Compiling "$@"'
	$(CC) $(CFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@
	@echo ' '

$(OBJ_DIR)/gtest_main.o : $(GTEST_SRCS_)
	$(MKDIR_P) $(OBJ_DIR)
	@echo 'Compiling "$@"'
	$(CC) $(CFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@
	@echo ' '

$(OBJ_DIR)/gtest_main.a : $(OBJ_DIR)/gtest-all.o $(OBJ_DIR)/gtest_main.o
	$(MKDIR_P) $(OBJ_DIR)
	@echo 'Archiving "$^" into "$@"'
	$(AR) $(ARFLAGS) $@ $^
	@echo ' '

$(TESTS) : $(OBJS) $(OBJ_DIR)/gtest_main.a
	@echo 'Linking "$@"...'
	$(CC) $(CFLAGS) $(OBJ_DIR)/*.o $(OBJ_DIR)/gtest_main.a -lpthread -o $@
	@$(MV) $(TESTS) $(BIN_DIR)/
	@touch $(BIN_DIR)/$(TESTS)  # ...otherwise $(BIN_DIR) will be younger than $(TESTS)
	@echo ' '

endif
