VPATH    += $(SRC_DIR)/led
DEPS     += $(DEPS_DIR)/led$(DEP_EXT)
PROD_OBJ += $(OBJ_DIR)/led$(OBJ_EXT)
CFLAGS   += -I$(SRC_DIR)/led

UNIT_TEST_BINARIES += $(BIN_DIR)/led$(TEST_SUITE_SUFFIX)

LED_TEST_OBJ    = $(OBJ_DIR)/led_test_runner$(OBJ_EXT) $(OBJ_DIR)/led$(TEST_SUITE_SUFFIX)$(OBJ_EXT)

$(AUTO_SRC_DIR)/led_test_runner.c : led$(TEST_SUITE_SUFFIX).c
	@echo Generating test runner $@
	$(GEN_TEST_RUNNER) $(SRC_DIR)/led/led$(TEST_SUITE_SUFFIX).c $(AUTO_SRC_DIR)/led_test_runner.c
	@echo ' '

$(BIN_DIR)/led$(TEST_SUITE_SUFFIX) : $(PROD_LIB) $(UNITY_OBJ) $(LED_TEST_OBJ)
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(LED_TEST_OBJ) $(PROD_LIB) $(UNITY_OBJ) -o $@
	@echo ' '
