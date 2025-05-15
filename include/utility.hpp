#ifndef UTILITY_H_
#define UTILITY_H_

class utility{
    private :
        const char * json_arg;
        bool terminal_mode;
    public :
        utility(const char * json_arg,bool terminal_mode);
        bool load_json_file();
        void set_terminal_mode(bool enabled);
        bool khbit();
};
#endif // UTILITY_H_
