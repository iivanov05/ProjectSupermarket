#include "ProductByWeight.h"



ProductByWeight::ProductByWeight(const my_string& name1,
    const Category& obj1,
    const double& price1,
    const double& weight1):Product(name1, obj1, price1) {

	weight = weight1;
}

double ProductByWeight::get_weight() {
    return weight;
}

void ProductByWeight::set_weight(const double& new_weight) {
    weight = new_weight;
}