#include"PCatalog.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Item.h"
using namespace std;

PCatalog::PCatalog()
{
	size = 43;
	ite = new Item[size];
}
void PCatalog::GetCatalog()
{
	int ss = 0;
	bool category = false;
	string name;
	string price;
	int i;
	string s;
	fstream rdr("Catalog.txt");
	//cout << "\nItem\tPrice\n";
	while (getline(rdr, s))
	{
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
		for (int f = i + 1; f < s.size(); f++)
		{
			price.push_back(s[f]);
		}
		this->ite[ss].setcategory(category);
		this->ite[ss].setname(name);
		this->ite[ss].setprice(price);
		ss++;
		name = "";
		price = "";
		category = false;
		//cout << s << "\n";
	}
	rdr.close();

}
void PCatalog::PrintCatalog()
{
	fstream rdr("Catalog.txt");
	rdr.clear();
	for (int i = 0; i < size; i++)
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
void PCatalog::ItemPriceUpdate(string s, string p)
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
void PCatalog::ItemSearch(string s)
{
	for (int i = 0; i < size; i++)
	{
		if (this->ite[i].getname() == s)
		{
			cout << "\nYes it exists";
			return;
		}
	}
	cout << "\nNo item exists with this name";
}
void PCatalog::DeleteItem(string s)
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
void PCatalog::Additem(string name, string pr)
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
	A[size - 1].setcategory(false);
	ite = new Item[size];
	for (int i = 0; i < size; i++)
	{
		this->ite[i] = A[i];
	}
}