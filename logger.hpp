#pragma once
#include "inc.hpp"
#include "buffer.hpp"
#include "time.hpp"

constexpr auto _00_00 = 0;
constexpr auto _23_59 = (23 * 60) + 59;

enum logger_mode {
	min = 0,
	max,
	mean,
};
enum logger_status {
	DISABLE = 0,
	ENABLE = 1,
};
struct logger_setting {
	int interval;
	logger_mode log_mode;
	int start_time;
	int stop_time;
	logger_status status;

};


class Logger_t {
public:
	static Logger_t* get_instance();
	void task();
	void set_configs();
	void get_configs(string& configs);
	void make_log();
	void ready_to_log(date_time& time_strct);
	
private:
	Logger_t();
	Date_Time_t* time_obj;
	int class_time;
	logger_setting logger_setting_obj;


protected:
};

