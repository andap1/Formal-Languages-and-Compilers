#include <string>
#include <iostream>
int verif_cifra(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return 1;
	return 0;
}
int verif_litera(char c)
{
	if (c == 'E')
		return 1;
	return 0;
}
int nr_nat(std::string s)
{
	int contor = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (verif_cifra(s[i]) == 0)
			contor = 0;
	}
	if (contor == 1)
		return contor;
	return 0;
}
int numar_real(std::string s)
{
	int gasit = 0;
	int ok = 1;
	int tipnr = 0;
	if (verif_cifra(s[0]) == 1)
	{
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '.')
				gasit++;
			else
				if (verif_cifra(s[i]) == 0)
					ok = 0;
		}

	}
	if (gasit == 1 && ok == 1)
		tipnr = 1;
	return tipnr;
}
int numar_intreg(std::string s)
{
	int tipnr = 0;
	int contor = 1;
	if (s[0] == '-'&&contor==1)
	{
		for (int i = 1; i < s.length(); i++)
		{
			if (verif_cifra(s[i]) == 0)
				contor = 0;
		}
		if (contor == 1)
			tipnr = 1;
	}
	return tipnr;
}
int numar_real_cu_exponent(std::string s)
{
	int tipnr = 0;
	int contor = 0;
	int gasitpunct = 0,gasite=0,gasitl=0;
	int ok = 1;
	if (verif_cifra(s[0]) == 1)
	{
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '.')
				gasitpunct++;
			if (s[i] == 'E')
				gasite++;
			if (s[i] == '-')
				gasitl++;
			if (verif_cifra(s[i]) == 0 && s[i] != '.' && s[i] != 'E' && s[i] != '-')
				ok = 0;
		}
		if (gasitpunct == 1 && gasite == 1 && gasitl == 1 && ok == 1)
		{
			for (int i = 1; i < s.length() - 2; i++)
			{
				if (s[i] == 'E' && s[i + 1] == '-')
					contor = 1;
			}
		}

	}
	
		if (contor == 1)
			tipnr = 1;
		return tipnr;
	
}
int main()
{
	int tipnr = 0;//0-nu e numar
	std::string s;
	std::getline(std::cin, s);
	if (nr_nat(s) == 1)
	{
		std::cout << "numar natural";
		tipnr = 1;
	}
		
	if (numar_intreg(s) == 1)
	{
		tipnr = 1;
		std::cout << "numar intreg";
	}
		
	if (numar_real(s) == 1)
	{
		tipnr = 1;
		std::cout << "numar real";
	}
		
	if (numar_real_cu_exponent(s) == 1)
	{
		tipnr = 1;
		std::cout << "numar real cu exponent";
	}

	if (tipnr == 0)
		std::cout << "nu e numar";

}

