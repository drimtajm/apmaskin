# "hello" has the main method and is not unit tested
ifneq ($(VARIANT), unit_tests)
VPATH += $(SRC_DIR)/hello
DEPS += $(DEPS_DIR)/HelloRaspberry.d
OBJS += HelloRaspberry.o
CFLAGS += -I$(SRC_DIR)
endif
