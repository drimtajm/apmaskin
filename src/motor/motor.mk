VPATH    += $(SRC_DIR)/motor
VPATH    += $(SRC_DIR)/motor/test
DEPS     += $(DEPS_DIR)/motor.d
PROD_OBJ += $(OBJ_DIR)/motor.o
CFLAGS   += -I$(SRC_DIR)/motor

UNIT_TEST_BINARIES += $(BIN_DIR)/motor$(TEST_SUITE_SUFFIX)

MOTOR_TEST_OBJ = $(OBJ_DIR)/motor_test_runner.o $(OBJ_DIR)/motor$(TEST_SUITE_SUFFIX).o \
                 $(OBJ_DIR)/led_mock.o

$(AUTO_SRC_DIR)/motor_test_runner.c : motor$(TEST_SUITE_SUFFIX).c
	@echo Generating test runner $@ because of $?
	$(GEN_TEST_RUNNER) $(SRC_DIR)/motor/test/motor$(TEST_SUITE_SUFFIX).c $(AUTO_SRC_DIR)/motor_test_runner.c
	@echo ' '

$(BIN_DIR)/motor$(TEST_SUITE_SUFFIX) : $(PROD_LIB) $(UNITY_OBJ) $(MOTOR_TEST_OBJ)
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(MOTOR_TEST_OBJ) $(PROD_LIB) $(UNITY_OBJ) -o $@
	@echo ' '
