#include"AFD.h"
#include"Delta.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
void AFD::Citire()
{
	std::ifstream fis("AFD.txt");
	std::string StringStari;
	fis >> nrStari;
	for (int index = 0; index < nrStari; index++)
	{
		fis >> StringStari;
		Stari.push_back(StringStari);
	}
	char charAlfabet;
	fis >> nrCaractere;
	for (int index = 0; index < nrCaractere; index++)
	{
		fis >> charAlfabet;
		Sigma.push_back(charAlfabet);
	}
	fis >> StareInitiala;
	std::string StringFinal;
	fis >> nrStariFinle;
	for (int index = 0; index < nrStariFinle; index++)
	{
		fis >> StringFinal;
		Finale.push_back(StringFinal);
	}
	fis >> nrDelta;
	std::string stare_plecare;
	char symbol;
	std::string stare_sosire;
	for (int index = 0; index < nrDelta; index++)
	{
		fis >> stare_plecare;
		fis >> symbol;
		fis >> stare_sosire;
		delta[index].set_stare_plecare(stare_plecare);
		delta[index].set_symbol(symbol);
		delta[index].set_stare_sosire(stare_sosire);
	}
}
void AFD::Afisare()
{
	std::cout << "AUTOMATUL:" << "\n";
	std::cout << "STARILE: ";
	for (int index = 0; index < Stari.size(); index++)
		std::cout << Stari[index] << " ";

	std::cout << "\n" << "ALFABETUL DE INTRARE: ";
	for (int index = 0; index < Sigma.size(); index++)
		std::cout << Sigma[index] << " ";

	std::cout << "\n" << "STAREA INITIALA: " << StareInitiala << "\n";

	std::cout << "STARILE FINALE: ";
	for (int index = 0; index < Finale.size(); index++)
		std::cout << Finale[index] << " ";
	std::cout << "\n" << "FUNCTII DE TRANZITIE: " << "\n";
	for (int index = 0; index < nrDelta; index++)
	{

		std::cout << delta[index].get_stare_plecare() << " ";
		std::cout << delta[index].get_symbol() << " ";
		std::cout << delta[index].get_stare_sosire() << " ";
		std::cout << std::endl;
	}
}
bool cautare(std::vector<std::string>v, std::string elem)
{
	int ok = 0;
	for (int index = 0; index < v.size()&&ok==0; index++)
		if (v[index] == elem)
			ok = 1;
	return ok;
}
bool cautare_char(std::vector<char>v, char elem)
{
	int ok = 0;
	for (int index = 0; index < v.size() && ok == 0; index++)
		if (v[index] == elem)
			ok = 1;
	return ok;
}
bool AFD::Verificare()
{
	int ok1 = 0, ok2 = 1, ok3 = 1;
	for (int index = 0; index < Stari.size(); index++)
		if (Stari[index] == StareInitiala)
			ok1 = 1;
	
	for (int index = 0; index < Finale.size(); index++)
	{
		if (cautare(Stari, Finale[index]) == 0)
			ok2 = 0;
	}
	for (int index = 0; index < nrDelta; index++)
	{
		if (cautare(Stari, delta[index].get_stare_plecare()) == 0)
			ok3 = 0;
		if (cautare(Stari, delta[index].get_stare_sosire()) == 0)
			ok3= 0;
		if(cautare_char(Sigma,delta[index].get_symbol())==0)
			ok3= 0;
	}

	if(ok1==1&&ok2==1&&ok3==1)
	  return 1;
	return 0;

}
void AFD::Accepta(std::string cuvant)
{
	std::string starecurenta = StareInitiala;
	int blocaj = 0;
	for(int index=0;index<cuvant.size();index++)
	{
		for (int index2 = 0; index2 < nrDelta; index2++)
			if (cuvant[index] == delta[index2].get_symbol() && starecurenta == delta[index2].get_stare_plecare())
			{
				starecurenta = delta[index2].get_stare_sosire();
				blocaj = 1;
				break;
			}
		if (blocaj == 0)
		{
			std::cout << "BLOCAJ";
			break;
		}
	}
	
	if (cautare(Finale, starecurenta) == 1)
		std::cout << "CUVANT ACCEPTAT";
	else
		std::cout << "NU ESTE CUVANT ACCEPTAT";
}