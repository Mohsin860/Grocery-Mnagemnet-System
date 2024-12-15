#pragma once
#include"Login.h"
#include"Inventory.h"
#include"Cart.h"
#include"Feedback.h"
#include"Store.h"
#include<iostream>
using namespace std;

class Customer : public Login          //class customer
{
private:
	Feedback ff;       //private data members
	
	string gender;
	string contact_no;
	string address;
	Inventory in;
	Cart c;
public:
	Customer();            //publically available functions 
	void Inputdetails();
	void Printdetails();
	void Register_customer();   //these functions are of registration,validation,login,logout,adding carts
	                            // and for online shopping so these functions are related all customers operastion
	void setusername();
	bool validpass(string& p);
	Login l;
	bool validdcnic(string& s);
	bool Login(int l = 1);
	void Addtocart();
	
	void getcartprice(Store&s);
	void printcart();
	void DoOnlineshopping(Store &s)
	{
		c.Additemtocart();
		c.gettotalprice(s);
		
	}
	void GiveFeedback(Store&s)
	{                          //for the feedback from customer
		string sa;
		cout << "\nEnter feedback: ";
		cin >> sa;
		s.setfeedback(sa);
	}
	bool Logoutt()
	{
		return this->l.Logout();
	}
};