#include "inc.hpp"
#include "systick.hpp"
#include "logger.hpp"
#include "display.hpp"
#include "input.hpp"
#include "buffer.hpp"


int main(void) {
	Display_t	display;

	Systick_t::get_instance()->add_task("input:		flag(0)",	5);
	Systick_t::get_instance()->add_task("display:	flag(1)",	10);
	Systick_t::get_instance()->add_task("buffer:	flag(2)",	10);
	Systick_t::get_instance()->add_task("logger:	flag(3)",	10);

	while (true)
	{
		Systick_t::get_instance()->systick_handler();
		if (Systick_t::get_instance()->get_flag(0))
		{
			Systick_t::get_instance()->reset_flag(0);
			Input_t::get_instance()->task();
		}
		if (Systick_t::get_instance()->get_flag(1))
		{
			Systick_t::get_instance()->reset_flag(1);
			display.show();
		}
		if (Systick_t::get_instance()->get_flag(2))
		{
			Systick_t::get_instance()->reset_flag(2);
			Buffer_t::get_instance()->task();
		}
		if (Systick_t::get_instance()->get_flag(3))
		{
			Systick_t::get_instance()->reset_flag(3);
			Logger_t::get_instance()->task();
		}
	}
}