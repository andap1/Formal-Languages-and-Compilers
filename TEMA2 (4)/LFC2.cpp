#include <iostream>
#include <fstream>
#include<vector>
#include <string.h>
class Gramatica
{
private:
	std::vector<std::string>VN;
	std::vector<std::string>VT;
	std::string S;
	int nrproductii;
	std::vector<std::string>PN;
	std::vector<std::string>PT;

public:
	void set_NETERMINALE(std::vector<std::string>aux)
	{
		VN.clear();
		for (int i = 0; i < aux.size(); i++)
			VN[i] = aux[i];
	}
	std::vector<std::string> get_NETERMINALE() {return VN;}
	void  set_TERMINALE(std::vector<std::string>aux)
	{
		VT.clear();
		for (int i = 0; i < aux.size(); i++)
			VT[i] = aux[i];
	}
	std::vector<std::string> get_TERMINALE() {return VT;}
	void set_START(std::string aux)
	{
		S=aux;
	}
	std::string get_START() { return S; }
	void set_NUMARPRODUCTII(int nr)
	{
		nrproductii = nr;
	}
	int get_NUMARPRODUCTII() { return nrproductii; }
	void set_PRODUCTII_NETERMINALE(std::vector<std::string>aux)
	{
		PN.clear();
		for (int i = 0; i < aux.size(); i++)
			PN[i] = aux[i];
	}
	std::vector<std::string> get_PRODUCTII_NETERMINALE() { return PN; }
	void set_PRODUCTII_TERMINALE(std::vector<std::string>aux)
	{
		PT.clear();
		for (int i = 0; i < aux.size(); i++)
			PT[i] = aux[i];
	}
	std::vector<std::string> get_PRODUCTII_TERMINALE() { return PT; }
	void Citirea()
	{
		std::ifstream fis("GramaticiGenerative.txt");
		int vn, vt;
		std::string string_adaugat;
		std::string char_adaugat;
		fis >> vn;
		for (int index = 0; index < vn; index++)
		{
			fis >> char_adaugat;
			VN.push_back(char_adaugat);
		}
		fis >> vt;
		for (int index = 0; index < vt; index++)
		{
			fis >> char_adaugat;
			VT.push_back(char_adaugat);
		}
		fis >> S;
		fis >> nrproductii;
		for (int index = 0; index < nrproductii; index++)
		{
			fis >> string_adaugat;
			PN.push_back(string_adaugat);
			fis >> string_adaugat;
			PT.push_back(string_adaugat);
		}
	}
	void Afisarea()
	{
		std::cout << "GRAMATICA GENERATIVA:" << std::endl;
		std::cout << "VN: ";
		for (int index = 0; index < VN.size(); index++)
			std::cout << VN[index] << " ";
		std::cout << std::endl << "VT: ";
		for (int index = 0; index < VT.size(); index++)
			std::cout << VT[index] << " ";
		std::cout << std::endl << "Simbol de start:" << S;
		std::cout << std::endl << "P: ";
		for (int index = 0; index < nrproductii; index++)
			std::cout << PN[index] << " -> " << PT[index]<< std::endl;

	}
	int verificare()
	{
		//1
		for (int index1 = 0; index1 < VN.size(); index1++)
			for (int index2 = 0; index2 < VT.size(); index2++)
				if (VN[index1] == VT[index2])
					return 0;
		////2
		if (VN[0] != S)
			return 0;
		//3
		for (int index = 0; index < nrproductii; index++)
		{
			if (PN.size() < 1)
				return 0;
		}
		//4
		int exista = 0;
		for (int index = 0; index < nrproductii ; index++)
		{
			if (PN[index].size() == 1)
				if (PN[index] == S)
					exista = 1;
		}
		if (exista == 0)
			return 0;
		//5
		for (int index = 0; index < nrproductii; index++)
		{
			
			for (int index1 = 0; index1 < VN.size(); index1++)
				if (PN[index] != VN[index1])
					return 0;
			int ok = 1;
			for (int index1 = 0; index1 < VT.size() && ok==1; index1++)
				if (PT[index] != VT[index1])
					ok = 0;
			if (ok == 1)
			{
				for (int index1 = 0; index1 < VN.size() && ok == 1; index1++)
					if (PT[index] != VN[index1])
						return 0;
			}
				

		}
		return 1;
	}
	
};
int main()
{
	Gramatica G;
	G.Citirea();
	G.Afisarea();
	std::cout << std::endl;
	if (G.verificare() == 0)
		std::cout << "NU ESTE GramaticaGENERATIVA";
	else
		std::cout << " GRAMATICA GENERATIVA";
	std::cout << std::endl;
	
	return 0;
}
