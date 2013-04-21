#ifndef VARIANT_H_
#define VARIANT_H_

#ifdef VARIANT_DEBUG
#include <stdio.h>
#define DEBUG_PRINTF(...) fprintf(stdout, __VA_ARGS__)
#else
#define DEBUG_PRINTF(...)
#endif

#endif /* VARIANT_H_ */
