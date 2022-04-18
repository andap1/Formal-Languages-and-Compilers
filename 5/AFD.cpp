#include "AFD.h"

AFD::AFD(std::vector<std::string> stari, std::vector<std::string> sigma, std::vector<std::tuple<std::string, std::string, std::string>> delta, std::string stareInit, std::vector<std::string> finale)
	:m_stari(stari), m_sigma(sigma), m_delta(delta), m_stareInit(stareInit), m_finale(finale)
{
}

AFD AFD::CitireFisier(const std::string& filename)
{
	std::ifstream f(filename);
	std::vector<std::string> stari;
	std::vector<std::string> sigma;
	std::vector<std::tuple<std::string, std::string, std::string>> delta;
	std::string stareInit;
	std::vector<std::string> finale;

	std::string aux1, aux2, aux3;
	std::tuple<std::string, std::string, std::string> deltaAuxiliar;

	int contorStari, contorSigma, contorDelta, contorFinale;

	while (!f.eof())
	{
		f >> contorStari >> contorSigma >> contorDelta >> contorFinale;
		for (int index = 0; index < contorStari; index++)
		{
			f >> aux1;
			stari.emplace_back(aux1);
		}
		for (int index = 0; index < contorSigma; index++)
		{
			f >> aux1;
			sigma.emplace_back(aux1);
		}
		for (int index = 0; index < contorDelta; index++)
		{
			f >> aux1 >> aux2 >> aux3;
			deltaAuxiliar = std::make_tuple(aux1, aux2, aux3);
			delta.emplace_back(deltaAuxiliar);
		}
		f >> stareInit;
		for (int index = 0; index < contorFinale; index++)
		{
			f >> aux1;
			finale.emplace_back(aux1);
		}
	}
	return AFD(stari, sigma, delta, stareInit, finale);
}

void AFD::AfisareFisier(const std::string& filename)
{
	std::ofstream f;
	f.open(filename);
	f.clear();

	f << "Starile sunt: ";
	for (int index = 0; index < m_stari.size(); index++)
	{
		f << m_stari[index] << " ";
	}
	f << std::endl;

	f << "Sigma este: ";
	for (int index = 0; index < m_sigma.size(); index++)
	{
		f << m_sigma[index] << " ";
	}
	f << std::endl;

	f << "Delta este:";
	for (int index = 0; index < m_delta.size(); index++)
	{
		f << "\n" << std::get<0>(m_delta[index]) << " " << std::get<1>(m_delta[index]) << " " << std::get<2>(m_delta[index]);
	}
	f << std::endl;

	f << "Starea initiala este: " << m_stareInit << "\n";

	f << "Starile finale sunt: ";
	for (int index = 0; index < m_finale.size(); index++)
	{
		f << m_finale[index] << " ";
	}
	f << std::endl;

	f.close();
}
std::string AFD::Verificare(std::string cuvantCitit)
{
	std::string stareCurenta = m_stareInit;

	for (int index = 0; index < cuvantCitit.size(); index++)
	{
		bool ok = false;
		for (int index2 = 0; index2 < m_delta.size(); index2++)
		{
			if (cuvantCitit[index] == std::get<1>(m_delta[index2])[0] && stareCurenta == std::get<0>(m_delta[index2]))
			{
				stareCurenta = std::get<2>(m_delta[index2]);
				ok = true;
				break;
			}
		}

		if (ok == false)
		{
			return "\nExista blocaj!\n";
		}
	}

	bool ok = false;
	for (int index = 0; index < m_finale.size(); index++)
	{
		if (stareCurenta == m_finale[index])
		{
			ok = true;
		}
	}
	if (ok == true)
	{
		return "\nCuvantul este acceptat!\n";
	}
	else
	{
		return "\nCuvantul nu este acceptat!\n";
	}
}
bool cautareStare(std::string stare, std::vector<std::string> finale)
{
	for (int index = 0; index < finale.size(); index++)
		if (stare == finale[index])
			return 0;
	return 1;
}
void AFD::Minimizare()
{
	std::vector<std::vector<int>> matrice;
	for (int index1 = 0; index1 < size_matrice; index1++)
	{
		for(int index2=0;index2< size_matrice; index2++)
			if (index1 > index2)
			{
				if (cautareStare(m_stari[index1], m_finale) == 1)
					matrice[index1][index2] = 1;
			}
	}
}
void AFD::EliminareStariNeaccesibile()
{
	std::vector<bool> caleVizitata;
	for (int index = 0; index < m_delta.size(); index++)
	{
		caleVizitata.emplace_back(false);
	}

	std::vector<std::pair<std::string, bool>> stariVizitate;
	for (int index = 0; index < m_stari.size(); index++)
	{
		stariVizitate.emplace_back(std::make_pair(m_stari[index], false));
	}

	bool oSchimbare = true;
	bool maiFacemOparcurgere = false;
	int lastIndex;
	std::string stareCurenta = m_stareInit;

	while (oSchimbare == true)
	{
		oSchimbare = false;
		for (int index = 0; index < m_delta.size(); index++)
		{
			if (std::get<0>(m_delta[index]) == stareCurenta)
			{
				if (caleVizitata[index] == false)
				{
					oSchimbare = true;
					maiFacemOparcurgere = true;
					stareCurenta = std::get<2>(m_delta[index]);
					for (int j = 0; j < stariVizitate.size(); j++)
					{
						if (stariVizitate[j].first == stareCurenta)
						{
							stariVizitate[j].second = true;
						}
					}
					lastIndex = index;
				}
			}

			if (index >= m_delta.size() - 1 && maiFacemOparcurgere == true)
			{
				caleVizitata[lastIndex] = true;
				index = 0;
				stareCurenta = m_stareInit;
				maiFacemOparcurgere = false;
			}

		}

	}

	for (int index = 0; index < stariVizitate.size(); index++)
	{
		if (stariVizitate[index].second == false && stariVizitate[index].first != m_stareInit)
		{
			for (int j = 0; j < m_delta.size(); j++)
			{
				if (stariVizitate[index].first == std::get<0>(m_delta[j]))
				{
					m_delta.erase(m_delta.begin() + j);
					j = 0;
				}
			}

			for (int j = 0; j < m_stari.size(); j++)
			{
				if (stariVizitate[index].first == m_stari[j])
				{
					m_stari.erase(m_stari.begin() + j);
				}
			}
		}
	}
}