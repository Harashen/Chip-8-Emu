#include "chip8.hpp"

Chip8::Chip8()
{

}

void Chip8::EmulateCycle(const float dt)
{

}

void Chip8::FetchOpCode()
{

}

void Chip8::ExecuteOpCode()
{

}

void Chip8::UpdateTimers(const float dt)
{

}

void Chip8::JumpToRoutine()
{

}

void Chip8::ClearScreen()
{

}

void Chip8::ReturnSubroutine()
{
    sp--;
    pc = stack[sp];
    pc += 2;
}

void Chip8::JumpToAddress()
{

}

void Chip8::ExecuteSubroutine()
{
    stack[sp] = pc;
    sp++;

    JumpToAddress();
}

void Chip8::SkipIfVxIsNN()
{

}

void Chip8::SkipIfVxIsNotNN()
{

}

void Chip8::SkipIfRegXisRegY()
{

}

void Chip8::SetRegXtoNN()
{

}

void Chip8::AddNNtoRegX()
{

}

void Chip8::SetRegXtoRegY()
{

}

void Chip8::SetRegXToRegXorRegY()
{

}

void Chip8::SetRegXtoRegXandRegY()
{

}

void Chip8::SetRegXtoRegXxorRegY()
{

}

void Chip8::AddVyToVx()
{

}

void Chip8::SubstractVyFromVx()
{

}

void Chip8::ShiftVyRightIntoVx()
{

}

void Chip8::SetVxToVyMinosVx()
{

}

void Chip8::ShiftVyLeftIntoVx()
{

}

void Chip8::SkipIfVxDifferentVy()
{

}

void Chip8::StoreMemoryInIndex()
{

}

void Chip8::JumpToNNN()
{

}

void Chip8::SetRandom()
{

}

void Chip8::Draw()
{

}

void Chip8::SkipIfPressed()
{

}

void Chip8::SkipIfNotPressed()
{

}

void Chip8::StoreCurrentDelayInVx()
{

}

void Chip8::WaitKeypress()
{

}

void Chip8::SetDelayTimer()
{

}

void Chip8::SetSoundTimer()
{

}

void Chip8::SetIndex()
{

}

void Chip8::SetIndexSprite()
{

}

void Chip8::StoreDecimalRegX()
{

}

void Chip8::StoreRegisters()
{

}

void Chip8::FillRegisters()
{

}