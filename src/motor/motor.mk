VPATH    += $(SRC_DIR)/motor
DEPS     += $(DEPS_DIR)/motor$(DEP_EXT)
PROD_OBJ += $(OBJ_DIR)/motor$(OBJ_EXT)
CFLAGS   += -I$(SRC_DIR)/motor

UNIT_TEST_BINARIES += $(BIN_DIR)/motor$(TEST_SUITE_SUFFIX)

$(BIN_DIR)/motor$(TEST_SUITE_SUFFIX) : $(PROD_LIB) $(GTEST_LIB) $(OBJ_DIR)/motor$(TEST_SUITE_SUFFIX)$(OBJ_EXT)
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(OBJ_DIR)/motor$(TEST_SUITE_SUFFIX)$(OBJ_EXT) $(PROD_LIB) $(GTEST_LIB) -lpthread -o $@
	@echo ' '
