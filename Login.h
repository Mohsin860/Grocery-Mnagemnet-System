#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Login
{
private:
	string username;
	string cnic;
	string pass;
public:
	bool Logout()
	{
		char c;
		cout << "\nDo you want to logout?Y/N";
		cin >> c;
		if (c == 'n' || c == 'N')
			return true;
		else
			return false;
	}
	bool Loginn(int l)
	{
		string us = "";
		string dummy;
		bool user_check = false;
		cout << "\n\n--------------------\nLOGIN PANEL\n--------------------";
		do
		{
			cout << "\n\nEnter your username to login:(enter n to go back) ";
			cin >> us;
			if (us == "n" || us == "N")
				return false;
			this->username = us;
			if (l == 1)
			{
				fstream rdr1("Customer.txt");
				while (getline(rdr1, dummy))
				{
					if (dummy == us)
					{
						user_check = true;
						break;
					}
				}
				rdr1.close();
			}
			else if (l == 2)
			{
				fstream rdr2("Manager.txt");
				while (getline(rdr2, dummy))
				{
					if (dummy == us)
					{
						user_check = true;
						break;
					}
				}
				rdr2.close();
			}
			else if (l == 3)
			{
				fstream rdr3("Admin.txt");
				while (getline(rdr3, dummy))
				{
					if (dummy == us)
					{
						user_check = true;
						break;
					}
				}
				rdr3.close();
			}
			if (user_check)
				break;
			else
			{
				cout << "\nInvalid username.Try again!";
			}
			
		} while (true);
		string ps = "";
		user_check = false;
		do
		{
			cout << "\n\nEnter your password to login(enter n to go back): ";
			cin >> ps;
			if (us == "n" || us == "N")
				return false;
			this->username = ps;
			if (l == 1)
			{
				fstream rdr4("Customer.txt");
				while (getline(rdr4, dummy))
				{
					if (dummy == ps)
						user_check = true;
				}
				rdr4.close();
			}
			else if (l == 2)
			{
				fstream rdr5("Manager.txt");
				while (getline(rdr5, dummy))
				{
					if (dummy == ps)
						user_check = true;
				}
				rdr5.close();
			}
			else if (l == 3)
			{
				fstream rdr6("Admin.txt");
				while (getline(rdr6, dummy))
				{
					if (dummy == ps)
						user_check = true;
				}
				rdr6.close();
			}
			if (user_check)
				break;
			else
			{
				cout << "\nInvalid password.Try again";
			}
			
		} while (true);
		cout << "\n\nSUCCESSFUL LOGIN";
		return true;
	}
	void setusername(string s)
	{
		this->username = s;
	}
	void setpass(string s)
	{
		this->pass = s;
	}
	void setcnic(string s)
	{
		this->cnic = s;
	}
	string getusername()
	{
		return username;
	}
	string getpassword()
	{
		return pass;
	}
	string getcnic()
	{
		return cnic;
	}
};
