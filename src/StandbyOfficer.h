#pragma once

#include <elapsedMillis.h>

struct StandbyOfficer
{
    explicit StandbyOfficer(unsigned long seconds_idle_before_standby = 60);

    void process(std::function<void()> on_standby_callback);

    void enable();

    void disable();

    void reset(unsigned long seconds_idle_before_standby = 60);

private:
    bool enabled{false};
    elapsedSeconds elapsed_seconds{0};
    unsigned long seconds_idle_before_standby;
};
