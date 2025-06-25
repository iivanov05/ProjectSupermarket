#pragma once
#include "my_string.h"
#include <fstream>

class GiftCard {

	my_string code;
	size_t percentage_discount;
	
public:

	GiftCard() = default;
	GiftCard& operator=(const GiftCard& other);
	GiftCard(const my_string& code1,
		const size_t& percentage_discount);
	virtual ~GiftCard() = default;

	void set_code(const my_string& new_code) {
		code = new_code;
	}
	my_string get_code() const {
		return code;
	}
	size_t get_percentage_discount();

	char random_digit() const;

	char random_uppercase() const;
	my_string special_code() const;





};