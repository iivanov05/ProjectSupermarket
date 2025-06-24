#include "Manager.h"

Manager::Manager(const size_t& id1,
	const my_string& name1,
	const my_string& surname1,
	const size_t& age1,
	const my_string& phone_number1,
	const my_string& password1) :Employee(id1, name1, surname1, age1, phone_number1, password1) {

	
}

    void Manager::set_special_code(const my_string& code) {

        special_code = code;

    }

    my_string Manager::get_special_code()const {
        return special_code;
    }

    char Manager::random_digit() {
        return '0' + rand() % 10;
    }

    char Manager::random_uppercase() {
        return 'A' + rand() % 26;
    }

    char Manager::random_lowercase() {
        return 'a' + rand() % 26;
    }

    my_string Manager::generate_special_code() {
        my_string code;
        code += random_digit();
        code += random_uppercase();
        code += random_uppercase();
        code += random_digit();
        code += random_digit();
        code += random_digit();
        code += random_lowercase();
        return code;
    }


	
