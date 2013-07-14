SPACE     := $(empty) $(empty)
SEMICOLON := ; 
ALL_UNIT_TESTS_COMMAND = $(subst tests$(SPACE),tests$(SEMICOLON),$(UNIT_TEST_BINARIES))
