#include "System.h"
#include <fstream>



System::System() {

    load_managers("load_managers.txt");
    load_cashiers("load_cashiers.txt");
    load_products_by_unit("load_products_by_unit.txt");
    load_products_by_weight("load_products_by_weight.txt");
    

}

static my_vector<my_string> split(const my_string& line, char delim) {
    my_vector<my_string> parts;
    my_string cur;

    for (size_t i = 0; i < line.get_length(); ++i) {
        char c = line[i];
        if (c == delim) {
            parts.push_back(cur); 
            cur = "";             
        }
        else {
            cur += c;             
        }
    }

    parts.push_back(cur); 
    return parts;

}

void System::load_managers(const my_string& filename) {
    std::ifstream in(filename.c_str());
    
    if (!in) {
        std::cout << "Error loading managers!" << std::endl;
    }

    if (in.peek() == EOF) {
        in.close();
        return; 
    }

    my_string line;
    while (my_getline(in, line)) {
        auto parts = split(line, ';');
        size_t id = convert_string_to_size_t(parts[0]);
        size_t age = convert_string_to_size_t(parts[3]);
        managers.push_back(Manager(
            id,
            parts[1], parts[2],
            age,
            parts[4], parts[5]
        ));
    }
    in.close();
}

void System::load_cashiers(const my_string& filename) {
    std::ifstream in(filename.c_str());

    if (!in) {
        std::cout << "Error loading cashiers!" << std::endl;
    }

    if (in.peek() == EOF) {
        in.close();
        return;
    }

    my_string line;
	size_t counter = 0;
    while (my_getline(in, line)) {
        auto parts = split(line, ';');
        size_t id = convert_string_to_size_t(parts[0]);
        size_t age = convert_string_to_size_t(parts[3]);
		size_t transactions = convert_string_to_size_t(parts[6]);
        cashiers.push_back(Cashier(id, parts[1], parts[2], age, parts[4], parts[5], transactions));
		
		my_string path =  parts[0] + "_warnings.txt";
		std::ifstream warnings_file(path.c_str());

        if (!warnings_file) {
            std::cout << "Error loading warning file!" << std::endl;
        }

        while (my_getline(warnings_file, line)) {
            auto parts = split(line, ';');
			my_string sender = parts[0] +" "+ parts[1];
			my_string description = parts[2];
			size_t critical_points = convert_string_to_size_t(parts[3]);

			Warning loading_warning(sender,description, critical_points);

			cashiers[counter].get_warnings().push_back(loading_warning);   
        }
		warnings_file.close();
		
		counter++;
    }

    
 in.close();

}


void System::load_products_by_unit(const my_string& filename) {
    std::ifstream in(filename.c_str());

    if (!in) {
        std::cout << "Error loading products by unit!" << std::endl;
    }

    if (in.peek() == EOF) {
        in.close();
        return;

    }

    my_string line;
    while (my_getline(in, line)) {
        auto parts = split(line, ';');
        Category categ(parts[1], parts[2]);
        double price = convert_string_to_double(parts[3]);
        int quantity = convert_string_to_double(parts[4]);
        products_by_unit.push_back(ProductByUnit(parts[0], categ, price, quantity));

        in.close();
    }
}

void System::load_products_by_weight(const my_string& filename) {
    std::ifstream in(filename.c_str());

    if (!in) {
        std::cout << "Error loading products by weight!" << std::endl;
    }

    if (in.peek() == EOF) {
        in.close();
        return;
    }

    my_string line;
    while (my_getline(in, line)) {
        auto parts = split(line, ';');
        Category categ(parts[1], parts[2]);
        double price = convert_string_to_double(parts[3]);
        int weight = convert_string_to_double(parts[4]);
        products_by_weight.push_back(ProductByWeight(parts[0], categ, price, weight));

        in.close();
    }
}

size_t System::convert_string_to_size_t(const my_string& str) {
    my_string temp = str;
    size_t num = 0;
    size_t size = str.get_length();
    for (size_t i = 0, j = size; i < size; i++) {
        num += (str[--j] - '0') * pow(10, i);
    }
    
    return num;
}

