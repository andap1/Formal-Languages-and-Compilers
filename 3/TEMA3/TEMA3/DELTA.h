#pragma once
#include "AFD.h"
#include <string>
#include <vector>
#include<fstream>
#include<iostream>
class Delta
{
private:
	std::string stare_plecare;
	char symbol;
	std::string stare_sosire;
public:
	Delta(std::string stareplecare, char symboll, std::string staresosire)
	{
		stare_plecare = stareplecare;
		symbol = symboll;
		stare_sosire = staresosire;
	}
	friend std::ostream operator<<(std::ostream& o, Delta delta)
	{
		o << delta.stare_plecare;
		o << delta.stare_sosire;
		o << delta.symbol;
		return o;
	}
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