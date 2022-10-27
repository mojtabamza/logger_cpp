#include "display.hpp"

Display_t::Display_t() : disp_time() {
}

void Display_t::show()
{
	
	double temp;
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
	Buffer_t::get_instance()->get_buffer(CHANNEL_0, temp);
	cout << "Instant Value : " << temp << endl;

#ifdef DESKTOP
	std::fstream FILE;
	FILE.open("logger.txt", std::ios::in);
	if (FILE.is_open()) {
		string line;
		while (getline(FILE, line)) {
			cout << line << endl;
		}
		FILE.close();
	}
#endif
}