double System::convert_string_to_double(const my_string& str) {
    my_string temp = str;
    size_t num = 0;
    size_t counter = 0;
    while (str[counter++] != '.');


    for (size_t i = 0, j = counter - 1; i < counter - 1; i++) {
        num += (str[--j] - '0') * pow(10, i);
    }

    size_t size = str.get_length();
    double dec = 0;
    for (size_t i = counter, j = size; i < size; i++) {
        dec += (str[--j] - '0') * pow(10, i - counter);
    }
    dec /= pow(10, size - counter);


    return dec + num;
}

double System::check_for_employee(const size_t& id) {
    size_t size = managers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (id == managers[i].get_id()) return true;
    }
    size = cashiers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (id == cashiers[i].get_id()) return true;
    }


    return false;
}

bool System::isManager(const size_t& id) {
    size_t size = managers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (id == managers[i].get_id()) return true;
    }
    size = cashiers.size();
    for (size_t i = 0; i < size; i++)
    {
        if (id == cashiers[i].get_id()) return false;
    }
}

size_t System::indexOfManager(const size_t& id) {
    int index = 0;
    for (;index < managers.size(); index++)
    {
        if (id == managers[index].get_id())return index;
    }
}

size_t System::indexOfCashier(const size_t& id) {
    int index = 0;
    for (; index < cashiers.size(); index++)
    {
        if (id == cashiers[index].get_id())return index;
    }
}

my_string my_to_string(size_t number) {
    my_string result;
    size_t size = 0;
    size_t temp = number;

    while (temp > 0) {
        temp /= 10;
        size++;
    }
    char ch;
    size_t dev = pow(10, size - 1);
    for (size_t i = 0; i < size; i++)
    {
        ch = (number / dev) + '0';
        result += ch;
        number %= dev;
        dev /= 10;

    }


    return result;
}

void System::update_current_cashier(const size_t& id) {
	size_t index = indexOfCashier(id);
    
	cashiers[index].set_transactions(current_transactions);

}



void System::save_managers(const my_string& filename) {
    std::ofstream out(filename.c_str(), std::ios::trunc);
    if (!out) {
        std::cout << "Error saving manager!" << std::endl;
        return;
    }
    for (size_t i = 0; i < managers.size(); i++)
    {
        out << managers[i].get_id() << ";"
            << managers[i].get_name() << ";"
            << managers[i].get_surname() << ";"
            << managers[i].get_age() << ";"
            << managers[i].get_phone_number() << ";"
            << managers[i].get_password() << "\n";
    }

    
    out.close();
}
void System::save_cashiers(const my_string& filename){

	std::ofstream out(filename.c_str(), std::ios::app);
	if (!out) {
		std::cout << "Error saving cashier!" << std::endl;
		return;
	}
    for (size_t i = 0; i < cashiers.size(); i++)
    {
        out << cashiers[i].get_id() << ";"
            << cashiers[i].get_name() << ";"
            << cashiers[i].get_surname() << ";"
            << cashiers[i].get_age() << ";"
            << cashiers[i].get_phone_number() << ";"
			<< cashiers[i].get_password() << ";"
            << cashiers[i].get_transactions() << "\n";
    }
	out.close();

}

void System::delete_manager(const size_t& id) {
	my_vector<Manager> temp_managers;
    for (size_t i = 0; i < managers.size(); i++)
    {   
		if (managers[i].get_id() != id) {
			temp_managers.push_back(managers[i]);
		}
    }
	managers = temp_managers;

	save_managers("load_managers.txt");
	Time time;
	feed_list.push_back("Manager with ID: " + my_to_string(id) + " has been deleted from the system!" + time.get_executuon_time());
}

void System::delete_cashier(const size_t& id) {
    my_vector<Cashier> temp_cashiers;
    for (size_t i = 0; i < cashiers.size(); i++)
    {
        if (cashiers[i].get_id() != id) {
            temp_cashiers.push_back(cashiers[i]);
        }
    }
    cashiers = temp_cashiers;

    my_string filename = my_to_string(id)+"_warnings.txt";

	std::ofstream out(filename.c_str(), std::ios::trunc); 
	out.close();
    
    
    save_cashiers("load_cashiers.txt");
	Time time;
    feed_list.push_back("Cashier with ID: " + my_to_string(id) + " has been deleted from the system!" + time.get_executuon_time());
}



