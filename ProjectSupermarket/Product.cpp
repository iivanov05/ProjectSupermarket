#include "Product.h"

Product::Product(const my_string& name1,
    const Category& obj1,
    const double& price1) {
    name = name1;
    obj = obj1;
    price = price1;

}

my_string Product::get_name()const{
    return name;
}

double Product::get_price() const{

    return price;
}

Category Product::get_category() const {
	return obj;
}

void Product::set_name(const my_string& new_name) {
    name = new_name;
}

void Product::set_price(const double& new_price) {
    price = new_price;
}