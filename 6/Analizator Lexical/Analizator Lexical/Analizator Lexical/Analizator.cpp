#include "Analizator.h"

void Analizator::Analiza()
{
	std::ifstream f("text.txt");
	while (!f.eof())
	{
		bool ok = false;
		std::string s;
		f >> s;
		for (int i = 0; i < tipuriDate.size(); ++i)
		{
			if (s == tipuriDate[i])
			{
				ok = true;
				std::cout << s << " este un tip de date\n";
			}
		}

		for (int i = 0; i < parateze.size(); ++i)
		{
			if (s == parateze[i])
			{
				ok = true;
				std::cout << s << " este o parateza\n";
			}
		}

		for (int i = 0; i < operatori.size(); ++i)
		{
			if (s == operatori[i])
			{
				ok = true;
				std::cout << s << " este o un operator\n";
			}
		}

		for (int i = 0; i < instructiuni.size(); ++i)
		{
			if (s == instructiuni[i])
			{
				ok = true;
				std::cout << s << " este o instructiune\n";
			}
		}

		for (int i = 0; i < delimitatori.size(); ++i)
		{
			if (s == delimitatori[i])
			{
				ok = true;
				std::cout << s << " este un delimitator\n";
			}
		}

		if (ok == false)
			std::cout << s << " este o  variabila\n";
	}
}
