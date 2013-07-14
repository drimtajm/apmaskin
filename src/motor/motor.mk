VPATH    += $(SRC_DIR)/motor
DEPS     += $(DEPS_DIR)/motor.d
PROD_OBJ += $(OBJ_DIR)/motor.o
CFLAGS   += -I$(SRC_DIR)/motor

UNIT_TEST_BINARIES += $(BIN_DIR)/motor$(TEST_SUITE_SUFFIX)

$(BIN_DIR)/motor$(TEST_SUITE_SUFFIX) : $(PROD_LIB) $(GTEST_LIB) $(OBJ_DIR)/motor$(TEST_SUITE_SUFFIX).o
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(OBJ_DIR)/motor$(TEST_SUITE_SUFFIX).o $(PROD_LIB) $(GTEST_LIB) -lpthread -o $@
	@echo ' '
