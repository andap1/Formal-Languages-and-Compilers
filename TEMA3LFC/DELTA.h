#pragma once
#include "AFD.h"
#include <string>
#include <vector>
#include<fstream>
#include<iostream>
class Delta
{
public:
	std::string stare_plecare;
	char symbol;
	std::string stare_sosire;

	void set_stare_plecare(const std::string& s)
	{
		stare_plecare = s;
	}
	void set_symbol(const char & s)
	{
		symbol = s;
	}
	void set_stare_sosire(const std::string& s1)
	{
		stare_sosire = s1;
	}
	std::string get_stare_plecare()const
	{
		return stare_plecare;
	}
	char get_symbol()const
	{
		return symbol;
	}
	
	std::string get_stare_sosire()const
	{
		return stare_sosire;
	}

};