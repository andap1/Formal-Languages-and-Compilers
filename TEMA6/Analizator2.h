#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <tuple>
class Analizator {

public:
	void Analiza();
	void Afisare();

private:
	std::vector<std::string> m_tipuriDate = { "int", "bool", "char", "float","double" };
	std::vector<std::string> m_instructiuni = { "if","while","for" ,"do","else" };
	std::vector<std::string> m_operatori = { "+", "-", "*", "/", "%", "=", "<", ">" };
	std::vector<std::string> m_delimitatori = { ";","," };
	std::vector<std::string> m_parateze = { "{","}","(",")" ,"[", "]" };
	std::vector < std::tuple<std::string,std::string, std::string>> m_analizator;
};