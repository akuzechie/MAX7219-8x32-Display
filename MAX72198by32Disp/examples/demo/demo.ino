//------------------------------------------------------
// Display Numbers & Letters on MAX7219 8x32 Dot Matrix
// using MAX72198by32Disp.h Library
// by: Anas Kuzechie
//-------------------------------------------------------
#include <MAX72198by32Disp.h>
#include "MAX7219_Letters.h"
//-----------------------------
MAX72198by32Disp disp(2, 3, 4);
//=======================================================
void setup()
{
  disp.Initialize(0);
  disp.Clear();
  delay(1000);
}
//=======================================================
void loop()
{
  disp.Numberdp(1, 3);
  disp.Number  (2, 1);
  disp.Number  (3, 4);
  disp.Number  (4, 2);

  delay(2000); disp.Clear(); delay(1000);

  disp.Letter  (1, G);
  disp.Symbol  (2, '=');
  disp.Numberdp(3, 9);
  disp.Number  (4, 8);

  delay(2000); disp.Clear(); delay(1000);
}