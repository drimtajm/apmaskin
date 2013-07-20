# "all_unit_tests_command.mk" defines a shell command for running all unit tests.
# For this to work all test suites must be listed, space-separated, in the variable
# 'UNIT_TEST_BINARIES' and have a name that ends with 'TEST_SUITE_SUFFIX' as defined in "makefile"

SPACE     := $(empty) $(empty)
SEMICOLON := ; 
ALL_UNIT_TESTS_COMMAND = $(subst $(TEST_SUITE_SUFFIX)$(SPACE),$(TEST_SUITE_SUFFIX)$(SEMICOLON),\
                         $(UNIT_TEST_BINARIES))
