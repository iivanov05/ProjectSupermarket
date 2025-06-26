#include "Reciept.h"


Receipt::Receipt(const my_string& item_name1, const double& item_quantity1,const double& item_price1) {

	item_name = item_name1;
	item_quantity = item_quantity1;
	item_price = item_price1;
}

my_string Receipt::get_item_name() const{
	return item_name;
}

double Receipt::get_item_quantity() const{
	return item_quantity;
}

double Receipt::get_item_price() const {
	return item_price;
}

void Receipt::set_item_quantity(const double& new_quantity) {
	if (new_quantity < 0) {
		throw std::invalid_argument("Quantity cannot be negative.");
	}
	item_quantity = new_quantity;
}