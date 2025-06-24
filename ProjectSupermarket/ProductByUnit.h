#pragma once
#include "Product.h"


class ProductByUnit : public Product {
private:
    int quantity;
    void set_quantity(const int& q);

public:
    ProductByUnit() = default;

    ProductByUnit(const my_string& name,
        const Category& obj,
        const double& price,
        const int& quantity);

    ~ProductByUnit() override = default;

   
    int get_quantity()  const;
    
};

