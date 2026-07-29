#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct Book {
	int id;
	string name;
	int quantity;
};
struct User {
	int id;
	string name;
	string borrowed_books[100];
	int counts_book_each_user = 0;
};
Book library[100];
User user[100];
int counts_user = 0;
int counts_book = 0;
void Adding_book() {
	int newId, newQuantity;
	string newName;
	cout << "name,id,quantity\n";
	cin >> newName >> newId >> newQuantity;
	try {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			throw runtime_error("Wrong input type!");
		}

		if (newId < 0)
			throw runtime_error("ID must be postive\n");
		if (newQuantity < 0)
			throw runtime_error("QUantity must be postive\n");
		if (newName.empty())
			throw runtime_error("BOOk name cant be empty\n");
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		return;
	}
	bool is_found = false;
	for (int i = 0; i < counts_book; i++) {
		if (library[i].name == newName) {
			is_found = true;
			break;
		}
	}
	if (is_found) {
		cout << newName << " is already exist\n";
	}
	else {
		library[counts_book].name = newName;
		library[counts_book].id = newId;
		library[counts_book].quantity = newQuantity;
		counts_book++;
		cout << newName << " is added succesfully in the library\n";
	}


}



void Searching_book_by_prefix() {
	string prefix;
	cout << "Enter the prefix of the book: ";
	cin >> prefix;
	int  printed = 0;
	for (int i = 0; i < counts_book; i++) {
		bool is_found = true;
		if (prefix.size() > library[i].name.size()) {
			continue;
		}

		for (int j = 0; j < prefix.size(); j++) {
			if (!(
				char(prefix[j]) - char(library[i].name[j]) == 0 ||
				char(prefix[j]) - char(library[i].name[j]) == 32 ||
				char(prefix[j]) - char(library[i].name[j]) == -32
				))
			{
				is_found = false;
				break;
			}



		}
		if (is_found) {
			cout << "Found book starting with prefix \"" << prefix
				<< "\": " << library[i].name << "\n";
			printed++;
		}

	}
	if (printed == 0) {
		cout << "There is no string starting with this prefix\n";

	}

}

void listing_books_by_name() {
	for (int pass = 0; pass < counts_book - 1; pass++) {
		for (int i = 0; i < counts_book - pass - 1; i++) {
			if (library[i].name > library[i + 1].name) {
				swap(library[i], library[i + 1]);
			}
		}
	}
	cout << "\nBooks sorted by name:\n";
	for (int i = 0; i < counts_book; i++) {
		cout << library[i].name << " ";
	}
	cout << endl;
}

void listing_books_by_id() {
	for (int pass = 0; pass < counts_book - 1; pass++) {
		for (int i = 0; i < counts_book - 1; i++) {
			if (library[i].id > library[i + 1].id) {
				swap(library[i], library[i + 1]);
			}
		}
	}

	cout << "\nBooks sorted by ID: \n";
	for (int i = 0; i < counts_book; i++) {
		cout << library[i].name << " ";
	}
}

void borrow_book_by_name() {
	string book_name, person;
	int idx_book = -1;
	int idx_user = -1;
	cout << "Enter the name of the book: "; cin >> book_name;
	cout << "Enter your name: "; cin >> person;
	for (int i = 0; i < counts_user; i++) {
		if (user[i].name == person) {
			idx_user = i;
			break;

		}
	}
	bool is_found = false;
	for (int i = 0; i < counts_book; i++) {
		if (library[i].name == book_name) {
			is_found = true;
			idx_book = i;
			break;
		}
	}
	if (!is_found) {
		cout << "the book not found in the library\n";
	}
	else {
		if (library[idx_book].quantity > 0) {
			user[idx_user].borrowed_books[user[idx_user].counts_book_each_user++] = book_name;
			library[idx_book].quantity--;
			cout << person << " borrowed " << book_name
				<< " and its quantity now is: " << library[idx_book].quantity;
		}
		else {
			cout << "Sorry, " << book_name << " is out of stock.\n";
		}
	}
}

