SHELL=/bin/bash
CC = g++
RM = rm -rf

APPLICATION = HelloRaspberry


# Intended variants:
# 'VARIANT_DEBUG'             - With debug prints    ARM
# 'VARIANT_RELEASE'           - Without prints       ARM
# 'VARIANT_UNIT_TESTS'        - Unit tests           x86
# 'VARIANT_INTEGRATION_TESTS' - Integration tests    x86
#
# TODO Make variant(s) for ARM - Currently only x86 variants

ifdef VARIANT_DEBUG
CFLAGS=-DVARIANT_DEBUG
else
CFLAGS=
endif

all: $(APPLICATION)
	@./$(APPLICATION)

$(APPLICATION): HelloRaspberry.o
	@echo 'Linking $@'
	$(CC)  -o "HelloRaspberry" $^
	@echo ' '

# TODO Formulate general rule for objects
HelloRaspberry.o : src/HelloRaspberry.cpp src/variant.h
	@echo 'Compiling $<'
	$(CC) $(CFLAGS) -c $<

# Other Targets
clean:
	$(RM) $(APPLICATION) HelloRaspberry.o
	-@echo ' '

