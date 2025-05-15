#include "timer.hpp"
#include <thread>

timer::timer(const std::string &name):timer_name(name),start_time(),end_time(),running(false),current_duration(0,0,0)
{
    std::cout << "Timer has started." << std::endl;
    start_time = std::chrono::steady_clock::now();
    running = true;
}
void start(){std::cout << "Starting timer" << std::endl;}
void stop(){std::cout << "Stopping timer" << std::endl;}
void pause_timer(){std::cout << "pausing timer" << std::endl;}
void resume(){std::cout << "resuming timer" << std::endl;}

void timer::duration_time()
{
     end_time = std::chrono::steady_clock::now();
     auto elapsed_duration = end_time - start_time;
     current_duration = Duration::from_duration(elapsed_duration);
     std::cout << current_duration.to_string() << std::endl;
}

bool timer::CheckIfTimerIsRunning(){
    return running;
}
