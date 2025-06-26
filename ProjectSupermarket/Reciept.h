#pragma once
#include "my_string.h"

class Receipt {
	my_string item_name;
	double item_quantity;
	double item_price;

public:
	Receipt() = default;
	Receipt(const my_string& item_name,const double& item_quantity, const double& item_price);

	~Receipt() = default;

	my_string get_item_name()const;

	double get_item_quantity()const;

	double get_item_price()const;
	void set_item_quantity(const double& new_quantity);

};



