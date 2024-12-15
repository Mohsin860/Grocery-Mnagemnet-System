#include"Inventory.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Item.h"
using namespace std;

Inventory::Inventory()
{                               // storing the items
	size = 45;
	ite = new Item[size];
}
void Inventory::GetInventory()
{
	size = 45;
	ite = new Item[size];
	int ss = 0;
	bool category = false;
	string name;
	string price;
	string quantity;
	int i, f;
	string s;
	fstream rdr("Inventory.txt");    //operating data from files  
	while (getline(rdr, s))
	{
		if (s == "Item:Price:Quantity")
		{
			name = s;
			category = true;
			this->ite[ss].setcategory(category);
			this->ite[ss].setname(name);
			ss++;
			name = "";
			price = "";
			category = false;
			continue;
		}
		if (s == "*Meat" || s == "*Dairy" || s == "Food" || s == "oPerishable_Goods" || s == "oFruit" || s == "oVegetable" || s == "oNon-Perishable_Goods" || s == "*Snacks" || s == "*Spices" || s == "oPersonal_Hygiene" || s == "oHousehold_Cleaning")
		{
			for (int g = 0; g < s.size(); g++)
			{
				if (s[g] == ' ')
					break;
				name.push_back(s[g]);
			}
			price = "0";
			category = true;
			this->ite[ss].setcategory(category);
			this->ite[ss].setname(name);
			this->ite[ss].setprice(price);
			ss++;
			name = "";
			price = "";
			category = false;
			continue;
		}
		for (i = 0; i < s.size(); i++)
		{

			if (s[i] == ' ' || s[i] == '\n')
				break;
			name.push_back(s[i]);
		}
		for (f = i + 1; f < s.size(); f++)
		{
			if (s[f] == ' ' || s[f] == '\n')
				break;
			price.push_back(s[f]);
		}
		for (int d = f + 1; d < s.size(); d++)
		{
			quantity.push_back(s[d]);
		}
		this->ite[ss].setcategory(category);
		this->ite[ss].setname(name);
		this->ite[ss].setprice(price);
		this->ite[ss].setquantity(quantity);
		ss++;
		name = "";
		price = "";
		quantity = "";
		category = false;
		//cout << s << "\n";
	}
	rdr.close();

}
void Inventory::PrintInventory()
{
	fstream rdr("Inventory.txt");
	rdr.clear();
	cout << "Item:Price:Quantity\n";
	rdr << "Item:Price:Quantity\n";
	for (int i = 1; i < size; i++)
	{
		if (this->ite[i].getname() == "-" && this->ite[i].getprice() == "-")
			continue;
		if (this->ite[i].getcategory() == true)
		{
			cout << this->ite[i].getname() << "\n";
			if (i == size - 1)
			{
				rdr << this->ite[i].getname();
				continue;
			}
			rdr << this->ite[i].getname() << "\n";
			continue;
		}
		else
		{
			cout << this->ite[i].getname() << " " << this->ite[i].getprice() << " " << this->ite[i].getquantity() << "\n";
			if (i == size - 1)
			{
				rdr << this->ite[i].getname() << " " << this->ite[i].getprice() << " " << this->ite[i].getquantity();
				continue;
			}
			rdr << this->ite[i].getname() << " " << this->ite[i].getprice() << " " << this->ite[i].getquantity() << "\n";
		}
	}
	rdr.close();
}
void Inventory::ItemPriceUpdate(string s, string p)
{
	for (int i = 0; i < size; i++)
	{
		if (this->ite[i].getname() == s)
		{
			this->ite[i].setprice(p);
			return;
		}
	}
	cout << "\nNo item exists with this name";
}
void Inventory::ItemQuantityUpdate(string s, string p)
{
	for (int i = 0; i < size; i++)
	{
		if (this->ite[i].getname() == s)
		{
			this->ite[i].setquantity(p);
			return;
		}
	}
	cout << "\nNo item exists with this name";
}
void Inventory::ItemSearchandview(string s)
{
	for (int i = 0; i < size; i++)
	{
		if (this->ite[i].getname() == s)
		{
			cout << "\nName: " << this->ite[i].getname();
			cout << "\nQuantity: " << this->ite[i].getquantity();
			cout << "\nPrice: " << this->ite[i].getprice();
			return;
		}
	}
	cout << "\nNo item exists with this name";
}
void Inventory::DeleteItem(string s)
{
	for (int i = 0; i < size; i++)
	{
		if (this->ite[i].getname() == s)
		{
			if (this->ite[i].getcategory() == true)
			{
				cout << "\nThis is not an item its a category";
				return;
			}
			else
			{
				this->ite[i].setname("-");
				this->ite[i].setprice("-");
				cout << "\nITEM DELETED!";
			}
		}
	}
	cout << "\nNo item exists with this name";
}
void Inventory::Additem(string name, string pr, string quant)
{
	size++;
	Item* A;
	A = new Item[size];
	for (int i = 0; i < size - 1; i++)
	{
		A[i] = this->ite[i];
	}
	A[size - 1].setname(name);
	A[size - 1].setprice(pr);
	A[size - 1].setquantity(quant);
	A[size - 1].setcategory(false);
	ite = new Item[size];
	for (int i = 0; i < size; i++)
	{
		this->ite[i] = A[i];
	}
}
int Inventory::getitemprice(string s)
{
	for (int i = 0; i < size; i++)
	{
		if (this->ite[i].getname() == s)
		{
			if (this->ite[i].getquantity() == "0")
			{
				cout << "\n" << this->ite[i].getname() << " NOT IN STOCK!SORRY";
				return 0;
			}
			string prr = this->ite[i].getprice();
			stringstream ss;
			int num;
			ss << prr;
			ss >> num;
			return num;
		}
	}
	cout << "\nNo item exists with this name";
	return 0;
}
string Inventory::getItem(string s)
{
	for (int i = 0; i < size; i++)
	{
		if (this->ite[i].getname() == s)
		{
			if (this->ite[i].getquantity() == "0")
			{
				cout << "\nOut of stock";
				return "0";
			}
			return s;
		}
	}
	cout << "\nOut of stock";
	return "0";
}