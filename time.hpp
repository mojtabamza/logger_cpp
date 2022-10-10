#pragma once
#include "inc.hpp"
#include <ctime>
#include <chrono>

using std::time_t;

struct date_time {
	struct time_structure {
		int ss;
		int mm;
		int hh;
	}time_strct_obj;
	struct date_structure {
		int day;
		int month;
		int year;
	}date_strct_obj;
};



class Date_Time_t {
public:
	Date_Time_t();
	string get_time_string();
	date_time get_time_struct();
private:


};
