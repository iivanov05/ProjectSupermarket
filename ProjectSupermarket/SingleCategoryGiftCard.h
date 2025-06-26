#pragma once
#include "GiftCard.h"

class SingleCategoryGiftCard : public GiftCard {


	my_string category;
	size_t percentage_discount;

public:

	SingleCategoryGiftCard() = default;
	SingleCategoryGiftCard& operator=(const SingleCategoryGiftCard& other);
	SingleCategoryGiftCard(const my_string& code1, const my_string& category1, const size_t& percentage_discount);

	~SingleCategoryGiftCard() override = default;

	void set_category(const my_string& new_category);
	my_string get_category() const;

};