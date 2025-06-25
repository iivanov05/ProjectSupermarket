#include "Cashier.h"

Cashier::Cashier(const size_t& id1,
	const my_string& name1,
	const my_string& surname1,
	const size_t& age1,
	const my_string& phone_number1,
	const my_string& password1,
	const size_t transactions1):Employee(id1,name1,surname1,age1,phone_number1,password1){

	transactions = transactions1;

}


size_t Cashier::get_points_from_all_warnings() const{
	size_t points = 0;

		for (size_t i = 0; i < warnings.size(); i++)
		{
			points += warnings[i].get_critical_points();
		}

	return points;

}

void Cashier::set_transactions(size_t transactions1) {
	transactions = transactions1;
}
size_t Cashier::get_transactions()const {
	return transactions;
}
my_vector<Warning> Cashier::get_warnings()const {
	return warnings;
}