#pragma once
#include "Warnings.h"
#include "Cashier.h"
#include "Manager.h"
#include "ProductByUnit.h"
#include "ProductByWeight.h"
#include "my_vector.h"
#include "my_string.h"
#include "Time.h"
#include "SingleCategoryGiftCard.h"
#include "AllProductsGiftCard.h"
#include "MultipleCategoryGiftCard.h"

class System {
private:
	 size_t current_id = 0;
	 my_string current_name;
	 my_string current_surname;
	 size_t current_age;
	 my_string current_phone_number;
	 my_string current_password;
	 my_string current_special_code;
	 size_t current_transactions;
	 my_vector<Warning> current_warnings;
	 my_string current_role;
	 
	
	 my_vector<SingleCategoryGiftCard> single_category_gift_cards;
	 my_vector<AllProductsGiftCard> all_products_gift_cards;
	 my_vector<MultipleCategoryGiftCard> multiple_category_gift_cards;
	 my_vector<my_string> transaction_list;
	 my_vector<my_string> feed_list;
	 my_vector<Cashier> pending_cashiers;
	 my_vector<Manager> managers;
	 my_vector<Cashier> cashiers;
	 my_vector<ProductByUnit> products_by_unit;
	 my_vector<ProductByWeight> products_by_weight;
	 my_vector< Category> categories;

	 void load_managers(const my_string& filename);
	 void load_cashiers(const my_string& filename);
	 void load_products_by_unit(const my_string& filename);
	 void load_products_by_weight(const my_string& filename);
	 void load_all_gift_cards(const my_string& filename);
public:

	System();
	~System() = default;



	//Cashier
	void login(const size_t& id, const my_string& password);
	void register_employee(const my_string& role,
		const my_string& name,
		const my_string& surname,
		const size_t& age,
		const my_string& phone_number,
		const my_string& password);
	void list_user_data();
	void list_workers();
	void list_products();
	void list_products(const my_string& category_name);
	void list_feed();
	void list_transactions();
	void leave();
	void logout();

	//Maneger

	void list_pending();
	void approve(const size_t& cashier_id, const my_string& special_code);
	void decline(const size_t& cashier_id, const my_string& special_code);
	void list_warned_cashiers(const size_t& points);
	void warn_cashier(const size_t& cashier_id, const size_t& points);
	void promote_cashier(const size_t& cashier_id, const my_string& special_code);
	void fire_cashier(const size_t& cashier_id, const my_string& special_code);
	void add_category(const my_string& category_name, const my_string& category_description);
	void delete_category(const my_string& category_name);
	void add_product(const my_string& product_name);
	void delete_product(const my_string& product_name);
	void load_products(const my_string& filename);
	void load_gift_card(const my_string& filename);



	//helping functions
	void start_System();
	void delete_gift_card(const my_string& special_code);
	void update_current_cashier(const size_t& id);
	void delete_manager(const size_t& id);
	void delete_cashier(const size_t& id);
	void save_cashiers( const my_string& filename);
	void save_managers( const my_string& filename);
	void save_products_by_unit(const my_string& filename);
	void save_products_by_weight(const my_string& filename);
	void save_gift_cards(const my_string& filename);
	size_t indexOfManager(const size_t& id);
	size_t indexOfCashier(const size_t& id);
	bool isManager(const size_t&id);
	size_t convert_string_to_size_t(const my_string& str);
	double convert_string_to_double(const my_string& str);
	bool check_for_employee(const size_t& id);
};
