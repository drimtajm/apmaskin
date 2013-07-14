VPATH    += $(SRC_DIR)/motor
DEPS     += $(DEPS_DIR)/motor$(DEP_EXT)
PROD_OBJ += $(OBJ_DIR)/motor$(OBJ_EXT)
CFLAGS   += -I$(SRC_DIR)/motor

UNIT_TEST_BINARIES += $(BIN_DIR)/motor$(TEST_SUITE_SUFFIX)

MOTOR_TEST_RUNNER = $(AUTO_SRC_DIR)/motor_test_runner$(SRC_EXT)
MOTOR_TEST_OBJ    = $(OBJ_DIR)/motor_test_runner$(OBJ_EXT) $(OBJ_DIR)/motor$(TEST_SUITE_SUFFIX)$(OBJ_EXT)

$(AUTO_SRC_DIR)/motor_test_runner.c : motor$(TEST_SUITE_SUFFIX).c
	@echo Generating test runner $@
	$(GEN_TEST_RUNNER) $(SRC_DIR)/motor/motor$(TEST_SUITE_SUFFIX).c $(AUTO_SRC_DIR)/motor_test_runner.c
	@echo ' '

$(BIN_DIR)/motor$(TEST_SUITE_SUFFIX) : $(PROD_LIB) $(UNITY_OBJ) $(MOTOR_TEST_OBJ)
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(MOTOR_TEST_OBJ) $(PROD_LIB) $(UNITY_OBJ) -o $@
	@echo ' '
