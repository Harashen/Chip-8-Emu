#ifndef TIMER_HPP
#define TIMER_HPP

class Timer
{
public:
    Timer();

    uint8_t Get();

    void Set(uint8_t value);
    
    void Reset();

    void Update();

private:
    uint8_t timer;
};

#endif