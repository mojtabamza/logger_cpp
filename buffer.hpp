#pragma once
#include "input.hpp"

class Buffer_t {
public:
	static Buffer_t* get_instance();
	void set_configs();
	void task();
private:
	Buffer_t();
	enum log_mode {
		min = 0,
		max,
		mean
	};
	struct setting {

	};
protected:


};
