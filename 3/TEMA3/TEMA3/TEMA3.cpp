#include <fstream>
#include"AFD.h"
int main()
{
	AFD A;
	A.Citire();
	A.Afisare();
	std::cout << "\n";
	if (A.Verificare() == 1)
		std::cout << "AUTOMATUL ESTE OK";
	std::string cuvant;
	std::cout << "\n" << "CUVANT: ";
	std::cin >> cuvant;
	A.Accepta(cuvant);
	return 0;
}
