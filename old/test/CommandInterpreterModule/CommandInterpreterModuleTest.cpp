/*
 * CommandInterpreterModuleTest.cpp
 *
 *  Created on: 9 sep 2009
 *      Author: daniel
 */

#include "gtest.h"
#include "CommandInterpreterModule.h"
#include <string>
#include <sstream>

TEST (CommandInterpreterModuleTest, performSimpleCommand) {
	std::istringstream input("help\nexit\n");
	std::ostringstream output;
	CommandInterpreterImpl commandInterpreter(input, output);
	commandInterpreter.registerCommands();
	commandInterpreter.start();
	EXPECT_EQ("> Command list: \n\texit\n\thelp\n> Goodbye!\n> ", output.str());
}

TEST (CommandInterpreterModuleTest, performFaultyCommand) {
	std::istringstream input("helpppppp\nexit\n");
	std::ostringstream output;
	CommandInterpreterImpl commandInterpreter(input, output);
	commandInterpreter.registerCommands();
	commandInterpreter.start();
	EXPECT_EQ("> ERROR: Command does not exist.\n> Goodbye!\n> ", output.str());
}
