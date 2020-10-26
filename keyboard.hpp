#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

static const uint8_t KeysNumber = 0x0010;   // 16 keys. Hexadecimal keypad

class Keyboard
{
public:
    Keyboard();

    void Clear();

    bool Poll();

    bool IsKeyPressed(uint8_t key);

    uint8_t WaitForKeyPress();

private:
    bool keys[KeysNumber];
};

#endif // !KEYBOARD_HPP
