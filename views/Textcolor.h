#ifndef TEXTCOLOR_H
#define TEXTCOLOR_H

#include <stdio.h>

// Display type: 0 Resets attributes.
#define RESET (0)
#define BRIGHT (1)
#define DIM (2)
#define UNDERLINE (3)
#define BLINK (4)
#define REVERSE (7)
#define HIDDEN (8)

// Display Colors
#define BLACK (0)
#define RED (1)
#define GREEN (2)
#define YELLOW (3)
#define BLUE (4)
#define MAGENTA (5)
#define CYAN (6)
#define	WHITE (7)

void textcolor(int attr, int fg, int bg)
{	
  char command[13];

  /* Command is the control command to the terminal */
  sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
  printf("%s", command);
}

#endif // TEXTCOLOR_H