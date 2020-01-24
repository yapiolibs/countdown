#include "StandbyOfficer.h"

StandbyOfficer::StandbyOfficer(unsigned long seconds_idle_before_standby) :
        seconds_idle_before_standby(seconds_idle_before_standby)
{}

void StandbyOfficer::process(std::function<void()> on_standby_callback) {
    if (!enabled)
        return;

    if (elapsed_seconds >= seconds_idle_before_standby)
    {
        disable();
        on_standby_callback();
    }
}

void StandbyOfficer::enable() {
    elapsed_seconds = 0;
    enabled = true;
}

void StandbyOfficer::disable() {
    enabled = false;
}

void StandbyOfficer::reset(unsigned long seconds_idle_before_standby) {
    this->seconds_idle_before_standby = seconds_idle_before_standby;
    elapsed_seconds = 0;
}
