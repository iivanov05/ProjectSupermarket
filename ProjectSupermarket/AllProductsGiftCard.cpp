#include "AllProductsGiftCard.h"


AllProductsGiftCard::AllProductsGiftCard(const my_string& code1
	,const size_t& percentage_discount1) : GiftCard(code1, percentage_discount1) {

}

AllProductsGiftCard& AllProductsGiftCard::operator=(const AllProductsGiftCard& other) {
	if (this != &other) {
		GiftCard::operator=(other);
	}
	return *this;
}

