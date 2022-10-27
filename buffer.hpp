#pragma once
#include "input.hpp"
#include "communication.hpp"
#include "logger.hpp"
#include "general_funcs.hpp"

enum buffer_mode {
	INSTANTANEOUS_VALUE = 0,
	MIN_VALUE,
	MAX_VALUE,
	MEAN_VALUE,
};
enum channel_address {
	CHANNEL_0 = 0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_COUNTER,
};
struct Buffer_channel {
	double buf_value_1;
};

class Buffer_t {
public:
	static Buffer_t* get_instance();
	void set_configs();
	void task();
	void update_buffer();
	int  get_buffer_size();
	void get_buffer(channel_address channel_addr, double& value);
	void get_instantaneous_value(channel_address channel_addr, double& value);
	//Input_t* input_obj;
	Communication_t* communication; //reserve to get data from peripherals
private:
	Buffer_t();
	void get_value(channel_address channel_addr, double& value);
	double value;
	Buffer_channel buff_values;
	int counter;
	struct setting {

	};
protected:


};
