#pragma once
#include"Delta.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>
class AFD
{
private:
	int nrStari;
	std::vector < std::string> Stari;
	int nrCaractere;
	std::vector <char> Sigma;
	int nrDelta;
	std::vector<Delta>delta;
	std::string StareInitiala;
	int nrStariFinle;
	std::vector < std::string> Finale;
public:
	void Citire();
	void Afisare();
	bool Verificare();
	void Accepta(std::string cuvant);
};
