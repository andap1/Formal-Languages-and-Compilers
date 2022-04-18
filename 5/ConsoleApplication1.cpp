#include <iostream>
#include"AFD.h"

int main()
{
	AFD afd = afd.CitireFisier("AFD_Citire.txt");
	//afd.Minimizare();
	afd.EliminareStariNeaccesibile();
	afd.AfisareFisier("AFD_MinimizatAfisare.txt");
	return 0;
}