void  System::login(const size_t& id, const my_string& password) {

    if (!check_for_employee(id)) {
        std::cout << "No employee with that ID!";
        return;
    }

    if (isManager(id)) {
        size_t index = indexOfManager(id);
        current_id = managers[index].get_id();
        current_name = managers[index].get_name();
        current_surname = managers[index].get_surname();
        current_age = managers[index].get_age();
        current_phone_number = managers[index].get_phone_number();
        current_password = managers[index].get_password();

		my_string path = my_to_string(id) + "_special_code.txt";
		my_string current_special_code;
		std::ifstream in(path.c_str());
        my_getline(in, current_special_code);

        current_role = "manager";
		Time time;
        feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(id) + " has logged into the system!" + time.get_executuon_time());
    }
    else {

        size_t index = indexOfCashier(id);
        current_id = cashiers[index].get_id();
        current_name = cashiers[index].get_name();
        current_surname = cashiers[index].get_surname();
        current_age = cashiers[index].get_age();
        current_phone_number = cashiers[index].get_phone_number();
        current_password = cashiers[index].get_password();
        current_transactions = cashiers[index].get_transactions();
        for (size_t i = 0; i < cashiers[index].get_warnings().size(); i++)
        {
            current_warnings[i] = cashiers[index].get_warnings()[i];
        }
        current_role = "cashier";

    }
        Time time;
        feed_list.push_back("Cashier " + current_name + " " + current_surname + " with ID: " + my_to_string(id) + " has logged into the system!" + time.get_executuon_time());

    if (current_password == password) {
        std::cout << "User " << current_name << " " << current_surname << " with ID: " << current_id << "has been logged into the system!" << std::endl;
	}
    else {
        std::cout << "Wrong password!" << std::endl;
        return;
    }
    




}

void System::register_employee(const my_string& role,
    const my_string& name,
    const my_string& surname,
    const size_t& age,
    const my_string& phone_number,
    const my_string& password)
{

    std::ifstream in("countEmployees.txt");
    if (!in) {
        std::cout << "Error loading products by weight!" << std::endl;
    }


    my_string line;
    my_getline(in, line);
    in.close();

    size_t id = convert_string_to_size_t(line);
    id++;
    ofstream outputFile("countEmployee.txt", ios::trunc);
    if (!outputFile) {
        std::cout << "Error opening file for writing!" << std::endl;
        return;
    }
    outputFile << id;
    outputFile.close();

    std::ifstream in2("countEmployees.txt");
    my_getline(in2, line);
    in.close();

    if (role == "manager")
    {
        line += "_special_code.txt";
        Manager manager(id, name, surname, age, phone_number, password);
        std::cout << "Manager registered successfully!" << std::endl;
        managers.push_back(manager);
        save_managers("load_managers.txt");

        std::ofstream out(line.c_str());
        if (!out) {
            std::cout << "Error saving manager's special code!" << std::endl;
            return;
        }
        manager.set_special_code(manager.generate_special_code());
        std::cout << "Special code: " << manager.get_special_code() << std::endl;
        std::cout << "Code: "<< line << std::endl;
        out << manager.get_special_code() << "\n";
        out.close();

		Time time;
		feed_list.push_back("Manager " + manager.get_name() + " " + manager.get_surname() + " with ID: " + my_to_string(id) + " has been registered in the system!" + time.get_executuon_time());


    }
    else if (role == "cashier")
    {

        Cashier cashier(id, name, surname, age, phone_number, password,0);
        pending_cashiers.push_back(cashier);
        std::cout << "Cashier registration pending approval from a manager." << std::endl;

		Time time;
		feed_list.push_back("Cashier " + cashier.get_name() + " " + cashier.get_surname() + " with ID: " + my_to_string(id) + " has been registered in the system and is pending approval!" + time.get_executuon_time());
    }

   

} 

void System::list_user_data(){

    std::cout   << "ID:" << current_id
                << "/nName:" << current_name
                << "/nSurname:" << current_surname
                << "/nAge:" << current_age
                << "/nPhone number:" << current_phone_number
                << "/nRole:" << current_role << std::endl;


}

