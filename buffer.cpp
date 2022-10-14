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
	this->counter = 0;
	buff_values.buf_value_1 = this->value;
}

void Buffer_t::set_configs() {

}

void Buffer_t::task() {
	this->value = Input_t::get_instance()->get_instant_value();
}

void Buffer_t::update_buffer() {
	logger_setting logger_setting_obj = Logger_t::get_instance()->get_configs();
	switch (logger_setting_obj.log_mode) {
	case MIN:
		buff_values.buf_value_1 = MIN(buff_values.buf_value_1, this->value);
		break;
	case MAX:
		buff_values.buf_value_1 = MAX(buff_values.buf_value_1, this->value);
		break;
	case MEAN:
		buff_values.buf_value_1 += this->value;
		counter++;
		break;
	default:
		break;
	}
}

void Buffer_t::get_buffer(int address, double& value) {
	switch (address)
	{
	case INSTANT_VALUE:
		value = this->value;
		break;
	case MIN_VALUE:
		value = this->buff_values.buf_value_1;
		break;
	case MAX_VALUE:
		value = this->buff_values.buf_value_1;
		break;
	case MEAN_VALUE:
		value = buff_values.buf_value_1 / counter;
		break;

	default:
		break;
	}
	
}
