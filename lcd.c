#include <reg51.h>

// Control pins
sbit RS = P2^0;
sbit EN = P2^1;

// Data port
#define LCD P1

// Delay
void delay()
{
    int i, j;
    for(i = 0; i < 101; i++)
        for(j = 0; j < 10; j++);
}

// Send command
void cmd(unsigned char c)
{
    LCD = c;
    RS = 0;
    EN = 1;
    delay();
    EN = 0;
}

// Send data
void data(unsigned char d)
{
    LCD = d;
    RS = 1;
    EN = 1;
    delay();
    EN = 0;
}

// Init LCD
void init()
{
    cmd(0x38); // 8-bit, 2 line
    cmd(0x0C); // Display ON
    cmd(0x01); // Clear screen
}

// Main
void main()
{
    init();

    data('H');
    data('E');
    data('L');
    data('L');
    data('O');

    while(1);
}
