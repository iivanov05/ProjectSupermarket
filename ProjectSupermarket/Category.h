#pragma once
#include "my_string.h";

class Category {
private:
    my_string name;
    my_string description;
    void set_name(const my_string& new_name);
    void set_description(const my_string& new_description);

public:

    Category() = default;

    Category& operator=(const Category& other);

    Category(const my_string& name,
        const my_string& description);

    ~Category() = default;


    my_string get_name();
    my_string get_description();

};