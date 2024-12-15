#include"Customer.h"
#include<iostream>
#include"Store.h"
#include<fstream>
using namespace std;

bool Customer::validpass(string& p)     //this method is for validation for the password
{
	char ch;
	bool ps = true;
	int s = 0, u = 0, l = 0, n = 0;
	int c = 0;
	int x;
	if (p.length() < 8)
		return false;
	do {
		ps = true;
		for (int i = 0; i < 9; i++)
		{

			if (islower(p[i]))
				l++;
			else if (isupper(p[i]))
				u++;
			else if (isdigit(p[i]))
				n++;
			else if (!islower(p[i]) && !isdigit(p[i]) && (!isupper(p[i])))
				s++;
		}
		                          //passwords validations
		if (s == 0) {
			cout << "\nWeak Password. Enter new Password\n";
			ps = false;
			return false;
		}
		if (u == 0) {
			cout << "\nWeak Password. Enter new Password\n";
			ps = false;
			return false;
		}
		if (l == 0) {
			cout << "\nWeak Password. Enter new Password\n";
			ps = false;
			return false;
		}
		if (n == 0) {
			cout << "\nWeak Password. Enter new Password\n";
			ps = false;
			return false;
		}
		return true;
	} while (true);            //handling the Information regarding CNIC validation
}

bool Customer::validdcnic(string& s) //CNIC validation
{
	int l = s.length();
	if (l != 13)
	{
		cout << "\nInvalid length";  //length validation
		return false;
	}
	for (int i = 0; i < l; i++)
	{
		if (s[i] < 48 && s[i]>57)
			return false;
	}
	return true;
}

void Customer::Register_customer()    //customer registration
{
	fstream rdr("Customer.txt");
	string s, s1;
	do
	{
		cout << "\nEnter CNIC :";   //CNIC details 
		cin >> s;
		if (validdcnic(s))
			break;
		else
			cout << "\nWrong cnic. Try again!";
	} while (true);
	rdr << s << "\n";
	this->l.setcnic(s);
	do
	{
		cout << "\nPassword must be 9 characters long and use of a minimum of one uppercase letter and one numeric digit is must. Enter Password:";
		cin >> s1;
		if (validpass(s1))      //password validation
			break;
		else
			cout << "\nWrong password. Try again!";
	} while (true);
	this->l.setpass(s1);
	rdr << s1 << "\n";
	rdr.close();
	setusername();
}

void Customer::setusername()     //writting username
{
	fstream rdr("Customer.txt");          //data operating from files
	string s;
	cout << "\nEnter username:";
	cin >> s;
	rdr << s << "\n";
	rdr.close();
	this->l.setusername(s);
}

bool Customer::Login(int l)         //login of customer
{
	return this->l.Loginn(1);
}

Customer::Customer()
{
	gender = "";
	contact_no = "";
	address = "";
};

void Customer::Inputdetails()         //details of customer
{
	cout << "\nEnter gender:";
	cin >> this->gender;
	cout << "\nEnter address:";
	cin >> this->address;
	cout << "\nEnter contact no:";
	cin >> this->contact_no;
}

void Customer::Printdetails()
{                                  //prnting the deatils

	cout << "\nUsername is:" << this->l.getusername();
	cout << "\nCNIC is:" << this->l.getcnic();
	cout << "\nGender is:" << this->gender;
	cout << "\nContact no is:" << this->contact_no;
	cout << "\nAddress is:" << this->address;
}

void Customer::Addtocart()
{                               //adding to cart the shopped items 
	c.Additemtocart();
}

void Customer::getcartprice(Store&s)
{
	c.gettotalprice(s);
}

void Customer::printcart()
{
	c.PrintCart();
}