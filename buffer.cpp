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
	case INSTANTANEOUS:
		buff_values.buf_value_1 = this->value;
		break;
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

int Buffer_t::get_buffer_size()
{
	return channel_address::CHANNEL_COUNTER;
}

void Buffer_t::get_buffer(channel_address channel_addr, double& value) {
	logger_setting logger_setting_obj = Logger_t::get_instance()->get_configs();
	switch (logger_setting_obj.log_mode) {
	case INSTANTANEOUS_VALUE:
	case MIN_VALUE:
	case MAX_VALUE:
		value = this->get_value(channel_addr);
		//value = this->buff_values.buf_value_1;
		break;
	case MEAN_VALUE:
		value = buff_values.buf_value_1 / counter;
		counter = 0;
		break;
	default:
		break;
	}
	
}

double Buffer_t::get_value(channel_address channel_addr) {
	double value = 0;
	switch (channel_addr) {
	case CHANNEL_0:
		value = buff_values.buf_value_1;
		break;
	case CHANNEL_1:
		break;
	case CHANNEL_2:
		break;
	case CHANNEL_3:
		break;
	default:
		break;
	}
	return value;
}