void return_book() {
	string name, book_name;
	int idx_book = -1;
	int idx_user = -1;
	cout << "Enter the name then book name: ";
	cin >> name >> book_name;
	bool is_exist_book = false;
	bool is_exist_user = false;
	bool is_found_book_user = false;
	int idx_book_user = -1;
	for (int i = 0; i < counts_book; i++) {
		if (library[i].name == book_name) {
			is_exist_book = true;
			idx_book = i;
			break;
		}
	}
	if (is_exist_book) {
		for (int i = 0; i < counts_user; i++) {
			if (user[i].name == name) {
				is_exist_user = true;
				idx_user = i;
				break;
			}

		}
	}

	bool is_last = false;

	for (int j = 0; j < user[idx_user].counts_book_each_user; j++) {
		if (user[idx_user].borrowed_books[j] == book_name) {
			is_found_book_user = true;
			idx_book_user = j;
			if (user[idx_user].borrowed_books[j + 1] == "") {
				is_last = true;
			}
		}



	}



	if (is_exist_book && is_exist_user && is_found_book_user) {
		library[idx_book].quantity++;
		cout << "This is after returning book: "
			<< "The id is : " << library[idx_book].id << endl
			<< "The name  is : " << library[idx_book].name << endl
			<< "The Quantity is : " << library[idx_book].quantity << endl;
		if (idx_book_user == 0) {
			user[idx_user].borrowed_books[idx_book_user] = "";
			for (int i = 0; i < user[idx_user].counts_book_each_user - 1; i++) {
				user[idx_user].borrowed_books[i] = user[idx_user].borrowed_books[i + 1];
			}
			user[idx_user].counts_book_each_user--;
		}

	}
	else if (is_last) {
		user[idx_user].borrowed_books[idx_book_user] = "";
		user[idx_user].counts_book_each_user--;
	}

	else {
		user[idx_user].borrowed_books[idx_book_user] = "";
		for (int i = idx_book_user; i < user[idx_user].counts_book_each_user - 1; i++) {
			user[idx_user].borrowed_books[i] = user[idx_user].borrowed_books[i + 1];
		}
		user[idx_user].counts_book_each_user--;
	}
}
void saves_books() {
	ofstream out("books.txt");
	for (int i = 0; i < counts_book; i++) {
		out << library[i].id << " "
			<< library[i].name << " "
			<< library[i].quantity << endl;
	}
	out.close();
}
void load_books() {
	ifstream in("books.txt");
	counts_book = 0;
	while (in >> library[counts_book].id
		>> library[counts_book].name
		>> library[counts_book].quantity
		)
	{
		counts_book++;
	}
	in.close();
}
void saves_user() {
	ofstream out("Users.txt");
	for (int i = 0; i < counts_user; i++) {
		out << user[i].name << endl;
	}
	out.close();
}
void load_users() {
	ifstream in("Users.txt");
	while (in >> user[counts_user].name) {
		string id;
		counts_user++;
	}
	in.close();
}

void adding_user() {
	if (counts_user >= 100) {
		cout << "Sry there is no free space to add anther one\n";
		return;
	}
	cout << "\nEnter the Id then the name of the user: ";
	try {
		cin >> user[counts_user].id >> user[counts_user].name;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			throw runtime_error("Invalid input\n");
		}
		if (user[counts_user].id < 0)
			throw runtime_error("Id cant be negative\n");
		if (user[counts_user].name.empty())
			throw runtime_error("Name cant be empty\n");
	}
	catch (runtime_error& e) {
		cout << e.what();
		return;
	}

	counts_user++;
	cout << "The user added succesfully\n";
}


void print_user_who_borrowed_book_name() {
	string name_book;
	cout << "Enter book name: "; cin >> name_book;
	bool is_exist = false;
	for (int i = 0; i < counts_book; i++) {
		if (library[i].name == name_book) {
			is_exist = true;
			break;
		}
	}
	if (is_exist) {
		bool is_found = false;
		cout << "Users who borrowed \"" << name_book << "\": ";
		for (int i = 0; i < counts_user; i++) {
			for (int j = 0; j < user[i].counts_book_each_user; j++) {
				if (user[i].borrowed_books[j] == name_book) {
					is_found = true;
					cout << user[i].name << " ";
					break;
				}

			}
		}
		if (!is_found) {
			cout << "No user borrowed this book";
		}
	}
	else {
		cout << "Invalid book name\n";
	}
}
void print_users() {
	for (int i = 0; i < counts_user; i++) {
		cout << user[i].name << " ";
	}
	cout << endl;
}
#include <iostream>
using namespace std;

void show_menu() {
	cout << "\n========== Library Menu ==========\n";
	cout << "1. Add Book\n";
	cout << "2. Search Book by Prefix\n";
	cout << "3. Borrow Book by Name\n";
	cout << "4. List Books by Name\n";
	cout << "5. List Books by ID\n";
	cout << "6. Add User\n";
	cout << "7. Return Book\n";
	cout << "8. printing all users\n";
	cout << "9.printing user_who_borrowed_book_by_name\n";
	cout << "0. Exit\n";
	cout << "=================================\n";
	cout << "Enter your choice: ";
}


int main() {
	load_books();
	load_users();
	int choice;

	while (true) {
		show_menu();
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nThis is adding book\n";
			Adding_book();
			saves_books();
			break;
		case 2:
			cout << "\nThis is Searching_book_by_prefix\n";
			Searching_book_by_prefix();
			break;
		case 3:
			cout << "\nThis is borrow_book_by_name\n";
			borrow_book_by_name();
			break;
		case 4:
			cout << "\nThis is listing_books_by_name\n";
			listing_books_by_name();
			break;
		case 5:
			cout << "\nThis is listing_books_by_id\n";
			listing_books_by_id();
			break;
		case 6:
			cout << "\nThis is adding_user\n";
			adding_user();
			saves_user();
			break;
		case 7:
			cout << "\nThis is returning book\n";
			return_book();
			break;
		case 8:
			cout << "\n printing the all users\n";
			print_users();
			break;
		case 9:
			print_user_who_borrowed_book_name();
			break;
		case 0:
			cout << "Exiting program... Goodbye!\n";
			return 0;
		default:
			cout << "Invalid choice! Please try again.\n";
		}
	}
}