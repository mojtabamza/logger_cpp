#pragma once
#include "inc.hpp"


class Input_t {
public:
	static Input_t* get_instance();
	void input_generator(void);
	float get_instant_value();
private:
	Input_t();
	float input_value;
};

