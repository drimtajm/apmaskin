VPATH += $(SRC_DIR)/motor
DEPS += $(DEPS_DIR)/motor.d
OBJS += motor.o
CFLAGS += -I$(SRC_DIR)/motor

ifeq ($(VARIANT), unit_tests)
OBJS += motor_tests.o
endif