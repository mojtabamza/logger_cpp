#pragma once
#include "inc.hpp"

class Logger_t {
public:
	static Logger_t* get_instance();
	void task();
private:
	Logger_t();
protected:
};

