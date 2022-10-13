#pragma once
#include "inc.hpp"
#include "buffer.hpp"
#include "time.hpp"

enum logger_mode {
	min = 0,
	max,
	mean,
};
struct logger_setting {
	int interval;
	logger_mode log_mode;
};

class Logger_t {
public:
	static Logger_t* get_instance();
	void task();
	void set_configs();
	void get_configs(string& configs);
	void make_log();
	void ready_to_log();
	
private:
	Logger_t();
	Date_Time_t* time_obj;
	int class_time;
	logger_setting logger_setting_obj;


protected:
};

