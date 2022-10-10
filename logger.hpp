#pragma once
#include "inc.hpp"
#include "buffer.hpp"
#include "time.hpp"

class Logger_t {
public:
	static Logger_t* get_instance();
	void task();
	void set_configs();
	void get_configs(string& configs);
	//Time_t* time_obj;
private:
	Logger_t();
	struct setting {

	};
	enum mode {
		min = 0,
		max,
		mean,
	};
protected:
};

