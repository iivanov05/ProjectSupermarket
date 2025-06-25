#include "GiftCard.h"
#include "System.h"


GiftCard::GiftCard(const my_string& code1,
    const size_t& percentage_discount1) {
    code = code1;
	percentage_discount = percentage_discount1;
}

GiftCard& GiftCard::operator=(const GiftCard& other) {
	if (this != &other) {
		code = other.code;
		percentage_discount = other.percentage_discount;
	}
	return *this;
}

size_t GiftCard::get_percentage_discount() {
	return percentage_discount;
}

char GiftCard::random_digit() const {
	return '0' + rand() % 10;
}

char GiftCard::random_uppercase() const {
	return 'A' + rand() % 26;
}

my_string GiftCard::special_code() const {
    my_string code;
    code += random_digit();
    code += random_uppercase();

	std::ifstream in("countGiftCards.txt");
    my_string line;
    my_getline(in, line);
	in.close();

	code += line;

    code += random_uppercase();
    code += random_digit();

    return code;
}