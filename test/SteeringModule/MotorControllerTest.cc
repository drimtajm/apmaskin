/*
 * MotorControllerTest.cc
 *
 *  Created on: Dec 9, 2009
 *      Author: bege
 */

#include "gtest.h"

using namespace std;


class MotorControllerTest : public testing::Test  {
protected:
	MotorControllerTest()  {}
};

TEST_F (MotorControllerTest, blabla) {
	ASSERT_NE(-1, -1); // Continue here
}
