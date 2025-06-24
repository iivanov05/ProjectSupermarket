#pragma once
#include "Employee.h"
#include "my_string.h"
#include <cstdlib>  
#include <ctime>    


class Manager : public Employee {
private:
	my_string special_code;

	
	char random_digit();
    char random_uppercase();
    char random_lowercase();
	
        
public:

	Manager() = default;

	Manager(const size_t& id1,
		const my_string& name1,
		const my_string& surname1,
		const size_t& age1,
		const my_string& phone_number1,
		const my_string& password1);

	~Manager() override = default;

	void set_special_code(const my_string& code);
	my_string get_special_code()const;
	my_string generate_special_code();
};