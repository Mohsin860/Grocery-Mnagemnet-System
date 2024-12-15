#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Store.h"
#include"Inventory.h"
using namespace std;

class Cart
{
private:
	string* items;
	int size;
public:
	Cart()
	{
		size = 0;
		items = new string[size];
	}
	void PrintCart()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\nProducts in the cart are:";
			if (items[i] == "0")
				continue;
			else
			{
				cout << "\n-" << items[i];
			}
		}
	}
	int gettotalprice(Store&s)
	{
		int total = 0;          //calculating the total price 
		Inventory ic;
		ic.GetInventory();
		for (int i = 0; i < size; i++)
		{
			/*if (items[i] == "0")
				continue;*/
			total += ic.getitemprice(items[i]);
		}
		cout << "Bill is: " << total;
		cout << "\nEnter payment method: ";
		int ii;
		string f;
		do         //payment method menu for shopping 
		{
			cout << "\nPress 1 for credit card or debit card: ";
			cout << "\nPress 2 for Easy paisa";
			cout << "\nPress 3 for Jazzcash";
			cout << "\nPress 4 for COD";
			cin >> ii;
			if (ii == 1 || ii == 2 || ii == 3)
			{
				cout << "\nTotal Bill is:" << total;
				break;
			}
			else if (ii == 4)
			{
				cout << "\nEnter your city od delievery: ";   //for COD 
				cin >> f;
				if (s.getlocation() == f)
				{
					total += 30;
					cout << "\n30 rs charged for COD in same city.";   //for same city 
					cout << "\nTotal Bill is:" << total;
					break;
				}
				else
				{
					total += 50;
					cout << "\n50 rs charged for COD in other city.";  //for diffrent city 
					cout << "\nTotal Bill is:" << total;
					break;
				}
			}
			else
			{
				cout << "\nWrong input!";   
				continue;
			}
			
		} while (true);
		return total;
	}
	void Additemtocart()   //adding the items to cart 
	{
		Inventory ic;
		ic.GetInventory();
		vector<string> A;
		char c;
		string ss;
		int oldsize = size;
		do
		{
			cout << "\nEnter product name: "; //items details 
			cin >> ss;
			A.push_back(ic.getItem(ss));
			size++;
			cout << "\nDo you want to add more items?Y/n";
			cin >> c;
			if (c == 'n' || c == 'N')
				break;
		} while (true);
		vector<string>aa;
		for (int i = 0; i < oldsize; i++)
		{
			aa.push_back(items[i]);
		}
		int g = 0;
		items = new string[size];
		for (g = 0; g < oldsize; g++)
		{
			items[g] = aa[g];
		}
		for (int i = g; i < size; i++)
		{
			items[i] = A[i];
		}
	}
};