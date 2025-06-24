#include "Warnings.h";

Warning::Warning() {
	std::cout << "Sender name:" << std::endl;
	std::cin >> sender;
	std::cout << std::endl << "Description:" << std::endl;
	std::cin >> description;
	std::cout << std::endl << "Critical Points:" << std::endl;
	std::cin >> critical_points;
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

my_string Warning::get_sender() const{
	return sender;
}
my_string Warning::get_description() const {
	return description;
}
size_t Warning::get_critical_points() const {
	return critical_points;
}