void System::list_workers() {

    std::cout << "Managers:" << std::endl;
    for (size_t i = 0; i < managers.size(); i++)
    {
       
        std::cout   << "ID:" << managers[i].get_id()
                    << "/nName:" << managers[i].get_name()
		            << "/nSurname:" << managers[i].get_surname()
                    << "/nAge:" << managers[i].get_age()
					<< "/nPhone number:" << managers[i].get_phone_number()
                    << "/nRole: manager"<< std::endl;
    }

    std::cout << "Cashiers:" << std::endl;
    for (size_t i = 0; i < cashiers.size(); i++)
    {
        std::cout << "ID:" << cashiers[i].get_id()
            << "/nName:" << cashiers[i].get_name()
            << "/nSurname:" << cashiers[i].get_surname()
            << "/nAge:" << cashiers[i].get_age()
            << "/nPhone number:" << cashiers[i].get_phone_number()
            << "/nRole: cashier" << std::endl;
    }


}

void System::list_products() {
	std::cout << "Products by unit:" << std::endl;
	for (size_t i = 0; i < products_by_unit.size(); i++)
	{
		std::cout << products_by_unit[i].get_name() << " - "
			<< products_by_unit[i].get_category().get_name() << " - "
			<< products_by_unit[i].get_price() << " - "
			<< products_by_unit[i].get_quantity() << std::endl;
	}
	std::cout << "Products by weight:" << std::endl;
	for (size_t i = 0; i < products_by_weight.size(); i++)
	{
		std::cout << products_by_weight[i].get_name() << " - "
			<< products_by_weight[i].get_category().get_name() << " - "
			<< products_by_weight[i].get_price() << " - "
			<< products_by_weight[i].get_weight() << std::endl;
	}
}

void System::list_products(const my_string& category_name) {
	std::cout << "Products in category: " << category_name << std::endl;
	for (size_t i = 0; i < products_by_unit.size(); i++)
	{
		if (products_by_unit[i].get_category().get_name() == category_name) {
			std::cout << products_by_unit[i].get_name() << " - "
				<< products_by_unit[i].get_price() << " - "
				<< products_by_unit[i].get_quantity() << std::endl;
		}
	}
	for (size_t i = 0; i < products_by_weight.size(); i++)
	{
		if (products_by_weight[i].get_category().get_name() == category_name) {
			std::cout << products_by_weight[i].get_name() << " - "
				<< products_by_weight[i].get_price() << " - "
				<< products_by_weight[i].get_weight() << std::endl;
		}
	}
}

void System::list_feed() {
	
	std::ofstream out("feed_list.txt", std::ios::app);
	if (!out) {
		std::cout << "Error opening feed file!" << std::endl;
		return;
	}
	for (size_t i = 0; i < feed_list.size(); i++)
	{
		out << feed_list[i] << std::endl;
	}       

	out.close();

	std::ifstream in("feed_list.txt");
	if (!in) {
		std::cout << "Error opening feed file!" << std::endl;
		return;
	}
	my_string line;
    std::cout << "Current feed:" << std::endl;
    while (my_getline(in, line)) {
        std::cout << line << std::endl;
    }
	in.close();
	
}

void System::list_transactions() {
    std::ofstream out("transaction_list.txt", std::ios::app);
    if (!out) {
        std::cout << "Error opening feed file!" << std::endl;
        return;
    }
    for (size_t i = 0; i < feed_list.size(); i++)
    {
        out << feed_list[i] << std::endl;
    }

    out.close();

    std::ifstream in("transaction_list.txt");
    if (!in) {
        std::cout << "Error opening feed file!" << std::endl;
        return;
    }
    my_string line;
    std::cout << "Transactionsw:" << std::endl;
    while (my_getline(in, line)) {
        std::cout << line << std::endl;
    }
	in.close();

}

