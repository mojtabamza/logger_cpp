#pragma once
#include "input.hpp"
#include "communication.hpp"
#include "logger.hpp"
#include "general_funcs.hpp"

enum buffer_address {
	INSTANT_VALUE = 0,
	MIN_VALUE,
	MAX_VALUE,
	MEAN_VALUE,
};
struct Buffer_values {
	double buf_value_1;
};

class Buffer_t {
public:
	static Buffer_t* get_instance();
	void set_configs();
	void task();
	void update_buffer();
	void get_buffer(int address, double& value);
	//Input_t* input_obj;
	Communication_t* communication; //reserve to get data from peripherals
private:
	Buffer_t();
	double value;
	Buffer_values buff_values;
	int counter;
	struct setting {

	};
protected:


};
