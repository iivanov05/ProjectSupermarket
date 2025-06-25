#pragma once
#include "GiftCard.h"
#include "my_vector.h"

class MultipleCategoryGiftCard : public GiftCard {

private:
	my_vector<my_string> categories;
public:
	MultipleCategoryGiftCard() = default;
	MultipleCategoryGiftCard& operator=(const MultipleCategoryGiftCard& other);
	MultipleCategoryGiftCard(const my_string& code1, const my_vector<my_string>& categories1, const size_t& percentage_discount);
	~MultipleCategoryGiftCard() override = default;
	void set_categories(const my_vector<my_string>& new_categories);
	my_vector<my_string> get_categories() const;

	void add_category(const my_string& category);

};