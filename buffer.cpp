#include "buffer.hpp"


Buffer_t* Buffer_t::get_instance() {
	static Buffer_t* instance;
	if (instance == NULL) {
		instance = new Buffer_t();
	}
	return instance;
}

Buffer_t::Buffer_t() {
}

void Buffer_t::set_configs() {

}

void Buffer_t::task() {

}
