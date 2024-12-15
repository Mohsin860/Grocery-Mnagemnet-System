#pragma once
#include<string>
using namespace std;

class Item
{
private:
	string name;
	string price;
	bool iscategory;
	string quantity;
public:
	void setname(string s)
	{
		this->name = s;
	}
	void setprice(string s)
	{
		this->price = s;
	}
	void setcategory(bool f)
	{
		this->iscategory = f;
	}
	string getname()
	{
		return name;
	}
	string getprice()
	{
		return price;
	}
	bool getcategory()
	{
		return this->iscategory;
	}
	void setquantity(string f)
	{
		this->quantity = f;
	}
	string getquantity()
	{
		return quantity;
	}
};
