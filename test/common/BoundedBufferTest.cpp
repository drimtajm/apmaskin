/*
 * BoundedBufferTest.cpp
 *
 *  Created on: 2009-jun-19
 *      Author: bege
 */


#include "gtest.h"
#include "BoundedBuffer.h"

class BoundedBufferTest : public testing::Test  {
protected:
	BoundedBufferTest() : buffer(4) {}
	BoundedBuffer<int> buffer;

};

TEST_F (BoundedBufferTest, firstInShouldBeFirstOut) {
  int a = 1;
  int b = 2;
  buffer.send(&a);
  buffer.send(&b);
  EXPECT_EQ(&a, buffer.receive());
  EXPECT_EQ(&b, buffer.receive());
}


