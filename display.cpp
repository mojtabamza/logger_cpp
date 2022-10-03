#include "display.hpp"

void Display_t::show()
{
	float temp;
	system("CLS");
	//cout << "Instant Value : " << Input_t::get_instance()->get_instant_value() << endl;
	Buffer_t::get_instance()->get_buffer(instant_value, temp);
	cout << "Instant Value : " << temp << endl;
}
