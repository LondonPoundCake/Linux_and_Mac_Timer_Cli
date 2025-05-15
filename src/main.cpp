#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
// These will go inside of the application_manager function.
#include "../include/utility.hpp"
#include "../include/cli.hpp"

#include "../include/timer.hpp"

// Need to define my own parameters so now i need to create a diagram of a basic flowloop of what my application should be able to do.


int main(int argc, char * argv[])
{
    //1] This is going be turned in to a cli function.

    cli commandlineinterface("CLI Timer project");


    std::cout << "1]. Check if we have a 2nd arg" << std::endl;
    if(argc < 2)
    {
        std::cout << "Json File " << argv[0] << " " << std::endl;
        return 1;
    }

    // 2] .
    // This is going to be turned in to a utility function.
    // my end goal is to have a manager class that can take bot of these.
    // End goal CLI + Utility = ApllicationManager.



    utility util(argv[1],true);
    timer timer_object;

    std::cout << "Press a key to stop the timer" << std::endl;
    while(timer_object.CheckIfTimerIsRunning())
    {
        timer_object.duration_time();
        sleep(1);
        if(util.khbit())
        {
            char c;
            read(STDIN_FILENO,&c,1);
            std::cout << "Key is pressed" << std::endl;
            break;
        }

    }

    util.set_terminal_mode(false);
    std::cout << "." << std::flush;

    std::cout << "Finished" << std::endl;

}
