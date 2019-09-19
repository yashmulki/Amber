#include "print.h"

#include "kernel.h"

static const uint32_t terminalWidth = 80;
static const uint32_t terminalHeight = 25;
static const uint8_t terminalColor = MAKE_TERMINAL_COLOR(PrintColorWhite, PrintColorBlack);
static uint16_t *const terminalBuffer = (uint16_t *)0xB8000;

uint64_t strlen(const char *text) {
  uint64_t size = 0;

  while (text[size] != '\0')
    size++;
  
  return size;
}

static void putCharacter(char c) {
  AmberState *amber = amberGet();

  if (c == '\n') {
    amber->terminal.column = 0;
    amber->terminal.row++;
  }

  terminalBuffer[amber->terminal.row * terminalWidth + amber->terminal.column] =
    terminalColor << 8 | c;

  if (c != '\n')
    amber->terminal.column++;
  if (amber->terminal.column == terminalWidth)
    amber->terminal.row++;
  
  amber->terminal.column %= terminalWidth;
  amber->terminal.row %= terminalHeight;
}

void puts(const char *text) {
  uint32_t textLength = strlen(text);
  for (uint64_t a = 0; a < textLength; a++) {
    putCharacter(text[a]);
  }
}

void printInit() {
  for (uint32_t a = 0; a < terminalWidth * terminalHeight; a++) {
    putCharacter(' ');
  }
}