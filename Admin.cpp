#include"Admin.h"
#include<iostream>
#include<fstream>
using namespace std;

Admin::Admin()
{
	this->st = 0;
	this->stores = new Store[st];
	m = 0;
	string s;
	string s1, s2, s3;
	fstream rdr("Manager.txt");     //operating the data from files
	while (getline(rdr, s))
	{
		rdr >> s;
		rdr >> s;
		m++;
	}
	rdr.close();
	fstream rdr2("Manager.txt");
	this->man = new Manager[m+1];
	while (getline(rdr2, s1))
	{
		rdr2 >> s2;
		rdr2 >> s3;
		this->man[m].setcredentials(s1, s2, s3);
	}
}

bool Admin::validpass(string& p)          //this method is handling the password validation
{
	char ch;
	bool ps = true;
	int s = 0, u = 0, l = 0, n = 0;
	int c = 0;
	int x;
	if (p.length() != 8)          //condition for password validation
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
	} while (true);
}

bool Admin::validdcnic(string& s)
{
	int l = s.length();
	if (l != 13)
	{
		cout << "\nInvalid length";
		return false;
	}
	for (int i = 0; i < l; i++)
	{
		if (s[i] < 48 && s[i]>57)
			return false;
	}
	return true;
}

void Admin::Register_Admin()
{
	fstream rdr("Admin.txt");
	string s, s1;
	do
	{
		cout << "\nEnter CNIC :";
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
		if (validpass(s1))
			break;
		else
			cout << "\nWrong password. Try again!";
	} while (true);
	this->l.setpass(s1);
	rdr << s1 << "\n";
	rdr.close();
	setusername();
}

void Admin::setusername()
{
	fstream rdr("Admin.txt");
	string s;
	cout << "\nEnter username:";
	cin >> s;
	rdr << s << "\n";
	rdr.close();
	this->l.setusername(s);
}

void Admin::Register_Manager()
{
	Manager s;
	s.Register_Manager();
	this->man[m] = s;
	m++;
}

bool Admin::Login(int l)
{
	return this->l.Loginn(3);
}