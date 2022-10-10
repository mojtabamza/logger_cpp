#include "display.hpp"

void Display_t::show()
{
	
	float temp;
	date_time disp_time_strct;

	system("CLS");

	cout << disp_time->get_time_string() << endl;

	
	disp_time_strct = disp_time->get_time_struct();
	cout << "********************************" << endl;
	cout << disp_time_strct.date_strct_obj.year << "/"
		 << disp_time_strct.date_strct_obj.month << "/"
		 << disp_time_strct.date_strct_obj.day << "  "
		 << disp_time_strct.time_strct_obj.hh << ":"
		 << disp_time_strct.time_strct_obj.mm << ":"
		 << disp_time_strct.time_strct_obj.ss << endl;


	//cout << "Instant Value : " << Input_t::get_instance()->get_instant_value() << endl;
	Buffer_t::get_instance()->get_buffer(instant_value, temp);
	cout << "Instant Value : " << temp << endl;
}
