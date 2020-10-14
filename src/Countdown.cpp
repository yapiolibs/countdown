#include "Countdown.h"

// -------------------------------------------------------------------------------------------------

bool Countdown::process(Callback_t &call_back)
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

    if(already_triggered)
        return false;

    if(elapsed_seconds >= seconds_idle_before_standby)
    {
        if(is_verbose)
        {
            Serial.printf("StandbyOfficer::process: officer %s ", name.c_str());
            Serial.printf("reports %lu seconds countdown timed out\n",
                          static_cast<unsigned long>(elapsed_seconds));
        }
        onTimeout();
        already_triggered = true;
        return true;
    }

    return false;
}

// -------------------------------------------------------------------------------------------------

bool Countdown::isEnabled() const { return enabled; }

// -------------------------------------------------------------------------------------------------

void Countdown::enable()
{
    if(is_verbose)
        Serial.printf("StandbyOfficer::enable: officer %s\n", name.c_str());
    enabled = true;
}

// -------------------------------------------------------------------------------------------------

void Countdown::disable()
{
    if(is_verbose)
        Serial.printf("StandbyOfficer::disable: officer %s\n", name.c_str());
    enabled = false;
}

// -------------------------------------------------------------------------------------------------

void Countdown::reset()
{
    if(is_verbose)
        Serial.printf("StandbyOfficer::reset: officer %s\n", name.c_str());
    already_triggered = false;
    elapsed_seconds = 0;
}
