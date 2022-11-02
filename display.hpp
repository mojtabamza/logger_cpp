#pragma once
#include "inc.hpp"
#include "input.hpp"
#include "buffer.hpp"
#include "time.hpp"

#ifdef DESKTOP
#include <fstream>
#endif
#ifdef EMBEDDED
#include "fatfs.h"
#endif

enum input_keys {
	SET_CONFIG = 0,
	GET_CONFIG,
};

class Display_t {
public:
	Display_t();
	void show();
	Date_Time_t* disp_time;
};

