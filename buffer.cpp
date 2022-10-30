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
	this->sample_count = 0;
	this->counter = 0;
	buff_values.buf_value_0 = this->value;
	buff_values.buf_value_1 = this->value;
	buff_values.buf_value_2 = this->value;
	buff_values.buf_value_3 = this->value;
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
		buff_values.buf_value_0 = this->value;
		buff_values.buf_value_1 = this->value;
		buff_values.buf_value_2 = this->value;
		buff_values.buf_value_3 = this->value;
		break;
	case MIN:
		buff_values.buf_value_0 = MIN(buff_values.buf_value_0, this->value);
		buff_values.buf_value_1 = MIN(buff_values.buf_value_1, this->value);
		buff_values.buf_value_2 = MIN(buff_values.buf_value_2, this->value);
		buff_values.buf_value_3 = MIN(buff_values.buf_value_3, this->value);
		break;
	case MAX:
		buff_values.buf_value_0 = MAX(buff_values.buf_value_0, this->value);
		buff_values.buf_value_1 = MAX(buff_values.buf_value_1, this->value);
		buff_values.buf_value_2 = MAX(buff_values.buf_value_2, this->value);
		buff_values.buf_value_3 = MAX(buff_values.buf_value_3, this->value);
		
		break;
	case MEAN:
		buff_values.buf_value_0 += this->value;
		buff_values.buf_value_1 += this->value;
		buff_values.buf_value_2 += this->value;
		buff_values.buf_value_3 += this->value;
		
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
	if (counter == 0) {
		value = INVALID_VALUE_ERR;
		return;
	}
	switch (logger_setting_obj.log_mode) {
	case INSTANTANEOUS_VALUE:
	case MIN_VALUE:
	case MAX_VALUE:
		this->get_value(channel_addr, value);
		break;
	case MEAN_VALUE:
		switch (channel_addr) {
		case CHANNEL_0:
			value = buff_values.buf_value_0 / counter;
			buff_values.buf_value_0 = 0;
			break;
		case CHANNEL_1:
			value = buff_values.buf_value_1 / counter;
			buff_values.buf_value_1 = 0;
			break;
		case CHANNEL_2:
			value = buff_values.buf_value_2 / counter;
			buff_values.buf_value_2 = 0;
			break;
		case CHANNEL_3:
			value = buff_values.buf_value_3 / counter;
			buff_values.buf_value_3 = 0;
			break;
		}
		if (channel_addr == THE_LAST_CHANNEL) {
			this->sample_count = counter;
			counter = 0;
		}
		break;
	default:
		break;
	}
}

void Buffer_t::get_instantaneous_value(channel_address channel_addr, double& value) {
	switch (channel_addr)
	{
	case CHANNEL_0:
		value = this->value;
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
}

int Buffer_t::get_sample_count(void) {
	return this->sample_count;
}

void Buffer_t::get_value(channel_address channel_addr, double& value) {
	switch (channel_addr) {
	case CHANNEL_0:
		value = buff_values.buf_value_0;
		break;
	case CHANNEL_1:
		value = buff_values.buf_value_1;
		break;
	case CHANNEL_2:
		value = buff_values.buf_value_2;
		break;
	case CHANNEL_3:
		value = buff_values.buf_value_3;
		break;
	default:
		break;
	}
}
