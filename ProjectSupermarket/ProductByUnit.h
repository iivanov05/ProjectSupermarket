#pragma once
#include "Product.h"


class ProductByUnit : public Product {
private:
    int quantity;


public:
    ProductByUnit() = default;

    ProductByUnit(const my_string& name,
        const Category& obj,
        const double& price,
        const int& quantity);

    ~ProductByUnit() override = default;

	void set_quantity(const int& new_quantity);
    int get_quantity()  const;
    
};

