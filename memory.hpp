#ifndef MEMORY_HPP
#define MEMORY_HPP

static const uint8_t MemoryLocations = 0x1000;    // 4096 bytes of RAM

class Memory 
{
public:
    Memory();

    uint8_t Get(uint16_t address);

    void Set(uint16_t address, uint8_t value);

    void Clear();

private:
    uint8_t ram[MemoryLocations];
};

#endif 
