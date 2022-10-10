#pragma once
#include "inc.hpp"


class Input_t {
public:
	static Input_t* get_instance();
	//Input_t();
	void task(void);
	float get_instant_value();
private:
	Input_t();
	float input_value;
};

