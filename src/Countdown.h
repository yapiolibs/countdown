#pragma once

#include <elapsedMillis.h>

/**
 * Convenience countdown that invokes virtual method onTimeout() or custom callback once the
 * counter is consumed.
 */
struct Countdown
{
    using Callback_t = std::function<void()>;

    Countdown(unsigned long seconds_countdown = 60, const String &name = "scotty")
    : seconds_idle_before_standby(seconds_countdown), name(name)
    {
    }

    virtual void onTimeout(){};

    /**
     * Calls callback and #process() on timeout.
     * @param call_back the callback to call if time run out
     * @return true if callback was executed, false otherwise
     */
    bool process(Callback_t &call_back);

    /**
     * Calls virtual method #onTimeout() if time run out.
     * @return true if callback was executed, false otherwise
     */
    bool process();

    void enable();
    void disable();
    void reset();

private:
    bool enabled{ false };
    elapsedSeconds elapsed_seconds{ std::numeric_limits<unsigned long>::max() };
    unsigned long seconds_idle_before_standby;
    const String name;
};
