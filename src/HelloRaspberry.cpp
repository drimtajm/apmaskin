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
  DEBUG_PRINTF("This is a 'VARIANT_DEBUG' build\n");
//  DEBUG_PRINTF("This is a number: %d\n", 4);  // TODO Does not work, needs VA-list, google...
  return 0;
}
