#pragma once
#include "Product.h"
class ProductByWeight : public Product {
private:
    double weight;
    

public:

    ProductByWeight() = default;

    ProductByWeight(const my_string& name,
        const Category& obj,
        const double& price,
        const double& weight);

    ~ProductByWeight() override = default;


    void set_weight(const double& weight);
    double get_weight();

};

