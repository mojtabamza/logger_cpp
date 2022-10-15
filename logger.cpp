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
        Buffer_t::get_instance()->update_buffer();
        
        
    }
    else {
        this->class_time = current_time;
        int time_between_start_and_now = current_time - logger_setting_obj.start_time;
        if (time_between_start_and_now % logger_setting_obj.interval == 0) {
            if (logger_setting_obj.status = ENABLE) {
                this->ready_to_log(time_strct);
            }
        }
        

    }
}

void Logger_t::set_configs(int interval, logger_mode mode, int start_time, int stop_time) {
    logger_setting_obj.interval = interval;
    logger_setting_obj.log_mode = mode;
    logger_setting_obj.start_time = start_time;
    logger_setting_obj.stop_time = stop_time;
}

logger_setting Logger_t::get_configs(void) {
    return logger_setting_obj;
}

void Logger_t::make_log(date_time& time_strct, string data) {
#ifdef DESKTOP
    std::fstream FILE;
    FILE.open("logger.txt", std::ios::out | std::ios::app);
    if (FILE.is_open()) {
        FILE << "[" <<
            time_strct.date_strct_obj.year << "." <<
            time_strct.date_strct_obj.month << "." <<
            time_strct.date_strct_obj.day <<
            "]" << "[" <<
            time_strct.time_strct_obj.hh << ":" <<
            time_strct.time_strct_obj.mm << ":" <<
            time_strct.time_strct_obj.ss <<
            "]" << "\n";
        FILE.close();
    }
#endif // DESKTOP
}

void Logger_t::ready_to_log(date_time& time_strct) {
    make_log(time_strct, "");
}

Logger_t::Logger_t() : time_obj() {
    class_time = 24 * 60;
    logger_setting_obj.interval = 1;
    logger_setting_obj.log_mode = MEAN;
    logger_setting_obj.status = ENABLE;
    logger_setting_obj.start_time = _00_00;
    logger_setting_obj.stop_time = _23_59;
}

