#include "Analizator2.h"

void Analizator::Analiza()
{
	std::ifstream f("text.txt");
	while (!f.eof())
	{
		bool ok = false;
		std::string s;
		f >> s;
		for (int i = 0; i < m_tipuriDate.size(); ++i)
		{
			if (s == m_tipuriDate[i])
			{
				ok = true;
				m_analizator.push_back(std::tie("TOKEN_", m_tipuriDate[i], "_"));
			}
		}

		for (int i = 0; i < m_parateze.size(); ++i)
		{
			if (s == m_parateze[i])
			{
				ok = true;
				if (m_parateze[i] == "(")
					m_analizator.push_back(std::tie("TOKEN_", "PD", "_"));
				if (m_parateze[i] == ")")
					m_analizator.push_back(std::tie("TOKEN_", "PI", "_"));
				if (m_parateze[i] == "{")
					m_analizator.push_back(std::tie("TOKEN_", "BID", "_"));
				if (m_parateze[i] == "}")
					m_analizator.push_back(std::tie("TOKEN_", "BII", "_"));
				if (m_parateze[i] == "[")
					m_analizator.push_back(std::tie("TOKEN_", "BDD", "_"));
				if (m_parateze[i] == "]")
					m_analizator.push_back(std::tie("TOKEN_", "BDI", "_"));
			}
		}

		for (int i = 0; i < m_operatori.size(); ++i)
		{
			if (s == m_operatori[i])
			{
				ok = true;
				if (m_operatori[i] == "+")
					m_analizator.push_back(std::tie("TOKEN_", "AD", "_"));
				if (m_operatori[i] == "-")
					m_analizator.push_back(std::tie("TOKEN_", "SC", "_"));
				if (m_operatori[i] == "*")
					m_analizator.push_back(std::tie("TOKEN_", "IN", "_"));
				if (m_operatori[i] == "/")
					m_analizator.push_back(std::tie("TOKEN_", "SL", "_"));
				if (m_operatori[i] == "%")
					m_analizator.push_back(std::tie("TOKEN_", "MODULO", "_"));
				if (m_operatori[i] == "=")
					m_analizator.push_back(std::tie("TOKEN_", "ATR", "_"));
				if (m_operatori[i] == "<")
					m_analizator.push_back(std::tie("TOKEN_", "LS", "_"));
				if (m_operatori[i] == ">")
					m_analizator.push_back(std::tie("TOKEN_", "LD", "_"));
			}
		}
		for (int i = 0; i < m_instructiuni.size(); ++i)
		{
			if (s == m_instructiuni[i])
			{
				ok = true;
				if (m_parateze[i] == "if")
					m_analizator.push_back(std::tie("TOKEN_", "IF", "_"));
				if (m_parateze[i] == "while")
					m_analizator.push_back(std::tie("TOKEN_", "WHILE", "_"));
				if (m_parateze[i] == "for")
					m_analizator.push_back(std::tie("TOKEN_", "FOR", "_"));
				if (m_parateze[i] == "do")
					m_analizator.push_back(std::tie("TOKEN_", "DO", "_"));
				if (m_parateze[i] == "else")
					m_analizator.push_back(std::tie("TOKEN_", "ELSE", "_"));
			}
		}

		for (int i = 0; i < m_delimitatori.size(); ++i)
		{
			if (s == m_delimitatori[i])
			{
				ok = true;
				if (m_parateze[i] == ";")
					m_analizator.push_back(std::tie("TOKEN_", "PV", "_"));
				if (m_parateze[i] == ",")
					m_analizator.push_back(std::tie("TOKEN_", "VG", "_"));
			}
		}

		if (ok == false)
			m_analizator.push_back(std::tie("TOKEN_ID,", "pointer_la_ ", s));
	
	}
}
void Analizator::Afisare()
{
	for (int index = 0; index < m_analizator.size(); index++)
		std::cout << "(" << std::get<0>(m_analizator[index]) << std::get<1>(m_analizator[index]) << std::get<2>(m_analizator[index]) << "),";
}
