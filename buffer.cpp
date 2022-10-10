#include "buffer.hpp"


Buffer_t* Buffer_t::get_instance() {
	static Buffer_t* instance;
	if (instance == NULL) {
		instance = new Buffer_t();
	}
	return instance;
}

Buffer_t::Buffer_t() : communication() {
	this->value = 0;
}

void Buffer_t::set_configs() {

}

void Buffer_t::task() {
	this->value = Input_t::get_instance()->get_instant_value();
}

void Buffer_t::get_buffer(int address, float& value) {
	switch (address)
	{
	case instant_value:
		value = this->value;
		break;
	default:
		break;
	}
	
}
