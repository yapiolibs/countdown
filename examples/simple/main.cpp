#include <Countdown.h>

Countdown standby_officer(120);

auto on_t_minus_zero = []()
{
    Serial.println("going to bed...");
    ESP.deepSleepMax();
};

void setup()
{
}

void main()
{  
    // Invoke std::function, alternatively inherit from counter and oveload onTimeout().
    standby_officer.process(on_t_minus_zero);
}

