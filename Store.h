#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Inventory.h"
#include"PCatalog.h"
#include"Manager.h"
#include"Feedback.h"
#include<vector>
using namespace std;

class Store
{
private:
	Feedback* ff;
	int sizefb;
	Manager man;
	string location;
	Inventory it;
	PCatalog Pcat;
public:
	void ShowFeedbacks(Store&s)
	{
		cout << "\nFeedbacks of store in " << s.getlocation();
		for (int i = 0; i < sizefb; i++)
		{
			cout << "\n-" << ff[i].getfeedback();
		}
	}
	void setfeedback(string &a)
	{
		int i;
		vector<string>ss;
		for (i = 0; i < sizefb; i++)
		{
			ss.push_back(ff[i].getfeedback());
		}
		sizefb++;
		ss.push_back(a);
		ff = new Feedback[sizefb];
		for (int x = 0; x < sizefb; x++)
		{
			ff[x].setfeedback(ss[x]);
		}
		ff[sizefb - 1].setfeedback(a);
	}
	void setlocation(string a)
	{
		location = a;
	}
	string getlocation()
	{
		return this->location;
	}
};