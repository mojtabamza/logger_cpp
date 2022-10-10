#pragma once
#include "input.hpp"
#include "communication.hpp"

enum buffer_address {
	instant_value = 0,
	min_value,
	max_value,
	mean_value,
};

class Buffer_t {
public:
	static Buffer_t* get_instance();
	void set_configs();
	void task();
	void get_buffer(int address, float& value);
	//Input_t* input_obj;
	Communication_t* communication; //reserve to get data from peripherals
private:
	Buffer_t();
	float value;
	struct setting {

	};
protected:


};
