//============================================================================
// Name        : HelloRaspberry.cpp
// Author      : Johan
// Version     :
// Copyright   : copy-me!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "variant.h"

int main()
{
  printf("Hello Raspberry!\n");
  DEBUG_PRINTF("This is a debug build\n");
  DEBUG_PRINTF("These are numbers: %d, %f, 0x%X\n", 4, 0.75, 0xFE);
  DEBUG_PRINTF("Line number: %d\n", __LINE__);
  return 0;
}