void System::logout() {
	if (current_role == "manager") {
		Time time;
		feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has logged out of the system!" + time.get_executuon_time());
	}
	else {
		Time time;
		update_current_cashier(current_id);
		feed_list.push_back("Cashier " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has logged out of the system!" + time.get_executuon_time());
	}

     current_id = 0;
     current_name = "";
     current_surname = "";
     current_age = 0;;
     current_phone_number = "";
     current_password = "";
     current_special_code = "";
     current_transactions = 0;
	 current_warnings = my_vector<Warning>();
     current_role = "";

}

void System::leave() {
	if (current_role == "manager") {
		Time time;
        delete_manager(current_id);
		feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has left the job!" + time.get_executuon_time());
		
    }
	else {
		Time time;
		delete_cashier(current_id);
		feed_list.push_back("Cashier " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has left the job!" + time.get_executuon_time());
	}

    logout();
}


void System::list_pending(const my_string& special_code) {
	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}
	if (special_code != current_special_code) {
		std::cout << "Wrong special code!" << std::endl;
		return;
	}
	std::cout << "Pending cashiers:" << std::endl;
	for (size_t i = 0; i < pending_cashiers.size(); i++)
	{
		std::cout << "ID: " << pending_cashiers[i].get_id() << ", Name: "
			<< pending_cashiers[i].get_name() << ", Surname: "
			<< pending_cashiers[i].get_surname() << ", Age: "
			<< pending_cashiers[i].get_age() << ", Phone number: "
			<< pending_cashiers[i].get_phone_number() << std::endl;
	}
}

void System::approve(const size_t& cashier_id, const my_string& special_code) {
	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}
	if (special_code != current_special_code) {
		std::cout << "Wrong special code!" << std::endl;
		return;
	}
	my_vector<Cashier> temp_pending_cashiers;
	size_t index = 0;
	for (; index < pending_cashiers.size(); index++)
	{
		if (pending_cashiers[index].get_id() == cashier_id) break;
	}

	cashiers.push_back(pending_cashiers[index]);

    my_string path = my_to_string(cashier_id) + "_warnings.txt";

    std::ofstream createWarningFile(path.c_str());
    
    createWarningFile.close();

    for (size_t i = 0; i < pending_cashiers.size(); i++)
    {
		if (i != index)temp_pending_cashiers.push_back(pending_cashiers[i]);


    }

	pending_cashiers = temp_pending_cashiers;
	
	Time time;
	feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has approved cashier with ID: " + my_to_string(cashier_id) + "!" + time.get_executuon_time());
}

void System::decline(const size_t& cashier_id, const my_string& special_code) {
	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}
	if (special_code != current_special_code) {
		std::cout << "Wrong special code!" << std::endl;
		return;
	}
	my_vector<Cashier> temp_pending_cashiers;
	size_t index = 0;
	for (; index < pending_cashiers.size(); index++)
	{
		if (pending_cashiers[index].get_id() == cashier_id) break;
	}
	for (size_t i = 0; i < pending_cashiers.size(); i++)
	{
		if (i != index)temp_pending_cashiers.push_back(pending_cashiers[i]);
	}
	pending_cashiers = temp_pending_cashiers;
	Time time;
	feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has declined cashier with ID: " + my_to_string(cashier_id) + "!" + time.get_executuon_time());
}

void System::list_warned_cashiers(const size_t& points) {
	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}
	std::cout << "Warned cashiers with more that" << points << " points:" << std::endl;
	for (size_t i = 0; i < cashiers.size(); i++)
	{
		if (cashiers[i].get_points_from_all_warnings() >= points) {
			std::cout << "ID: " << cashiers[i].get_id() << ", Name: "
				<< cashiers[i].get_name() << ", Surname: "
				<< cashiers[i].get_surname() << ", Age: "
				<< cashiers[i].get_age() << ", Phone number: "
				<< cashiers[i].get_phone_number() << std::endl;
		}
	}
}

void System::warn_cashier(const size_t& cashier_id, const size_t& points) {
	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}
	size_t index = indexOfCashier(cashier_id);
    std::cout << "Description of the warning: " << std::endl;
	my_string des;
    std::cin >> des;

	Warning new_warning (current_name + " " + current_surname,des, points);
	cashiers[index].get_warnings().push_back(new_warning);
	Time time;
	feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has warned cashier with ID: " + my_to_string(cashier_id) + " with " + my_to_string(points) + " points!" + time.get_executuon_time());
}


