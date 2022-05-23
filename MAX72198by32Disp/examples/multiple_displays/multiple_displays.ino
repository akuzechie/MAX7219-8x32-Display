//---------------------------------------------
// Display Pi=3.1416 on 2 MAX7219 8x32 Displays
// using MAX72198by32Disp.h Library
// by: Anas Kuzechie
//---------------------------------------------
#include <MAX72198by32Disp.h>
#include "MAX7219_Letters.h"
//-----------------------------
MAX72198by32Disp disp1(2, 3, 4), disp2(6, 7, 8);
//=======================================================
void setup()
{
  disp1.Initialize(0); disp1.Clear();
  disp2.Initialize(0); disp2.Clear();
  //----------------------------------
  delay(1000);
}
//=======================================================
void loop()
{  
  disp2.Letter(4, P); delay(150);
  disp2.Letter(3, i); delay(150);
  disp2.Symbol(2, '='); delay(150);
  disp2.Numberdp(1, 3); delay(150);
  //---------------------------------
  disp1.Number(1, 1);  delay(150);
  disp1.Number(2, 4); delay(150);
  disp1.Number(3, 1);  delay(150);
  disp1.Number(4, 6);
  //-----------------------------------------------------
  delay(2000); disp1.Clear(); disp2.Clear(); delay(1000);
}