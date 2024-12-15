#pragma once
#include<iostream>
#include"Manager.h"
#include<fstream>
#include<string>
#include"Store.h"
#include"PCatalog.h"
using namespace std;


class Admin : public Login           //class admin
{
private:
	PCatalog cat;
	Store* stores;
	int st;
	Manager *man;
	int m;
	
public:
	Admin();
	void Register_Manager();   //admin registration
	void Register_Admin();
	bool validpass(string& p);    //admin password validation
	bool validdcnic(string& s);    //admin CNIC validation
	void setusername();
	Login l;
	bool Login(int l = 3);
	bool Logoutt()
	{
		return this->l.Logout();
	}
	void PrintCatalog()
	{
		cat.PrintCatalog();
	}
	void ItemPriceUpdate()
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";   //items details 
			cin >> a;
			cout << "\nEnter price: ";
			cin >> b;
			cat.ItemPriceUpdate(a, b);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	void ItemSearch()   //searching the items 
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";  
			cin >> a;
			cat.ItemSearch(a);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	void DeleteItem()     //deleting the items
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";      //items details 
			cin >> a;
			cat.DeleteItem(a);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
	void Additem()     //adding the item for Admin
	{
		char c;
		string a, b;
		do
		{
			cout << "\nEnter item name:";
			cin >> a;
			cout << "\nEnter price: ";
			cin >> b;
			cat.Additem(a, b);
			cout << "\nDo you want to enter more?Y/N: ";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
	}
};
