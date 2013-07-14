VPATH    += $(SRC_DIR)/led
DEPS     += $(DEPS_DIR)/led$(DEP_EXT)
PROD_OBJ += $(OBJ_DIR)/led$(OBJ_EXT)
CFLAGS   += -I$(SRC_DIR)/led

UNIT_TEST_BINARIES += $(BIN_DIR)/led$(TEST_SUITE_SUFFIX)

$(BIN_DIR)/led$(TEST_SUITE_SUFFIX) : $(PROD_LIB) $(GTEST_LIB) $(OBJ_DIR)/led$(TEST_SUITE_SUFFIX)$(OBJ_EXT)
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(OBJ_DIR)/led$(TEST_SUITE_SUFFIX)$(OBJ_EXT) $(PROD_LIB) $(GTEST_LIB) -lpthread -o $@
	@echo ' '
