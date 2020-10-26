#ifndef CHIP8_HPP
#define CHIP8_HPP

#include <array>

using namespace std;

static const uint8_t  RegisterSize    = 0x0010;    // 16 general purpose 8-bit registers.
static const uint8_t  StackSize       = 0x0010;    // 16 16-bit values.
static const uint8_t  MemoryLocations = 0x1000;    // 4096 bytes of RAM.
static const uint8_t  KeysNumber      = 0x0010;    // 16 keys. Hexadecimal keypad.
static const uint8_t  ScreenWidth     = 0x0040:    // 64
static const uint8_t  ScreenHeight    = 0x0020;    // 32
static const uint16_t Pixels          = ScreenWidth * ScreenHeight;

class Chip8
{
public:
    Chip8();

    void EmulateCycle(const float dt);
    //void ExecuteNextInstruction();
    //void DumpRegisters();
    //bool IsRunning();
    //bool LoadRom(const string filePath);

private:
    bool isRunning;

    uint8_t keyboard[KeysNumber];
    uint8_t ram[MemoryLocations];
    uint8_t delayTimer;
    uint8_t soundTimer;

    uint16_t index;        // register I
    uint8_t  sp;           // Stack Pointer
    uint16_t pc;           // Program Counter

    array<uint8_t,  RegisterSize> registers;
    array<uint16_t, StackSize>    stack;

    void FetchOpCode();
    void ExecuteOpCode();
    void UpdateTimers(const float dt);

    void JumpToRoutine();           // 0xNNN

    void ClearScreen();             // 0x00E0

    void ReturnSubroutine();        // 0x00EE

    void JumpToAddress();           // 0x1NNN

    void ExecuteSubroutine();       // 0x2NNN

    void SkipIfVxIsNN();            // 0x3XNN

    void SkipIfVxIsNotNN();         // 0x4XNN

    void SkipIfRegXisRegY();        // 0x5XY0

    void SetRegXtoNN();             // 0x6XNN

    void AddNNtoRegX();             // 0x7XNN

    void SetRegXtoRegY();           // 0x8XY0

    void SetRegXToRegXorRegY();     // 0x8XY1

    void SetRegXtoRegXandRegY();    // 0x8XY2

    void SetRegXtoRegXxorRegY();    // 0x8XY3

    void AddVyToVx();               // 0x8XY4

    void SubstractVyFromVx();       // 0x8XY5

    void ShiftVyRightIntoVx();      // 0x8XY6

    void SetVxToVyMinosVx();        // 0x8XY7

    void ShiftVyLeftIntoVx();       // 0x8XYE

    void SkipIfVxDifferentVy();     // 0x9XY0

    void StoreMemoryInIndex();      // 0xANNN

    void JumpToNNN();               // 0xBNNN

    void SetRandom();               // 0xCXNN

    void Draw();                    // 0xDXYN

    void SkipIfPressed();           // 0xEX9E

    void SkipIfNotPressed();        // 0xEXA1

    void StoreCurrentDelayInVx();   // 0xFX07

    void WaitKeypress();            // 0xFX0A

    void SetDelayTimer();           // 0xFX15

    void SetSoundTimer();           // 0xFX18

    void SetIndex();                // 0xFX1E

    void SetIndexSprite();          // OxFX29

    void StoreDecimalRegX();        // 0xFX33

    void StoreRegisters();          // 0xFX55

    void FillRegisters();           // 0xFX65
};

#endif