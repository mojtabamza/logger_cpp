#include "time.hpp"

Date_Time_t::Date_Time_t() {
	this->get_time_struct();
}
string Date_Time_t::get_time_string(void) {
	time_t now = std::time(0);

	//char str[26] = {};
	char* str;
	//ctime_s(str, sizeof(str), &now);
	str = ctime(&now);
	return str;
}

date_time Date_Time_t::get_time_struct() {
	date_time temp_struct;
	time_t now = std::time(0);
	struct tm* tm_obj;
	//localtime_s(&tm_obj, &now);
	tm_obj = localtime(&now);
	temp_struct.time_strct_obj.ss = tm_obj->tm_sec;
	temp_struct.time_strct_obj.mm = tm_obj->tm_min;
	temp_struct.time_strct_obj.hh = tm_obj->tm_hour;
	temp_struct.date_strct_obj.day = tm_obj->tm_mday;
	temp_struct.date_strct_obj.month = tm_obj->tm_mon + 1;
	temp_struct.date_strct_obj.year = tm_obj->tm_year + 1900;
	return temp_struct;
}