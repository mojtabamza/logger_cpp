#include "systick.hpp"

Systick_t* Systick_t::get_instance() {
	static Systick_t* instance;
	if (instance == NULL) {
		instance = new Systick_t();
	}
	return instance;
}

Systick_t::Systick_t() {
	tick_counter = 0;
}

void Systick_t::add_task(string task_name, int interval) {
	task_t* new_task = new task_t();
	new_task->interval = interval;
	new_task->task = 0;
	new_task->exe_time = new_task->interval + tick_counter;

	tasks_vec.push_back(new_task);
	flags.push_back(false);
}

void Systick_t::systick_handler() {
	static int timer = 0;
	if (++timer >= 50000) {
		timer = 0;
		systick_isr();
	}
}

void Systick_t::systick_isr() {
	tick_counter++;
	for (auto i = 0; i < tasks_vec.size(); i++) {
		if (tasks_vec[i]->exe_time == tick_counter) {
			flags[i] = true;
			tasks_vec[i]->exe_time = tasks_vec[i]->interval + tick_counter;
		}
	}
}

int Systick_t::get_flag(int flag) {
	return flags[flag];
}

void Systick_t::reset_flag(int flag) {
	 flags[flag] = false;
}

void Systick_t::reset_flags(void)
{
	for (auto i = 0; i < flags.size(); i++) {
		flags[i] = false;
	}
}
