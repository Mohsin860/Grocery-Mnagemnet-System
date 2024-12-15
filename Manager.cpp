#include"Manager.h"
#include<iostream>
#include<fstream>
using namespace std;

bool Manager::validpass(string& p)     //password validation for manager
{
	char ch;
	bool ps = true;
	int s = 0, u = 0, l = 0, n = 0;
	int c = 0;
	int x;
	if (p.length() != 8)
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

bool Manager::validdcnic(string& s)  //CNIC validation for Manager
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

void Manager::Register_Manager()   //registration for the manager 
{
	fstream rdr("Manager.txt");
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
	this->l.setcnic(s);
	rdr << s << "\n";
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

void Manager::setusername()  //set username for manager
{
	fstream rdr("Manager.txt");
	string s;
	cout << "\nEnter username:";    //operating the data from files 
	cin >> s;
	rdr << s << "\n";
	rdr.close();
	this->l.setusername(s);
}

bool Manager::Login(int l)    //manager login 
{
	return this->l.Loginn(2);
}

bool Manager::Logoutt()       //manager logout 
{
	return this->l.Logout();
}