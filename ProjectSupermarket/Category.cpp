#include "Category.h"

Category::Category(const my_string& name1,
    const my_string& description1) {
    
    set_name(name1);
    set_description(description1);
    
}
Category& Category::operator=(const Category& other) {
    if (this != &other) { 
        name = other.name;
        description = other.description;
    }
    return *this;
}

void Category::set_name(const my_string& new_name) {
      name = new_name;
}

void Category::set_description(const my_string& new_description) {
    description = new_description;
}

my_string Category::get_name() {
    return name;
}

my_string Category::get_description() {
    return description;
}