#include "MultipleCategoryGiftCard.h"


MultipleCategoryGiftCard::MultipleCategoryGiftCard(const my_string& code1,
	const my_vector<my_string>& categories1, 
	const size_t& percentage_discount1):GiftCard(code1,percentage_discount1) {
	categories = categories1;
}

MultipleCategoryGiftCard& MultipleCategoryGiftCard::operator=(const MultipleCategoryGiftCard& other) {
	if (this != &other) {
		GiftCard::operator=(other);

		for (size_t i = 0; i < categories.size(); i++)
		{
			categories[i] = other.categories[i];
		}
		
	}
	return *this;
}

void MultipleCategoryGiftCard::set_categories(const my_vector<my_string>& new_categories) {
	categories = new_categories;
}

my_vector<my_string> MultipleCategoryGiftCard::get_categories() const {

	return categories;
}

void MultipleCategoryGiftCard::add_category(const my_string& category) {
	categories.push_back(category);
}
