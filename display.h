#ifndef DISPLAY_H
#define DISPLAY_H

static const uint8_t ScreenWidth  = 0x0040:   // 64
static const uint8_t ScreenHeight = 0x0020;   // 32

static const uint16_t MemorySize = ScreenWidth * ScreenHeight / 8;

class Display
{
public:
    Display();

    void Clear();

};

#endif // !DISPLAY_H