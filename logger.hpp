#pragma once
#include "inc.hpp"

class Logger_t {
public:
	static Logger_t* get_instance();
	void task();
	void set_configs();
	void get_configs(string& configs);
private:
	Logger_t();
protected:
};

