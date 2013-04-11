/*
 * CommandParserTest.cpp
 *
 *  Created on: 2009-okt-11
 *      Author: bege
 */

#include "gtest.h"
#include <string>
#include <vector>
#include <iostream>
#include "CommandParser.h"

using namespace std;
class CommandParserTest : public testing::Test {
public:
	CommandParserTest() : parser(cmd, params) {}
protected:
	string cmd;
	vector<int> params;
	CommandParser parser;

};

TEST_F(CommandParserTest, shouldlSucceedWhenGotNoParameters) {
	parse_info<> info = parse("help", parser, space_p);
	ASSERT_TRUE(info.full);
	EXPECT_EQ("help", cmd);
}

TEST_F(CommandParserTest, shouldlSucceedWhenGotOneIntegerParameter) {
	parse_info<> info = parse("help 1", parser, space_p);
	ASSERT_TRUE(info.full);
}

TEST_F(CommandParserTest, shouldlFailWhenGotNotIntegerParameter) {
	parse_info<> info = parse("help 1,2,a,1", parser, space_p);
	ASSERT_FALSE(info.full);
}

TEST_F(CommandParserTest, shouldlFailWhenGotOnlyIntegerParameters) {
	parse_info<> info = parse("help 1,2,3,4", parser, space_p);
	ASSERT_TRUE(info.full);
}

