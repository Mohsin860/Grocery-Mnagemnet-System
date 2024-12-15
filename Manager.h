#pragma once
#include"Login.h"
#include<string>
#include"Inventory.h"
using namespace std;

class Manager
{
private:
	Login l;
	Inventory ic;
public:
	Manager() {};
	void Register_Manager();      //manager registration and validation for the password ,CNIC etc 
	bool validpass(string& p);
	bool validdcnic(string& s);
	void setusername();
	void setcredentials(string s1, string s2, string s3)
	{
		this->l.setcnic(s1);
		this->l.setpass(s2);
		this->l.setusername(s3);
	}
	bool Login(int l = 2);
	bool Logoutt();
	void GetInventory()
	{
		ic.GetInventory();
	}
	void PrintInventory()
	{
		ic.PrintInventory();
	}
	void ItemPriceUpdate()
	{
		char c;
		string a, b;
		do                   //details of the items 
		{
			cout << "\nEnter item name:";
			cin >> a;
			cout << "\nEnter price: ";
			cin >> b;
			ic.ItemPriceUpdate(a, b);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	void ItemQuantityUpdate()     //updation of the items 
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";
			cin >> a;
			cout << "\nEnter quantity: ";     //items details 
			cin >> b;
			ic.ItemQuantityUpdate(a, b);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	void ItemSearchandview()          //for searching the items 
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";
			cin >> a;
			ic.ItemSearchandview(a);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	void DeleteItem()            //for the deleting the items 
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";   // items details 
			cin >> a;
			ic.DeleteItem(a);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	void Additem()      //manager can add the items 
	{
		char c;
		string a, b, d;
		do
		{
			cout << "\nEnter item name:";   //giving the items details 
			cin >> a;
			cout << "\nEnter quantity: ";
			cin >> b;
			cout << "\nEnter price: ";
			cin >> d;
			ic.Additem(a, d, b);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	int getitemprice()       //getting item price 
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";
			cin >> a;
			ic.getitemprice(a);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	string getItem() 
	{
		char c;
		string a, ans;
		cout << "\nEnter item name:";
		cin >> a;
		ans = ic.getItem(a);
		return ans;
	}
};
