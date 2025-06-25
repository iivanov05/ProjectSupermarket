#include "Warnings.h";
#include "Cashier.h"
Warning::Warning(const my_string& sender1,
	const my_string& description1,
	const size_t& critical_points1) {


	sender = sender1;
	description = description1;
	critical_points = critical_points1;

	if (critical_points <= 100) {
		set_points_description("Low");
	}
	else if (critical_points <= 200)
	{
		set_points_description("Medium");
	}
	else if (critical_points <= 300)
	{
		set_points_description("High");
	}

}
Warning& Warning::operator=(const Warning& other) {
	if (this != &other) {
		sender = other.sender;
		description = other.description;
		critical_points = other.critical_points;
		points_description = other.points_description;
	}

	return *this;

}
	
void Warning::set_points_description(const my_string& description) {
	points_description = description;
}



my_string Warning::get_sender() const{
	return sender;
}
my_string Warning::get_description() const {
	return description;
}
size_t Warning::get_critical_points() const {
	return critical_points;
}

my_string Warning::get_points_description() const {
	return points_description;
}