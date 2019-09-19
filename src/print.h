#ifndef AMBER_PRINT_H
#define AMBER_PRINT_H

#define MAKE_TERMINAL_COLOR(foreground, background) background << 4 | foreground

enum PrintColor {
  PrintColorBlack,
  PrintColorBlue,
  PrintColorGreen,
  PrintColorCyan,
  PrintColorRed,
  PrintColorMagenta,
  PrintColorBrown,
  PrintColorLightGray,
  PrintColorDarkGray,
  PrintColorLightBlue,
  PrintColorLightGreen,
  PrintColorLightCyan,
  PrintColorLightRed,
  PrintColorLightMagenta,
  PrintColorLightBrown,
  PrintColorWhite,
};

// Should be in it's own clib file, stdio, etc.
void puts(const char *text);

void printInit();

#endif // AMBER_PRINT_H