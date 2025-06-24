#include "Cashier.h"

Cashier::Cashier(const size_t& id1,
	const my_string& name1,
	const my_string& surname1,
	const size_t& age1,
	const my_string& phone_number1,
	const my_string& password1):Employee(id1,name1,surname1,age1,phone_number1,password1){



}
size_t Cashier::get_transactions()const {
	return transactions;
}
my_vector<Warning> Cashier::get_warnings()const {
	return warnings;
}