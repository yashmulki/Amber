#include "kernel.h"

#include "print.h"

AmberState state;

void amberInitState(AmberState *state) {
  state->terminal.column = 0;
  state->terminal.row = 0;

  printInit();
}

// Would be nice if we could make this an extern but you can't do that for structs.
AmberState *amberGet() {
  return &state;
}

void amberMain() {
  amberInitState(amberGet());

  puts("Hello World!\nReally long text lol gets long wow it's getting longer and longer and longer.");
}