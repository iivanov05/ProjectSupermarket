#include "SingleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(const my_string& code1,
	const my_string& category1,
	const size_t& percentage_discount1) : GiftCard(code1,percentage_discount1) {

	category = category1;
}

SingleCategoryGiftCard& SingleCategoryGiftCard::operator=(const SingleCategoryGiftCard& other) {
	if (this != &other) {
		GiftCard::operator=(other);
		category = other.category;
	}
	return *this;
}

void SingleCategoryGiftCard::set_category(const my_string& new_category) {
	category = new_category;
}
my_string SingleCategoryGiftCard::get_category() const {
	return category;
}