#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Item.h"
using namespace std;

class PCatalog    //class catalog 
{
private:             //private data members 
	Item* ite;
	int size;
public:                 //publically available functions for catalog 
	PCatalog();
	void GetCatalog();
	void PrintCatalog();
	void ItemPriceUpdate(string s, string p);    //item validation 
	void ItemSearch(string s);
	void DeleteItem(string s);
	void Additem(string name, string pr);
};