void System::promote_cashier(const size_t& cashier_id, const my_string& special_code) {

	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}

	if (special_code != current_special_code) {
		std::cout << "Wrong special code!" << std::endl;
		return;
	}

    size_t index = indexOfCashier(cashier_id);
	Manager promoted_cashier(cashiers[index].get_id(),
		cashiers[index].get_name(),
		cashiers[index].get_surname(),
		cashiers[index].get_age(),
		cashiers[index].get_phone_number(),
		cashiers[index].get_password());

	    promoted_cashier.set_special_code(promoted_cashier.generate_special_code());

        my_string line;
        
        line += "_special_code.txt";

        std::cout << "Cashier promoted successfully!" << std::endl;
        managers.push_back(promoted_cashier);
        save_managers("load_managers.txt");

        std::ofstream out(line.c_str());

        if (!out) {
            std::cout << "Error saving manager's special code!" << std::endl;
            return;
        }
        
        std::cout << "Special code: " << promoted_cashier.get_special_code() << std::endl;
        std::cout << "Code: " << line << std::endl;
        out << promoted_cashier.get_special_code() << "\n";
        out.close();

	Time time;
	feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has promoted cashier with ID: " + my_to_string(cashier_id) + " to manager!" + time.get_executuon_time());
	delete_cashier(cashier_id);


}


void System::fire_cashier(const size_t& cashier_id, const my_string& special_code) {

    if (current_role != "manager") {
        std::cout << "You are not a manager!" << std::endl;
        return;
    }

    if (special_code != current_special_code) {
        std::cout << "Wrong special code!" << std::endl;
        return;
    }

    Time time;
    delete_cashier(current_id);
    feed_list.push_back("Manager " + current_name + " " + current_surname + " fired Cashier with ID: " + my_to_string(cashier_id) + "!" + time.get_executuon_time());





}


void System::add_category(const my_string& category_name, const my_string& category_description) {
    if (current_role != "manager") {
        std::cout << "You are not a manager!" << std::endl;
        return;
    }

    for (size_t i = 0; i < categories.size(); i++)
    {
		if (categories[i].get_name() == category_name) {
			std::cout << "Category with that name already exists!" << std::endl;
			return;
		}
    }

	Category new_category(category_name, category_description);
	categories.push_back(new_category);
	Time time;
	feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has added category: " + category_name + "!" + time.get_executuon_time());
}

void System::delete_category(const my_string& category_name) {
	
	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;

	}

    for (size_t i = 0; i < products_by_unit.size(); i++)
    {
        if (products_by_unit[i].get_category().get_name() == category_name && products_by_unit[i].get_quantity()!=0) {
			std::cout << "You cannot delete a category that has products in it!" << std::endl;
            return;
        }
    }
    for (size_t i = 0; i < products_by_weight.size(); i++)
    {
        if (products_by_weight[i].get_category().get_name() == category_name && products_by_weight[i].get_weight() != 0) {
            std::cout << "You cannot delete a category that has products in it!" << std::endl;
            return;
        }
    }

    my_vector<Category> temp_categories;
	for (size_t i = 0; i < categories.size(); i++)
	{
		if (categories[i].get_name() != category_name) {
			temp_categories.push_back(categories[i]);
		}
	}
	categories = temp_categories;
	Time time;
	feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has deleted category: " + category_name + "!" + time.get_executuon_time());
}

void System::add_product(const my_string& product_type) {

	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}

	my_string name, category_name, category_description;
	double price;
	

	std::cout << "Enter product name: ";
	std::cin >> name;
	std::cout << "Enter category name: ";
	std::cin >> category_name;
    
	bool category_exists = false;
    Category current_category;
    for (size_t i = 0; i < categories.size(); i++)
    {
		if (categories[i].get_name() == category_name) {
			category_exists = true;
			current_category = categories[i];
		
		}
    }

    if (!category_exists) {

	    std::cout << "Category does not exist! Please add it first." << std::endl;
	    return;
    }
    else
    {
        
        if (product_type == "product_by_unit") {
			size_t quantity = 0;
            std::cout << "Enter product quantity: ";
            std::cin >> quantity;
            std::cout << "Enter product price: ";
            std::cin >> price;

			bool product_exists = false;
			size_t product_index = 0;
            for (size_t i = 0; i < products_by_unit.size(); i++)
            {
                if (products_by_unit[i].get_name() == name) {
					product_exists = true;
					product_index = i;
                }
            }

            if (product_exists) {

                products_by_unit[product_index].set_quantity(products_by_unit[product_index].get_quantity() + quantity);
            }
            else
            {
		        ProductByUnit new_product(name, current_category, price, quantity);
                products_by_unit.push_back(new_product);
            }

            Time time;
            feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has added product by unit: " + name + "!" + time.get_executuon_time());
        }
        else if (product_type == "product_by_weight") {
			double weight = 0;
            std::cout << "Enter product weight: ";
            std::cin >> weight;
            std::cout << "Enter product price: ";
            std::cin >> price;

            bool product_exists = false;
            size_t product_index = 0;
            for (size_t i = 0; i < products_by_weight.size(); i++)
            {
                if (products_by_weight[i].get_name() == name) {
                    product_exists = true;
                    product_index = i;
                }
            }

            if (product_exists) {

                products_by_weight[product_index].set_weight(products_by_weight[product_index].get_weight() + weight);
            }
            else
            {
                ProductByWeight new_product(name, current_category, price, weight);
                products_by_weight.push_back(new_product);
            }

            Time time;
            feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has added product by weight: " + name + "!" + time.get_executuon_time());
        }

    }

}

