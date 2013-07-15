AUTO_SRC_DIR = $(BUILD_OUTPUT_DIR)/auto_src
UNITY_SRC_DIR = $(UNITY_DIR)/src
UNITY_AUTO_DIR = $(UNITY_DIR)/auto
UNITY_LIB = $(LIB_DIR)/unity.a
UNITY_SRC = $(UNITY_SRC_DIR)/unity.c
UNITY_OBJ = $(OBJ_DIR)/unity.o

CFLAGS += -I$(UNITY_SRC_DIR)
GEN_TEST_RUNNER = @$(RUBY) $(UNITY_AUTO_DIR)/generate_test_runner.rb

$(OBJ_DIR)/%_runner.o : $(AUTO_SRC_DIR)/%_runner.c
	@echo Compiling $^
	$(CC) $(CFLAGS) -c $^ -o $@
	@echo ' '
 
$(OBJ_DIR)/unity.o : $(UNITY_SRC)
	@echo Compiling $^
	$(CC) $(CFLAGS) -c $^ -o $@
	@echo ' '

$(UNITY_LIB) : $(OBJ_DIR)/unity.o
	@echo Archiving $^ into $@
	$(AR) $(ARFLAGS) $@ $(OBJ_DIR)/unity.o
	@echo ' '

$(AUTO_SRC_DIR) :
	@$(MKDIR) $@
	@echo ' '