#include "logger.hpp"

Logger_t* Logger_t::get_instance()
{
    static Logger_t* instance;
    if (instance == NULL) {
        instance = new Logger_t();
    }
    return instance;
}

Logger_t::Logger_t() : time_obj() {
    class_time = 24 * 60;
    logger_setting_obj.interval = 1;
    logger_setting_obj.log_mode = MEAN;
    logger_setting_obj.status = ENABLE;
    logger_setting_obj.start_time = _00_00;
    logger_setting_obj.stop_time = _23_59;
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

void Logger_t::task()
{
    date_time time_strct = time_obj->get_time_struct();
    int current_time = (time_strct.time_strct_obj.hh * 60) + (time_strct.time_strct_obj.mm);
    if (class_time == current_time) {
        //Buffer_updateing
        //Buffer_t::get_instance()->update_buffer();
        
        
    }
    else {
        this->class_time = current_time;
        int time_between_start_and_now = current_time - logger_setting_obj.start_time;
        if (time_between_start_and_now % logger_setting_obj.interval == 0) {
            if (logger_setting_obj.status = ENABLE) {
                this->prepare_to_log(time_strct);
            }
        }
        

    }
}

void Logger_t::prepare_to_log(date_time& time_strct) {
    string time_stamp = make_timestamp(time_strct);
    string data = prepare_data();
    string mode = get_mode();
    make_log(time_stamp, data, mode);
}

string Logger_t::make_timestamp(date_time& time_strct) {
    char time_stamp[31] = { 0 };
    sprintf_s(time_stamp, "[%d.%02d.%02d][%02d:%02d:%02d]",
        time_strct.date_strct_obj.year,
        time_strct.date_strct_obj.month,
        time_strct.date_strct_obj.day,
        time_strct.time_strct_obj.hh,
        time_strct.time_strct_obj.mm,
        time_strct.time_strct_obj.ss);
    return string(time_stamp);
}

string Logger_t::prepare_data(void)
{
    double value = 0;
    char value_char[40] = { 0 };
    string value_str = "";
    for (int i = 0; i < channel_address::CHANNEL_COUNTER; i++) {
        Buffer_t::get_instance()->get_buffer((channel_address)i, value);
        if (value == INVALID_VALUE_ERR) {
            sprintf_s(value_char, "[INVALID]");
        }
        else {
            sprintf_s(value_char, "[%0.2f]", value);
        }
        value_str += string(value_char);
        if (i == THE_LAST_CHANNEL) {
            sprintf_s(value_char, "[Sample_COUNT : %03d]", Buffer_t::get_instance()->get_sample_count());
            value_str += string(value_char);
        }
    }
    return value_str;
}

string Logger_t::get_mode(void) {
    switch (this->get_configs().log_mode) {
    case INSTANTANEOUS:
        return "[INSTANTANEOUS]";
        break;
    case MIN:
        return "[MIN-mode]";
        break;
    case MAX:
        return "[MAX-mode]";
        break;
    case MEAN:
        return "[MEAN-mode]";
        break;
    default:
        return "[NO-mode]";
        break;
    }
}

void Logger_t::make_log(string time_stamp, string data, string mode) {
#ifdef DESKTOP
    std::fstream FILE;
    FILE.open("logger.txt", std::ios::out | std::ios::app);
    if (FILE.is_open()) {
        FILE << time_stamp;
        FILE << " ";
        FILE << data;
        FILE << mode;
        FILE << "\r\n";
        FILE.close();
    }
#endif // DESKTOP
}

