#include "display.hpp"

void Display_t::show()
{
	system("CLS");
	cout << "Instant Value : " << Input_t::get_instance()->get_instant_value() << endl;

}
