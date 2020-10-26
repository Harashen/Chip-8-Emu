#include "memory.hpp"

Memory::Memory() 
{

}

uint8_t Memory::Get(uint16_t address)
{
    if (address > 0 && address < MemoryLocations)
        return ram[address];
    else
        return 0;
}

void Memory::Set(uint16_t address, uint8_t value)
{
    if (address >= 0 && address < MemoryLocations)
        ram[address] = value;
}

void Memory::Clear()
{
    for (uint16_t address = 0; address < MemoryLocations; address++)
        Set(address, 0);
}