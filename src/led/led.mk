VPATH += $(SRC_DIR)/led
DEPS += $(DEPS_DIR)/led.d
OBJS += led.o
CFLAGS += -I$(SRC_DIR)/led

ifeq ($(VARIANT), unit_tests)
OBJS += led_tests.o
endif