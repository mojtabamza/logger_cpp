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
    date_time time_strct = time_obj->get_time_struct();
    int current_time = (time_strct.time_strct_obj.hh * 3600) + (time_strct.time_strct_obj.mm * 60) + time_strct.time_strct_obj.ss;
    if (class_time == current_time) {
        this->ready_to_log();
    }
    else {
        this->class_time = current_time;

    }
}

void Logger_t::set_configs() {
}

void Logger_t::get_configs(string& configs) {
}

Logger_t::Logger_t() : time_obj() {
    class_time = 24 * 60 * 60;
    logger_setting_obj.interval = 1;
    logger_setting_obj.log_mode = mean;


}

