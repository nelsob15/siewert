#include "Textcolor.h"
#include <iostream>

using namespace std;

int main()
{
  textcolor(BRIGHT, RED, BLACK);
  cout << "In color!" << endl;
  textcolor(RESET, WHITE, BLACK);

  // For MobaXTerm, reset, wht, blk
  // This will also change the terminal, so it'll only
  // be useful when we know exactly what terminal is used.
  // If it's the command prompt in windows, reset, blk, wht
  // will still be usable. 

  cout << "Return to normal mode!" << endl;
}
