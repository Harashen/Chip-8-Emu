#include "timer.hpp"

Timer::Timer()
{
    Reset();
}

uint8_t Timer::Get()
{
    return timer;
}

void Timer::Set(uint8_t value)
{
    timer = value;
}

void Timer::Reset()
{
    timer = 0;
}

void Timer::Update()
{
    if (timer > 0) timer--;
}