void System::delete_product(const my_string& product_name) {
	if (current_role != "manager") {
		std::cout << "You are not a manager!" << std::endl;
		return;
	}
	my_vector<ProductByUnit> temp_products_by_unit;
	for (size_t i = 0; i < products_by_unit.size(); i++)
	{
		if (products_by_unit[i].get_name() != product_name) {
			temp_products_by_unit.push_back(products_by_unit[i]);
		}
	}
	products_by_unit = temp_products_by_unit;
	my_vector<ProductByWeight> temp_products_by_weight;
	for (size_t i = 0; i < products_by_weight.size(); i++)
	{
		if (products_by_weight[i].get_name() != product_name) {
			temp_products_by_weight.push_back(products_by_weight[i]);
		}
	}
	products_by_weight = temp_products_by_weight;
	Time time;
	feed_list.push_back("Manager " + current_name + " " + current_surname + " with ID: " + my_to_string(current_id) + " has deleted product: " + product_name + "!" + time.get_executuon_time());
}

void System::load_products(const my_string& filename) {
	my_string path = filename + ".txt";
	std::ifstream in(path.c_str());
	if (!in) {
		std::cout << "Error loading products!" << std::endl;
		return;
	}
	my_string line;
	while (my_getline(in, line)) {
		auto parts = split(line, ':');
        if (parts[0] == "NEW") {

			my_string product_type = parts[1];
			my_string product_name = parts[2];
			my_string category_name = parts[3];

			size_t categ_index = 0;
			bool category_exists = false;
            for (size_t i = 0; i < categories.size(); i++)
            {
                if (categories[i].get_name() == category_name)
                {
                    category_exists = true;
					categ_index = i;
                }
            }
            if (!category_exists)
            {
				std::cout << "Category does not exist! Please add it first." << std::endl;
                return;
            }
            
            if (product_type == "product_by_unit") {
				double price = convert_string_to_double(parts[4]);
				size_t quantity = convert_string_to_size_t(parts[5]);
				
				products_by_unit.push_back(ProductByUnit(product_name, categories[categ_index], price, quantity));
			}
			else if (product_type == "product_by_weight") {
				double price = convert_string_to_double(parts[4]);
				double weight = convert_string_to_double(parts[5]);
				products_by_weight.push_back(ProductByWeight(product_name, categories[categ_index], price, weight));
			}
			else {
				std::cout << "Unknown product type!" << std::endl;
            }

        }
        else
        {
            my_string product_type = parts[0];
            my_string product_name = parts[1];
            my_string category_name = parts[2];

            size_t categ_index = 0;
            bool category_exists = false;
            for (size_t i = 0; i < categories.size(); i++)
            {
                if (categories[i].get_name() == category_name)
                {
                    category_exists = true;
                    categ_index = i;
                }
            }
            if (!category_exists)
            {
                std::cout << "Category does not exist! Please add it first." << std::endl;
                return;
            }


            if (product_type == "product_by_unit") {
                double price = convert_string_to_double(parts[3]);
                size_t quantity = convert_string_to_size_t(parts[4]);

                products_by_unit.push_back(ProductByUnit(product_name, categories[categ_index], price, quantity));
            }
            else if (product_type == "product_by_weight") {
                double price = convert_string_to_double(parts[3]);
                double weight = convert_string_to_double(parts[4]);
                products_by_weight.push_back(ProductByWeight(product_name, categories[categ_index], price, weight));
            }
            else {
                std::cout << "Unknown product type!" << std::endl;
            }
        }
       
		
	}


}

