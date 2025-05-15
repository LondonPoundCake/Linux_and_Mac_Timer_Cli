#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <termios.h>
#include <sys/select.h>
#include <CLI/CLI.hpp>
#include "utility.hpp"
#include "nlohmann/json.hpp"
#include <unistd.h>

using json = nlohmann::json;

utility::utility(const char * arg,bool terminal) : json_arg(arg),terminal_mode(terminal)
{
    std::cout << "Constructor" << std::endl;
    std::cout << "UTILITY FUNCTION (Utility.cpp): " << std::endl;
    load_json_file();
    set_terminal_mode(terminal_mode);

}

bool utility::load_json_file()
{
    std::cout << "UTILITY FUNCTION (Utility.cpp): " << std::endl;
    std::cout << "1]. Load in .Json File" << std::endl;
    std::ifstream Json_file(json_arg);
    if(!Json_file)
    {
        std::cout << "Failed to open .Json file" << std::endl;
        return false;
    }
    else
    {
         std::cout << "Opened .Json file" << std::endl;
         json data = nlohmann::json::parse(Json_file);
         std::cout << std::setw(4) << data << "\n\n" << std::endl;
         return true;
    }
    return false;
}

void utility::set_terminal_mode(bool enabled)
{
    static struct termios oldt, newt;
    if (enabled)
    {
        tcgetattr(STDIN_FILENO,&oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW,&newt);

    }
    else {
        tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
    }

}

bool utility::khbit()
{
    struct timeval tv ={0,0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv) > 0;
}
