#include "input.hpp"


Input_t* Input_t::get_instance() {
	static Input_t* instance;
	if (instance == NULL) {
		instance = new Input_t();
	}
	return instance;
}

Input_t::Input_t() {

}

void Input_t::input_generator(void) {
	this->input_value = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100));
}

float Input_t::get_instant_value() {
	return this->input_value;
}
