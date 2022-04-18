#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

class Analizator {

public:
	void Analiza();

private:
	std::vector<std::string> tipuriDate = { "int", "bool", "char", "float","double" };
	std::vector<std::string> instructiuni = { "if","while","for" ,"do","else" };
	std::vector<std::string> operatori = { "+", "-", "*", "/", "%", "=", "<", ">" };
	std::vector<std::string> delimitatori = { ";","," };
	std::vector<std::string> parateze = { "{","}","(",")" ,"[", "]" };
};