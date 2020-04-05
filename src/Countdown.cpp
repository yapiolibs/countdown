#include "Countdown.h"

// -------------------------------------------------------------------------------------------------

bool Countdown::process(Callback_t call_back)
{
    if(process())
        call_back();
}

// -------------------------------------------------------------------------------------------------

bool Countdown::process()
{
    if(!enabled)
        return false;

    if(elapsed_seconds >= seconds_idle_before_standby)
    {
        Serial.printf("StandbyOfficer::process: officer %s ", name.c_str());
        Serial.printf("reports %lu seconds countdown timed out\n", static_cast<unsigned long>(elapsed_seconds));
        onTimeout();
        return true;
    }
}

// -------------------------------------------------------------------------------------------------

void enable()
{
    Serial.printf("StandbyOfficer::enable: officer %s\n", name.c_str());
    enabled = true;
}

// -------------------------------------------------------------------------------------------------

void disable()
{
    Serial.printf("StandbyOfficer::disable: officer %s\n", name.c_str());
    enabled = false;
}

// -------------------------------------------------------------------------------------------------

void reset()
{

    Serial.printf("StandbyOfficer::reset: officer %s\n", name.c_str());
    elapsed_seconds = 0;
}
