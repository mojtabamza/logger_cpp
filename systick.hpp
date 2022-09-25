#pragma once
#include "inc.hpp"


class Systick_t {
public:
	static Systick_t* get_instance();
	void add_task(string task_name, int interval);
	void systick_handler();
	void systick_isr();
	int	 get_flag(int flag);
	void reset_flag(int flag);
	void reset_flags(void);
private:
	Systick_t();
	int tick_counter;
	struct task_t
	{
		int interval;
		void(*task)(void);
		int exe_time;
	};

	vector<bool> flags;
	vector<task_t*> tasks_vec;


};