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
    int current_time = (time_strct.time_strct_obj.hh * 60) + (time_strct.time_strct_obj.mm);
    if (class_time == current_time) {
        //Buffer_updateing
        
    }
    else {
        this->class_time = current_time;
        int time_between_start_and_now = current_time - logger_setting_obj.start_time;
        if (time_between_start_and_now % logger_setting_obj.interval == 0) {
            this->ready_to_log(time_strct);
        }
        

    }
}

void Logger_t::set_configs() {
}

void Logger_t::get_configs(string& configs) {
}

void Logger_t::make_log() {
    cout << "make log" << endl;
}

void Logger_t::ready_to_log(date_time& time_strct) {
    cout << "ready to log" << endl;
}

Logger_t::Logger_t() : time_obj() {
    class_time = 24 * 60;
    logger_setting_obj.interval = 1;
    logger_setting_obj.log_mode = mean;
    logger_setting_obj.status = ENABLE;
    logger_setting_obj.start_time = _00_00;
    logger_setting_obj.stop_time = _23_59;
}

