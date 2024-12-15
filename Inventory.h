#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Item.h"
#include<sstream>
using namespace std;

class Inventory
{
private:
	Item* ite;
	int size;
public:
	Inventory();
	void GetInventory();
	void PrintInventory();
	void ItemPriceUpdate(string s, string p);
	void ItemQuantityUpdate(string s, string p);
	void ItemSearchandview(string s);
	void DeleteItem(string s);
	void Additem(string name, string pr, string quant);
	int getitemprice(string s);
	string getItem(string s);

};