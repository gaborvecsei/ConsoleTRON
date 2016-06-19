/****************************************
* Vecsei Gábor
* 2013
* https://gaborvecsei.wordpress.com/
* https://github.com/gaborvecsei
****************************************/


#include <windows.h>
#include <time.h>
#include "consoletron.h"
#include "consoletron.c"

#define MAX_X 60
#define MAX_Y 22

int main()
{
    system("title ConsoleTRON");
    menu();
    elrendezes();
    kirajzol();
      while (1)
    {
      figyel();
      jatekosok();
      ellenoriz();
      kirajzol();
    }
return 0;
}
