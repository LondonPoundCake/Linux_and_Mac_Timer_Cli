#include "cli.hpp"
#include <iostream>
#include <CLI/CLI.hpp>


cli::cli(const std::string name): app(name)
{
    std::cout << "Constructor" << std::endl;
    //std::cout << cli_name << std::endl;
    //app.sub_command(Commands::Start,"starting");



}

void cli::check_args()
{

}

void cli::print_help_message()
{

}
