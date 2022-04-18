#pragma once
#include<string>
#include<tuple>
#include<vector>
#include<fstream>
#include<iostream>

class AFD
{
private:
	std::vector<std::string> m_stari;
	std::vector<std::string> m_sigma;
	std::vector<std::tuple<std::string, std::string, std::string>> m_delta;
	std::string m_stareInit;
	std::vector<std::string> m_finale;
public:
	AFD(std::vector<std::string> stari, std::vector<std::string> sigma, std::vector<std::tuple<std::string, std::string, std::string>> delta, std::string stareInit, std::vector<std::string> finale);
	AFD CitireFisier(const std::string& filename);
	void AfisareFisier(const std::string& filename);
	std::string Verificare(std::string cuvantCitit);
	void Minimizare();
	void EliminareStariNeaccesibile();

};