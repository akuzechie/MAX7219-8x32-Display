//-------------------------------------------------
// Count from 00 to 99 on MAX7219 8x32 Dot Matrix
// using MAX72198by32Disp.h Library
// by: Anas Kuzechie
//-------------------------------------------------
#include <MAX72198by32Disp.h>
#include "MAX7219_Letters.h"
//-----------------------------
MAX72198by32Disp disp(2, 3, 4);
//========================================================
void setup()
{
  disp.Initialize(0);
  disp.Clear();
  delay(1000);
}
//========================================================
void loop()
{
  disp.Letter(1, P);
  disp.Letter(2, L);
  disp.Letter(3, A);
  disp.Letter(4, Y);
  //----------------------------------------
  delay(2000); disp.Clear(); delay(1000);
  //----------------------------------------
  for(byte MSD=0; MSD<=9; MSD++)
  {
    disp.Number(2, MSD);
    for(byte LSD=0; LSD<=9; LSD++)
    {
      disp.Number(3, LSD); delay(300);
    }
  }
  //----------------------------------------
  disp.Letter(1, d);
  disp.Letter(2, o);
  disp.Letter(3, n);
  disp.Letter(4, e);
  //----------------------------------------
  delay(2000); disp.Clear(); delay(1000);
}