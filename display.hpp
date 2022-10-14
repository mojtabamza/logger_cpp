#pragma once
#include "inc.hpp"
#include "input.hpp"
#include "buffer.hpp"
#include "time.hpp"


class Display_t {
public:
	Display_t();
	void show();
	Date_Time_t* disp_time;
};

