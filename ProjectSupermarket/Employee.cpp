#include "Employee.h"

Employee::Employee(const size_t& id1,
	const my_string& name1,
	const my_string& surname1,
	const size_t& age1,
	const my_string& phone_number1,
	const my_string& password1) {
	
	set_id(id1);
	set_name(name1);
	set_surname(surname1);
	set_age(age1);
	set_phone_number(phone_number1);
	set_password(password1);

}

size_t Employee::get_id()	const {
	return id;
}

void Employee::set_id(size_t n)  {
	id = n;
}

my_string Employee::get_name()const {
	return name;
}

void Employee::set_name(my_string str) {
	name = str;
}

my_string Employee::get_surname()const {
	return surname;
}

void Employee::set_surname(my_string str) {
	surname = str;
}

size_t Employee::get_age()const {
	return age;
}

void Employee::set_age(size_t n) {
	age = n;
}

my_string Employee::get_phone_number()const {
	return phone_number;
}

void Employee::set_phone_number(my_string str) {
	phone_number = str;
}

my_string Employee::get_password()const {
	return password;
}

void Employee::set_password(my_string str) {
	password = str;
}

