#pragma once
#include "my_string.h"
#include "Category.h"

class Product {
private:
    my_string name;
    Category obj;
    double price;

    void set_name(const my_string& new_name);
    void set_price(const double& new_price);

public:

    Product() = default;
    Product(const my_string& name,
        const Category& obj,
        const double& price);

    virtual ~Product() = default;


     my_string get_name()const;
     double get_price()const;
     Category get_category() const;
};