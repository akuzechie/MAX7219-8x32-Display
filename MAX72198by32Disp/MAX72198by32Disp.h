//-------------------------------------------------------------
// MAX72198by32Disp.h - Header File
// Library for Displaying Chracters on MAX7219 Dot Matrix Display
// by: Anas Kuzechie (May 20, 2022)
//-------------------------------------------------------------
//header guards
#ifndef MAX72198by32Disp_h
#define MAX72198by32Disp_h
//--------------------------------------------------------
//class definition
class MAX72198by32Disp
{
    public:
        //constructor
        MAX72198by32Disp(int DIN, int CS, int CLK);
        //methods
        void Initialize(byte bright);
        void Clear();
        void Number(byte digit, byte num);
        void Numberdp(byte digit, byte num);
        void Letter(byte digit, byte im[]);
        void Symbol(byte digit, char sym);       
    private:
        int _DIN;
        int _CS;
        int _CLK;
        void Write(byte c1, byte d1, byte c2, byte d2, byte c3, byte d3, byte c4, byte d4);
        void SPI_send(byte data);
};
//--------------------------------------------------------
#endif