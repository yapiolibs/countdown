#include "Countdown.h"

// -------------------------------------------------------------------------------------------------

bool Countdown::process(Callback_t call_back)
{
    bool timed_out = process();
    if(timed_out)
        call_back();
    return timed_out;
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

    return false;
}

// -------------------------------------------------------------------------------------------------

void Countdown::enable()
{
    Serial.printf("StandbyOfficer::enable: officer %s\n", name.c_str());
    enabled = true;
}

// -------------------------------------------------------------------------------------------------

void Countdown::disable()
{
    Serial.printf("StandbyOfficer::disable: officer %s\n", name.c_str());
    enabled = false;
}

// -------------------------------------------------------------------------------------------------

void Countdown::reset()
{

    Serial.printf("StandbyOfficer::reset: officer %s\n", name.c_str());
    elapsed_seconds = 0;
}
