#include "logger.hpp"

Logger_t* Logger_t::get_instance()
{
    static Logger_t* instance;
    if (instance == NULL) {
        instance = new Logger_t();
    }
    return instance;
}

void Logger_t::task()
{
    cout << "Logger" << endl;
}

void Logger_t::set_configs() {
}

void Logger_t::get_configs(string& configs) {
}

Logger_t::Logger_t() {

}

