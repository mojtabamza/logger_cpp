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

class Display_t {
public:
	Display_t();
	void show();
	Date_Time_t* disp_time;
};

