CFLAGS += -I$(GTEST_DIR) -I$(GTEST_DIR)/include -I$(GTEST_DIR)/include/gtest -I$(GTEST_DIR)/include/gtest/internal

GTEST_LIB = $(LIB_DIR)/gtest_main$(LIB_EXT)

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
                
# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

$(OBJ_DIR)/gtest-all$(OBJ_EXT) : $(GTEST_SRCS_)
	@echo 'Compiling "$@"'
	$(CC) $(CFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@
	@echo ' '

$(OBJ_DIR)/gtest_main$(OBJ_EXT) : $(GTEST_SRCS_)
	@echo 'Compiling "$@"'
	$(CC) $(CFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@
	@echo ' '

$(LIB_DIR)/gtest_main$(LIB_EXT) : $(OBJ_DIR)/gtest-all$(OBJ_EXT) $(OBJ_DIR)/gtest_main$(OBJ_EXT)
	@echo 'Archiving "$^" into "$@"'
	$(AR) $(ARFLAGS) $@ $^
	@echo ' '
