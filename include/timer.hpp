#ifndef TIMER_H_
#define TIMER_H_
#include <iostream>
#include <chrono>
#include <sstream>
#include <string>

#include <sstream>
#include <iomanip>


class timer  {
    public:
        struct Duration {
            int64_t hours;
            int64_t minuites;
            int64_t seconds;

            Duration(int64_t h, int64_t m, int64_t s) : hours(h), minuites(m), seconds(s) {};

            static Duration from_duration(const std::chrono::steady_clock::duration& duration_1)
            {
                auto hours = std::chrono::duration_cast<std::chrono::hours>(duration_1);
                auto mins = std::chrono::duration_cast<std::chrono::minutes>(duration_1 % std::chrono::hours(1));
                auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration_1 % std::chrono::minutes(1));

                return Duration{hours.count(),mins.count(),seconds.count()};
            }
            // Maybe this could be inside of the utility function.
            std::string to_string() const
            {
                std::stringstream ss;
                ss << std::setfill('0') << std::setw(2) << hours << ":"
                   << std::setfill('0') << std::setw(2) << minuites << ":"
                   << std::setfill('0') << std::setw(2) << seconds;
                return ss.str();
            }
        };


    timer(const std::string & name = "");

    void start();
    void stop();
    void pause_timer();
    void resume();
    void duration_time();
    bool CheckIfTimerIsRunning();

    private :
        std::string timer_name = "";
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        bool running = false;
        Duration current_duration;

        std::chrono::system_clock::time_point elapsed_time;
};

#endif // TIMER_H_
