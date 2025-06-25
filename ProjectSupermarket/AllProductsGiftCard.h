#pragma once
#include "GiftCard.h"

class AllProductsGiftCard : public GiftCard {
	 
	const my_string products = "ALL_PRODUCTS";
public:
	AllProductsGiftCard() = default;
	AllProductsGiftCard& operator=(const AllProductsGiftCard& other);
	AllProductsGiftCard(const my_string& code1,const size_t& percentage_discount);
	virtual ~AllProductsGiftCard() = default;
	// Override the special_code method to return a specific code for all products
	


};


