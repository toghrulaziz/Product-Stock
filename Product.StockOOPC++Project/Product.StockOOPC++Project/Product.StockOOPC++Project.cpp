#include <iostream>
using namespace std;

//class : Product
//	fields : id, name, description, price, discount
//	methods : ShowProduct(), GetPriceWithDiscount()
//
//
//	class Stock {
//	char* name
//		Product*	// array
//		Print()	// show all product in Stock
//		Product& GetProduct(int id);
//}


class Product {
	int id = 0;
	char* name = nullptr;
	char* description = nullptr;
	double price = 0;
	short discount = 0;
public:

	Product() : id(0), name(nullptr), description(nullptr), price(0), discount(0) {}

	Product(int id) : Product() {
		SetId(id);
	}

	Product(int id, const char* name) : Product(id) {
		SetName(name);
	}

	Product(int id, const char* name, const char* description) : Product(id, name) {
		SetDescription(description);
	}

	Product(int id, const char* name, const char* description, double price) : Product(id, name, description) {
		SetPrice(price);
	}

	Product(int id, const char* name, const char* description, double price, short discount) : Product(id, name, description, price) {
		SetDiscount(discount);
	}

	void ShowProduct() {
		cout << "Id: " << id << endl << "Name: " << name << endl << "Description: " << description << endl << "Price: " << price << endl << "Discount: " << discount << endl << "Price With Discount: " << GetPriceWithDiscount(price, discount) << endl << endl << endl;
	}

	double GetPriceWithDiscount(double price, short discount) {
		return price - (price * discount / 100);
	}


#pragma region Setters
	void SetId(int id) {
		this->id = id >= 0 ? id : 1;
	}

	void SetName(const char* name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void SetDescription(const char* description) {
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void SetPrice(double price) {
		this->price = price > 0 ? price : 10;
	}

	void SetDiscount(short discount) {
		this->discount = discount > 0 ? discount : 10;
	}
#pragma endregion

#pragma region Getters
	int GetId() { return id; }
	const char* GetName() { return name; }
	const char* GetDescription() { return description; }
	double GetPrice() { return price; }
	short GetDiscount() { return discount; }
#pragma endregion

	~Product() {
		delete[] name;
		delete[] description;
	}

};




class Stock {
	char* name = nullptr;
public:
	Product* products = new Product[3];

	Stock() :name(nullptr) {}

	Stock(const char* name) :Stock() {
		SetName(name);
	}

	int size = 3;
	Stock(Product* products, int size) {
		int productCount = size + 1;
		Product* temp = new Product[productCount];
		for (int i = 0; i < productCount; i++) {
			temp[i].SetName(products[i].GetName());
			temp[i].SetDescription(products[i].GetDescription());
			temp[i].SetPrice(products[i].GetPrice());
			temp[i].SetId(products[i].GetId());
			temp[i].SetDiscount(products[i].GetDiscount());
		}
	}

	void Print() {
		for (int i = 0; i < size; i++) {
			products[i].ShowProduct();
		}
	}

	Product& GetProduct(int id) {
		for (int i = 0; i < size; i++) {
			if (products[i].GetId() == id) {
				return products[i];
			}
		}
	}

#pragma region Setters
	void SetName(const char* name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
#pragma endregion


#pragma region Getter
	const char* GetName() { return name; }
#pragma endregion

};



void main() {

	Product p = Product(0, "Coco-Cola", "Drink", 2, 20);
	Product p1 = Product(1, "Water", "Drink", 5, 10);
	Product p2 = Product(2, "Bread", "Bakery", 4, 30);
	Product p3 = Product(3, "Red Bull", "Drink", 5, 30);
	Product p4 = Product(4, "Lays", "Junk food", 3, 30);

	Stock s;
	s.products = new Product[3]{ p,p3,p4 };
	cout << "All products in stock: \n" << endl;
	s.Print();
	s.GetProduct(2);


}