#include "ProductByUnit.h"

ProductByUnit::ProductByUnit(const my_string& name1,
    const Category& obj1,
    const double& price1,
    const int& quantity1) :Product(name1, obj1, price1){

	quantity = quantity1;

}



void ProductByUnit::set_quantity(const int& new_quantity) {
	if (new_quantity < 0) {
		throw std::invalid_argument("Quantity cannot be negative.");
	}
quantity = new_quantity;
}

int ProductByUnit::get_quantity() const {
    return quantity;
}


