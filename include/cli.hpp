#ifndef CLI_H_
#define CLI_H_
#include <iostream>
#include <CLI/CLI.hpp>

class cli{
    private :
        CLI::App app;
    public :
        cli(const std::string name);

        void parse_json_config_file_path();
        void validate_file_exists();
        void handle_other_flags();

        // Start pasue stop etc
        void process_user_input_commands();
        void show_error_message();

        void check_args();
        void print_help_message();

        void avaliabe_commands();
        void quit_commands();


        enum class Commands{
                START,
                PAUSE,
                STOP,
                RESUME,
                STATUS,
                CONFIG
        };

};


#endif // CLI_H_
