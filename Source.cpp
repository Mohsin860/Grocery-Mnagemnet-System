#include<iostream>
#include"Admin.h"
#include"Customer.h"
#include"Manager.h"
#include"PCatalog.h"
#include"Inventory.h"
using namespace std;

int main()
{
	Inventory invent;
	PCatalog pcat;      //These are all the objects from diffrent classes that are using in the store
	Customer C;
	Store S;
	Manager M;
	Admin A;
	int i1, i2, i3;
	invent.GetInventory();
	pcat.GetCatalog();
	string s1;
	cout << "\n\n\t\t\t\t------------WELCOME TO OUR STORE------------";   //initial display
	cout << "\nEnter store location : Lahore,Islamabad,Karachi";
	cin >> s1;
	S.setlocation(s1);
	//Below are choices for customer ,manager and admin for registration and login and logout etc
	do
	{
		cout << "\nIf you are manager press 1 :\nIf you are customer press 2: \nIf you are Admin press 3: \nIf you want to stop the program press 9: ";
		cin >> i1;
		if (i1 == 1)
		{              //For login  for manager
			do
			{
				cout << "\nIf you want to login press 1: \nIf you want to go back enter 9: ";
				cin >> i2;
				if (i2 == 1)
				{
					M.Login();
					system("cls");
					do
					{       //Menu for the manager to see and seraching and updation,addition etc, the items

						cout << "\nPress 1 if you want to see inventory: \nPress 2 if you want to update price of item in inventory:\nPress 3 if you want to update quantity of item in inventory: \nPress 4 if you want to add item in inventory: \nPress 5 if you want to remove item in inventory: \nPress 6 if you want to search and view item: \nPress 7 if you want to see feedbacks: \nPress 8 to logout: ";
						cin >> i3;
						if (i3 == 1)
						{
							M.PrintInventory();
						}
						else if (i3 == 2)
						{
							M.ItemPriceUpdate();
						}
						else if (i3 == 3)
						{
							M.ItemQuantityUpdate();
						}
						else if (i3 == 4)
						{
							M.Additem();
						}
						else if (i3 == 5)
						{
							M.DeleteItem();
						}
						else if (i3 == 6)
						{
							M.ItemSearchandview();
						}
						else if (i3 == 7)
						{
							S.ShowFeedbacks(S);
						}
						else if (i3 == 8)
						{
							M.Logoutt();
							break;
						}
						else
						{
							cout << "\nWrong input. Try again!";   //error handling
						}
					} while (true);
				}
				else if (i2 == 9)
					break;
				else
				{
					cout << "\nWrong input.Try again!";
				}
			} while (true);
		}
		else if (i1 == 2)
		{
			do           //Menu for the Customer to login or registration or go back

			{
				cout << "\nIf you want to register press 1:\nIf you want to login press 2: \nIf you want to go back enter 9: ";
				cin >> i2;
				if (i2 == 1)
				{
					C.Register_customer();
					system("cls");
				}
				else if (i2 == 2)
				{
					C.Login();
					system("cls");
					do

					{
						cout << "\nPress 1 to do online shopping: \n Press 2 to give feedback: \nPress 3 to logout: ";
						cin >> i3;
						if (i3 == 1)
						{
							C.DoOnlineshopping(S);
						}
						else if (i3 == 2)
						{
							C.GiveFeedback(S);
						}
						else if (i3 == 3)
						{
							C.Logoutt();
							break;
						}
						else 
						{
							cout << "\nInvalid input.Try again!";
						}
					} while (true);
				}
				else if (i2 == 9)
					break;
				else
				{
					cout << "\nWrong input.Try again!";
				}
			} while (true);
		}
		else if (i1 == 3)
		{
			do  //menu for the admin to register ,login and go back
			{
				cout << "\nIf you want to register press 1:\nIf you want to login press 2: \nIf you want to go back enter 9: ";
				cin >> i2;
				if (i2 == 1)
				{
					A.Register_Admin();
					system("cls");
				}
				else if (i2 == 2)
				{
					A.Login();
					system("cls");
					cout << "\n\t\t\t\t---------------MENU---------------";
					do
					{
						cout << "\nPress 1 if you want to add a new manager: \nPress 2 if you want to see catalog: \nPress 3 if you want to add item in catalog: \nPress 4 if you want to remove item from catalog: \nPress 5 to logout: ";
						cin >> i3;
						if (i3 == 1)
						{
							A.Register_Manager();
						}
						else if (i3 == 2)
						{
							A.PrintCatalog();
						}
						else if (i3 == 3)
						{
							A.Additem();
						}
						else if (i3 == 4)
						{
							A.DeleteItem();
						}
						else if (i3 == 5)
						{
							A.Logoutt();
							break;
						}
						else
						{
							cout << "\nWrong input. Try again!";
						}
					} while (true);
				}
				else if (i2 == 9)
					break;
				else
				{
					cout << "\nWrong input.Try again!";
				}
				
			} while (true);
		}
		else if (i1 == 9)
			break;
		else
		{
			cout << "\nWrong input!Try again";
		}
	} while (true);
	return 0;
}