VPATH    += $(SRC_DIR)/motor
DEPS     += $(DEPS_DIR)/motor.d
PROD_OBJ += $(OBJ_DIR)/motor.o
CFLAGS   += -I$(SRC_DIR)/motor

UNIT_TEST_BINARIES += $(BIN_DIR)/motor_tests

$(BIN_DIR)/motor_tests : $(PROD_LIB) $(GTEST_LIB) $(OBJ_DIR)/motor_tests.o
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(OBJ_DIR)/motor_tests.o $(PROD_LIB) $(GTEST_LIB) -lpthread -o $@
	@echo ' '
