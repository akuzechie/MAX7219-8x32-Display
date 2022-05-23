//----------------------------------------------------------------
// MAX72198by32Disp.cpp - Source File
// Library for Displaying Characters on MAX7219 Dot Matrix Display
// by: Anas Kuzechie (May 20, 2022)
//----------------------------------------------------------------
#include <Arduino.h>
#include <MAX72198by32Disp.h>
#include "MAX7219_data_bytes.h"
//========================================================================
// Constructor
//========================================================================
MAX72198by32Disp::MAX72198by32Disp(int DIN, int CS, int CLK)
{
  pinMode(DIN, OUTPUT); _DIN = DIN;
  pinMode(CS, OUTPUT); _CS = CS;
  pinMode(CLK, OUTPUT); _CLK = CLK;
}
//========================================================================
// Function Prototypes
//========================================================================
void Write(byte, byte, byte, byte, byte, byte, byte, byte);
void SPI_send(byte);
//========================================================================
// Methods
//========================================================================
void MAX72198by32Disp::Initialize(byte bright)
{
  //DDRD |= (1<<PD2)|(1<<PD3)|(1<<PD4);   //pins D2, D3 & D4 o/p
  //----------------------------------
  Write(0x09,0,0x09,0,0x09,0,0x09,0);                    //decoding mode OFF
  Write(0x0A,bright,0x0A,bright,0x0A,bright,0x0A,bright);//brightness level
  Write(0x0B,7,0x0B,7,0x0B,7,0x0B,7);                    //scan limit
  Write(0x0C,1,0x0C,1,0x0C,1,0x0C,1);                    //turn ON MAX7219
}
//========================================================================
void MAX72198by32Disp::Clear()
{
  for(byte i=0; i<8; i++) Write(i+1,0,i+1,0,i+1,0,i+1,0);
}
//========================================================================
void MAX72198by32Disp::Number(byte digit, byte num)
{
  switch(digit)
  {
    case 1:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(i+1,n0[i],0,0,0,0,0,0); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(i+1,n1[i],0,0,0,0,0,0); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(i+1,n2[i],0,0,0,0,0,0); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(i+1,n3[i],0,0,0,0,0,0); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(i+1,n4[i],0,0,0,0,0,0); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(i+1,n5[i],0,0,0,0,0,0); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(i+1,n6[i],0,0,0,0,0,0); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(i+1,n7[i],0,0,0,0,0,0); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(i+1,n8[i],0,0,0,0,0,0); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(i+1,n9[i],0,0,0,0,0,0);
    } break;
    //--------------------------------------------------------------
    case 2:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n0[i],0,0,0,0); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n1[i],0,0,0,0); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n2[i],0,0,0,0); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n3[i],0,0,0,0); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n4[i],0,0,0,0); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n5[i],0,0,0,0); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n6[i],0,0,0,0); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n7[i],0,0,0,0); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n8[i],0,0,0,0); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n9[i],0,0,0,0);
    } break;
    //--------------------------------------------------------------
    case 3:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n0[i],0,0); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n1[i],0,0); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n2[i],0,0); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n3[i],0,0); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n4[i],0,0); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n5[i],0,0); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n6[i],0,0); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n7[i],0,0); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n8[i],0,0); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n9[i],0,0);
    } break;
    //--------------------------------------------------------------
    case 4:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n0[i]); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n1[i]); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n2[i]); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n3[i]); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n4[i]); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n5[i]); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n6[i]); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n7[i]); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n8[i]); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n9[i]);
    }
  }
}
//========================================================================
void MAX72198by32Disp::Numberdp(byte digit, byte num)
{
  switch(digit)
  {
    case 1:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(i+1,n0dp[i],0,0,0,0,0,0); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(i+1,n1dp[i],0,0,0,0,0,0); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(i+1,n2dp[i],0,0,0,0,0,0); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(i+1,n3dp[i],0,0,0,0,0,0); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(i+1,n4dp[i],0,0,0,0,0,0); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(i+1,n5dp[i],0,0,0,0,0,0); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(i+1,n6dp[i],0,0,0,0,0,0); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(i+1,n7dp[i],0,0,0,0,0,0); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(i+1,n8dp[i],0,0,0,0,0,0); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(i+1,n9dp[i],0,0,0,0,0,0);
    } break;
    //--------------------------------------------------------------
    case 2:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n0dp[i],0,0,0,0); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n1dp[i],0,0,0,0); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n2dp[i],0,0,0,0); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n3dp[i],0,0,0,0); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n4dp[i],0,0,0,0); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n5dp[i],0,0,0,0); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n6dp[i],0,0,0,0); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n7dp[i],0,0,0,0); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n8dp[i],0,0,0,0); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(0,0,i+1,n9dp[i],0,0,0,0);
    } break;
    //--------------------------------------------------------------
    case 3:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n0dp[i],0,0); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n1dp[i],0,0); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n2dp[i],0,0); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n3dp[i],0,0); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n4dp[i],0,0); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n5dp[i],0,0); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n6dp[i],0,0); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n7dp[i],0,0); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n8dp[i],0,0); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,n9dp[i],0,0);
    } break;
    //--------------------------------------------------------------
    case 4:
    switch(num)
    {
      case 0:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n0dp[i]); break;
      case 1:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n1dp[i]); break;
      case 2:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n2dp[i]); break;
      case 3:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n3dp[i]); break;
      case 4:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n4dp[i]); break;
      case 5:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n5dp[i]); break;
      case 6:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n6dp[i]); break;
      case 7:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n7dp[i]); break;
      case 8:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n8dp[i]); break;
      case 9:
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,n9dp[i]);
    }
  }
}
//========================================================================
void MAX72198by32Disp::Letter(byte digit, byte im[])
{
  switch(digit)
  {
    case 1:
    for(byte i=0; i<=7; i++) Write(i+1,im[i],0,0,0,0,0,0); break;
    case 2:
    for(byte i=0; i<=7; i++) Write(0,0,i+1,im[i],0,0,0,0); break;
    case 3:
    for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,im[i],0,0); break;
    case 4:
    for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,im[i]);
  }
}
//========================================================================
void MAX72198by32Disp::Symbol(byte digit, char sym)
{
  switch(digit)
  {
    case 1:
    switch(sym)
    {
      case '=':
      for(byte i=0; i<=7; i++) Write(i+1,equal[i],0,0,0,0,0,0); break;
      case '+':
      for(byte i=0; i<=7; i++) Write(i+1,plus[i],0,0,0,0,0,0); break;
      case '-':
      for(byte i=0; i<=7; i++) Write(i+1,minus[i],0,0,0,0,0,0); break;
      case '*':
      for(byte i=0; i<=7; i++) Write(i+1,multiply[i],0,0,0,0,0,0); break;
      case '/':
      for(byte i=0; i<=7; i++) Write(i+1,divide[i],0,0,0,0,0,0); break;
      case '?':
      for(byte i=0; i<=7; i++) Write(i+1,qm[i],0,0,0,0,0,0); break;
      case '!':
      for(byte i=0; i<=7; i++) Write(i+1,em[i],0,0,0,0,0,0); break;
      case ' ':
      for(byte i=0; i<=7; i++) Write(i+1,space[i],0,0,0,0,0,0); break;
      case '%':
      for(byte i=0; i<=7; i++) Write(i+1,percent[i],0,0,0,0,0,0);
    }break;
    //-------------------------------------------------------------------
    case 2:
    switch(sym)
    {
      case '=':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,equal[i],0,0,0,0); break;
      case '+':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,plus[i],0,0,0,0); break;
      case '-':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,minus[i],0,0,0,0); break;
      case '*':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,multiply[i],0,0,0,0); break;
      case '/':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,divide[i],0,0,0,0); break;
      case '?':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,qm[i],0,0,0,0); break;
      case '!':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,em[i],0,0,0,0); break;
      case ' ':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,space[i],0,0,0,0); break;
      case '%':
      for(byte i=0; i<=7; i++) Write(0,0,i+1,percent[i],0,0,0,0);
    }break;
    //-------------------------------------------------------------------
    case 3:
    switch(sym)
    {
      case '=':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,equal[i],0,0); break;
      case '+':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,plus[i],0,0); break;
      case '-':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,minus[i],0,0); break;
      case '*':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,multiply[i],0,0); break;
      case '/':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,divide[i],0,0); break;
      case '?':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,qm[i],0,0); break;
      case '!':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,em[i],0,0); break;
      case ' ':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,space[i],0,0); break;
      case '%':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,i+1,percent[i],0,0);
    }break;
    //-------------------------------------------------------------------
    case 4:
    switch(sym)
    {
      case '=':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,equal[i]); break;
      case '+':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,plus[i]); break;
      case '-':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,minus[i]); break;
      case '*':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,multiply[i]); break;
      case '/':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,divide[i]); break;
      case '?':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,qm[i]); break;
      case '!':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,em[i]); break;
      case ' ':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,space[i]); break;
      case '%':
      for(byte i=0; i<=7; i++) Write(0,0,0,0,0,0,i+1,percent[i]);
    }
  }
}
//========================================================================
void MAX72198by32Disp::Write(byte c1, byte d1, byte c2, byte d2, 
           byte c3, byte d3, byte c4, byte d4)
{
  digitalWrite(_CS, LOW);
  //PORTD &= ~(1<<PD3);                   //CS low
  //-----------------------------------------------------------------
  SPI_send(c4); SPI_send(d4);           //command & data for digit 4
  SPI_send(c3); SPI_send(d3);           //command & data for digit 3
  SPI_send(c2); SPI_send(d2);           //command & data for digit 2
  SPI_send(c1); SPI_send(d1);           //command & data for digit 1
  //-----------------------------------------------------------------
  //PORTD |= (1<<PD3);                    //CS high
  digitalWrite(_CS, HIGH);
}
//========================================================================
void MAX72198by32Disp::SPI_send(byte data)
{
  for(byte i=0; i<8; i++)
  {
    digitalWrite(_CLK, LOW);
    //PORTD &= ~(1<<PD4);                 //CLK low
    //----------------------------------------------------------------
    //if(data & 0x80) PORTD |= (1<<PD2);  //o/p high if MSB = 1
    //else PORTD &= ~(1<<PD2);            //o/p low if MSB = 0
    if(data & 0x80) digitalWrite(_DIN, HIGH);
    else digitalWrite(_DIN, LOW);
    //----------------------------------------------------------------
    //PORTD |= (1<<PD4);                  //CLK high
    digitalWrite(_CLK, HIGH);
    data = data << 1;                   //shift data left one bit
  }  
}