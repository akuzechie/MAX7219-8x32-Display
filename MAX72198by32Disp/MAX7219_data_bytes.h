//-------------------
//MAX7219 Data Bytes
//-------------------
// Symbols (math & punctuation marks)
//----------------------------------------------------
byte equal[8] = {
        0b00000000,0b00000000,0b01111110,0b00000000,
        0b00000000,0b01111110,0b00000000,0b00000000};
byte plus[8] = {
        0b00000000,0b00010000,0b00010000,0b00010000,
        0b11111110,0b00010000,0b00010000,0b00010000};
byte minus[8] = {
        0b00000000,0b00000000,0b00000000,0b00000000,
        0b01111110,0b00000000,0b00000000,0b00000000};
byte multiply[8] = {
        0b00000000,0b01000010,0b00100100,0b00011000,
        0b00011000,0b00100100,0b01000010,0b00000000};
byte divide[8] = {
        0b00000000,0b00000010,0b00000100,0b00001000,
        0b00010000,0b00100000,0b01000000,0b00000000};
byte qm[8] = {
        0b00111100,0b01000010,0b00000010,0b00001100,
        0b00010000,0b00010000,0b00000000,0b00010000};
byte em[8] = {
        0b00010000,0b00010000,0b00010000,0b00010000,
        0b00010000,0b00010000,0b00000000,0b00010000};
byte percent[8] = {
        0b01000000,0b10100010,0b01000100,0b00001000,
        0b00010000,0b00100010,0b01000101,0b00000010};
byte space[8] = {0,0,0,0,0,0,0,0};
//----------------------------------------------------
// Numbers from 0 to 9
// ---------------------------------------------------
byte n0[8] = {
        0b00111100,0b01000010,0b01000010,0b01000010,
        0b01000010,0b01000010,0b01000010,0b00111100};
byte n1[8] = {
        0b00001000,0b00011000,0b00101000,0b00001000,
        0b00001000,0b00001000,0b00001000,0b00011100};
byte n2[8] = {
        0b00111100,0b01000010,0b00000010,0b00011100,
        0b00100000,0b01000000,0b01000000,0b01111100};
byte n3[8] = {
        0b00111100,0b01000010,0b00000010,0b00111100,
        0b00000010,0b00000010,0b01000010,0b00111100};
byte n4[8] = {
        0b00000110,0b00001010,0b00010010,0b00100010,
        0b01111110,0b00000010,0b00000010,0b00000010};
byte n5[8] = {
        0b01111110,0b01000000,0b01000000,0b01111100,
        0b00000010,0b00000010,0b01000010,0b00111100};
byte n6[8] = {
        0b00111100,0b01000010,0b01000000,0b01111100,
        0b01000010,0b01000010,0b01000010,0b00111100};
byte n7[8] = {
        0b01111110,0b00000010,0b00000100,0b00001000,
        0b00010000,0b00100000,0b00100000,0b00100000};
byte n8[8] = {
        0b00111100,0b01000010,0b01000010,0b00111100,
        0b01000010,0b01000010,0b01000010,0b00111100};
byte n9[8] = {
        0b00111100,0b01000010,0b01000010,0b01000010,
        0b00111110,0b00000010,0b01000010,0b00111100};
//----------------------------------------------------
// Numbers with decimal point from 0. to 9.
// ---------------------------------------------------
byte n0dp[8] = {
        0b00111100,0b01000010,0b01000010,0b01000010,
        0b01000010,0b01000010,0b01000010,0b00111101};
byte n1dp[8] = {
        0b00001000,0b00011000,0b00101000,0b00001000,
        0b00001000,0b00001000,0b00001000,0b00011101};
byte n2dp[8] = {
        0b00111100,0b01000010,0b00000010,0b00011100,
        0b00100000,0b01000000,0b01000000,0b01111101};
byte n3dp[8] = {
        0b00111100,0b01000010,0b00000010,0b00111100,
        0b00000010,0b00000010,0b01000010,0b00111101};
byte n4dp[8] = {
        0b00000110,0b00001010,0b00010010,0b00100010,
        0b01111110,0b00000010,0b00000010,0b00000011};
byte n5dp[8] = {
        0b01111110,0b01000000,0b01000000,0b01111100,
        0b00000010,0b00000010,0b01000010,0b00111101};
byte n6dp[8] = {
        0b00111100,0b01000010,0b01000000,0b01111100,
        0b01000010,0b01000010,0b01000010,0b00111101};
byte n7dp[8] = {
        0b01111110,0b00000010,0b00000100,0b00001000,
        0b00010000,0b00100000,0b00100000,0b00100001};
byte n8dp[8] = {
        0b00111100,0b01000010,0b01000010,0b00111100,
        0b01000010,0b01000010,0b01000010,0b00111101};
byte n9dp[8] = {
        0b00111100,0b01000010,0b01000010,0b01000010,
        0b00111110,0b00000010,0b01000010,0b00111101};
