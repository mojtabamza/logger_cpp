#include "inc.hpp"
#include "systick.hpp"
#include "logger.hpp"
#include "display.hpp"
#include "input.hpp"
#include "buffer.hpp"


int main(void) {
	Display_t	display;

	Systick_t::get_instance()->add_task("flag(0)",	5);
	Systick_t::get_instance()->add_task("flag(1)",	10);
	Systick_t::get_instance()->add_task("flag(2)",	50);
	Systick_t::get_instance()->add_task("flag(3)",	100);

	while (true)
	{
		Systick_t::get_instance()->systick_handler();
		if (Systick_t::get_instance()->get_flag(0)) {
			Input_t::get_instance()->input_generator();
			
		}
		if (Systick_t::get_instance()->get_flag(1)) {
			display.show();
		}
		if (Systick_t::get_instance()->get_flag(2)) {
			Buffer_t::get_instance()->task();
		}

		Systick_t::get_instance()->reset_flags();
	}


}