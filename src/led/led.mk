VPATH    += $(SRC_DIR)/led
DEPS     += $(DEPS_DIR)/led.d
PROD_OBJ += $(OBJ_DIR)/led.o
CFLAGS   += -I$(SRC_DIR)/led

UNIT_TEST_BINARIES += $(BIN_DIR)/led_tests

$(BIN_DIR)/led_tests : $(PROD_LIB) $(GTEST_LIB) $(OBJ_DIR)/led_tests.o
	@echo 'Linking $@'
	$(CC) $(CFLAGS) $(OBJ_DIR)/led_tests.o $(PROD_LIB) $(GTEST_LIB) -lpthread -o $@
	@echo ' '
