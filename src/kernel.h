#ifndef AMBER_KERNEL_H
#define AMBER_KERNEL_H

#include <stdint.h>

typedef struct {
  struct {
    uint32_t column;
    uint32_t row;
  } terminal;
} AmberState;

void amberInitState(AmberState *state);

AmberState *amberGet();

#endif // AMBER_KERNEL_H