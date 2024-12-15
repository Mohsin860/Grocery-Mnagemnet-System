#pragma once
#include<iostream>
#include<string>
using namespace std;

class Feedback
{
private:
	string feedback;
public:
	void setfeedback(string s)
	{                               //for showing the feedback
		feedback = s;
	}
	string getfeedback()
	{
		return feedback;
	}
};